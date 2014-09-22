#include "Player.h"
void Player::readPlayerData()//will read from a file of first and last names
{
    string line;
    ifstream fnameFile("/Users/gabeorlanski/Desktop/Plse save battery/C++/Hockey-Sim/PlayersFname.txt");
    if (fnameFile.is_open())
    {
        while (getline(fnameFile,line))
            plFname.push_back(line);
        fnameFile.close();
    }
    ifstream lnameFile("/Users/gabeorlanski/Desktop/Plse save battery/C++/Hockey-Sim/PlayersLname.txt");
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
    uniform_int_distribution<int> lname_rand(0, plLname.size());
    int fname = fname_rand(rand_engine);
    int lname = lname_rand(rand_engine);
    test1 = plFname[fname];
    test2 = plLname[lname];
    
}
void Player::setPlayerTeam(int team) //Gives the player a numerical value for what team he is on
{
    plteam = team;
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
void Player::setPlyrPOS(int TYPE_OF_PLAYER)
{
    if (TYPE_OF_PLAYER == 0)
    {
        plPOS = "D";
    }
    else
    {
        int F_POS_DESIGN = rand()% 3;
        if (F_POS_DESIGN == 0)
        {
            plPOS = "LW";
        }
        else if (F_POS_DESIGN == 1)
        {
            plPOS = "RW";
        }
        else
        {
            plPOS = "C";
        }
    }


}

