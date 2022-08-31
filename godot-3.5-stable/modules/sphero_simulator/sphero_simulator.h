#pragma once

#include "core/reference.h"

class SpheroSimulator : public Reference {
	GDCLASS(SpheroSimulator, Reference);

	// Data members

protected:
	static void _bind_methods();

public:
	SpheroSimulator();

	Array read_input(String file_path);
};
