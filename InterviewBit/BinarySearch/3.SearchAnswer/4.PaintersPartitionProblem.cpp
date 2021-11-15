/*
This problem is very similar to the previous problem that we solved.
Rather than finding the min pages value, here we will be finding min boards values, and then 
just mutiply it with b.
That's it.
*/

#include<bits/stdc++.h>
using namespace std;

bool isPossible(int a, vector<int> c, long long currentMinimum) {
    long long currentSum = 0;
    int painters = 1;
    int n = c.size();
    for(int i=0; i<n; i++) {
        // If our array element is greater than currently assumed minimum,
        // impossible
        if(currentMinimum < c[i]){
            return false;
        }

        if(currentSum + c[i] > currentMinimum) {
            currentSum = c[i];
            painters++;

            // if number of required painters exceeds max value, return false
            if(painters > a){
                return false;
            }
        } else {
            currentSum += c[i];
        }
    }

    return true;
}

int solve(int a, int b, vector<int> c) {
    int n = c.size();
    long long minValue = 0;
    long long maxValue = 0;
    int simpleMaxValue = 0;
    int MOD = 10000003;
    int result = 0;

    for(int i=0; i<n; i++) {
        maxValue += c[i];
        simpleMaxValue = max(simpleMaxValue, c[i]);
    }

    // what if number of painters are greater than number of boards,
    // That means, we can simply find the max value of the board, and multiply it with B.
    long long tempResult = 0; 
    if(a > n) {
        tempResult = simpleMaxValue * b;
        tempResult = tempResult % MOD;
        result = tempResult;
        return result;
    }

    // Let's find our minValue
    while(minValue <= maxValue){
        long long mid = (minValue + maxValue)/2;
        bool possible = isPossible(a, c, mid);

        if(possible) {
            // if possible, we got one of our results
            tempResult = mid;

            // But we need to decrease max value to check if a minimum solution is possible
            maxValue = mid - 1;
        } else {
            // This minimum value is not feasible, increase it
            minValue = mid + 1;
        }
    }

    tempResult = tempResult * b;
    tempResult = tempResult % MOD;
    result = tempResult;
    return result;
}

int main(){
    int a = 10;
    int b = 1;
    vector<int> c = {1, 8, 11, 3};
    int result = solve(a, b, c);
    cout << "Result value: " << result << endl;
    return 0;
}