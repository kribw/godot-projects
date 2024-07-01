extends Spatial

func _on_Timer_timeout():
	if($helicopter.translation.x > 20):
		$Timer.stop()
		return

func setup_timer():
	$Timer.connect("timeout", self, "_on_Timer_timeout")
	$Timer.set_wait_time(1.0)
	$Timer.set_one_shot(false)
	#$Timer.start()
	
	var start = Vector3(52.51, -68.91, 0.0)
	var end = Vector3(80.57, -81.40, 0.0)
	$Tween.interpolate_property($helicopter, "translation", start, end, 14.4, Tween.TRANS_LINEAR)
	$Tween.start()

func _ready():
	setup_timer()



# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
