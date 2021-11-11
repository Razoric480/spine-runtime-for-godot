//
// Created by Raiix on 2021/7/13.
//

#ifndef GODOT_RESOURCEFORMATSAVERSPINEATLAS_H
#define GODOT_RESOURCEFORMATSAVERSPINEATLAS_H

#include <Godot.hpp>
#include <ResourceFormatSaver.hpp>

class ResourceFormatSaverSpineAtlas : public godot::ResourceFormatSaver {
    GODOT_CLASS(ResourceFormatSaverSpineAtlas, godot::ResourceFormatSaver);
    
protected:
    static void _register_methods();
    
public:
    void _init();
    godot::Error save(const godot::String &p_path, const godot::Ref<godot::Resource> &p_resource, uint32_t p_flags = 0);
    godot::PoolStringArray get_recognized_extensions(const godot::Ref<godot::Resource> &p_resource) const;
    bool recognize(const godot::Ref<godot::Resource> &p_resource) const;
};

#endif //GODOT_RESOURCEFORMATSAVERSPINEATLAS_H
