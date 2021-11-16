#include<bits/stdc++.h>
using namespace std;

double solve(vector<int> a, vector<int> b) {
    int n = a.size();
    int m = b.size();

    if(n==0) {
        if(m % 2 == 0){
            double median1 = b[m/2];
            double median2 = b[(m-1)/2];
            return (median1 + median2)/2;
        } else {
            return b[m/2];
        }
    } else if( m == 0){
        if(n % 2 == 0){
            double median1 = a[n/2];
            double median2 = a[(n-1)/2];
            return (median1 + median2)/2;
        } else {
            return a[n/2];
        }
    } else if (n == 0 && m == 0){
        return 0;
    }

    int minValue = min(a[0], b[0]);
    int maxValue = max(a[n-1], b[m-1]);
    if((n+m) % 2 == 0){
        // even
        int desiredValue1 = (n+m)/2;
        int desiredValue2 = desiredValue1 + 1;
        double median1 = 0;
        double median2 = 0;

        while(minValue < maxValue) {
            int mid = minValue + (maxValue - minValue)/2;
            int place = 0;
            place += (upper_bound(a.begin(), a.end(), mid) - a.begin());
            place += (upper_bound(b.begin(), b.end(), mid) - b.begin());

            if(place < desiredValue1){
                minValue = mid + 1;
            } else {
                maxValue = mid;
            }
        }
        median1 = (double) minValue;
        cout << "Median1 is : " << median1 << endl;

        minValue = min(a[0], b[0]);
        maxValue = max(a[n-1], b[m-1]);
        
        while(minValue < maxValue) {
            cout << "Desired 2 value: " << desiredValue2 << endl;
            int mid = (minValue + maxValue)/2;
            cout << "Mid value: " << mid << endl;
            int place = 0;
            place += (upper_bound(a.begin(), a.end(), mid) - a.begin());
            place += (upper_bound(b.begin(), b.end(), mid) - b.begin());

            cout << "Place value: " << place << endl;
            if(place < desiredValue2){
                minValue = mid + 1;
            } else {
                maxValue = mid;
            }
            cout << "MinValue: " << minValue << endl;
            cout << "MaxValue: " << maxValue << endl;
            cout << endl;
        }
        median2 = (double) minValue;
        cout << "Median2 is: " << median2 << endl;
        double result = (median1 + median2)/2;
        return result;
    } else {
        // odd
        int desiredValue = (n+m+1)/2;
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
        double result = (double) minValue;
        return result;
    }   
}

int main(){
    vector<int> a = {-50, -41, -40, -19, 5, 21, 28};
    vector<int> b = {-50, -21, -10};
    double result = solve(a, b);
    cout << "Result is: " << result << endl;
    return 0;
}