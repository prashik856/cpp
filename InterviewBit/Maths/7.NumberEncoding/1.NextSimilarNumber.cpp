/*
Problem Description

Given a number A in a form of string.

You have to find the smallest number that has same set of digits as A and is greater than A.

If A is the greatest possible number with its set of digits, then return -1.



Problem Constraints
 1 <= A <= 10100000

 A doesn't contain leading zeroes.



Input Format
First and only argument is an numeric string denoting the number A.



Output Format
Return a string denoting the smallest number greater than A with same set of digits , if A is the largest possible then return -1.



Example Input
Input 1:

 A = "218765"
Input 2:

 A = "4321"


Example Output
Output 1:

 "251678"
Output 2:

 "-1"


Example Explanation
Explanation 1:

 The smallest number greater then 218765 with same set of digits is 251678.
Explanation 2:

 The given number is the largest possible number with given set of digits so we will return -1.
*/

/*
I was correct, it is just next permutation.

Steps:
1. Find the index where i+1 > i, index will be i.
2. Find the smallest greater value from i+1 to n-1 in the array. 
We do this by using custom lower bound function which is just binary search
3. Recheck if our number is actually greater than arr[index]
4. Swap index and arr[lowerBoundIndex]
5. Reverse index+1 to n-1 elements.
*/

#include<bits/stdc++.h>
using namespace std;

int lowerBound(string a, int low, int high, char value){
    int result;
    while(low < high){
        int mid = (low + high)/2;

        if(value == a[mid]){
            result = mid;
            break;
        }
        
        if(value > a[mid]){
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if(low == high){
        result = low;
    }

    return result;
}

string solve(string A){
    int n = A.size();
    
    int index = -1;
    for(int i=n-1; i>0; i--){
        if(A[i] > A[i-1]){
            index = i-1;
            break;
        }
    }

    if(index == -1){
        return "-1";
    }

    // cout << "Value of index is: " << index << endl;
    char indexValue = A[index];
    // cout << "Value of index in array is: " << indexValue << endl;
    
    // cout << "Finding smallest greater value " << endl;
    int lowerBoundIndex = lowerBound(A, index+1, n-1, indexValue);

    // check if same value
    while(A[lowerBoundIndex] <= indexValue){
        lowerBoundIndex--;
    }

    // cout << "Value of smallest greater value is: " << A[lowerBoundIndex] << endl;

    // Got our lowest greater value
    // Swap index and lowerBoundIndex

    char temp = A[lowerBoundIndex];
    A[lowerBoundIndex] = A[index];
    A[index] = temp;

    // cout << "Value of string after replacement is: " << A << endl;

    // Reverse the string from index+1 to n-1
    string tempString = "";
    for(int i=index+1; i<n; i++){
        tempString.push_back(A[i]);
    }

    int j = index+1;
    for(int i=tempString.size() - 1; i>=0; i-- ){
        A[j] = tempString[i];
        j++;
    }

    // cout << "Value of string after sorting is: " << A << endl;

    return A;
}

int main(){
    string A = "218765";
    cout << "Given input array is: " << A << endl;
    string result = solve(A);
    cout << "Result: " << endl;
    cout << result << endl;

    return 0;
}