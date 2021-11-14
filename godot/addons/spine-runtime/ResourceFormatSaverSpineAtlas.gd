class_name ResourceFormatSaverSpineAtlas
tool
extends ResourceFormatSaver


func save(path: String, resource: Resource, flags: int) -> int:
	var error: int = resource.save_to_file(path)
	return error


func get_recognized_extensions(resource: Resource) -> PoolStringArray:
	var extensions := PoolStringArray()
	var native_name: String = resource.get_script().get_class_name()
	var atlas_resource_name: String = "SpineAtlasResource"
	if native_name == atlas_resource_name:
		extensions.push_back("spatlas")
	return extensions


func recognize(resource: Resource) -> bool:
	var native_name: String = resource.get_script().get_class_name()
	var atlas_resource_name: String = "SpineAtlasResource"
	return native_name == atlas_resource_name
