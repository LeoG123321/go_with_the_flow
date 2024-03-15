#include "Source.h"

Source::Source(int source_location, double source_temperature) {
	this->source_location = source_location;
	this->source_temperature = source_temperature;
}

int Source::get_source_location() {
	return source_location;
}

double Source::get_source_temperature() {
	return this->source_temperature;
}
