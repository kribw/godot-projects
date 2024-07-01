extends KinematicBody

# Signals
signal sim_completed
signal sim_restart
signal collision

# Member variables
var _simulator
var _size = 0
var _index # Current index of data
var _wait_time = 0.16 # Initial wait time
var _prev_tstep 

const SCALE = 5 # Make sphero data more friendly to Godot

# Called when the node enters the scene tree for the first time.
func _ready():
	_simulator = SpheroSimulator.new()
	
	# Check that size is 0 to prevent duplicates on restart
	if(_simulator.get_velocity_size() == 0):
		var path = "data/Sphero-okt.08-2022-@-01-17"
		_simulator.parse_file(path)

	var main = get_parent().get_node(".")
	$Timer.connect("timeout", self, "_on_Timer_timeout")
	connect("sim_completed", main, "_on_sim_completed")
	connect("sim_restart", main, "_on_sim_restart")
	init()

func init():
	_size = _simulator.get_velocity_size()
	var collisions = _simulator.get_collisions_size() # Remove
	print("Size: ", _size, " Collisions: ", collisions) # Remove

	_index = 0
	$Timer.set_wait_time(_wait_time)
	$Timer.set_one_shot(false)
	$Timer.start()

func _on_Timer_timeout():
	_prev_tstep = _simulator.get_velocity_time(_index)
	_index += 1
	
	var _tstep = _simulator.get_velocity_time(_index) - _prev_tstep
	$Timer.set_wait_time(_tstep)
	
	var pitch = _simulator.get_orientation_pitch(_index)
	var yaw = _simulator.get_orientation_yaw(_index)
	var roll  = _simulator.get_orientation_roll(_index)
	var rot = Vector3(pitch, yaw, roll)

	var x = _simulator.get_location_x(_index) / SCALE
	var z = _simulator.get_location_y(_index) / SCALE
	var dest = Vector3(x, 2.0, z)
	
	if(_simulator.is_collision(_index)):
		add_collision(dest)
		
	$Tween.interpolate_property(self, "translation", translation, dest, _tstep, Tween.TRANS_LINEAR)
	$Tween.interpolate_property($Model, "rotation_degrees", $Model.rotation_degrees, rot, _tstep, Tween.TRANS_LINEAR)
	$Tween.start()
	
	# print("Count: ", _index, ", _tstep: ", _tstep, " Pitch: ", pitch, " Roll: ", roll, " Yaw: ", yaw)
	
	if(_index >= _size - 1):
		print("Finished. Index: ", _index, " Size: ", _size)
		var collisions = _simulator.get_collisions_size()
		emit_signal("sim_completed", "%d collisions detected." % collisions)
		$Timer.stop()

func add_collision(dest):
	# Add collision object to scene
	var obj_res = load("res://scenes/Flag.tscn")
	var obj = obj_res.instance()
	var offset = $Model/Sphere.mesh.radius # Spawn next to our Sphero, not on top
	obj.set_translation(dest - Vector3(offset, 0.0, 0.0))
	get_parent().add_child(obj)
	
	$Collision.play() # Play sound

func _physics_process(delta):
	var _camera = get_node("Target/Camera").get_global_transform()

func _process(delta):
	pass
	
func _input(ev):
	var is_visible = get_parent().get_node("UserInterface/SimCompleted").visible
	if Input.is_key_pressed(KEY_ENTER) and is_visible:
		init()
		emit_signal("sim_restart")
