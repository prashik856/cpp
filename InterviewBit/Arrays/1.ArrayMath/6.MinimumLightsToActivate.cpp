/*
Problem Description

There is a corridor in a Jail which is N units long. 
Given an array A of size N. The ith index of this array is 0 if the light at ith position is faulty otherwise it is 1.

All the lights are of specific power B which if is placed at position X, it can light the corridor from [ X-B+1, X+B-1].

Initially all lights are off.

Return the minimum number of lights to be turned ON to light the whole corridor or -1 if the whole corridor cannot be lighted.



Problem Constraints
1 <= N <= 1000

1 <= B <= 1000



Input Format
First argument is an integer array A where A[i] is either 0 or 1.

Second argument is an integer B.



Output Format
Return the minimum number of lights to be turned ON to light the whole corridor or -1 if the whole corridor cannot be lighted.


Example Input
Input 1:

A = [ 0, 0, 1, 1, 1, 0, 0, 1].
B = 3
Input 2:

A = [ 0, 0, 0, 1, 0].
B = 3


Example Output
Output 1:

2
Output 2:

-1

*/
#include<bits/stdc++.h>
using namespace std;

void printLightTable(vector< vector<int> > lightTable) {
    int n = lightTable.size();
    for(int i=0; i<n; i++){
        cout << lightTable[i][0] << " - " << lightTable[i][1] << endl;
    }
    cout << endl;
}

int solve(vector<int> &A, int B) {
    int n = A.size();
    int result = 0;

    // let's create lightTable first
    vector< vector<int> > lightTable;
    int index = 0;
    for(int i=0; i<A.size(); i++){
        if(A[i] == 1){
            lightTable.push_back(vector<int>());
            int left = max(0, i - (B - 1));
            int right = min(n-1, i + B - 1);
            lightTable[index].push_back(left);
            lightTable[index].push_back(right);
            index++;
        }
    }

    //printLightTable(lightTable);

    int currentCovered = -1;
    int lightTableSize = lightTable.size();

    // Let's start our logic
    // We cannot light anything
    if(lightTableSize == 0) {
        return -1;
    }
    // Cannot light first corridor
    if(lightTable[0][0] != 0) {
        return -1;
    }
    // Cannot light last corridor
    if(lightTable[lightTableSize - 1][1] != n-1) {
        return -1;
    }
    // Got through all lightTables except the last lightTable
    for(int i=0; i<lightTableSize - 1; i++){
        // this light can light the next corridor
        if(lightTable[i][0] == currentCovered + 1) {
            currentCovered = lightTable[i][1];
            result++;
        }

        // This light cannot light the next corridor
        else if(lightTable[i][0] > currentCovered + 1) {
            return -1;
        }

        // If next light is greater than currentCovered + 1
        // That means we need to light our current light.
        else if(lightTable[i+1][0] > currentCovered + 1) {
            currentCovered = lightTable[i][1];
            result++;
        }

        // if the first value of range is same, our covered corridor can be increased
        if(lightTable[i][0] == lightTable[i+1][0]) {
            currentCovered = lightTable[i+1][1];
        }
    }

    if(currentCovered == n-1) {
        return result;
    }

    // check the last guy
    if(lightTable[lightTableSize - 1][0] > currentCovered + 1) {
        return -1;
    } else {
        result++;
    }

    return result;
}

int main(){
    int t;
    cin >> t;
    for(int z=0; z<t; z++) {
        int n, b; 
        cin >> n >> b;
        cout << n << " " << b << endl;
        vector<int> arr;
        cout << "Given input array is: " << endl;
        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            arr.push_back(temp);
            cout << temp << " ";
        }
        cout << endl;

        int result = solve(arr, b);
        cout << "Result: " << result << endl;;
        cout << endl;
    }
}