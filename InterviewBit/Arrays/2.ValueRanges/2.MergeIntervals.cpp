/*
Given a set of non-overlapping intervals, insert a new interval into 
the intervals (merge if necessary).

You may assume that the intervals were initially sorted 
according to their start times.

Example 1:

Given intervals [1,3],[6,9] insert and 
merge [2,5] would result in [1,5],[6,9].

Example 2:

Given [1,2],[3,5],[6,7],[8,10],[12,16], 
insert and merge [4,9] would result in [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

Make sure the returned intervals are also sorted.
*/

/*
Solution Approach:
1. Find all the corner cases first:
left side interval, right side interval, or empty input interval.

2. Find all the affected intervals
-> If affected intervals are empty, we need to check if the given interval lies between some input intervals.
-> If afftected intervals is not ready, created a new interval using given interval and affected intervals.
    return the results.
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

vector<Interval> solve(vector<Interval> &intervals, Interval newInterval){
    int n = intervals.size();
    vector<Interval> result;
    if(intervals.size() == 0){
        result.push_back(newInterval);
        return result;
    }
    Interval first = intervals[0];
    Interval last = intervals[n-1];
    vector<Interval> affectedIntervals;

    // corner cases
    if(first.start > newInterval.end) {
        // Interval is at the start
        result.push_back(newInterval);
        for(int i=0; i<n; i++){
            result.push_back(intervals[i]);
        }
        return result;
    }
    if(last.end < newInterval.start) {
        // Interval is at the end
        for(int i=0; i<n; i++){
            result.push_back(intervals[i]);
        }
        result.push_back(newInterval);
        return result;
    }


    for(int i=0; i<n; i++) {
        // When do we continue?
        Interval currentInterval = intervals[i];
        if((newInterval.start >= currentInterval.start && newInterval.start <= currentInterval.end) ||
            (newInterval.end >= currentInterval.start && newInterval.end <= currentInterval.end) ||
            (newInterval.start <= currentInterval.start && newInterval.start <= currentInterval.end && 
             newInterval.end >= currentInterval.start && newInterval.end >= currentInterval.end)){
                affectedIntervals.push_back(currentInterval);
        }
    }

    // printIntervals(affectedIntervals);

    // This means now the interval lies between one of the intervals
    if(affectedIntervals.size() == 0) {
        for(int i=0; i<n-1; i++) {
            // check for i and i + 1
            Interval currentInterval = intervals[i];
            Interval nextInterval = intervals[i+1];

            if(currentInterval.end < newInterval.start && newInterval.end < nextInterval.start) {
                result.push_back(currentInterval);
                result.push_back(newInterval);
            } else {
                result.push_back(currentInterval);
            }
        }
        result.push_back(intervals[n-1]);
        return result;
    } 
    // Look at the range here
    else {
        int start = min(newInterval.start, affectedIntervals[0].start);
        int end = max(newInterval.end, affectedIntervals[affectedIntervals.size() - 1].end);
        Interval mergedInterval(start, end);

        // merge our result
        for(int i=0; i<n; i++) {
            Interval currentInterval = intervals[i];

            if(currentInterval.start == affectedIntervals[0].start) {
                result.push_back(mergedInterval);
                i = i + affectedIntervals.size() - 1;
            } else {
                result.push_back(currentInterval);
            }
        }
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

        cout << "Give Interval is: " << endl;
        cin >> s;
        cin >> e;
        Interval interval(s,e);
        cout << interval.start << " " << interval.end << endl;

        vector<Interval> result = solve(arr, interval);
        cout << "Result: " << endl;
        printIntervals(result);
        cout << endl;
    }
    return 0;
}