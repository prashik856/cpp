/*
https://www.geeksforgeeks.org/find-the-two-repeating-elements-in-a-given-array/

Find duplicates in O(n) time and O(1) extra space
Given an array of n elements that contains elements from 0 to n-1, 
with any of these numbers appearing any number of times. 
Find these repeating numbers in O(n) and using only constant memory space.

*/

/*
Solution Approach:
Method 5 (Use array elements as index) 
Traverse the array. Do following for every index i of A[].
{
check for sign of A[abs(A[i])] ;
if positive then
   make it negative by   A[abs(A[i])]=-A[abs(A[i])];
else  // i.e., A[abs(A[i])] is negative
   this   element (ith element of list) is a repetition
}

Example: A[] =  {1, 1, 2, 3, 2}
i=0; 
Check sign of A[abs(A[0])] which is A[1].  A[1] is positive, so make it negative. 
Array now becomes {1, -1, 2, 3, 2}

i=1; 
Check sign of A[abs(A[1])] which is A[1].  A[1] is negative, so A[1] is a repetition.

i=2; 
Check sign of A[abs(A[2])] which is A[2].  A[2] is  positive, so make it negative. '
Array now becomes {1, -1, -2, 3, 2}

i=3; 
Check sign of A[abs(A[3])] which is A[3].  A[3] is  positive, so make it negative. 
Array now becomes {1, -1, -2, -3, 2}

i=4; 
Check sign of A[abs(A[4])] which is A[2].  A[2] is negative, so A[4] is a repetition.
I really think we can apply this method!

*/
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr) {
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

long long fact(int n){
    long long result=1;

    if(n==1){
        return 1;
    }

    for(int i=1; i<=n; i++){
        result = result * i;
    }

    return result;
}

vector<int> solve(vector<int> arr) {
    vector<int> result;

    set<int> result1;

    for(int i=0; i<arr.size(); i++){
        int index = abs(arr[i]);

        if(arr[index] > 0){
            arr[index] = -arr[index];
        } else {
            result1.insert(abs(arr[index]));
        }
    }

    set<int>::iterator itr;
    for(itr = result1.begin(); itr!=result1.end(); itr++){
        result.push_back(*itr);
    }

    return result;
}

int main() {
    int t;
    cin >> t;
    for(int z=0; z<t; z++) {
        int n; 
        cin >> n;
        cout << "Given size of array is: " << n << endl;
        vector<int> arr(n, 0);
        for(int i=0; i<n; i++){
                int temp;
                cin >> temp;
                arr[i] = temp;
                cout << temp << " ";
        }
        cout << endl;
        
        vector<int> result = solve(arr);
        cout << "Result: " << endl;
        printVector(result);

        cout << endl;
    }
    return 0;
}