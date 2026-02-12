/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Constraints:

    nums1.length == m
    nums2.length == n
    0 <= m <= 1000
    0 <= n <= 1000
    1 <= m + n <= 2000
    -106 <= nums1[i], nums2[i] <= 106

*/
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums1 = {1,2,3,4,10,11,24,26};
    vector<int> nums2 = {3,5,6,7,9};

    cout << "Input vector 1 : " << endl;
    printVector(nums1);

    cout << "Input vector 2 : " << endl;
    printVector(nums2);

    int n = nums1.size();
    int m = nums2.size();

    bool isOdd = true;
    if ((n+m) % 2 == 0) {
        isOdd = false;
    }

    // cout << "Is odd value: " << isOdd << endl;

    // cout << "Total merged size: " << n+m << endl;
    int count = (n+m)/2 + 1;
    // cout << "Count value: " << count << endl;
    vector<int> merged;
    int index1 = 0;
    int index2 = 0;

    while ((index1 < n || index2 < m) && merged.size() < count) {
        // cout << "Index1 value: " << index1 << endl;
        // cout << "Index2 value: " << index2 << endl;
        if (index1 < n && index2 < m) {
            if (nums1[index1] < nums2[index2]) {
                merged.push_back(nums1[index1]);
                index1++;
                continue;
            }
            merged.push_back(nums2[index2]);
            index2++;
            continue;
        }

        if (index1 < n && index2 >= m) {
            merged.push_back(nums1[index1]);
            index1++;
        }

        if (index2 < m && index1 >= n) {
            merged.push_back(nums2[index2]);
            index2++;
        }
    }

    // cout << "The merged array is: " << endl;
    // printVector(merged);

    double result = 0;
    if (isOdd) {
        result = (double) merged[count-1];
    } else {
        double val1 = merged[count-1];
        double val2 = merged[count-2];
        result = (val1+val2)/2;
    }

    // cout << "Result value is: " << result << endl;
    return 0;
}

// this got accepted