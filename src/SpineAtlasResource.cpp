//
// Created by Raymond_Lx on 2020/6/2.
//

#include "SpineAtlasResource.h"

#include <spine/Atlas.h>
#include <File.hpp>
#include <JSON.hpp>
#include <JSONParseResult.hpp>
#include <ResourceLoader.hpp>
#include <String.hpp>

class RaiixSpineTextureLoader : public spine::TextureLoader {
private:
	godot::Array *tex_list, *ntex_list;
	godot::String normal_tex_prefix;

public:
	RaiixSpineTextureLoader(godot::Array *t, godot::Array *nt, const godot::String &p) :
			tex_list(t), ntex_list(nt), normal_tex_prefix(p) {
		if (tex_list)
			tex_list->clear();
		if (ntex_list)
			ntex_list->clear();
	}

	godot::String fixPathIssue(const godot::String &path) {
		if (path.length() > 5 && path[4] == '/' && path[5] == '/')
			return path;
		const godot::String prefix = "res:/";
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
		godot::Error err = godot::Error::OK;

		//		print_line(String("Spine is loading texture: ") + String(path.buffer()));
		auto fixed_path = fixPathIssue(godot::String(path.buffer()));
		//        print_line("Fixed path: " + fixed_path);

		// Load texture (e.g. tex.png)
		godot::Ref<godot::Texture> tex = godot::ResourceLoader::get_singleton()->load(fixed_path, "", false);
		if (!tex.is_valid()) {
			spine::String error_message = spine::String("Can't load texture \"");
			error_message.append(path);
			error_message.append("\"");
			godot_print_error(error_message.buffer(), __FUNCTION__, __FILE__, __LINE__);
			page.setRendererObject((void *)new SpineRendererObject{ nullptr });
			return;
		}

		if (tex_list)
			tex_list->append(tex);
		auto p_spine_renderer_object = new SpineRendererObject;
		p_spine_renderer_object->tex = tex;

		// Load normal texture (e.g. n_tex.png)
		godot::String temppath = fixed_path;
		godot::String newpath = temppath.get_base_dir();
		newpath += "/" + normal_tex_prefix + "_" + temppath.get_file();
		//        print_line(vformat("try n tex: %s", newpath));
		if (godot::ResourceLoader::get_singleton()->exists(newpath)) {
			godot::Ref<godot::Texture> normal_tex = godot::ResourceLoader::get_singleton()->load(newpath);
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
		godot::Ref<godot::Texture> &tex = p_spine_renderer_object->tex;
		godot::Ref<godot::Texture> &normal_tex = p_spine_renderer_object->normal_tex;

		if (tex.is_valid())
			tex.unref();
		if (normal_tex.is_valid())
			normal_tex.unref();

		delete p_spine_renderer_object;
	}
};

void SpineAtlasResource::_init() {
	atlas = nullptr;
	normal_texture_prefix = "n";
}

SpineAtlasResource::SpineAtlasResource() {}
SpineAtlasResource::~SpineAtlasResource() {
	if (atlas) {
		delete atlas;
	}
}

void SpineAtlasResource::_register_methods() {
	godot::register_method("load_from_atlas_file", &SpineAtlasResource::load_from_atlas_file);

	godot::register_method("get_source_path", &SpineAtlasResource::get_source_path);

	godot::register_method("get_textures", &SpineAtlasResource::get_textures);
	godot::register_method("get_normal_textures", &SpineAtlasResource::get_normal_textures);

	godot::register_property<SpineAtlasResource, godot::String>("source_path", nullptr, &SpineAtlasResource::get_source_path, "");
	godot::register_property<SpineAtlasResource, godot::Array>("textures", nullptr, &SpineAtlasResource::get_textures, godot::Array());
	godot::register_property<SpineAtlasResource, godot::Array>("normal_textures", nullptr, &SpineAtlasResource::get_normal_textures, godot::Array());
}

godot::Array SpineAtlasResource::get_textures() {
	return tex_list;
}

godot::Array SpineAtlasResource::get_normal_textures() {
	return ntex_list;
}

godot::String SpineAtlasResource::get_source_path() {
	return source_path;
}

godot::Error SpineAtlasResource::load_from_atlas_file(const godot::String &p_path) {
	//    print_line(vformat("Importing atlas file: %s", p_path));
	source_path = p_path;

	godot::Error err;

	godot::Ref<godot::File> file;
	file.instance();
	err = file->open(p_path, godot::File::READ);
	if (err != godot::Error::OK) {
		return err;
	}
	atlas_data = file->get_as_text();
	file->close();

	if (atlas) {
		delete atlas;
	}

	tex_list.clear();
	ntex_list.clear();
	atlas = new spine::Atlas(atlas_data.utf8().get_data(), atlas_data.length(), source_path.get_base_dir().utf8().get_data(), new RaiixSpineTextureLoader(&tex_list, &ntex_list, normal_texture_prefix));

	//    print_line(vformat("atlas loaded!"));

	if (atlas) {
		return godot::Error::OK;
	}

	tex_list.clear();
	ntex_list.clear();

	return godot::Error::ERR_FILE_UNRECOGNIZED;
}

godot::Error SpineAtlasResource::load_from_file(const godot::String &p_path) {
	godot::Error err;

	godot::Ref<godot::File> file;
	file.instance();
	err = file->open(p_path, godot::File::READ);
	if (err != godot::Error::OK) {
		return err;
	}
	godot::String json_string = file->get_as_text();
	file->close();

	godot::String error_string;
	int error_line;
	godot::JSON *json = godot::JSON::get_singleton();
	godot::Ref<godot::JSONParseResult> result = json->parse(json_string);
	if (result->get_error() != godot::Error::OK) {
		return result->get_error();
	}

	godot::Dictionary content = result->get_result();

	source_path = content["source_path"];
	atlas_data = content["atlas_data"];
	normal_texture_prefix = content["normal_texture_prefix"];

	if (atlas) {
		delete atlas;
	}
	tex_list.clear();
	ntex_list.clear();
	atlas = new spine::Atlas(atlas_data.utf8().get_data(), atlas_data.length(), source_path.get_base_dir().utf8().get_data(), new RaiixSpineTextureLoader(&tex_list, &ntex_list, normal_texture_prefix));

	if (atlas) {
		return godot::Error::OK;
	}

	tex_list.clear();
	ntex_list.clear();
	return godot::Error::ERR_FILE_UNRECOGNIZED;
}

godot::Error SpineAtlasResource::save_to_file(const godot::String &p_path) {
	godot::Error err;
	godot::Ref<godot::File> file;
	file.instance();
	err = file->open(p_path, godot::File::WRITE);
	if (err != godot::Error::OK) {
		return err;
	}

	godot::Dictionary content;
	content["source_path"] = source_path;
	content["atlas_data"] = atlas_data;
	content["normal_texture_prefix"] = normal_texture_prefix;

	//    print_line(vformat("storing source_path: %s", source_path));

	file->store_string(godot::JSON::get_singleton()->print(content));
	file->close();

	return godot::Error::OK;
}
