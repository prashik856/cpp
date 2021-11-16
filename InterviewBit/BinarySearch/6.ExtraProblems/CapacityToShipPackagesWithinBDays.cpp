#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> a, int b, int currentMinimum){
    int currentSum = 0;
    int days = 1;
    int n = a.size();
    for(int i=0; i<n; i++){
        if(currentMinimum < a[i]){
            return false;
        }

        if(currentSum + a[i] > currentMinimum){
            days++;
            currentSum = a[i];

            if(days > b){
                return false;
            }
        } else {
            currentSum += a[i];
        }
    }

    return true;
}

int solve(vector<int> a, int b){
    int n = a.size();
    int minValue = 0;
    int simpleMaxValue = 0;
    int maxValue = 0;
    for(int i=0; i<n; i++){
        maxValue += a[i];
        simpleMaxValue = max(simpleMaxValue, a[i]);
    }
    if(n < b){
        return simpleMaxValue;
    }

    int result = 0;
    while(minValue <= maxValue){
        int mid = (minValue + maxValue)/2;

        bool possible = isPossible(a, b, mid);
        if(possible){
            result = mid;

            maxValue = mid - 1;
        } else {
            minValue = mid + 1;
        }
    }
    return result;
}

int main(){
    vector<int> a = {3, 2, 2, 4, 1, 4};
    int b = 3;
    int result = solve(a, b);
    cout << "Result is: " << result << endl;
    return 0;
}