#include "solution.h"

/* Put your codes */
vector<vector<int>> Solution::kClosest(vector<vector<int>> &points, vector<int> keypoint, int K)
{
    //벡터
    /*vector<pair<float, int>> v;

    for (int i = 0; i < points.size(); i++)
        v.push_back(pair<float, int>(sqrt(pow(points[i][0] - keypoint[0], 2) + pow(points[i][1] - keypoint[1], 2)), i));
    nth_element(v.begin(), v.begin() + K - 1, v.end());  
    vector<vector<int>> result = {points[v[K - 1].second]};
    
    return result;*/

    //배열
    pair<float, int> p[100000];
    int i;
    for (i = 0; i < points.size(); i++)
        p[i] = pair<float, int>(sqrt(pow(points[i][0] - keypoint[0], 2) + pow(points[i][1] - keypoint[1], 2)), i);
    nth_element(p,p+K-1, p+i);
    vector<vector<int>> result = {points[p[K - 1].second]};
    return result;
}