#include "FirstTime.h"
using namespace std;
void FIRSTTIME_LAUNCHED()
{
    cout << "Is this the first time this program has run?" << endl;
    string FIRST_LAUNCH;
    cin >> FIRST_LAUNCH;
    if (FIRST_LAUNCH == "Yes" || FIRST_LAUNCH == "yes") //Performs first time setup i.e it generates players
    {
        vector<Player> plyrs;
        for (int q = 0; q < 30; q++)
        {
            int limit = 18; //rand() % (25 - 18) + 18;


            for (int w = 0; w < limit; w++)
            {

                int z = plyrs.size();
                plyrs.resize(z+1);
                plyrs[z].readPlayerData();

                plyrs[z].setPlayeName();

                plyrs[z].setPlyrVal();

                if (w <= 6)
                {
                    plyrs[z].setPlyrPOS(0);   //1 = Forwards 0 = Defense
                }
                if (w > 6)
                {
                    plyrs[z].setPlyrPOS(1);
                }
                plyrs[z].setPlayerTeam(q);


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
            cout << "yes?" << endl;
            playerSaveData << plyrs[i].plName << endl;
            playerSaveData << plyrs[i].plPOS<< endl;
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
    else if (FIRST_LAUNCH =="No" || FIRST_LAUNCH == "no")
    {
        assemble_Team_Data();
    }
    else
    {
        cout << "Uh Oh! Invalid response!" << endl;
        FIRST_LAUNCH = "";
        FIRSTTIME_LAUNCHED();
    }
}

