#include <iostream>
#include <ctime>
#include "solution.h"
using namespace std;

Solution s;

/* This main function is only for reference. 
 * Evaluation will be made by other main function tailored for grading 
 * Please, DO NOT submit main.cpp and solution.h files 
 */ 

int main (void)
{
    struct TreeNode* root;
    unsigned long long int answer;
    root = s.buildTree("sample2.txt");
    
    /* Run your codes */
    clock_t begin = clock();    
    answer = s.getPathSum(root);
    clock_t end = clock();

    cout << answer << endl;
    cout << "Elapsed time: " << double (end - begin)/CLOCKS_PER_SEC << " (s)" << endl;

    return 0;
}