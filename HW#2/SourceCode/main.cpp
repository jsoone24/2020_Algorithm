#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include "solution.h"
using namespace std;

Solution s;

/* The following main function is for your convinience. 
 * Evaluation will be conducted through our own evaluation system, not this file.
 * You are free to utilize/edit source codes of "main.cpp".
 * But, DO NOT include the "main.cpp" file into your homework submission.
 */ 

int main (void)
{
    vector<vector<int>> points, results;
    vector<int> keypoint (2), temp(2);
    int K, numPoints;
    Solution s;
    
    /* Initialize */
    ifstream ifs ("sample4.txt");
    if (ifs.is_open())
    {
        ifs >> keypoint[0] >> keypoint[1] >> K >> numPoints;
        for (int i=0; i<numPoints; i++)
        {
            ifs >> temp[0] >> temp[1];
            points.push_back(temp);
        }
    }

    /* Run your codes */
    clock_t begin = clock();    
    results = s.kClosest (points, keypoint, K);
    clock_t end = clock();
    
    /* Print output */
    for (const auto& p: results)
    {
        cout << p[0] << " " << p[1] << endl;
    }
    cout << "Elapsed time: " << double (end - begin)/CLOCKS_PER_SEC << " (s)" << endl;

    return 0;
}