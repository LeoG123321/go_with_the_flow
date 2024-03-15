#pragma once
#include <string>
#include <vector>
#include "Source.h"
using namespace std;
class HeatFlow
{
private:
	double K;
	vector<double> bar;
	vector<Source> sources;

public:
	HeatFlow(double, int, double, vector<Source>);
	void tick();
	string pretty_print();
};