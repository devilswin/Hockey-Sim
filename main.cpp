#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <unistd.h>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include "Player.h"
#include "assemble_teamdata.h"
#include "game_sim.h"
#include "FirstTime.h"

using namespace std;

int main()
{

    srand(time(NULL));

    FIRSTTIME_LAUNCHED();

    return 0;
}
