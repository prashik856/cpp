/*
Problem Description

Find the intersection of two sorted arrays. OR in other words, Given 2 sorted arrays, find all the elements which occur in both the arrays.

Example:

Input:
    A: [1 2 3 3 4 5 6]
    B: [3 3 5]


Output: [3 3 5]



Input:
    A: [1 2 3 3 4 5 6]
    B: [3 5]



Output: [3 5]

NOTE : For the purpose of this problem ( as also conveyed by the sample case ), assume that elements that appear more than once in both arrays should be included multiple times in the final output. 


*/

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print2DVector(vector< vector<int> > arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void printStrings(vector<string> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << endl;
    }
}

vector<int> solve(vector<int> a, vector<int> b){
    vector<int> result;

    int n = a.size();
    int m = b.size();
    int i=0,j=0;
    for(;i<n && j<m;){
        if(a[i] == b[j]){
            result.push_back(a[i]);
            i++;
            j++;
            continue;
        }

        if(a[i] < b[j]){
            i++;
            continue;
        } else {
            j++;
        }
    }

    return result;
}

int main(){
    vector<int> a = {1, 2, 3, 3, 4, 5, 6};
    vector<int> b = {3, 5};
    vector<int> result = solve(a, b);
    cout << "Result is: " << endl;
    printVector(result);
    return 0;
}

// g++ -std=c++11