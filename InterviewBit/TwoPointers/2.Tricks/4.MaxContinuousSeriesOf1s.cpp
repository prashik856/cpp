/*
You are given with an array of 1s and 0s. And you are given with an integer M, which signifies number of flips allowed.

Find the position of zeros which when flipped will produce maximum continuous series of 1s.

For this problem, return the indices of maximum continuous series of 1s in order.

Example:

Input : 
Array = {1 1 0 1 1 0 0 1 1 1 } 
M = 1

Output : 
[0, 1, 2, 3, 4] 

If there are multiple possible solutions, return the sequence which has the minimum start index.
*/

/*
We can solve this problem using the same sliding window concept!

Please remember how to use sliding window in this case, stupid me :(
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

vector<int> solve(vector<int> a, int b){
    vector<int> result;
    int lIndex = -1;
    int hIndex = -1;

    int n =a.size();
    // maintain a sliding window, with b number of zeroes
    int l = 0;
    int zeroes = 0;
    int maxLength = -1;

    for(int i=0; i<n; i++){
        if(a[i] == 0){
            zeroes++;
        }

        while(zeroes > b){
            if(a[l] == 0){
                zeroes--;
            }
            l++;
        }

        int currentLength = i - l + 1;
        if(currentLength > maxLength){
            maxLength = currentLength;
            lIndex = l;
            hIndex = i;
        }
    }

    // cout << "low index is: " << lIndex << endl;
    // cout << "high index is: " << hIndex << endl;

    for(int i=lIndex; i<=hIndex; i++){
        result.push_back(i);
    }

    return result;
}

int main(){
    vector<int> a = {1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1};
    int b = 7;
    vector<int> result = solve(a, b);
    cout << "Result is: " << endl;
    printVector(result);
    return 0;
}

// g++ -std=c++11