#include <iostream>
#include "max.hpp"
using namespace std;

void MaxFinder::input()
{
    cout << "Input:";
    cin >> a;
    cout << "Input:";
    cin >> b;
}

void MaxFinder::findMax()
{
    if (a > b)
        max = a;
    else
        max = b;
}

void MaxFinder::print()
{
    cout << "Max:" << max << endl;
}