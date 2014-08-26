#include "assemble_teamdata.h"
using namespace std;
void assemble_Team_Data()
{
    string line;
    int line_int1 = 0, line_int2 = 0, line_int3 = 0, line_int4 = 0;
    float line_float1, line_float2, line_float3, line_float4;
    int numPlayers = 0;
    vector<float> spsStats;
    vector<float> spgStats;
    vector<float> dspsStats;
    vector<float> dspgStats;
    vector <float>teamSpsavg;
    vector <float>teamSpgavg;
    vector <int> nums;
    vector<Player> teamPlyr;
    vector<int> teamDaw;
    vector<int> teamOaw;
    vector<float> teamDawavg;
    vector<float> teamOawavg;
    vector<vector<string> > roster_team(30, vector<string>(0, ""));
    ifstream player_data("plyr.txt");
    int human_team = 0;
    getline(player_data,line);
    human_team = atoi(line.c_str()) - 1;
    player_data.close();
    ifstream save_data ("savedata.txt");

    if (save_data.is_open())
    {
        while (save_data.eof() == false)
        {

            int z = teamPlyr.size();
            teamPlyr.resize(z+1);
            spgStats.resize(teamPlyr.size());
            spsStats.resize(teamPlyr.size());
            dspgStats.resize(teamPlyr.size());
            dspsStats.resize(teamPlyr.size());
            teamSpgavg.resize(teamPlyr.size());
            teamSpsavg.resize(teamPlyr.size());
            teamOawavg.resize(teamPlyr.size());
            teamDawavg.resize(teamPlyr.size());
            teamOaw.resize(teamPlyr.size());
            teamDaw.resize(teamPlyr.size());
            nums.resize(teamPlyr.size());

            getline(save_data,line);
            teamPlyr[numPlayers].plName = line;

            getline(save_data,line);
            line_int1 = atoi(line.c_str());
            teamPlyr[numPlayers].plOvr = line_int1;
            getline(save_data,line);
            line_int3 = atoi(line.c_str());
            teamPlyr[numPlayers].ploaw = line_int3;
            getline(save_data,line);
            line_int4 = atoi(line.c_str());
            teamPlyr[numPlayers].pldaw = line_int4;

            getline(save_data,line);
            line_float1 = atof(line.c_str());
            teamPlyr[numPlayers].pldspg = line_float1;
            getline(save_data,line);
            line_float2 = atof(line.c_str());
            teamPlyr[numPlayers].pldsps = line_float2;
            getline(save_data,line);
            line_float3 = atof(line.c_str());
            teamPlyr[numPlayers].plSpg = line_float3;
            getline(save_data,line);
            line_float4 = atof(line.c_str());
            teamPlyr[numPlayers].plSps = line_float4;
            getline(save_data,line);
            line_int2 = atoi(line.c_str());
            teamPlyr[numPlayers].plteam = line_int2;

            nums[teamPlyr[numPlayers].plteam] ++;
            dspsStats[teamPlyr[numPlayers].plteam] += teamPlyr[numPlayers].pldsps;
            dspgStats[teamPlyr[numPlayers].plteam] += teamPlyr[numPlayers].pldspg;
            spsStats[teamPlyr[numPlayers].plteam] += teamPlyr[numPlayers].plSps;
            spgStats[teamPlyr[numPlayers].plteam] += teamPlyr[numPlayers].plSpg;
            teamOaw[teamPlyr[numPlayers].plteam] += teamPlyr[numPlayers].ploaw;
            teamDaw[teamPlyr[numPlayers].plteam] += teamPlyr[numPlayers].pldaw;
            int s = roster_team[teamPlyr[numPlayers].plteam].size();
            roster_team[teamPlyr[numPlayers].plteam].resize(s+1);
            roster_team[teamPlyr[numPlayers].plteam][s] = teamPlyr[numPlayers].plName;
            numPlayers += 1;

        }
        save_data.close();
    }

    else cout << "Unable to open file";
    for (int i = 0; i < 30;)
    {
        teamSpsavg[i] = spsStats[i] / nums[i];
        teamOawavg[i] = teamOaw[i] / nums[i];
        teamDawavg[i] = teamDaw[i] / nums[i];
        i++;
    }
    string ui;
    cout << "Please enter # for team 2: " << endl;
    cin >> ui;
    int team2num = atoi(ui.c_str()) - 1;
    view_roster(roster_team,teamPlyr,human_team);
    game_sim(spgStats,teamSpsavg,human_team,team2num, teamOawavg,teamDawavg,dspgStats,dspsStats);


}
