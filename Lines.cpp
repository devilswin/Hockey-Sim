#include "Lines.h"
using namespace std;
struct foo_b_sorter {

    bool operator()(const Player& plOvr1, const Player & plOvr2)
    {
    	if(plOvr1.plOvr == plOvr2.plOvr)
    		return plOvr1.plOvr < plOvr2.plOvr;
    	else
	        return plOvr1.plOvr < plOvr2.plOvr;
    }
};
void Lines::Sort_Players_OVR(vector<Lines> Team_Lines)
{



   // POS_TO_SORT.resize(30);
    for (int q = 0; q < 30; q++) {
    sort(Team_Lines[q].Tot_LW.end(),Team_Lines[q].Tot_LW.begin(),foo_b_sorter());
    sort(Team_Lines[q].Tot_CE.end(),Team_Lines[q].Tot_CE.begin(),foo_b_sorter());
    sort(Team_Lines[q].Tot_RW.end(),Team_Lines[q].Tot_RW.begin(),foo_b_sorter());
    sort(Team_Lines[q].Tot_DE.end(),Team_Lines[q].Tot_DE.begin(),foo_b_sorter());
    }
    //for (int i = 0; i < POS_TO_SORT.size(); i++){cout << POS_TO_SORT[i].plName << ": " << POS_TO_SORT[i].plOvr << endl; Sleep(500);}
}
/*Lines::Lines(int Team_Num_Val)
{
    Team_Ros_Lines = Team_Num_Val;
}*/
