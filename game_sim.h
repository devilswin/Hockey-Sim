#ifndef GAME_SIM_H_INCLUDED
#define GAME_SIM_H_INCLUDED
#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <unistd.h>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#pragma once
using namespace std;
void game_sim(vector<float> Spg, vector<float> Sps, vector<float> Dsps, vector<float> Dspg, int x, int y, vector<float>teamOaw, vector<float>teamDaw, vector<float> dSpg, vector<float> dSps);


#endif // GAME_SIM_H_INCLUDED
