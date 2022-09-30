extends KinematicBody


# Declare member variables here. Examples:
# var a = 2
# var b = "text"
var _camera
var _timer
var _pos
var _simulator
var _size
var _count
var _wait_time = 0.5

# Called when the node enters the scene tree for the first time.
func _ready():
	_camera = get_node("Target/Camera").get_global_transform()
	_timer = Timer.new()
	_pos = get_global_transform()
	
	add_child(_timer)
	
	_timer.connect("timeout", self, "_on_Timer_timeout")
	_timer.set_wait_time(_wait_time)
	_timer.set_one_shot(false)
	_timer.start()
	
	_simulator = SpheroSimulator.new()
	_size = _simulator.get_velocity_size()
	_count = 0

func _on_Timer_timeout():
	
	_pos.origin = _pos.origin.linear_interpolate(Vector3(50.0, 2.0, 2.0), _wait_time)
	set_global_transform(_pos)
	_count = _count + 1
	
	if(_count == _size):
		_timer.stop()
		# Make some menu appear "Simulation over"
	# pass

func _physics_process(delta):
	_camera = get_node("Target/Camera").get_global_transform()

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):

	pass
	# print(delta)

