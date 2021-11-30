/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note: You have to modify the array A to contain the merge of A and B. Do not output anything in your code.

TIP: C users, please malloc the result into a new array and return the result.

If the number of elements initialized in A and B are m and n respectively, the resulting size of array A after your code is executed should be m + n

Example :

Input : 
         A : [1 5 8]
         B : [6 9]

Modified A : [1 5 6 8 9]
*/
/*
Remember merge sort.
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
    for(; i<n && j<m;){
        if(a[i] < b[j]){
            result.push_back(a[i]);
            i++;
        } else {
            result.push_back(b[j]);
            j++;
        }
    }

    while(i<n){
        result.push_back(a[i]);
        i++;
    }

    while(j<m){
        result.push_back(b[j]);
        j++;
    }

    a = result;
    return a;
}

int main(){
    vector<int> a = {1, 2};
    vector<int> b = {-1, 2};
    vector<int> result = solve(a, b);
    cout << "Result is: " << endl;
    printVector(result);
    return 0;
}