
#include "game_sim.h"
using namespace std;
void game_sim(vector<float> Spg, vector<float> Sps, vector<float> Dsps, vector<float> Dspg, int x, int y, vector<float>teamOaw, vector<float>teamDaw, vector<float> dSpg, vector<float> dSps)//X is the first team (usually the human team), Y is the other team
{
    cout << Dsps[x] << Dsps[y] << Dspg[x] << Dspg[y] << endl;
    int otwt1 = 0;
    int otwt2 = 0;
    int t1wins =0;
    int t2wins = 0;
    const	string saveCommentary[] = {"What A save by team ", "Theyr'e coming down the wing with speed...Sprawling save by team ", "SCRAMBLE IN THE CREASE, AND THE PUCK GOES WIDE!!!", "Big glove save by team "};
    const	string goalCommentary[] = {"Here they come in a 2 on 1...GOALLLL FOR TEAM ", "A breakaway...GOALLL BY TEAM ", "SCRAMBLE FOR IT, GOALLLL FOR TEAM "};

    int edge2 = 0;
    int edge1 = 0;


    float t1Oaw = teamOaw[x];
    float t2Oaw = teamOaw[y];
    float t1Daw = teamDaw[x];
    float t2Daw = teamDaw[y];
    bool begin_game = true;
    if ([begin_game]) //Just gives the user the idea which team is better
    {
        if (t1Daw > t2Oaw)
        {
            edge1 += 1;
        }
        else
        {
            edge2 +=1;
        }
        if (t2Daw > t1Oaw)
        {
            edge2 +=1;
        }
        else
        {
            edge1 += 1;
        }
        begin_game = false;
    }
    float spgt1 = Spg[x] - 2.5 + 2.5*rand()/RAND_MAX;
    float spgt2 = Spg[y] - 2.5 + 2.5*rand()/RAND_MAX;
    float spst1 = Sps[x] - 2.0 + 2.0*rand()/RAND_MAX;
    float spst2 =Sps[y] - 2.0 + 2.0*rand()/RAND_MAX;
    if (edge1 > edge2)
    {
        cout << "Team " << x + 1 << " has the edge" << endl;
    }
    else if (edge1 < edge2)
    {
        cout << "Team " << y + 1 << " has the edge" << endl;
    }
    else
    {
        cout << "No one has the edge" << endl;
    }
    Sleep (3000);
    cout << spgt1 << "    " << spgt2 << endl;
    cout << spst1 << "    " << spst2 << endl;
    int spgInt_t1 = (int)spgt1;
    int spgInt_t2 = (int)spgt2;
    int limitt1 = rand() % (10) + spgInt_t1 - 5;
    int limitt2 = rand() % (10) + spgInt_t1 - 5;
    int t1shottake = 0;
    int t2shottake = 0;
    bool otnes = false;
    bool game_in_progress = true;
    bool pause = false;
    int limit = limitt1>limitt2?limitt1:limitt2;
    int count = 0;
    int time_left = limitt1+limitt2;
    system("cls");
    if (pause == false)
    {
        int otscore = 0;
        int goalComChoose;
        int saveComChoose;
        int t1score = 0;
        int t2score = 0;
        int t1shots = 0;
        int t2shots = 0;
        while (t1shottake < limitt1 || t2shottake < limitt2 )
        {

            if (t1shottake < limitt1)
            {

                cout << "Score:" << "\n" << "Team " << x + 1 <<": "<< t1score <<"    "<< "Team " << y +1  << ": " << t2score << endl;
                cout <<"Time Left: " << time_left << endl;
                int goalran_t1 = rand() % (100 - 0) + 0;
                if (goalran_t1 < spst1)
                {
                    goalComChoose = rand()% (2-0) + 0;
                    t1score += 1;
                    cout << goalCommentary[goalComChoose] << x + 1<< "!!!!" << endl;
                    t1shots += 1;
                    if (otnes == true)
                    {
                        otscore = 1;
                        otnes = false;
                        otwt1 += 1;
                        pause = true;
                    }
                    else
                    {
                        otnes = false;
                    }

                }
                else
                {
                    t1shots += 1;
                    saveComChoose = rand()% (2-0) + 0;
                    cout << saveCommentary[saveComChoose] << x + 1 << endl;
                    if (otnes == true)
                    {
                        limitt1 +=1;
                    }
                    else
                    {
                        otnes = false;
                    }

                }
                time_left -=1;

                Sleep (1000);
                system("cls");
                t1shottake++;

            }
            if (t2shottake < limitt2)
            {
                cout << "Score:" << "\n" << "Team " << x + 1 << ": "<< t1score <<"    "<< "Team " << y+ 1<< ": " << t2score << endl;
                cout <<"Time Left: " <<  time_left << endl;
                int goalran_t2 = rand() % (100 - 0) + 0;
                if (goalran_t2 < spst2)
                {
                    goalComChoose = rand()% (2-0) + 0;
                    t2score += 1;
                    t2shots += 1;
                    cout << goalCommentary[goalComChoose] << y + 1<< "!!!!" << endl;
                    if (otnes == true)
                    {
                        otscore = 1;
                        otnes = false;
                        otwt2 +=1;
                        pause = true;
                    }
                    else
                    {
                        otnes = false;
                    }
                }
                else
                {
                    t2shots += 1;
                    saveComChoose = rand()% (2-0) + 0;
                    cout << saveCommentary[saveComChoose] << y + 1 << endl;
                    if (otnes == true)
                    {
                        limitt2 +=1;
                    }
                    else
                    {
                        otnes = false;
                    }
                }
                time_left -=1;
                Sleep (1000);
                system("cls");
                t2shottake++;

            }
            if (otnes == true)
            {
                limit += 1;
            }
            if (t1shottake >= limitt1 && t2shottake >= limitt2)
            {
                game_in_progress = false;
            }


            if (!game_in_progress)
            {

                if (t1score > t2score)
                {
                    t1wins+=1;
                    cout << "Team "<< x+1 <<" Wins!!!!" << endl;
                    otnes = false;
                    pause = true;
                }
                else if (t1score == t2score && t1shottake == limitt1 && t2shottake == limitt2)
                {
                    cout << "OT is necessary" << endl;

                    otnes = true;
                    limitt1 +=1;
                    limitt2 +=2;

                }
                else
                {
                    t2wins+=1;
                    cout << "Team " << y + 1<< " Wins" << endl;
                    otnes = false;
                    pause = true;

                }
            }

        }
    }
    cout << "Team "<< x+1 <<" won: " << t1wins << "    " << otwt1 <<  endl;
    cout << "Team "<< y+1 <<" won: : " << t2wins <<"    " << otwt2 << endl;
    Sleep(5000);

}

