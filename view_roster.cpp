#include "view_roster.h"
using namespace std;
void view_roster(const vector<vector<string> > &roster_team, const vector<Player> &teamPlyr, int human_team) //Allows the player to view his roster. Will make it so they can edit lines
{
    int yn = 0;
    cout << "Would you like to view your roster? (Answer with 1 or 2) " << endl;
    cin >> yn;
    if (yn == 1)
    {
        for (int i = 0; i<18; i++)
        {
            cout << roster_team[human_team][i] << " Overall: " << teamPlyr[i].plOvr << " Defense: " << teamPlyr[i].pldaw << " Offense: " << teamPlyr[i].ploaw << endl;
            Sleep(1000);

        }
        Sleep(10000);
    }
}
