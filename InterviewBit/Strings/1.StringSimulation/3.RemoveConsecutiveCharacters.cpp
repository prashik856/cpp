/*
Problem Description

Given a string A and integer B, remove all consecutive same characters that have length exactly B.



Problem Constraints
1 <= |A| <= 100000

1 <= B <= |A|



Input Format
First Argument is string A.

Second argument is integer B.



Output Format
Return a string after doing the removals.



Example Input
Input 1:

A = "aabcd"
B = 2
Input 2:

A = "aabbccd"
B = 2


Example Output
Output 1:

 "bcd"
Output 2:

 "d"


Example Explanation
Explanation 1:

 "aa" had length 2.
Explanation 2:

 "aa", "bb" and "cc" had length of 2.
*/
/*
Solution approach:
Keep track of indices we need to remove.
Take care of the last index!
*/

#include<bits/stdc++.h>
using namespace std;

void print2DVector(vector< vector<int> > arr){

    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

string solve(string a, int b){
    string result;
    int n = a.size();
    if(b > a.size()){
        return a;
    }
    vector< vector<int> > indices;

    int count = 1;
    int start = 0;
    int end = -1;
    for(int i=1; i<a.size(); i++){
        if(a[i] == a[i-1]){
            // if equal
            count++;
            if(i == n-1){
                end = i;
                if(count == b){
                    vector<int> temp;
                    temp.push_back(start);
                    temp.push_back(end);
                    indices.push_back(temp);
                }
            }
        } else {
            // not equal
            end = i - 1;
            if(count == b){
                vector<int> temp;
                temp.push_back(start);
                temp.push_back(end);
                indices.push_back(temp);
            }
            start = i;
            count = 1;

            if(i == n-1){
                end = i;
                if(count == b){
                    vector<int> temp;
                    temp.push_back(start);
                    temp.push_back(end);
                    indices.push_back(temp);
                }
            }
        }
    }
    // cout << "Indices to remove: " << endl;
    // print2DVector(indices);

    if(indices.size() == 0){
        return a;
    } else {
        int index = 0;
        for(int i=0; i<n; i++){
            if(index < indices.size() && indices[index][0] == i){
                i = indices[index][1];
                index++;
                continue;
            }
            result.push_back(a[i]);
        }
    }

    return result;
}

int main(){
    string a = "aabcdd";
    int b = 3;
    string result = solve(a, b);
    cout << "Result is: " << result << endl;
    return 0;
}