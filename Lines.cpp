#include "Lines.h"
using namespace std;
void Sort_Players_OVR(vector<Player>POS_TO_SORT, vector<int> Plyr_OVR)
{
    Plyr_OVR.resize(POS_TO_SORT.size());
    for (int i = 0; i < Plyr_OVR.size(); i++){Plyr_OVR[i] = POS_TO_SORT[i].plOvr;}
    sort(Plyr_OVR.end(),Plyr_OVR.begin());
    cout << "Working" << endl;
    //for (int i = 0; i < POS_TO_SORT.size(); i++){cout << POS_TO_SORT[i].plName << ": " << POS_TO_SORT[i].plOvr << endl; Sleep(500);}
}
/*Lines::Lines(int Team_Num_Val)
{
    Team_Ros_Lines = Team_Num_Val;
}*/
