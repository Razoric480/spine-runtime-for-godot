tool
class_name ResourceFormatLoaderSpineAtlas
extends ResourceFormatLoader


func load(path: String, original_path: String):
	var atlas := preload("res://addons/spine-runtime/SpineAtlasResource.gdns").new()
	atlas.load_from_file(path)
	
	return atlas


func get_recognized_extensions() -> PoolStringArray:
	var extensions := PoolStringArray()
	extensions.push_back("spatlas")
	return extensions


func get_resource_type(path: String) -> String:
	return "SpineAtlasResource"


func handles_type(typename: String) -> bool:
	return typename == "SpineAtlasResource" or ClassDB.is_parent_class(typename, "SpineAtlasResource")
