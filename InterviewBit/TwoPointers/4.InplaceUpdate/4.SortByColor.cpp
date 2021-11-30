/*
Given an array with n objects colored red, white or blue, 

sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: Using library sort function is not allowed.

Example :

Input : [0 1 2 0 1 2]
Modify array so that it becomes : [0 0 1 1 2 2]
*/

/*
Simple count sort.
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

void solve(vector<int> &a){
    vector<int> count(3, 0);
    int n = a.size();
    for(int i=0; i<a.size(); i++){
        int value = a[i];
        count[value]++;
    }
    // printVector(count);

    int index = 0;
    for(int i=0; i<count.size(); i++){
        for(int j=0; j<count[i]; j++){
            a[index] = i;
            // cout << a[index] << " ";
            index++;
        }
        // cout << endl;
    }

}

int main(){
    vector<int> a = {0, 1, 2, 0, 1, 2};
    solve(a);
    cout << "Result is: " << endl;
    printVector(a);
    return 0;
}

// g++ -std=c++11