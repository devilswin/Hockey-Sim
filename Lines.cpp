#include "Lines.h"
using namespace std;
void Sort_Players_OVR(vector<Player>POS_TO_SORT)
{
    sort(POS_TO_SORT.end(),POS_TO_SORT.begin());
    for (int i = 0; i < POS_TO_SORT.size(); i++){cout << POS_TO_SORT[i].plNAME << ": " << POS_TO_SORT[i].plOVR << endl; sleep(500);}
}
