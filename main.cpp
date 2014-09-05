#include <ctime>
#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <Windows.h>
#include <stdio.h>
#include <vector>
#include <cstdlib>
#include "Player.h"
#include "assemble_teamdata.h"
#include "game_sim.h"

using namespace std;

int main()
{

    srand(time(0));
    cout << "Is this the first time this program has run?" << endl;
    string firstTime;
    cin >> firstTime;
    if (firstTime == "Yes" || firstTime == "yes") //Performs first time setup i.e it generates players
    {
        vector<Player> plyrs;
        for (int i = 0; i < 30; i++)
        {
            int limit = 18; //rand() % (25 - 18) + 18;
            for (int w = 0; w < limit; w++)
            {
                int z = plyrs.size();
                plyrs.resize(z+1);
                plyrs[z].readPlayerData();
                plyrs[z].setPlayeName();
                plyrs[z].setPlyrVal();
                plyrs[z].setPlayerTeam(i);
            }
        }
        string human_input;
        cout << "Pick a # between 1-30, this will be your team: " << endl;
        cin >> human_input;
        int human_teamInput = 0;
        human_teamInput = atoi(human_input.c_str());
        ofstream plyrdata;
        plyrdata.open("plyr.txt");
        plyrdata << human_teamInput << endl;
        plyrdata.close();
        ofstream playerSaveData;
        playerSaveData.open ("savedata.txt");
        for (int i = 0; i<plyrs.size(); i++)
        {
            playerSaveData << plyrs[i].plName << endl;
            playerSaveData << plyrs[i].plOvr << endl;
            playerSaveData << plyrs[i].ploaw << endl;
            playerSaveData << plyrs[i].pldaw << endl;
            playerSaveData << plyrs[i].pldspg << endl;
            playerSaveData << plyrs[i].pldsps << endl;
            playerSaveData << plyrs[i].plSpg << endl;
            playerSaveData << plyrs[i].plSps << endl;
            playerSaveData << plyrs[i].plteam << (i<(plyrs.size()-1)?"\n":"");//No clue what this does
        }
        playerSaveData.close();
        assemble_Team_Data();
    }
    else if (firstTime =="No" || firstTime == "no")
    {
        assemble_Team_Data();
    }
   else
   {
       cout << "Uh Oh! Invalid response! Program Will exit" << endl;
       return 0;
   }
    return 0;
}
