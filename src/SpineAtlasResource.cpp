//
// Created by Raymond_Lx on 2020/6/2.
//

#include "SpineAtlasResource.h"

#include <spine/Atlas.h>
#include <File.hpp>
#include <JSON.hpp>
#include <JSONParseResult.hpp>
#include <ResourceLoader.hpp>

namespace godot {

#define ERR_PRINT(msg) Godot::print_error(String(msg), __FUNCTION__, __FILE__, __LINE__)

class RaiixSpineTextureLoader : public spine::TextureLoader {
private:
	Array *tex_list, *ntex_list;
	String normal_tex_prefix;

public:
	RaiixSpineTextureLoader(Array *t, Array *nt, const String &p) :
			tex_list(t), ntex_list(nt), normal_tex_prefix(p) {
		if (tex_list)
			tex_list->clear();
		if (ntex_list)
			ntex_list->clear();
	}

	String fixPathIssue(const String &path) {
		if (path.length() > 5 && path[4] == '/' && path[5] == '/')
			return path;
		const String prefix = "res:/";
		auto i = path.find(prefix);
		//        print_line(String("Found i at ") + String(Variant(i)));
		auto sub_str_pos = i + prefix.length() - 1;
		if (sub_str_pos < 0)
			return path;
		auto res = path.substr(sub_str_pos, -1);
		//        print_line(String("rest of it: ") + res);
		if (res.length() > 0) {
			if (res[0] != '/') {
				return prefix + "/" + res;
			} else {
				return prefix + res;
			}
		}
		return path;
	}

	virtual void load(spine::AtlasPage &page, const spine::String &path) {
		int err = GODOT_OK;

		//		print_line(String("Spine is loading texture: ") + String(path.buffer()));
		auto fixed_path = fixPathIssue(String(path.buffer()));
		//        print_line("Fixed path: " + fixed_path);

		// Load texture (e.g. tex.png)
		Ref<Texture> tex = ResourceLoader::get_singleton()->load(fixed_path, "Texture");
		if (tex.is_null()) {
			ERR_PRINT(String("Can't load texture: " + String(path.buffer())));
			SpineRendererObject *renderer_object = new SpineRendererObject();
			page.setRendererObject(renderer_object);
			return;
		}

		if (tex_list)
			tex_list->append(tex);
		SpineRendererObject *p_spine_renderer_object = new SpineRendererObject();
		p_spine_renderer_object->tex = tex;

		// Load normal texture (e.g. n_tex.png)
		String temppath = fixed_path;
		String newpath = String(temppath.get_base_dir() + "/") + String(normal_tex_prefix + "_") + String(temppath.get_file());
		//        print_line(vformat("try n tex: %s", newpath));
		if (ResourceLoader::get_singleton()->exists(newpath)) {
			Ref<Texture> normal_tex = ResourceLoader::get_singleton()->load(newpath, "Texture");
			if (ntex_list)
				ntex_list->append(normal_tex);
			p_spine_renderer_object->normal_tex = normal_tex;

			// print_line(String("From atlas resource load: ") + String(" ro ") + String(Variant((long long) p_spine_renderer_object)));
			// print_line(String("From atlas resource load: ") + String(Variant(p_spine_renderer_object->tex)) + String(", ") + String(Variant(p_spine_renderer_object->normal_tex)));
		}

		page.setRendererObject((void *)p_spine_renderer_object);

		page.width = tex->get_width();
		page.height = tex->get_height();
	}

	virtual void unload(void *p) {
		// print_line("I'm out.");
		auto p_spine_renderer_object = (SpineRendererObject *)p;
		Ref<Texture> &tex = p_spine_renderer_object->tex;
		Ref<Texture> &normal_tex = p_spine_renderer_object->normal_tex;

		if (tex.is_valid())
			tex.unref();
		if (normal_tex.is_valid())
			normal_tex.unref();

		delete p_spine_renderer_object;
	}
};

SpineAtlasResource::SpineAtlasResource() {}
SpineAtlasResource::~SpineAtlasResource() {
	if (atlas)
		delete atlas;
}

void SpineAtlasResource::_init() {
	atlas = nullptr;
	normal_texture_prefix = "n";
}

void SpineAtlasResource::_register_methods() {
	register_method("load_from_atlas_file", &SpineAtlasResource::load_from_atlas_file);
	register_method("load_from_file", &SpineAtlasResource::load_from_file);
	register_method("save_to_file", &SpineAtlasResource::save_to_file);

	register_method("get_source_path", &SpineAtlasResource::get_source_path);

	register_method("get_textures", &SpineAtlasResource::get_textures);
	register_method("get_normal_textures", &SpineAtlasResource::get_normal_textures);

	register_property<SpineAtlasResource, String>("source_path", nullptr, &SpineAtlasResource::get_source_path, "");
	register_property<SpineAtlasResource, Array>("textures", nullptr, &SpineAtlasResource::get_textures, Array());
	register_property<SpineAtlasResource, Array>("normal_textures", nullptr, &SpineAtlasResource::get_normal_textures, Array());
}

Array SpineAtlasResource::get_textures() {
	return tex_list;
}

Array SpineAtlasResource::get_normal_textures() {
	return ntex_list;
}

String SpineAtlasResource::get_source_path() {
	return source_path;
}

int SpineAtlasResource::load_from_atlas_file(String p_path) {
	//    print_line(vformat("Importing atlas file: %s", p_path));
	source_path = p_path;

	int err;
	Ref<File> file;
	file.instance();
	err = (int)file->open(p_path, File::READ);
	if (err != GODOT_OK) {
		return err;
	}
	atlas_data = file->get_as_text();
	file->close();

	if (atlas)
		delete atlas;

	tex_list.clear();
	ntex_list.clear();

	atlas = new spine::Atlas(atlas_data.alloc_c_string(), atlas_data.length(), source_path.get_base_dir().alloc_c_string(), new RaiixSpineTextureLoader(&tex_list, &ntex_list, normal_texture_prefix));

	//    print_line(vformat("atlas loaded!"));

	if (atlas)
		return GODOT_OK;

	tex_list.clear();
	ntex_list.clear();

	return GODOT_ERR_FILE_UNRECOGNIZED;
}

int SpineAtlasResource::load_from_file(String p_path) {
	int err;

	Ref<File> file;
	file.instance();
	err = (int)file->open(p_path, File::READ);
	if (err != GODOT_OK) {
		return err;
	}
	String json_string = file->get_as_text();
	file->close();

	String error_string;
	int error_line;
	Ref<JSONParseResult> result = JSON::get_singleton()->parse(json_string);
	if ((int)result->get_error() != GODOT_OK) {
		return (int)result->get_error();
	}

	Dictionary content = result->get_result();

	source_path = content["source_path"];
	atlas_data = content["atlas_data"];
	normal_texture_prefix = content["normal_texture_prefix"];

	if (atlas)
		delete atlas;
	tex_list.clear();
	ntex_list.clear();
	atlas = new spine::Atlas(atlas_data.alloc_c_string(), atlas_data.length(), source_path.get_base_dir().alloc_c_string(), new RaiixSpineTextureLoader(&tex_list, &ntex_list, normal_texture_prefix));

	if (atlas)
		return GODOT_OK;

	tex_list.clear();
	ntex_list.clear();
	return GODOT_ERR_FILE_UNRECOGNIZED;
}

int SpineAtlasResource::save_to_file(String p_path) {
	int err;
	Ref<File> file;
	file.instance();
	err = (int)file->open(p_path, File::WRITE);
	if (err != GODOT_OK) {
		return err;
	}

	Dictionary content;
	content["source_path"] = source_path;
	content["atlas_data"] = atlas_data;
	content["normal_texture_prefix"] = normal_texture_prefix;

	file->store_string(JSON::get_singleton()->print(content));
	file->close();

	return GODOT_OK;
}

} //namespace godot