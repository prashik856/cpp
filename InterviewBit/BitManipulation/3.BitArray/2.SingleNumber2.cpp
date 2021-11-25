/*
Given an array of integers, every element appears thrice except for one which occurs once.

Find that element which does not appear thrice.

Note: Your algorithm should have a linear runtime complexity.

Could you implement it without using extra memory?

Input Format:

    First and only argument of input contains an integer array A
Output Format:

    return a single integer.
Constraints:

2 <= N <= 5 000 000  
0 <= A[i] <= INT_MAX
For Examples :

Example Input 1:
    A = [1, 2, 4, 3, 3, 2, 2, 3, 1, 1]
Example Output 1:
    4
Explanation:
    4 occur exactly once
Example Input 2:
    A = [0, 0, 0, 1]
Example Output 2:
    1
*/
/*
Let's try using count array?
For negative numbers, we can set 32nd bit as 1

Cooool This solution worked.

1. Get the bit count for all the numbers.
2. For negative numbers, we store it's bit count in 32nd element.
3. See if every bit[i] is divisible by 3. if it is not, that bit belongs to the number that we need.
*/

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int solve(vector<int> a){
    int result = 0;

    vector<int> bits(32,0);
    int n = a.size();

    for(int i=0; i<n; i++){
        int val = a[i];
        if(a[i] < 0){
            bits[31] = 1;
        }
        val = abs(val);
        int index = 0;
        while(val > 0){
            if(val % 2 == 1){
                bits[index]++;
            }
            index++;
            val = val/2;
        }
    }
    // printVector(bits);

    for(int i=0; i<31; i++){
        bits[i] = bits[i] % 3;
        if(bits[i] != 0){
            result  = result + pow(2, i);
        }
    }

    return result;
}

int main(){
    vector<int> a = {1,1, 2, 2, 2, 3, 1};
    int result = solve(a);
    cout << "Result is: " << result << endl;
    return 0;
}