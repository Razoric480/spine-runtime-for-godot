class_name ResourceFormatSaverSpineSkeletonJsonData
tool
extends ResourceFormatSaver


func save(path: String, resource: Resource, flags: int) -> int:
	var error: int = resource.save_to_file(path)
	return error


func get_recognized_extensions(resource: Resource) -> PoolStringArray:
	var extensions := PoolStringArray()
	var native_name: String = resource.get_script().get_class_name()
	var atlas_resource_name: String = "SpineSkeletonJsonDataResource"
	if native_name == atlas_resource_name:
		extensions.push_back("spjson")
	return extensions


func recognize(resource: Resource) -> bool:
	var native_name: String = resource.get_script().get_class_name()
	var atlas_resource_name: String = "SpineSkeletonJsonDataResource"
	return native_name == atlas_resource_name
