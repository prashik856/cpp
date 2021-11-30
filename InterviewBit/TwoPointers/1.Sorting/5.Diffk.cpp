/*
Given an array ‘A’ of sorted integers and another non negative integer k, 
find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

Example:

Input :

    A : [1 3 5] 
    k : 4
Output : YES

as 5 - 1 = 4

Return 0 / 1 ( 0 for false, 1 for true ) for this problem

Try doing this in less than linear space complexity.
*/
/*
The same as first question!

Just copy pasta
*/
#include<bits/stdc++.h>
using namespace std;

// using two pointers
int solve(vector<int> a, int b){
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
    vector<int> a = {1, 3, 5};
    int b = 4;
    int result = solve(a, b);
    cout << "Result is: " << result << endl;
    return 0;
}