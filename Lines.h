#ifndef LINES_H_INCLUDED
#define LINES_H_INCLUDED
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <Windows.h>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <cmath>
#include "Player.h"
#include <algorithm>
#pragma once
using namespace std;
class Lines
{
    public:
        vector<Player> Tot_LW;
        vector<Player> Tot_CE;
        vector<Player> Tot_RW;
        vector<Player> Tot_DE;
        void Sort_Players_OVR(vector<Player>POS_TO_SORT);
    private:
        int Team_Ros_Lines;
        string Team_ORG;
};


#endif // LINES_H_INCLUDED
