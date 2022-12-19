shader_type spatial;

uniform sampler2D my_texture;
varying vec2 tex_position;
varying vec2 position;
const float area = 100.0;
uniform vec3 color;
uniform float x_offset = -31.01;
uniform float y_offset = 0.0;

const float x_max = 90.56;
const float x_min = -23.43;
const float y_max = 62.37;
const float y_min = -66.22;

const float x_area = x_max - x_min;
const float y_area = y_max - y_min;


vec2 get_tex_pos(vec2 pos) {
	// set tex_position
	// float x = ((pos.x / x_area) / 2.0) + 0.5;
	// float y = ((pos.y / y_area) / 2.0) + 0.5;
	//float x = (pos.x - x_min - x_offset) / (x_area - x_offset);
	//float y = (pos.y - y_min + y_offset) / y_area;
	float x = (pos.x - x_min) / x_area;
	float y = (pos.y - y_min) / y_area;
	return vec2(x, y);
}

bool is_valid_area() {
	// return position.x + x_offset < x_area && position.x > -x_area && position.y > -y_area && position.y < y_area;
	return position.x < x_max && position.x > x_min && position.y < y_max && position.y > y_min;
}

void vertex() {
	// Manipulate vertices
	position = VERTEX.xz + vec2(x_offset, y_offset);
	tex_position = get_tex_pos(position);
}

void fragment() {
	// Set individual pixels between vertices
	if(is_valid_area())
		//ALBEDO = vec3(1.0, 0.0, 0.812);
		ALBEDO = texture(my_texture, tex_position).rgb;
	else
		//ALBEDO = vec3(0.0, 0.812, 0.812);
		ALBEDO = color;
}