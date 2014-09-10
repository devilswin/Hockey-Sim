#include "Lines.h"
using namespace std;
void Lines::Sort_Players_OVR(vector<Lines> POS_TO_SORT)
{
    
    
    POS_TO_SORT.resize(30);
    for (int i = 0; i < 30; i++) {
    sort(POS_TO_SORT[i].Tot_LW.plOvr.end(),POS_TO_SORT[i].Tot_LW.begin());
    sort(POS_TO_SORT[i].Tot_CE.plOvr.end(),POS_TO_SORT[i].Tot_CE.begin());
    sort(POS_TO_SORT[i].Tot_RW.plOvr.end(),POS_TO_SORT[i].Tot_RW.begin());
    sort(POS_TO_SORT[i].Tot_DE.plOvr.end(),POS_TO_SORT[i].Tot_DE.begin());
    }
    cout << "Working" << endl;
    //for (int i = 0; i < POS_TO_SORT.size(); i++){cout << POS_TO_SORT[i].plName << ": " << POS_TO_SORT[i].plOvr << endl; Sleep(500);}
}
/*Lines::Lines(int Team_Num_Val)
{
    Team_Ros_Lines = Team_Num_Val;
}*/
