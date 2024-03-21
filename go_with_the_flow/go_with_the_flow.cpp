/*
    Leonardo Gonzalez   3/14/2024
    
    Week 9              Go With the Flow
*/

#include <iostream>
#include "HeatFlow.h"

using namespace std;

int main()
{
    vector<Source> source_list;
    Source source1(0, 100);
    source_list.push_back(source1);
    string input = "";
    HeatFlow metal_bar (10.0, 8, 1.0, source_list);

    while (input != "n") {
        try_again:
        cout << "Type 'y' to tick time foward"
            << endl
            << "Type 'n' to end program"
            << endl;

        cin >> input;

        if (input == "y") {
            metal_bar.tick();
            metal_bar.pretty_print();
        }
        else if (input != "n") {
            cout << "Error: Wrong Input" << endl << endl;
            goto try_again;
        }
    }
}

