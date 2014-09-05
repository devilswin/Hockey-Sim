#include "view_roster.h"
using namespace std;
void view_roster(vector<Player> my_team_plyr, int human_team) //Allows the player to view his roster. Will make it so they can edit lines
{
    int yn = 0;
    cout << "Would you like to view your roster? (Answer with 1 or 2) " << endl;
    cin >> yn;
    if (yn == 1)
    {
        for (int i = 0; i < 18; i++)
        {
            string plyr_name = my_team_plyr[i].plName;
            int plyr_ovr = my_team_plyr[i].plOvr;
            int plyr_def = my_team_plyr[i].pldaw;
            int plyr_off = my_team_plyr[i].ploaw;
            cout << plyr_name << " "<< "Overall: " << plyr_ovr << " Defense: " << plyr_def << " Offense: " << plyr_off << endl;
            Sleep(1000);

        }
        Sleep(10000);
    }
}
