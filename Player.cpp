#include "Player.h"
void Player::readPlayerData()//will read from a file of first and last names
    {
        string line;
        ifstream fnameFile("PlayersFname.txt");
        if (fnameFile.is_open())
        {
            while (getline(fnameFile,line))
            plFname.push_back(line);
            fnameFile.close();
        }
        ifstream lnameFile("PlayersLname.txt");
        if (lnameFile.is_open())
        {
           while (getline(lnameFile,line))
            plLname.push_back(line);
            lnameFile.close();
        }

    }
void Player::setPlayeName(mt19937& rand_engine) //Will pick two options for a first and last name
    {
        //readPlayerData();
        uniform_int_distribution<int> fname_rand(0, plFname.size());

        string fname = plFname[fname_rand(rand_engine)];
        uniform_int_distribution<int> lname_rand(0, plLname.size());

        string lname = plLname[lname_rand(rand_engine)];
        plName = string(fname + " " + lname);

    }
void Player::setPlayerTeam(const int& team) //Gives the player a numerical value for what team he is on
    {
        plteam = team;
    }
void Player::organize_Players(string z,int a,float b,float c,int d)
    {
        plName = z, plOvr = a, plSpg = b, plSps = c, plteam = d;
    }
void Player::setPlyrVal() //all of the algorithms to determine the stats
    {
        pldaw = rand()% (99-70) + 70;
        ploaw = rand()% (99-70) + 70;
        plOvr = (pldaw + ploaw) / 2;
        plSps = ploaw / 10.0f;
        pldsps = (pldaw / 10.0f)/5;
        plSpg = (plSps / 2) / 2.25;
        pldspg = (pldsps / 2) / 2.25;
    }
