#include "HeatFlow.h"

HeatFlow::HeatFlow(double initial_temperature, int number_of_sections, double K, double source_temperature, int source_location) {
	this->K = K;
	this->source_location = source_location;

}

void HeatFlow::tick() {

}

void HeatFlow::pretty_print() {

}