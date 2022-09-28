#pragma once

#include "core/reference.h"

class SpheroSimulator : public Reference {
	GDCLASS(SpheroSimulator, Reference);
	//OBJ_TYPE(SpheroSimulator, Reference);

	// Data members

protected:
	static void _bind_methods();

public:
	SpheroSimulator();
	void read_input(String file_path);
	void read_velocity(String file_path);
	void read_orientation(String file_path);
	void read_location(String file_path);
	void read_gyroscope(String file_path);
	void read_distance(String file_path);
	void read_accelerometer(String file_path);
	float get_velocity_x(int index);
	int get_data_size();
	int get_velocity_size();
};
