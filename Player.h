#ifndef PLAYER_H
#define PLAYER_H
#pragma once
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <unistd.h>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

class Player
{
public:
    void readPlayerData();
    void setPlayeName();
    void setPlayerTeam(const int& team);

    void setPlyrVal();
    void setPlyrPOS(int TYPE_OF_PLAYER);
public:
    int plOvr;//Stats will only change when the potential system is implemented
    int plteam;
    string plName;
    int pldaw, ploaw;
    float plSpg, plSps, pldsps, pldspg;
    string plPOS;
private:
    int numFnames;
    int numLnames;
    vector<string> plFname, plLname;

};


#endif // PLAYER_H
