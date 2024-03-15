#pragma once
#include <vector>
using namespace std;
class HeatFlow
{
private:
	double K;
	int source_location;
	vector<double> sections;

public:
	HeatFlow(double, int, double, double, int);
	void tick();
	void pretty_print();
};

