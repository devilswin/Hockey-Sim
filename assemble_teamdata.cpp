#include "assemble_teamdata.h"
using namespace std;
void assemble_Team_Data()//reads player data from a file and assembles averages for the teams
{
    string line;


    vector<float> spsStats; //Holds all of the Shooting percentage stats
    vector<float> spgStats; //Holds all of the Shots per game stats
    vector<float> dspsStats; //All of the defensive shooting percentage against stats
    vector<float> dspgStats;//All of the defensive shots per game
    vector <float>teamSpsavg;// Avg of each teams SPS, 30 Slots
    vector <float>teamSpgavg;//Avg of each teams SPG, 30 slots
    vector <float>teamDspsavg;// Avg of each teams defensive SPS, 30 Slots
    vector <float>teamDspgavg;//Avg of each teams defensive SPG, 30 slots
    vector <float> NUMBER_PLY_TEAM; //Numbers of players on each team, will be used more once injuries are implemented
    vector<Player> teamPlyr; //vector of the class players that stores all of this data
    vector<int> teamDaw; //DAW
    vector<int> teamOaw; // same as above but for offense
    vector<float> teamDawavg;
    vector<float> teamOawavg;
    vector<Lines> Team_Lines;
    vector<vector<string> > roster_team(30, vector<string>(0, ""));
    ifstream player_data("plyr.txt");
    int human_team = 0;
    getline(player_data,line);
    human_team = atoi(line.c_str()) - 1;
    player_data.close();
    ifstream save_data ("savedata.txt");
    int numPlayers = 0;
    int line_int1 = 0, line_int2 = 0, line_int3 = 0, line_int4 = 0; //Honestly i have no idea what either this or line 36 does
    float line_float1, line_float2, line_float3, line_float4;
    if (save_data.is_open())
    {
        while (!save_data.eof()) //Checks to see if the file is done, if it isnt it will read the data and convert it into the correct data type
        {
            int z = teamPlyr.size();
            teamPlyr.resize(z+1);
            spgStats.resize(teamPlyr.size());
            spsStats.resize(teamPlyr.size());
            dspgStats.resize(teamPlyr.size());
            dspsStats.resize(teamPlyr.size());
            teamOaw.resize(teamPlyr.size());
            teamDaw.resize(teamPlyr.size());
            Team_Lines.resize(30);
            NUMBER_PLY_TEAM.resize(30);
            getline(save_data,line);
            teamPlyr[numPlayers].plName = line;
            getline(save_data,line);
            teamPlyr[numPlayers].plPOS = line;
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
            NUMBER_PLY_TEAM[teamPlyr[numPlayers].plteam] += 1;
            if (teamPlyr[numPlayers].plPOS == "LW") //Places the players into diffrent vecs based on what POS they are
            {
                Team_Lines[teamPlyr[numPlayers].plteam].Tot_LW.resize(NUMBER_PLY_TEAM[teamPlyr[numPlayers].plteam]);
                Team_Lines[teamPlyr[numPlayers].plteam].Tot_LW[NUMBER_PLY_TEAM[teamPlyr[numPlayers].plteam]] = teamPlyr[numPlayers];
            }
            if (teamPlyr[numPlayers].plPOS == "C")
            {
                Team_Lines[teamPlyr[numPlayers].plteam].Tot_CE.resize(NUMBER_PLY_TEAM[teamPlyr[numPlayers].plteam]);
                Team_Lines[teamPlyr[numPlayers].plteam].Tot_CE[NUMBER_PLY_TEAM[teamPlyr[numPlayers].plteam]] = teamPlyr[numPlayers];
            }
            if (teamPlyr[numPlayers].plPOS == "RW")
            {
                Team_Lines[teamPlyr[teamPlyr[numPlayers].plteam].plteam].Tot_RW.resize(NUMBER_PLY_TEAM[teamPlyr[numPlayers].plteam]);
                Team_Lines[teamPlyr[teamPlyr[numPlayers].plteam].plteam].Tot_RW[NUMBER_PLY_TEAM[teamPlyr[numPlayers].plteam]] = teamPlyr[numPlayers];
            }
            else
            {
                Team_Lines[teamPlyr[numPlayers].plteam].Tot_DE.resize(NUMBER_PLY_TEAM[teamPlyr[numPlayers].plteam]);
                Team_Lines[teamPlyr[numPlayers].plteam].Tot_DE[NUMBER_PLY_TEAM[teamPlyr[numPlayers].plteam]] = teamPlyr[numPlayers];
            }
            dspsStats[teamPlyr[numPlayers].plteam] += teamPlyr[numPlayers].pldsps;
            dspgStats[teamPlyr[numPlayers].plteam] += teamPlyr[numPlayers].pldspg;
            spsStats[teamPlyr[numPlayers].plteam] += teamPlyr[numPlayers].plSps;
            spgStats[teamPlyr[numPlayers].plteam] += teamPlyr[numPlayers].plSpg;
            teamOaw[teamPlyr[numPlayers].plteam] += teamPlyr[numPlayers].ploaw;
            teamDaw[teamPlyr[numPlayers].plteam] += teamPlyr[numPlayers].pldaw;
            numPlayers += 1;

        }
        save_data.close();
    }

    else cout << "Unable to open file" << endl;
    teamSpgavg.resize(30);
    teamSpsavg.resize(30);
    teamDspgavg.resize(30);
    teamDspsavg.resize(30);
    teamOawavg.resize(30);
    teamDawavg.resize(30);
    vector<int> LWS;
    vector<int> CES;
    vector<int> RWS;
    vector<int> DES;

    for (int i = 0; i < 30; i++)//This sorts the players Overalls by greatest to least so that it could eventually sort the players into lines
    {
                   //The error that occurs here is that the func() Sort_Players_OVR, no clue why
            Team_Lines[i].Sort_Players_OVR(Team_Lines, i);
    }
    for (int i = 0; i < 30;) //Gathers all of the averages for each stat type for each team
    {
        teamSpsavg[i] = spsStats[i] / NUMBER_PLY_TEAM[i];
        teamSpgavg[i] = spgStats[i] / NUMBER_PLY_TEAM[i];
        teamDspsavg[i] = dspsStats[i] / NUMBER_PLY_TEAM[i];
        teamDspgavg[i] = dspgStats[i] / NUMBER_PLY_TEAM[i];
        teamOawavg[i] = teamOaw[i] / NUMBER_PLY_TEAM[i];
        teamDawavg[i] = teamDaw[i] / NUMBER_PLY_TEAM[i];
        i++;
    }
    string ui;
    cout << "Please enter # for team 2: " << endl;
    cin >> ui;
    int team2num = atoi(ui.c_str()) - 1;
    view_roster(teamPlyr,human_team);
    game_sim(spgStats,teamSpsavg,teamDspsavg,teamDspgavg, human_team,team2num, teamOawavg,teamDawavg,dspgStats,dspsStats); //Getting error here, says cannot convert ftom vector<float> to int?
}
