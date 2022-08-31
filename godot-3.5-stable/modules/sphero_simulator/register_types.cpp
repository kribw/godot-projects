#include "register_types.h"

#include "core/class_db.h"
#include "sphero_simulator.h"

void register_sphero_simulator_types() {
	ClassDB::register_class<SpheroSimulator>();
}

void unregister_sphero_simulator_types() {
	// Nothing to do here in this example.
}
