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
using namespace std;
class Lines
{
    public:
        vector<Player> Tot_LW;//Vec of all of the LWs on one team
        vector<Player> Tot_CE;
        vector<Player> Tot_RW;
        vector<Player> Tot_DE;
        vector<int> LW_OVR;
        vector<int> CE_OVR;
        vector<int> RW_OVR;
        vector<int> DE_OVR;
        void Sort_Players_OVR(vector<Player>POS_TO_SORT,vector<int> Plyr_OVR);//Sorts players
        //Lines(int);
        //void init_Line_Vec(vector<Player>);
    private:
        int Team_Ros_Lines;
        string Team_ORG;
};


#endif // LINES_H_INCLUDED
