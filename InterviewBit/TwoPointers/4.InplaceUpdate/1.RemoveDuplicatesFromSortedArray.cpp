/*
Problem Description

Given a sorted array A consisting of duplicate elements.

 Your task is to remove all the duplicates and return a sorted array of distinct elements consisting of all distinct elements present in A.

But, instead of returning an answer array, you have to rearrange the given array in-place such that it resembles what has been described above.
Hence, return a single integer, the index(1-based) till which the answer array would reside in the given array A.

Note: This integer is the same as the number of integers remaining inside A had we removed all the duplicates.
Look at the example explanations for better understanding.



Input Format
First and only argurment containing the integer array A.



Output Format
Return a single integer, as per the problem given.


Example Input
Input 1:

A = [1, 1, 2]
Input 2:

A = [1, 2, 2, 3, 3]


Example Output
Output 1:

2
Output 2:

3


Example Explanation
Explanation 1:

Updated Array: [1, 2, X] after rearranging. Note that there could be any number in place of x since we dont need it.
We return 2 here.
Explanation 2:

Updated Array: [1, 2, 3, X, X] after rearranging duplicates of 2 and 3.
We return 3 from here.
*/
/*
Solution approach:
We need to return array as well.
Two ways we can do this, either by using sets or by two pointers.
Both of the methods are implemented below.
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

int solve(vector<int> &a){
    int result = 0;
    int n = a.size();
    int index = 0;

    set<int> arr;
    for(int i=0; i<n; i++){
        arr.insert(a[i]);
    }

    set<int>::iterator it;
    for(it = arr.begin(); it!=arr.end(); it++){
        int value = *it;
        a[index] = value;
        index++;
    }
    result = arr.size();

    return result;
}

int solve(vector<int> &a, bool twoPointers){
    int result = 0;
    int n = a.size();
    int index = 1;
    for(int i=1; i<n; i++){
        if(a[i] == a[i-1]){
            continue;
        } else {
            a[index] = a[i];
            index++;
            result++;
        }
    }

    a[index] = a[n-1];
    index++;

    return result+1;
}

int main(){
    vector<int> a = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 };
    a = {1, 2, 3, 4, 4};
    int result = solve(a, true);
    printVector(a);
    cout << "Result is: " << result << endl;
    return 0;
}

// g++ -std=c++11