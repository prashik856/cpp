/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Try to solve it in linear time/space.

Example :

Input : [1, 10, 5]
Output : 5 
Return 0 if the array contains less than 2 elements.

You may assume that all the elements in the array are non-negative integers and fit in the 32-bit signed integer range.
You may also assume that the difference will not overflow.
*/

/*
Solution Approach:
To solve this problem, we first need to learn about PegionHole Sorting.
https://www.geeksforgeeks.org/pigeonhole-sort/


Approach from Interview Bit:
Now, first try to think if you were already given the minimum value MIN and maximum value MAX in the array of size N, 
under what circumstances would the max gap be minimum and maximum ?
Obviously, maximum gap will be maximum when all elements are either MIN or MAX making maxgap = MAX - MIN.

Maximum gap will be minimum when all the elements are equally spaced apart between MIN and MAX. 
Lets say the spacing between them is gap.

So, they are arranged as
MIN, MIN + gap, MIN + 2*gap, MIN + 3*gap, ... MIN + (N-1)*gap 
where
MIN + (N-1)*gap = MAX 
=> gap = (MAX - MIN) / (N - 1). 

So, we know now that our answer will lie in the range [gap, MAX - MIN].
Now, if we know the answer is more than gap, what we do is create buckets of size gap for ranges

[MIN, MIN + gap), [Min + gap, `MIN` + 2* gap) ... and so on
There will only be (N-1) such buckets. We place the numbers in these buckets based on their value.

If you pick any 2 numbers from a single bucket, their difference will be less than gap, 
and hence they would never contribute to maxgap ( Remember maxgap >= gap ). 
We only need to store the largest number and the smallest number in each bucket, 
and we only look at the numbers across bucket.

Now, we just need to go through the bucket sequentially ( they are already sorted by value ), 
and get the difference of min_value with max_value of previous bucket with at least one value. 
We take maximum of all such values.


Critical cases:
What will happen when array size is 1?  -> return 0
What will happen when all the elements of the array are equal? -> return 0
*/

/*
O(n) solution and still a TLE. Fuck you.
*/

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr) {
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print2DVector(vector< vector<int> > arr) {
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }   
        cout << endl;
    }
}

int solve(const vector<int> arr){
    if(arr.size() == 1) {
        return 0;
    }
    
    int result = 0;
    int n = arr.size();
    int maxValue=numeric_limits<int>::min(), minValue=numeric_limits<int>::max();
    vector< vector<int> > bucket(n, vector<int>(2));

    for(int i=0; i<arr.size(); i++){
        if(arr[i] > maxValue) {
            maxValue = arr[i];
        }

        if(arr[i] < minValue) {
            minValue = arr[i];
        }

        bucket[i][0] = numeric_limits<int>::max();
        bucket[i][1] = numeric_limits<int>::min();
    }

    int range = (maxValue - minValue);
    double gap = (double)range / ((double)(n-1));
    if(gap == 0) {
        return 0;
    }
    // cout << "MaxValue: " << maxValue << endl;
    // cout << "MinValue: " << minValue << endl;
    // cout << "Range: " << range << endl;
    // cout << "Gap: " << gap << endl;

    // We need to find some x
    // minValue + x * gap = arr[i]
    // x = (double)(arr[i] - minValue)/gap
    // Here, x will be the index
    // Max value of x? = N-1

    for(int i=0; i<arr.size(); i++){
        double indexDouble = (double)(arr[i] - minValue)/gap;
        int index = floor(indexDouble);
        // cout << index << endl;
        if(arr[i] < bucket[index][0]){
            bucket[index][0] = arr[i];
        }
        if(arr[i] > bucket[index][1]) {
            bucket[index][1] = arr[i];
        }
    }

    // cout << "Bucket is: " << endl;
    // print2DVector(bucket);

    int prevBucketMax = -1;
    int currentBucketMin = -1; 
    for(int i=0; i<bucket.size(); i++) {
        // non empty
        if(bucket[i][0] != numeric_limits<int>::max() && bucket[i][1] != numeric_limits<int>::min()){
            if(prevBucketMax == -1){
                // set value
                prevBucketMax = bucket[i][1];
                continue;
            } else {
                currentBucketMin = bucket[i][0];
                if(currentBucketMin - prevBucketMax > result) {
                    result = currentBucketMin - prevBucketMax;
                }
                // update prevBucketMax
                prevBucketMax = bucket[i][1];
            }
        } else {
            continue;
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