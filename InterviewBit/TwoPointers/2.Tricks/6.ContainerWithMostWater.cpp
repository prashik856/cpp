/*
Given n non-negative integers a1, a2, ..., an,

where each represents a point at coordinate (i, ai).

'n' vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).

Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Your program should return an integer which corresponds to the maximum area of water that can be contained ( Yes, we know maximum area instead of maximum volume sounds weird. But this is 2D plane we are working with for simplicity ).

Note: You may not slant the container.

Example :

Input : [1, 5, 4, 3]
Output : 6

Explanation : 5 and 3 are distance 2 apart. So size of the base = 2. Height of container = min(5, 3) = 3. 
So total area = 3 * 2 = 6
*/

/*
Solution Approach:
https://www.geeksforgeeks.org/container-with-most-water/
Approach: Given an array of heights of lines of boundaries of the container, find the maximum water that can be stored in a container. So start with the first and last element and check the amount of water that can be contained and store that container. Now the question arises is there any better boundaries or lines that can contain maximum water. So there is a clever way to find that. Initially, there are two indices the first and last index pointing to the first and the last element (which acts as boundaries of the container), if the value of first index is less than the value of last index increase the first index else decrease the last index. As the decrease in width is constant, by following the above process the optimal answer can be reached.
The GIF below explains the approach.

Keep two index, first = 0 and last = n-1 and a value max_area that stores the maximum area.
-> Run a loop until first is less than the last.
        Get current area. [min(a[high], a[low])*(high - low)]
        result = max(result, currentArea)
        Update the first or last element
        if the value at array[first] is greater the array[last] then update last as last – 1 else update first as first + 1
    Print the maximum area.
*/

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print2DVector(vector< vector<int> > arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void printStrings(vector<string> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << endl;
    }
}

int solve(vector<int> a){
    int result = 0;
    int n = a.size();

    int low = 0;
    int high = n - 1;

    while(low < high){
        int base = high - low;
        int height = min(a[high], a[low]);
        int area = base * height;

        result = max(result, area);

        if(a[low] > a[high]){
            high--;
        } else {
            low++;
        }
    }

    return result;
}

int main(){
    vector<int> a = {3, 1, 2, 4, 5};
    int result = solve(a);
    cout << "Result is: " << result << endl;
    return 0;
}

// g++ -std=c++11