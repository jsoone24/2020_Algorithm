#include <iostream>
#include <ctime>
#include <vector>
#include "solution.h"
using namespace std;

Solution s;

int main (void)
{
    unsigned long long int answer;

    vector<vector<int>> intervals {
        vector<int> {1,2},
        vector<int> {2,3},
        vector<int> {3,4},
        vector<int> {1,3},
    };
  
    /* Run your codes */
    clock_t begin = clock();    
    answer = s.removeInterval (intervals);
    clock_t end = clock();

    cout << answer << endl;
    cout << "Elapsed time: " << double (end - begin)/CLOCKS_PER_SEC << " (s)" << endl;

    return 0;
}