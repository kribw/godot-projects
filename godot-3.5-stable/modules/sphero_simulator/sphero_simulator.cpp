#include "sphero_simulator.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

SpheroSimulator::SpheroSimulator() {
	// Nothing here for now
}

struct SpheroVelocity {
	float time, x, y, total;
};

struct SpheroOrientation {
	float pitch, roll, yaw;
};

struct SpheroLocation {
	float x, y;
};

struct SpheroGyroscope {
	float pitch, roll, yaw;
};

struct SpheroDistance {
	float x, y, total;
};

struct SpheroAccelerometer {
	float x, y, z, total;
};

struct SpheroData {
	float time;
	SpheroVelocity velocity;
	SpheroOrientation orientation;
	SpheroLocation location;
	SpheroGyroscope gyroscope;
	SpheroDistance distance;
	SpheroAccelerometer accelerometer;
};

std::vector<SpheroData> _data;
std::vector<SpheroVelocity> _velocities;

void SpheroSimulator::read_input(String file_path) {
	read_velocity(file_path);
}

void SpheroSimulator::read_velocity(String file_path) {
	std::ifstream ifs;
	ifs.open(file_path.c_str(), std::ios::in);

	if (!ifs)
		// Return if we cant open file
		// Maybe add some exception or something
		return;

	std::string line;

	// Skip csv description
	if (!ifs.eof())
		std::getline(ifs, line);

	while (!ifs.eof()) {
		std::getline(ifs, line);
		std::istringstream s(line);
		SpheroVelocity vel {};
		std::string temp;

		std::getline(s, temp, ',');
		vel.time = std::stof(temp);

		std::getline(s, temp, ',');
		vel.x = std::stof(temp);

		std::getline(s, temp, ',');
		vel.y = std::stof(temp);

		std::getline(s, temp, ',');
		vel.total = std::stof(temp);

		_velocities.push_back(vel);
	}

	ifs.close();
}

void SpheroSimulator::read_orientation(String file_path) {

}

void SpheroSimulator::read_location(String file_path) {

}

void SpheroSimulator::read_gyroscope(String file_path) {

}

void SpheroSimulator::read_distance(String file_path) {

}

void SpheroSimulator::read_accelerometer(String file_path) {
	String path = file_path + "-Accelerometer.csv";
}

float SpheroSimulator::get_velocity_x(int index) {
	//SpheroData data = _data[index];
	//return data.velocity.x;
	return _velocities[index].x;
}

int SpheroSimulator::get_data_size() {
	return _data.size();
}

int SpheroSimulator::get_velocity_size() {
	return _velocities.size();
}

void SpheroSimulator::_bind_methods() {
	ClassDB::bind_method(D_METHOD("read_input"), &SpheroSimulator::read_input);
	ClassDB::bind_method(D_METHOD("get_velocity_x"), &SpheroSimulator::get_velocity_x);
	ClassDB::bind_method(D_METHOD("read_velocity"), &SpheroSimulator::read_velocity);
	ClassDB::bind_method(D_METHOD("get_velocity_size"), &SpheroSimulator::get_velocity_size);
	//ClassDB::bind_method(D_METHOD("get_map"), &SpheroSimulator::get_map);
}
