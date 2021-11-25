/*
Given an integer array A of N integers, find the pair of integers in the array which have minimum XOR value. Report the minimum XOR value.

Input Format:

    First and only argument of input contains an integer array A
Output Format:

    return a single integer denoting minimum xor value
Constraints:

2 <= N <= 100 000  
0 <= A[i] <= 1 000 000 000
For Examples :

Example Input 1:
    A = [0, 2, 5, 7]
Example Output 1:
    2
Explanation:
    0 xor 2 = 2
Example Input 2:
    A = [0, 4, 7, 9]
Example Output 2:
    3
*/
/*
Solution approach:
https://www.geeksforgeeks.org/minimum-xor-value-pair/

Method 1:
A Simple Solution is to generate all pairs of the given array and compute XOR their values. 
Finally, return minimum XOR value. This solution takes O(n2) time. 


Method 2:
An Efficient solution can solve this problem in O(nlogn) time. Below is the algorithm: 
1). Sort the given array
2). Traverse and check XOR for every consecutive pair

Yes!!! 
Should have thought of that!
*/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> a){
    sort(a.begin(), a.end());
    int n = a.size();
    int result = INT_MAX;
    for(int i=0; i<n-1; i++){
        int val = a[i] ^ a[i+1];
        result = min(val, result);
    }
    return result;
}

int main(){
    vector<int> a = {0, 2, 5, 7};
    int result = solve(a);
    cout << "Result is: " << result << endl;
    return 0;
}