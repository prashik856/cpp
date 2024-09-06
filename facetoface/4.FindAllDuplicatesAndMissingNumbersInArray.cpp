/**
 * Find all duplicates and missing numbers in array
 * Given an unsorted array of size n. 
 * Array elements are in the range from 1 to n. 
 * Some numbers from set {1, 2, …n} are missing and some are repeating in the array. 
 * Find these two numbers in order of one space.
 * Input:[3 1 1 5 3] 
 * Duplicate = 3,1  Missing = 2,4 . 
 * 
 * Time complexity of algorithm is O(n).
 * 
 */
#include <iostream>
#include<vector>
#include<set>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swapSortByMe(vector<int> &arr) {
    int i=0;
    while(i < arr.size()) {
        int item = arr[i];
        int expectedIndex = item - 1;
        if(i == expectedIndex) {
            i++;
        } else {
            int valueOfExpectedIndex = arr[expectedIndex];
            if(valueOfExpectedIndex == item) {
                i++;
            } else {
                // perform swap of i and expectedIndex.
                int temp = arr[i];
                arr[i] = arr[expectedIndex];
                arr[expectedIndex] = temp;
                continue;
            }
        }
    }
}

class Solution {
    public:
        vector<int> duplicates;
        vector<int> missing;
        Solution() {
            this->duplicates = vector<int>();
            this->missing = vector<int>();
        }
};

Solution getAllDuplicatesAndMissing(vector<int> &arr) {
    Solution solution = Solution();
    swapSortByMe(arr);



    for(int i=0; i<arr.size(); i++) {
        if(arr[i] - 1 != i) {
            solution.duplicates.push_back(arr[i]);
            solution.missing.push_back(i+1);
        }
    }

    return solution;
}

int main() {
    vector<int> arr = vector<int>({3, 1, 1, 5, 3});
    cout << "Input: " << endl;
    printVector(arr);

    Solution solution = getAllDuplicatesAndMissing(arr);
    cout << "Missing: " << endl;
    printVector(solution.missing);

    cout << "Duplicates: " << endl;
    printVector(solution.duplicates);

    return 0;
}