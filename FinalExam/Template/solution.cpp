#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include "solution.h"
using namespace std;

int Solution::removeInterval(vector<vector<int>> intervals)
{
    int size = intervals.size(), rem = 0; 
  
    if (size <= 1) 
        return 0; 
  
    // Sort by minimum starting point 
    sort(intervals.begin(), intervals.end(),  
        [](const vector<int>& a, const vector<int>& b)  
                    { return a[0] < b[0]; }); 
  
    int end = intervals[0][1]; 
    for (int i = 1; i < intervals.size(); i++) { 
  
        // If the current starting point is less than 
        // the previous interval's ending point  
        // (ie. there is an overlap) 
        if (intervals[i][0] < end) { 
            // increase rem 
            rem++; 
            // Remove the interval 
            // with the higher ending point 
            end = min(intervals[i][1], end); 
        } 
        else
            end = intervals[i][1]; 
    } 
  
    return rem; 
}
