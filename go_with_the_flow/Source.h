#pragma once
class Source
{
private:
	int source_location;
	double source_temperature;
public:
	Source(int, double);
	int get_source_location();
	double get_source_temperature();
};

