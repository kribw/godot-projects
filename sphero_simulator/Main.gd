extends Node


# Declare member variables here. Examples:
# var a = 2
# var b = "text"

var simulator = SpheroSimulator.new()

var vel_path = "C:\\Users\\Kristoffer\\OneDrive - UiT Office 365\\VR\\Sensor data\\Sphero-sep.26-2022-@-09-55-Velocity.csv"

# Called when the node enters the scene tree for the first time.
func _ready():
	simulator.read_velocity(vel_path)
	
	var size = simulator.get_velocity_size()
	print(str("Size: ", size))
	
	for i in size:
		print(simulator.get_velocity_x(i))
	
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass
