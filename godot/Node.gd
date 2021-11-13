extends Node


func _ready() -> void:
	var file := File.new()
	file.open("res://character/spineboy-pro.json", File.READ)
	var result := file.get_as_text()
	file.close()
	print(result[0])
