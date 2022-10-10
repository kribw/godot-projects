#pragma once

#include "core/reference.h"

#include <string>
#include <vector>

class SpheroSimulator : public Reference {
	GDCLASS(SpheroSimulator, Reference);

protected:
	static void _bind_methods();

public:
	SpheroSimulator();
	// Read/parse file
	std::vector<std::string> read_file(const String file_path);
	void parse_file(const String file_path);
	void parse_velocity(const String file_path);
	void parse_orientation(const String file_path);
	void parse_location(const String file_path);
	void parse_gyroscope(const String file_path);
	void parse_distance(const String file_path);
	void parse_accelerometer(const String file_path);

	// Getters
	float get_velocity_time(const int index);
	float get_velocity_x(const int index);
	float get_velocity_y(const int index);
	float get_velocity_total(const int index);

	float get_orientation_pitch(const int index);
	float get_orientation_roll(const int index);
	float get_orientation_yaw(const int index);

	float get_location_x(const int index);
	float get_location_y(const int index);

	float get_gyroscope_pitch(const int index);
	float get_gyroscope_roll(const int index);
	float get_gyroscope_yaw(const int index);

	float get_distance_x(const int index);
	float get_distance_y(const int index);
	float get_distance_total(const int index);

	float get_accelerometer_x(const int index);
	float get_accelerometer_y(const int index);
	float get_accelerometer_z(const int index);
	float get_accelerometer_total(const int index);

	// Check/validate size
	int get_velocity_size();
	bool is_data_consistent();
	String get_all_sizes();

	bool is_collision(int index);
	void find_collisions();
	int get_collisions_size();
};
