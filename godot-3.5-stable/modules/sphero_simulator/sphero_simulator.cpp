#include "sphero_simulator.h"

#include <fstream>
#include <iostream>
#include <sstream>

SpheroSimulator::SpheroSimulator() {}

struct SpheroVelocity {
	float time, x, y, total;
};

struct SpheroOrientation {
	float time, pitch, roll, yaw;
};

struct SpheroLocation {
	float time, x, y;
};

struct SpheroGyroscope {
	float time, pitch, roll, yaw;
};

struct SpheroDistance {
	float time, x, y, total;
};

struct SpheroAccelerometer {
	float time, x, y, z, total;
};

// Store Sphero data in vectors
std::vector<SpheroVelocity> _velocities;
std::vector<SpheroOrientation> _orientations;
std::vector<SpheroLocation> _locations;
std::vector<SpheroGyroscope> _gyroscopes;
std::vector<SpheroDistance> _distances;
std::vector<SpheroAccelerometer> _accelerometers;

// Parse file containing Sphero data
void SpheroSimulator::parse_file(const String file_path) {
	parse_velocity(file_path);
	parse_orientation(file_path);
	parse_location(file_path);
	parse_gyroscope(file_path);
	parse_distance(file_path);
	parse_accelerometer(file_path);
}

// Read a file and return lines in vector<string>
std::vector<std::string> SpheroSimulator::read_file(const String file_path) {
	std::vector<std::string> lines;
	std::ifstream ifs;

	try {
		ifs.open(file_path.c_str(), std::ios::in);

		if (!ifs)
			throw("Error: no IFS.");

		std::string line;

		// Skip first line (csv description)
		if (!ifs.eof())
			std::getline(ifs, line);

		while (!ifs.eof()) {
			std::getline(ifs, line);
			lines.push_back(line);
		}

		ifs.close();
	} catch (...) {
		std::cout << "Error occurred while reading file." << std::endl;
	}

	return lines;
}

// Parse Sphero velocity data from file
void SpheroSimulator::parse_velocity(const String file_path) {
	const String path = file_path + "-Velocity.csv";
	std::vector<std::string> lines = read_file(path);

	try {
		for (std::string line : lines) {
			std::istringstream s(line);
			SpheroVelocity velocity{};
			std::string temp;

			std::getline(s, temp, ',');
			velocity.time = std::stof(temp);

			std::getline(s, temp, ',');
			velocity.x = std::stof(temp);

			std::getline(s, temp, ',');
			velocity.y = std::stof(temp);

			std::getline(s, temp, ',');
			velocity.total = std::stof(temp);

			_velocities.push_back(velocity);
		}
	} catch (...) {
		std::cout << "Error parsing velocity." << std::endl;
	}
}

// Parse Sphero orientation data from file
void SpheroSimulator::parse_orientation(const String file_path) {
	const String path = file_path + "-Orientation.csv";
	std::vector<std::string> lines = read_file(path);

	try {
		for (std::string line : lines) {
			std::istringstream s(line);
			SpheroOrientation orientation{};
			std::string temp;

			std::getline(s, temp, ',');
			orientation.time = std::stof(temp);

			std::getline(s, temp, ',');
			orientation.pitch = std::stof(temp);

			std::getline(s, temp, ',');
			orientation.roll = std::stof(temp);

			std::getline(s, temp, ',');
			orientation.yaw = std::stof(temp);

			_orientations.push_back(orientation);
		}
	} catch (...) {
		std::cout << "Error parsing orientation." << std::endl;
	}
}

// Parse Sphero location data from file
void SpheroSimulator::parse_location(const String file_path) {
	const String path = file_path + "-Location.csv";
	std::vector<std::string> lines = read_file(path);

	try {
		for (std::string line : lines) {
			std::istringstream s(line);
			SpheroLocation location{};
			std::string temp;

			std::getline(s, temp, ',');
			location.time = std::stof(temp);

			std::getline(s, temp, ',');
			location.x = std::stof(temp);

			std::getline(s, temp, ',');
			location.y = std::stof(temp);

			_locations.push_back(location);
		}
	} catch (...) {
		std::cout << "Error parsing location." << std::endl;
	}
}

// Parse Sphero gyroscope data from file
void SpheroSimulator::parse_gyroscope(const String file_path) {
	const String path = file_path + "-Gyroscope.csv";
	std::vector<std::string> lines = read_file(path);

	try {
		for (std::string line : lines) {
			std::istringstream s(line);
			SpheroGyroscope gyroscope{};
			std::string temp;

			std::getline(s, temp, ',');
			gyroscope.time = std::stof(temp);

			std::getline(s, temp, ',');
			gyroscope.pitch = std::stof(temp);

			std::getline(s, temp, ',');
			gyroscope.roll = std::stof(temp);

			std::getline(s, temp, ',');
			gyroscope.yaw = std::stof(temp);

			_gyroscopes.push_back(gyroscope);
		}
	} catch (...) {
		std::cout << "Error parsing gyroscope." << std::endl;
	}
}

// Parse Sphero distance data from file
void SpheroSimulator::parse_distance(const String file_path) {
	const String path = file_path + "-Distance.csv";
	std::vector<std::string> lines = read_file(path);

	try {
		for (std::string line : lines) {
			std::istringstream s(line);
			SpheroDistance distance{};
			std::string temp;

			std::getline(s, temp, ',');
			distance.time = std::stof(temp);

			std::getline(s, temp, ',');
			distance.x = std::stof(temp);

			std::getline(s, temp, ',');
			distance.y = std::stof(temp);

			std::getline(s, temp, ',');
			distance.total = std::stof(temp);

			_distances.push_back(distance);
		}
	} catch (...) {
		std::cout << "Error parsing distance." << std::endl;
	}
}

// Parse Sphero accelerometer data from file
void SpheroSimulator::parse_accelerometer(const String file_path) {
	const String path = file_path + "-Accelerometer.csv";
	std::vector<std::string> lines = read_file(path);

	try {
		for (std::string line : lines) {
			std::istringstream s(line);
			SpheroAccelerometer accelerometer{};
			std::string temp;

			std::getline(s, temp, ',');
			accelerometer.time = std::stof(temp);

			std::getline(s, temp, ',');
			accelerometer.x = std::stof(temp);

			std::getline(s, temp, ',');
			accelerometer.y = std::stof(temp);

			std::getline(s, temp, ',');
			accelerometer.z = std::stof(temp);

			std::getline(s, temp, ',');
			accelerometer.total = std::stof(temp);

			_accelerometers.push_back(accelerometer);
		}
	} catch (...) {
		std::cout << "Error parsing accelerometer." << std::endl;
	}
}

// Velocity getters
float SpheroSimulator::get_velocity_time(const int index) {
	return _velocities[index].time;
}

float SpheroSimulator::get_velocity_x(const int index) {
	return _velocities[index].x;
}

float SpheroSimulator::get_velocity_y(const int index) {
	return _velocities[index].y;
}

float SpheroSimulator::get_velocity_total(const int index) {
	return _velocities[index].total;
}

// Orientation getters
float SpheroSimulator::get_orientation_pitch(const int index) {
	return _orientations[index].pitch;
}

float SpheroSimulator::get_orientation_roll(const int index) {
	return _orientations[index].roll;
}

float SpheroSimulator::get_orientation_yaw(const int index) {
	return _orientations[index].yaw;
}

// Location getters
float SpheroSimulator::get_location_x(const int index) {
	return _locations[index].x;
}

float SpheroSimulator::get_location_y(const int index) {
	return _locations[index].y;
}

// Gyroscope getters
float SpheroSimulator::get_gyroscope_pitch(const int index) {
	return _gyroscopes[index].pitch;
}

float SpheroSimulator::get_gyroscope_roll(const int index) {
	return _gyroscopes[index].roll;
}

float SpheroSimulator::get_gyroscope_yaw(const int index) {
	return _gyroscopes[index].yaw;
}

// Distance
float SpheroSimulator::get_distance_x(const int index) {
	return _distances[index].x;
}

float SpheroSimulator::get_distance_y(const int index) {
	return _distances[index].y;
}

float SpheroSimulator::get_distance_total(const int index) {
	return _distances[index].total;
}

// Accelerometer
float SpheroSimulator::get_accelerometer_x(const int index) {
	return _accelerometers[index].x;
}

float SpheroSimulator::get_accelerometer_y(const int index) {
	return _accelerometers[index].y;
}

float SpheroSimulator::get_accelerometer_z(const int index) {
	return _accelerometers[index].z;
}

float SpheroSimulator::get_accelerometer_total(const int index) {
	return _accelerometers[index].total;
}

// Check size. Should be same for all vectors
int SpheroSimulator::get_velocity_size() {
	return _velocities.size();
}

// Verify that data is consistent for all vectors
bool SpheroSimulator::is_data_consistent() {
	return _velocities.size() == _orientations.size() &&
			_velocities.size() == _locations.size() &&
			_velocities.size() == _gyroscopes.size() &&
			_velocities.size() == _distances.size() &&
			_velocities.size() == _accelerometers.size();
}

// Get string containing all vector sizes
String SpheroSimulator::get_all_sizes() {
	int vel = static_cast<int>(_velocities.size());
	int ori = static_cast<int>(_orientations.size());
	int loc = static_cast<int>(_locations.size());
	int gyr = static_cast<int>(_gyroscopes.size());
	int dis = static_cast<int>(_distances.size());
	int acc = static_cast<int>(_accelerometers.size());

	std::string str =
			"Vel: " + std::to_string(vel) + ", " +
			"Ori: " + std::to_string(ori) + ", " +
			"Loc: " + std::to_string(loc) + ", " +
			"Gyr: " + std::to_string(gyr) + ", " +
			"Dis: " + std::to_string(dis) + ", " +
			"Acc: " + std::to_string(acc) + ", ";

	return String(str.c_str());
}

void SpheroSimulator::_bind_methods() {
	ClassDB::bind_method(D_METHOD("parse_file"), &SpheroSimulator::parse_file);

	ClassDB::bind_method(D_METHOD("get_velocity_time"), &SpheroSimulator::get_velocity_time);
	ClassDB::bind_method(D_METHOD("get_velocity_x"), &SpheroSimulator::get_velocity_x);
	ClassDB::bind_method(D_METHOD("get_velocity_y"), &SpheroSimulator::get_velocity_y);
	ClassDB::bind_method(D_METHOD("get_velocity_total"), &SpheroSimulator::get_velocity_total);

	ClassDB::bind_method(D_METHOD("get_orientation_pitch"), &SpheroSimulator::get_orientation_pitch);
	ClassDB::bind_method(D_METHOD("get_orientation_roll"), &SpheroSimulator::get_orientation_roll);
	ClassDB::bind_method(D_METHOD("get_orientation_yaw"), &SpheroSimulator::get_orientation_yaw);

	ClassDB::bind_method(D_METHOD("get_location_x"), &SpheroSimulator::get_location_x);
	ClassDB::bind_method(D_METHOD("get_location_y"), &SpheroSimulator::get_location_y);

	ClassDB::bind_method(D_METHOD("get_gyroscope_pitch"), &SpheroSimulator::get_gyroscope_pitch);
	ClassDB::bind_method(D_METHOD("get_gyroscope_roll"), &SpheroSimulator::get_gyroscope_roll);
	ClassDB::bind_method(D_METHOD("get_gyroscope_yaw"), &SpheroSimulator::get_gyroscope_yaw);

	ClassDB::bind_method(D_METHOD("get_distance_x"), &SpheroSimulator::get_distance_x);
	ClassDB::bind_method(D_METHOD("get_distance_y"), &SpheroSimulator::get_distance_y);
	ClassDB::bind_method(D_METHOD("get_distance_total"), &SpheroSimulator::get_distance_total);

	ClassDB::bind_method(D_METHOD("get_accelerometer_x"), &SpheroSimulator::get_accelerometer_x);
	ClassDB::bind_method(D_METHOD("get_accelerometer_y"), &SpheroSimulator::get_accelerometer_y);
	ClassDB::bind_method(D_METHOD("get_accelerometer_z"), &SpheroSimulator::get_accelerometer_z);
	ClassDB::bind_method(D_METHOD("get_accelerometer_total"), &SpheroSimulator::get_accelerometer_total);

	ClassDB::bind_method(D_METHOD("get_velocity_size"), &SpheroSimulator::get_velocity_size);
	ClassDB::bind_method(D_METHOD("is_data_consistent"), &SpheroSimulator::is_data_consistent);
	ClassDB::bind_method(D_METHOD("get_all_sizes"), &SpheroSimulator::get_all_sizes);
}
