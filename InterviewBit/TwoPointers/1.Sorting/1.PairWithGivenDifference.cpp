/*
Problem Description

Given an one-dimensional unsorted array A containing N integers.

You are also given an integer B, find if there exists a pair of elements in the array whose difference is B.

Return 1 if any such pair exists else return 0.



Problem Constraints
1 <= N <= 105
-103 <= A[i] <= 103
-105 <= B <= 105


Input Format
First argument is an integer array A of size N.

Second argument is an integer B.



Output Format
Return 1 if any such pair exists else return 0.



Example Input
Input 1:

 A = [5, 10, 3, 2, 50, 80]
 B = 78
Input 2:

 A = [-10, 20]
 B = 30


Example Output
Output 1:

 1
Output 2:

 1


Example Explanation
Explanation 1:

 Pair (80, 2) gives a difference of 78.
Explanation 2:

 Pair (20, -10) gives a difference of 30 i.e 20 - (-10) => 20 + 10 => 30
*/
/*
We use two pointers here:
https://www.geeksforgeeks.org/find-a-pair-with-the-given-difference/
sort array.
We start from i=0, and j=1, and check if a[j] - a[i] is equal to difference.
If difference is greater, increase i, if difference is smaller, increase j.
if difference is equal to given distance and i==j, increase j.

*/
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> a, int b){
    int result = 0;
    int n = a.size();
    unordered_map<int, int> hashTable;
    for(int i=0; i<n; i++){
        int value = hashTable[a[i]];
        if(value == 0){
            hashTable[a[i]] = 1;
        } else {
            hashTable[a[i]] = value + 1;
        }
        
    }

    if(b == 0){
        for(int i=0; i<n; i++){
            int value = a[i];
            int isPresent = hashTable[value];
            if(isPresent == 2){
                return 1;
            }
        }
    } else {
        for(int i=0; i<n; i++){
            int value = a[i] + b;
            int isPresent = hashTable[value];
            if(isPresent == 1){
                return 1;
            }
        }
    }

    return result;
}

// using two pointers
int solve(vector<int> a, int b, bool twoPointers){
    sort(a.begin(), a.end());
    int n = a.size();
    int l=0, r=1;
    int result = 0;
    
    while(l<n && r<n){
        int difference = a[r] - a[l];
        if(difference == b && r != l){
            return 1;
        }

        if(difference > b){
            l++;
        } else {
            r++;
        }
    }

    return result;
}

int main(){
    vector<int> a = {20, 500, 100, 1000, 200};
    int b = 0;
    int result = solve(a, b, true);
    cout << "Result is: " << result << endl;
    return 0;
}