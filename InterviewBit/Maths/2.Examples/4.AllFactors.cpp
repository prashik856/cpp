/*
Given a number N, find all factors of N.

Example:

N = 6 
factors = {1, 2, 3, 6}
Make sure the returned array is sorted.

Problem Approach:

Complete code in the hint.
*/

/*
Solution Approach:
https://www.geeksforgeeks.org/find-divisors-natural-number-set-1/

A Naive Solution would be to iterate all the numbers from 1 to n, checking if that number divides n and printing it.

If we look carefully, all the divisors are present in pairs. 
For example if n = 100, then the various pairs of divisors are: (1,100), (2,50), (4,25), (5,20), (10,10)
Using this fact we could speed up our program significantly. 
We, however, have to be careful if there are two equal divisors as in the case of (10, 10). 
In such case, we’d print only one of them. 

Below is an implementation for the same:
*/

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr) {
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> solve(int A) {
    vector<int> result;

    if(A == 0){
        return result;
    }

    if(A == 1){
        result.push_back(1);
        return result;
    }

    set<int> tempResult;

    int upperLimit = (int) sqrt(A);
    upperLimit++;

    for(int i=1; i<=upperLimit; i++){
        if(A % i == 0){
            int quotient = A / i;
            tempResult.insert(i);
            tempResult.insert(quotient);
        }
    }

    set<int>::iterator itr;
    for(itr=tempResult.begin(); itr!=tempResult.end(); itr++){
        result.push_back(*itr);
    }

    return result;
}

int main() {
    int t;
    cin >> t;
    for(int z=0; z<t; z++) {
        int n; 
        cin >> n;
        cout << "Given number is: " << n << endl;
        // vector<int> arr(n, 0);
        // for(int i=0; i<n; i++){
        //         int temp;
        //         cin >> temp;
        //         arr[i] = temp;
        //         cout << temp << " ";
        // }
        // cout << endl;
        
        vector<int> result = solve(n);
        cout << "Result: " << endl;
        printVector(result);

        cout << endl;
    }
    return 0;
}