/*
You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.

f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

For example,

A=[1, 3, -1]

f(1, 1) = f(2, 2) = f(3, 3) = 0
f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

So, we return 5.
*/
/*
An efficient solution in O(n) time complexity can be worked out using the properties of absolute values. 
f(i, j) = |A[i] – A[j]| + |i – j| can be written in 4 ways (Since we are looking at max value, we don’t even care if the value becomes negative as long as we are also covering the max value in some way). 
 



Case 1: A[i] > A[j] and i > j
|A[i] - A[j]| = A[i] - A[j]
|i -j| = i - j
hence, f(i, j) = (A[i] + i) - (A[j] + j)

Case 2: A[i] < A[j] and i < j
|A[i] - A[j]| = -(A[i]) + A[j]
|i -j| = -(i) + j
hence, f(i, j) = -(A[i] + i) + (A[j] + j)

Case 3: A[i] > A[j] and i < j
|A[i] - A[j]| = A[i] - A[j]
|i -j| = -(i) + j
hence, f(i, j) = (A[i] - i) - (A[j] - j)

Case 4: A[i] < A[j] and i > j
|A[i] - A[j]| = -(A[i]) + A[j]
|i -j| = i - j
hence, f(i, j) = -(A[i] - i) + (A[j] - j)
Note that cases 1 and 2 are equivalent and so are cases 3 and 4 and hence we can design our algorithm only for two cases as it will cover all the possible cases.
 

1. Calculate the value of A[i] + i and A[i] – i for every element of the array while traversing through the array.
2. Then for the two equivalent cases, we find the maximum possible value. 
For that, we have to store minimum and maximum values of expressions A[i] + i and A[i] – i for all i.
3. Hence the required maximum absolute difference is maximum of two values i.e. 
    max((A[i] + i) – (A[j] + j)) and 
    max((A[i] – i) – (A[j] – j)). 
    These values can be found easily in linear time. 
     a. For max((A[i] + i) – (A[j] + j)) 
        Maintain two variables max1 and min1 which will store maximum and minimum values of A[i] + i respectively. 
        max((A[i] + i) – (A[j] + j)) = max1 – min1 
     b. For max((A[i] – i) – (A[j] – j)). 
        Maintain two variables max2 and min2 which will store maximum and minimum values of A[i] – i respectively. 
        max((A[i] – i) – (A[j] – j)) = max2 – min2
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

void print2DVector(vector< vector<int> > arr) {
    int n = arr.size();
    for(int i=0; i<n; i++) {
        for(int j=0; j<arr[i].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int solve(vector<int> &A) {
    int n = A.size();
    int result = 0;

    int maxiplusi = numeric_limits<int>::min();
    int miniplusi = numeric_limits<int>::max();

    int maximinusi = numeric_limits<int>::min();
    int miniminusi = numeric_limits<int>::max();
    for(int i=0; i<n; i++){
        int Aiplusi = A[i] + i;
        int Aiminusi = A[i] - i;

        maxiplusi = max(maxiplusi, Aiplusi);
        miniplusi = min(miniplusi, Aiplusi);

        maximinusi = max(maximinusi, Aiminusi);
        miniminusi = min(miniminusi, Aiminusi);
    }

    int exp1 = abs(maxiplusi - miniplusi);
    int exp2 = abs(maximinusi - miniminusi);

    result = max(exp1, exp2);
    
    return result;
}

int main() {
    int t;
    cin >> t;
    for(int z=0; z<t; z++) {
        int n; 
        cin >> n;
        cout << n << endl;
        vector<int> arr;
        cout << "Given input array is: " << endl;
        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            arr.push_back(temp);
            cout << temp << " ";
        }
        cout << endl;

        int result = solve(arr);
        cout << "Result: " << result << endl;;
        cout << endl;
    }
    return 0;
}