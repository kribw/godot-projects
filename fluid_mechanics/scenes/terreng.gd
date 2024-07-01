extends MeshInstance

func _ready():
	var material = get_node(".").get_surface_material(0)
	#print("material: ", mesh.surface_get_material(0))
	print("material: ", material)


	var image = Image.new()
	var err = image.load("images/output.png")

	if(err != OK):
		print("Failed to load image.")
	
	var texture = ImageTexture.new()
	texture.create_from_image(image, 0)
	print("texture: ", texture)
	material.set_shader_param("my_texture", texture)

# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass
