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
    ifstream player_data("/Users/gabeorlanski/Desktop/Plse save battery/C++/Hockey-Sim/plyr.txt");
    int human_team = 0;
    getline(player_data,line);
    human_team = atoi(line.c_str()) - 1;
    player_data.close();
    ifstream save_data ("/Users/gabeorlanski/Desktop/Plse save battery/C++/Hockey-Sim/savedata.txt");
    int line_int1 = 0, line_int2 = 0, line_int3 = 0, line_int4 = 0; //Honestly i have no idea what either this or line 36 does
    float line_float1, line_float2, line_float3, line_float4;
    int z = 1;
    teamPlyr.resize(z);
    Team_Lines.resize(30);
    spgStats.resize(30);
    spsStats.resize(30);
    dspgStats.resize(30);
    dspsStats.resize(30);
    teamOaw.resize(30);
    teamDaw.resize(30);
    if (save_data.is_open())
    {
        while (!save_data.eof()) //Checks to see if the file is done, if it isnt it will read the data and convert it into the correct data type
        {
            
            
          
            Player Assemble_Player;
            NUMBER_PLY_TEAM.resize(30);
            getline(save_data,line);
            Assemble_Player.plName = line;
            getline(save_data,line);
            Assemble_Player.plPOS = line;
            getline(save_data,line);
            line_int1 = atoi(line.c_str());
            Assemble_Player.plOvr = line_int1;
            getline(save_data,line);
            line_int3 = atoi(line.c_str());
            Assemble_Player.ploaw = line_int3;
            getline(save_data,line);
            line_int4 = atoi(line.c_str());
            Assemble_Player.pldaw = line_int4;
            getline(save_data,line);
            line_float1 = atof(line.c_str());
            Assemble_Player.pldspg = line_float1;
            getline(save_data,line);
            line_float2 = atof(line.c_str());
            Assemble_Player.pldsps = line_float2;
            getline(save_data,line);
            line_float3 = atof(line.c_str());
            Assemble_Player.plSpg = line_float3;
            getline(save_data,line);
            line_float4 = atof(line.c_str());
            Assemble_Player.plSps = line_float4;
            getline(save_data,line);
            line_int2 = atoi(line.c_str());
            Assemble_Player.plteam = line_int2;
            NUMBER_PLY_TEAM[Assemble_Player.plteam] += 1;
            
            if (Assemble_Player.plPOS == "LW") //Places the players into diffrent vecs based on what POS they are
            {
                Team_Lines[Assemble_Player.plteam].Tot_LW.push_back(Assemble_Player);
            }
            if (Assemble_Player.plPOS == "C")
            {
                Team_Lines[Assemble_Player.plteam].Tot_CE.push_back(Assemble_Player);
               
            }
            if (Assemble_Player.plPOS == "RW")
            {
                Team_Lines[Assemble_Player.plteam].Tot_RW.push_back(Assemble_Player);
                
            }
            else
            {
                Team_Lines[Assemble_Player.plteam].Tot_DE.push_back(Assemble_Player);
               

            }
            
            
            dspsStats[Assemble_Player.plteam] += Assemble_Player.pldsps;
            dspgStats[Assemble_Player.plteam] += Assemble_Player.pldspg;
            spsStats[Assemble_Player.plteam] += Assemble_Player.plSps;
            spgStats[Assemble_Player.plteam] += Assemble_Player.plSpg;
            teamOaw[Assemble_Player.plteam] += Assemble_Player.ploaw;
            teamDaw[Assemble_Player.plteam] += Assemble_Player.pldaw;
            teamPlyr.push_back(Assemble_Player);

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
            Team_Lines[i].Sort_Players_OVR(Team_Lines);
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
