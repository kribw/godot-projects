extends Spatial

var textures = []
var tex_index
var buildings
var helipad
var terrain
var image
var texture

func load_textures():
	tex_index = 0
	var dir = Directory.new()
	if dir.open("textures/") == OK:
		dir.list_dir_begin()
		var file_name = dir.get_next()
		
		while file_name != "":
			if dir.current_is_dir():
				print("Found directory: " + file_name)
			else:
				#print("Found file: " + file_name)
				if file_name.get_extension() == "png":
					textures.append(file_name)
			file_name = dir.get_next()
		#print(textures)
		# Make sure textures are sorted in correct order
		textures.sort()
	else:
		print("An error occurred when trying to access the path.")

func _on_Timer_timeout():
	# Check if we have reached final texture
	if(tex_index >= textures.size()):
		$Timer.stop()
		return
	
	var err = image.load("textures/" + textures[tex_index])
	if(err != OK):
		print("Failed to load image.")
	
	texture.create_from_image(image, 0)
	buildings.set_shader_param("my_texture", texture)
	helipad.set_shader_param("my_texture", texture)
	terrain.set_shader_param("my_texture", texture)
	
	# Increase index for next timestep
	tex_index += 1

func setup_timer():
	$Timer.connect("timeout", self, "_on_Timer_timeout")
	$Timer.set_wait_time(0.4)
	$Timer.set_one_shot(false)
	$Timer.start()

# Called when the node enters the scene tree for the first time.
func _ready():
	load_textures()
	
	# Set up vars for node materials
	buildings = get_node("bygninger").get_surface_material(0)
	helipad = get_node("helipad_skjerm").get_surface_material(0)
	terrain = get_node("terreng").get_surface_material(0)

	# Create Image and Texture class
	image = Image.new()
	texture = ImageTexture.new()

	setup_timer()

	# Interpolate Flow3D texture offset
	$Tween.interpolate_property(buildings, "shader_param/x_offset", -31.01, -43.5, 14.03, Tween.TRANS_LINEAR)
	$Tween.interpolate_property(helipad, "shader_param/x_offset", -31.01, -43.5, 14.03, Tween.TRANS_LINEAR)
	$Tween.interpolate_property(terrain, "shader_param/x_offset", -31.01, -43.5, 14.03, Tween.TRANS_LINEAR)
	$Tween.start()

# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass
