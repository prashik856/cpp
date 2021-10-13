/*
Given a collection of intervals, merge all overlapping intervals.

For example:

Given [1,3],[2,6],[8,10],[15,18],

return [1,6],[8,10],[15,18].

Make sure the returned intervals are sorted.
*/

/*
Solution Approach:
Stack was a very important approach here!!!
https://www.geeksforgeeks.org/merging-intervals/
*/
#include<bits/stdc++.h>
using namespace std;

class Interval {
    public:
        int start;
        int end;
        Interval(){
            start = 0;
            end = 0;
        }
        Interval(int s, int e) {
            start = s;
            end = e;
        }
};

void printIntervals(vector<Interval> arr) {
    cout << "Intervals array is: " << endl;
    int n = arr.size();
    for(int i=0; i<n; i++){
        cout << arr[i].start << " " << arr[i].end << endl;
    }
}

void print2DVector(vector< vector<int> > arr) {
    cout << "Given 2D vector is: " << endl;
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

vector<Interval> solve(vector<Interval> &intervals){
    vector<Interval> result;
    stack<Interval> st;
    
    // Store it in a vector and first sort our input
    int n = intervals.size();

    if(n == 0){
        return result;
    }

    vector< vector<int> > vectoredIntervals(n, vector<int>());
    for(int i=0; i<n; i++) {
        Interval currentInterval = intervals[i];
        vectoredIntervals[i].push_back(currentInterval.start);
        vectoredIntervals[i].push_back(currentInterval.end);
    }

    sort(vectoredIntervals.begin(), vectoredIntervals.end());

    for(int i=0; i<n; i++){
        Interval currentInterval(vectoredIntervals[i][0], vectoredIntervals[i][1]);
        if(st.empty()){
            // if empty 
            st.push(currentInterval);
        } else {
            Interval topInterval = st.top();
            // check if currentInterval is overlapping
            if((currentInterval.start >= topInterval.start && currentInterval.start <= topInterval.end) || 
                (currentInterval.end >= topInterval.start && currentInterval.end <= topInterval.end) || 
                (currentInterval.start >= topInterval.start && currentInterval.start <= topInterval.end 
                && currentInterval.end >= topInterval.start && currentInterval.end <= topInterval.end)){
                    topInterval.start = min(topInterval.start, currentInterval.start);
                    topInterval.end = max(topInterval.end, currentInterval.end);
                    st.pop();
                    st.push(topInterval);
            } else {
                // No overlap
                st.push(currentInterval);
            }
        }
    }

    vector<Interval> tempResult;
    while(!st.empty()) {
        tempResult.push_back(st.top());
        st.pop();
    }

    for(int i=tempResult.size() - 1; i>=0; i--){
        result.push_back(tempResult[i]);
    }

    return result;
}

int main() {
    int t;
    cin >> t;
    for(int z=0; z<t; z++) {
        int n; 
        cin >> n;
        cout << "Size of array: " << n << endl;

        vector<Interval> arr;
        cout << "Given input array is: " << endl;
        int s,e;
        for(int i=0; i<n; i++){
            cin >> s;
            cin >> e;
            Interval interval(s,e);
            cout << interval.start << " " << interval.end << endl;
            arr.push_back(interval);
        }

        vector<Interval> result = solve(arr);
        cout << "Result: " << endl;
        printIntervals(result);
        cout << endl;
    }
    return 0;
}