#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> a, vector<int> b) {
    int n = a.size();
    // Let's use the concept we learned earlier
    int minValue = min(a[0], b[0]);
    int maxValue = max(a[n-1], b[n-1]);

    int desiredValue = n;
    while(minValue < maxValue) {
        int mid = (minValue + maxValue)/2;

        int place = 0;
        place += (upper_bound(a.begin(), a.end(), mid) - a.begin());
        place += (upper_bound(b.begin(), b.end(), mid) - b.begin());

        if(place < desiredValue){
            minValue = mid + 1;
        } else {
            maxValue = mid;
        }
    }
    cout << "First required value is: " << minValue << endl;
    int median1 = minValue;

    minValue = min(a[0], b[0]);
    maxValue = max(a[n-1], b[n-1]);
    desiredValue = n + 1;
    while(minValue < maxValue) {
        int mid = (minValue + maxValue)/2;

        int place = 0;
        place += (upper_bound(a.begin(), a.end(), mid) - a.begin());
        place += (upper_bound(b.begin(), b.end(), mid) - b.begin());

        if(place < desiredValue){
            minValue = mid + 1;
        } else {
            maxValue = mid;
        }
    }
    cout << "Second required value is: " << minValue << endl;
    int median2 = minValue;

    int median = (median1 + median2)/2;

    return median;
}

int main(){
    vector<int> a = {1, 4, 5};
    vector<int> b = {1, 2, 3};
    int result = solve(a, b);
    cout << "Result is: " << result << endl;
    return 0;
}