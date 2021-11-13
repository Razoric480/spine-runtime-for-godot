tool
class_name ResourceFormatLoaderSpineSkeletonJsonData
extends ResourceFormatLoader


func load(path: String, original_path: String):
	var skeleton := preload("res://addons/spine-runtime/SpineSkeletonJsonDataResource.gdns").new()
	skeleton.load_from_file(path)
	
	return skeleton


func get_recognized_extensions() -> PoolStringArray:
	var extensions := PoolStringArray()
	extensions.push_back("spjson")
	return extensions


func get_resource_type(path: String) -> String:
	return "SpineSkeletonJsonDataResource"


func handles_type(typename: String) -> bool:
	return typename == "SpineSkeletonJsonDataResource" or ClassDB.is_parent_class(typename, "SpineSkeletonJsonDataResource")
