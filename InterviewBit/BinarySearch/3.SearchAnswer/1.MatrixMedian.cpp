#include<bits/stdc++.h>
using namespace std;

int solve(vector< vector<int> > arr) {
    int minValue = numeric_limits<int>::max();
    int maxValue = numeric_limits<int>::min();

    int n = arr.size();
    int m = arr[0].size();

    for(int i=0; i<n; i++){
        minValue = min(minValue, arr[i][0]);
        maxValue = max(maxValue, arr[i][m-1]);
    }
    // cout << "Min Value: " << minValue << endl;
    // cout << "Max value: " << maxValue << endl;

    int desired = (n*m + 1)/2;

    while(minValue < maxValue){
        int mid = (minValue + maxValue)/2;
        int place = 0;
        for(int i=0; i<n; i++){
            place += (upper_bound(arr[i].begin(), arr[i].end(), mid) - arr[i].begin());
        }

        if(place < desired) {
            // We have to do this to avoid an infinite while loop.
            minValue = mid + 1;
        } else {
            // We are doing this here, because we are not considering value of mid
            maxValue = mid;
        }
    }
    return minValue;
}

int main(){
    vector< vector<int> > m = { {1,3,5}, {2,6,9}, {3,6,9} };
    cout << "Median is: " << solve(m) << endl;
}