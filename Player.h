#ifndef PLAYER_H
#define PLAYER_H
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <Windows.h>
#include <stdio.h>
#include <vector>
#include <cstdlib>
using namespace std;

class Player
{
public:
    void readPlayerData();
    void setPlayeName(mt19937& rand_engine);
    void setPlayerTeam(const int& team);
    void organize_Players(string z,int a,float b,float c,int d);
    void setPlyrVal();
public:
    int numFnames;
    int numLnames;
    int plteam, pldaw, ploaw;
    int plOvr;
    float plSpg, plSps, pldsps, pldspg;
    string werk;
    string plName;
    vector<string> plFname, plLname;

};


#endif // PLAYER_H
