extends Spatial

func _on_Timer_timeout():
	if($Helicopter.translation.x > 20):
		$Timer.stop()
		return
	
	var dest = $Helicopter.translation + Vector3(1, 0, 0)
	print(dest)
	$Tween.interpolate_property($Helicopter, "translation", $Helicopter.translation, dest, 1.0, Tween.TRANS_LINEAR)
	$Tween.start()

func setup_timer():
	$Timer.connect("timeout", self, "_on_Timer_timeout")
	$Timer.set_wait_time(1.0)
	$Timer.set_one_shot(false)
	$Timer.start()

func _ready():
	setup_timer()



# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
