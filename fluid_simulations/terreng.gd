extends MeshInstance


# Declare member variables here. Examples:
# var a = 2
# var b = "text"


# Called when the node enters the scene tree for the first time.
func _ready():
	var material = get_active_material(0)
	material.set_shader_param("test", 1.0)
	print("test: ", material.get_shader_param("test"))
	
	material.set_shader_param("global_transform", get_global_transform())
	print("global transform: ", material.get_shader_param("global_transform"))
# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass
