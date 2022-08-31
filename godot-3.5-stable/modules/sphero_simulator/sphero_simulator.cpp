#include "sphero_simulator.h"

#include <fstream>
#include <iostream>
#include <string>

SpheroSimulator::SpheroSimulator() {
	// Nothing here for now
}

Array SpheroSimulator::read_input(String file_path) {
	Array data;
	std::string line;
	std::ifstream ifs;
	ifs.open(file_path.c_str(), std::ios::in);

	if (!ifs)
		// Return if we cant open file
		// Maybe add some exception or something
		return data;

	while (!ifs.eof()) {
		std::getline(ifs, line);
		data.append(line.c_str());
	}

	ifs.close();

	return data;
}

void SpheroSimulator::_bind_methods() {
	ClassDB::bind_method(D_METHOD("read_input"), &SpheroSimulator::read_input);
}
