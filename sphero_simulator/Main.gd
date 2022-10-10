extends Node

# Called when the node enters the scene tree for the first time.
func _ready():
	$UserInterface/SimCompleted.hide()

# Called when simulation is completed
func _on_sim_completed(message):
	$UserInterface/SimCompleted/SimStats.text = message
	$UserInterface/SimCompleted.show()
	print("_on_sim_completed")

# Called when key to restart simulation is pressed
func _on_sim_restart():
	get_tree().reload_current_scene()
