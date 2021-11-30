/*
Remove Element

Given an array and a value, remove all the instances of that value in the array. 

Also return the number of elements left in the array after the operation.

It does not matter what is left beyond the expected length.

Example:

If array A is [4, 1, 1, 2, 1, 3]

and value elem is 1, 

then new length is 3, and A is now [4, 2, 3]

Try to do it in less than linear additional space complexity.
*/

/*
I don't know. 
it was easy, and my solution worked.
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

int solve(vector<int> a, int b){
    int result = 0;
    int n = a.size();

    vector<int> indices;
    for(int i=0; i<n; i++){
        if(a[i] != b){
            indices.push_back(a[i]);
        }
    }

    for(int i=0; i<indices.size(); i++){
        a[i] = indices[i];
    }

    return indices.size();
}

int main(){
    vector<int> a = {4, 1, 1, 2, 1, 3};
    int b = 1;
    int result = solve(a,b);
    cout << "Result is: " << result << endl;
    return 0;
}

// g++ -std=c++11