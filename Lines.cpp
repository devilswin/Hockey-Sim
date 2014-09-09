#include "Lines.h"
using namespace std;
void Sort_Players_OVR(vector<Player>POS_TO_SORT)
{

    sort(POS_TO_SORT.plOvr.end,POS_TO_SORT.plOvr.begin());
    cout << "Working" << endl;
    //for (int i = 0; i < POS_TO_SORT.size(); i++){cout << POS_TO_SORT[i].plName << ": " << POS_TO_SORT[i].plOvr << endl; Sleep(500);}
}
/*Lines::Lines(int Team_Num_Val)
{
    Team_Ros_Lines = Team_Num_Val;
}*/
