#include "HeatFlow.h"
#include <iostream>

HeatFlow::HeatFlow(double initial_temperature, int number_of_sections, double K, vector<Source> sources) {
	this->K = K;
	this->sources = sources;

	for (int i = 0; i < number_of_sections; i++) {	//creates the bar and its starting temperature
		bar.push_back(initial_temperature);
	}

	for (int i = 0; i < sources.size(); i++) {	//Sets the sources at the locations and sets the temperatures
		bar[sources[i].get_source_location()] = sources[i].get_source_temperature();
	}
}

void HeatFlow::tick() {
	vector<double> ghost_bar = bar;
	bool source_flag = false;

	for (int i = 0; i < bar.size(); i++) {
		for (int j = 0; j < sources.size(); j++) {	//checks if the current position of the bar, i , is a source, sets flag to true.
			if (i == sources[j].get_source_location()){
				source_flag = true;
				j = sources.size();
			}
		}
		if (!source_flag) {
			if (i == 0) {
				bar[i] = ghost_bar[i] + K * (ghost_bar[i + 1] - 2 * ghost_bar[i] + ghost_bar[i]);
			}
			else if (i == bar.size() - 1) {
				bar[i] = ghost_bar[i] + K * (ghost_bar[i] - 2 * ghost_bar[i] + ghost_bar[i - 1]);
			}
			else {
				bar[i] = ghost_bar[i] + K * (ghost_bar[i + 1] - 2 * ghost_bar[i] + ghost_bar[i - 1]);
			}
		}
		source_flag = false;
	}
}

string HeatFlow::pretty_print() {
	string place_holder;
	for (int i = 0; i < bar.size(); i++) {
		place_holder += "[ ";
		place_holder += to_string(bar[i]);
		place_holder += " ]";
	}
	return place_holder;
}