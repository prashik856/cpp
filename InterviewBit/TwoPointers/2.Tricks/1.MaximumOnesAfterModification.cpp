/*
Problem Description

Given a binary array A and a number B, we need to find length of the longest subsegment of ‘1’s possible by changing at most B ‘0’s.



Problem Constraints
 1 <= N, B <= 105

 A[i]=0 or A[i]=1



Input Format
First argument is an binary array A.

Second argument is an integer B.



Output Format
Return a single integer denoting the length of the longest subsegment of ‘1’s possible by changing at most B ‘0’s.



Example Input
Input 1:

 A = [1, 0, 0, 1, 1, 0, 1]
 B = 1
Input 2:

 A = [1, 0, 0, 1, 0, 1, 0, 1, 0, 1]
 B = 2


Example Output
Output 1:

 4
Output 2:

 5


Example Explanation
Explanation 1:

 Here, we should only change 1 zero(0). Maximum possible length we can get is by changing the 3rd zero in the array,
 we get a[] = {1, 0, 0, 1, 1, 1, 1}
Explanation 2:

 Here, we can change only 2 zeros. Maximum possible length we can get is by changing the 3rd and 4th (or) 4th and 5th zeros.
*/

/*
Solution Approach:
https://www.geeksforgeeks.org/longest-subsegment-1s-formed-changing-k-0s/
We can solve this problem using two pointers technique. 
-> Let us take a subarray [l, r] which contains at most k zeroes. 
-> Let our left pointer be l and right pointer be r. 
-> We always maintain our subsegment [l, r] to contain no more than k zeroes by moving the left pointer l. 
Check at every step for maximum size (i.e, r-l+1). 

Man, when I tried this on my own, I couldn't even do it.
I am fucking stupid :(
*/

#include<bits/stdc++.h>
using namespace std;

void printWindow(vector<int>arr, int low, int high){
    for(int i=low; i<=high; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int solve(vector<int> a, int b){
    int n = a.size();
    int result = 0;
    if(b > n){
        return n;
    }

    int cz = 0;
    int l = 0;
    for(int i=0; i<n; i++){
        if(a[i] == 0){
            cz++;
        }

        while(cz > b){
            if(a[l] == 0){
                cz--;
            }
            l++;
        }

        result = max(result, i - l + 1);
    }

    return result;
}

int main(){
    vector<int> a = {1, 0, 0, 1, 1, 0, 1};
    int b = 3;
    int result = solve(a, b);
    cout << "Result is: " << result << endl;
    return 0;
}