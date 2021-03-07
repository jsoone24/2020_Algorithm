#include <iostream>
#include <vector>
#include <set>
#include "solution.h"
using namespace std;

int Solution::removeInterval(vector<vector<int>> intervals)
{
    /* Fill up here with your codes */
    int tasknum = 0, answer = 0;
    bool doI;
    set<int> tt;

    for (vector<vector<int>>::iterator i = intervals.begin(); i != intervals.end(); i++)
    {
        if (tt.find((*i)[0]) == tt.end())
        {
            tt.insert((*i)[0]);
        }
        if (tt.find((*i)[1]) == tt.end())
        {
            tt.insert((*i)[1]);
        }
    }

    vector<vector<int>> vv(tt.size());
    for (vector<vector<int>>::iterator i = intervals.begin(); i != intervals.end(); i++)
    {
        vv[(*i)[0]].push_back((*i)[1]);
    }

    for (vector<vector<int>>::iterator i = vv.begin(); i != vv.end(); i++)
    {
        if ((*i).size() > 0)
        {
            doI = true;
            break;
        }
    }

    while (doI)
    {
        answer++;
        doI = false;
        int MAX = 9999;
        pair<int, int> MAXneighbornum = make_pair(-1, -1);
        for (int j = 0; j < tt.size(); j++)
        {
            if (vv[j].size() > MAXneighbornum.second)
            {
                MAXneighbornum.first = j;
                MAXneighbornum.second = vv[j].size();
            }
        }

        vv.erase(vv.begin() + MAXneighbornum.first);
        for (int j = 0; j < tt.size(); j++)
        {
            for (int k = 0; k < vv[j].size(); k++)
            {
                if(vv[j][k] == MAXneighbornum.first)
                    vv[j].erase(vv[j].begin()+k);
            }
        }

        for (vector<vector<int>>::iterator i = vv.begin(); i != vv.end(); i++)
        {
            if ((*i).size() > 0)
            {
                doI = true;
                break;
            }
        }
    }
    
    return answer;
}
