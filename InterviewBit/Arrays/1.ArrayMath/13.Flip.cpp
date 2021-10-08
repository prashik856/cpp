/*
Problem Description

You are given a binary string A(i.e. with characters 0 and 1) consisting of characters A1, A2, ..., AN. In a single operation, you can choose two indices L and R such that 1 ≤ L ≤ R ≤ N and flip the characters AL, AL+1, ..., AR. By flipping, we mean change character 0 to 1 and vice-versa.

Your aim is to perform ATMOST one operation such that in final string number of 1s is maximised.

If you don't want to perform the operation, return an empty array. Else, return an array consisting of two elements denoting L and R. If there are multiple solutions, return the lexicographically smallest pair of L and R.

NOTE: Pair (a, b) is lexicographically smaller than pair (c, d) if a < c or, if a == c and b < d.



Input Format
First and only argument is a string A.



Output Format
Return an array of integers denoting the answer.



Example Input
Input 1:

A = "010"
Input 2:

A = "111"


Example Output
Output 1:

[1, 1]
Output 2:

[]


Example Explanation
Explanation 1:

A = "010"


Pair of [L, R] | Final string
____________|__________
[1 1]          | "110"
[1 2]          | "100"
[1 3]          | "101"
[2 2]          | "000"
[2 3]          | "001"



We see that two pairs [1, 1] and [1, 3] give same number of 1s in final string. So, we return [1, 1].

Explanation 2:

No operation can give us more than three 1s in final string. So, we return empty array [].
*/

/*
Solution Approach:
Remember kidane's algo!
Use current Sum, and maximum Sum!
We just have the left index and right index
*/

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr) {
    int n = arr.size();
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> solve(string A) {
    vector<int> result;

    int globalSum = numeric_limits<int>::min();
    int currentSum = 0;

    int left = 0;
    int right = -1;
    int resultLeft = -1;
    int resultRight = -1;
    for(int i=0; i<A.size(); i++){
        if(A[i] == '0') {
            currentSum++;
        } else {
            currentSum--;
        }


        if(currentSum > globalSum){
            globalSum = currentSum;
            resultLeft = left;
            right = i;
            resultRight = right;
        }

        if(currentSum < 0){
            currentSum = 0;
            left = i+1;
        }
    }

    if(globalSum <= 0){
        return result;
    } else {
        result.push_back(resultLeft + 1);
        result.push_back(resultRight + 1);
    }

    // cout << "Result: " << globalSum << endl;
    // cout << "Left: " << left+1 << " | Right: " << right+1 << endl;

    return result;
}

int main() {
    int t;
    cin >> t;
    for(int z=0; z<t; z++) {
        string arr;
        cout << "Given input array is: " << endl;
        cin >> arr;
        cout << arr << endl;

        vector<int> result = solve(arr);
        cout << "Range: " << endl;
        printVector(result);
        cout << endl;
    }
    return 0;
}