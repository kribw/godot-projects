extends Node


# Declare member variables here. Examples:
# var a = 2
# var b = "text"

var simulator = SpheroSimulator.new()

var path = "data/Sphero-sep.26-2022-@-09-55"

# Called when the node enters the scene tree for the first time.
func _ready():
	simulator.read_input(path)
	
	var size = simulator.get_velocity_size()
	print(str("Size: ", size))
	
	for i in size:
		print(simulator.get_velocity_x(i))
	
	print(str("Is data consistent? ", simulator.is_data_consistent()))
	print(str("Data sizes: ", simulator.get_all_sizes()))
	
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass
