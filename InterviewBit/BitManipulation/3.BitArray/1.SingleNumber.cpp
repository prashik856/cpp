/*
Problem Description

Given an array of integers A, every element appears twice except for one. Find that single one.


NOTE: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?



Problem Constraints
2 <= |A| <= 2000000

0 <= A[i] <= INTMAX



Input Format
First and only argument of input contains an integer array A.



Output Format
Return a single integer denoting the single element.



Example Input
Input 1:

 A = [1, 2, 2, 3, 1]
Input 2:

 A = [1, 2, 2]


Example Output
Output 1:

 3
Output 2:

 1


Example Explanation
Explanation 1:

3 occurs once.
Explanation 2:

1 occurs once.
*/

#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> a){
    int result = 0;

    for(int i=0; i<a.size(); i++){
        result = result ^ a[i];
    }

    return result;
}

int main(){
    vector<int> a = {1, 2, 2, 3, 1};
    int result = solve(a);
    cout << "Result is: " << result << endl;
    return 0;
}