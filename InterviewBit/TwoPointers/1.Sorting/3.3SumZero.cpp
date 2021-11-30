/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 

Find all unique triplets in the array which gives the sum of zero.

Note:

Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)

The solution set must not contain duplicate triplets.

For example, given array S = {-1 0 1 2 -1 -4},

A solution set is:

  (-1, 0, 1)

  (-1, -1, 2)

*/

/*
Solution approach:
Same as the previous question.
Only change here:
We need unique solutions, so we need to use a hashmap to check if solution is already considered.
Take care of overflows. For calculations, use long instead of int.
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
    // cout << endl;
}

vector< vector<int> > solve(vector<int> a){
    int b= 0;
    vector< vector<int> > result;
    int n = a.size();
    sort(a.begin(), a.end());
    unordered_map<string, int> isPresent;

    for(int i=0; i<a.size(); i++){
        // cout << a[i] << endl;
        if(i > 1 && a[i] == a[i-1]){
            // cout << "Equal values" << endl;
            continue;
        }
        long valueToFind = (long)b - (long)a[i];


        int j=i+1,k=n-1;
        // because we need unique
        while(j<k){
            // cout << j << " : " << k << endl;
            // cout << a[j] << " : " << a[k] << endl;
            long currentSum = (long)a[j] + (long)a[k];
            if(currentSum == valueToFind){
                string key = to_string(a[i]) + "-" + to_string(a[j]) + "-" + to_string(a[k]);
                int alreadyPresent = isPresent[key];
                if(alreadyPresent == 0){
                    // cout << "Equal" << endl;
                    result.push_back(vector<int>());
                    int sizeOfResult = result.size();
                    result[sizeOfResult - 1].push_back(a[i]);
                    result[sizeOfResult - 1].push_back(a[j]);
                    result[sizeOfResult - 1].push_back(a[k]);
                    isPresent[key] = 1;
                }
            }

            if(currentSum > valueToFind){
                k--;
            } else {
                j++;
            }
        }
        // cout << endl;
    }

    return result;
}

int main(){
    vector<int> a = {2147483647, -2147483648, -2147483648, 0, 1};
    int b = 0;
    vector< vector<int> >  result = solve(a);
    cout << "Result is: " << endl;
    print2DVector(result);
    return 0;
}