/*
You are given an array of N non-negative integers, A0, A1 ,…, AN-1.

Considering each array element Ai as the edge length of some line segment, 
count the number of triangles which you can form using these array values.

Notes:

You can use any value only once while forming each triangle. 
Order of choosing the edge lengths doesn’t matter. Any triangle formed should have a positive area.

Return answer modulo 109 + 7.

For example,

A = [1, 1, 1, 2, 2]

Return: 4
*/

/*
Solution Approach:
https://www.geeksforgeeks.org/find-number-of-triangles-possible/
Method 3: The time complexity can be greatly reduced using Two Pointer methods in just two nested loops.
 

Approach: First sort the array, and run a nested loop, fix an index and then try to fix an upper and lower index within which we can use all the lengths to form a triangle with that fixed index.
Algorithm:
-> Sort the array and then take three variables l, r and i, pointing to start, end-1 and array element starting from end of the array.
-> Traverse the array from end (n-1 to 1), and for each iteration keep the value of l = 0 and r = i-1
-> Now if a triangle can be formed using arr[l] and arr[r] then triangles can obviously formed 
from a[l+1], a[l+2]…..a[r-1], arr[r] and a[i], because the array is sorted , 
which can be directly calculated using (r-l). and then decrement the value of r and continue the loop till l is less than r
-> If a triangle cannot be formed using arr[l] and arr[r] then increment the value of l and continue the loop till l is less than r 

So the overall complexity of iterating 
through all array elements reduces.
*/

#include<bits/stdc++.h>
using namespace std;

bool checkTriangularity(int a, int b, int c){
    bool check1 = (a + b > c);
    bool check2 = (b + c > a);
    bool check3 = (a + c > b);
    if(check1 && check2 && check3){
        return true;
    }
    return false;
}

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int solve(vector<int> a){
    long MOD = 1000000007;
    int result = 0;
    // sort it
    sort(a.begin(), a.end());
    printVector(a);

    int n = a.size();
    for(int i=n-1; i>=2; i--){
        int l = 0;
        int r = i-1;
        while(l < r){
            bool isPossible = checkTriangularity(a[i], a[l], a[r]);
            if(isPossible){
                result += (r - l);
                result = (result % MOD);
                cout << result << endl;

                // We need to check even more possible solutions!
                // This condition is very important!
                r--;
            } else {
                l++;
            }
        }
    }

    return result;
}

int main(){
    vector<int> a = {4, 6, 13, 16, 20, 3, 1, 12};
    int result = solve(a);
    cout << "Result is: " << result << endl;
    return 0;
}