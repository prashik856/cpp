/*
https://www.geeksforgeeks.org/given-an-array-a-and-a-number-x-check-for-pair-in-a-with-sum-as-x/
Write a program that, given an array A[] of n numbers and another number x, 
determines whether or not there exist two elements in A[] whose sum is exactly x. 

*/

#include<bits/stdc++.h>
using namespace std;


int solve(vector<int> a, int b){
    int result =0;
    int n =a.size();

    sort(a.begin(), a.end());

    int i=0,j=n-1;
    while(i<n && j >=0){
        int currentSum = a[i] + a[j];
        if(currentSum == b){
            return 1;
        }
        if(currentSum > b){
            j--;
        } else {
            i++;
        }
    }

    return result;
}

int main(){
    vector<int> a = {20, 500, 1000, 200};
    int b = 1201;
    int result = solve(a, b);
    cout << "Result is: " << result << endl;
    return 0;
}