/**
 * Peak Element in the array
 * 
 * A Peak element is an element that is greater than its neighbours
 * 
 * Given an input array nums, where nums[i] != nums[i+1], find a peak element
 * and return its index.
 * 
 * They array may contain multple peaks, in that case return the index 
 * to any one of the peak is find.
 * 
 * nums[-1] = num[n] = -infinite
 * 
 * Example:
 * [1, 2, 3, 1]
 * 
 * Output: 2
 * 3 is greater than 2, and 1.
 * And it's index is 2.
 * 
 * 
 * Example2:
 * Input: 5 10 20 15
 * Output: 2
 * 
 * Flow:
 * 1. Problem Statement
 * 2. Criteria
 *  -> Mid is answer
 *  -> left/right criteria
 * 
 * PROBLEM STATEMENT:
 * Why do we need to apply binary search?
 * Peak element? -> arr[i] > arr[i-1] && arr[i] > arr[i+1].
 * This is our mid criteria.
 * arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]
 * 
 * We can have multiple peak elements.
 * For this case, we just need to return one of the peak element index.
 * 
 * For, corner cases, index 0 and index size - 1. 
 * we just need to check the neighbouring element. 
 * If they are greater than their neighbour, they are peak element.
 * 
 * CRITERIA:
 * For peak element, we need to have this condition.
 * arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]
 * This is our criteria for output.
 * Take care of corner elements.
 * 
 * // my thoughts
 * Don't we have to apply recursion here?
 * We need to go to left and right?
 * 
 * How do we make a decision now?
 * When we have a mid, we check if mid-1 and mid+1 is smaller.
 * Now, when our current mid is greater than mid -1, than means, peak cannot be present in mid-1 side.
 * So, more promising side is mid+1.
 * So, we can make a decision to go to mid+1.
 * 
 * THIS IS OUR SECOND CRITERIA TO MAKE A DECISION.
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int peakElement(vector<int> &input) {
    // when array size is 1.
    if(input.size() == 1) {
        return 0;
    }

    int output = -1;

    int low = 0;
    int high = input.size() - 1;
    while(high >= low) {
        int mid = (high + mid)/2;

        if(mid - 1 < 0) {
            if(input[mid] > input[mid+1]) {
                output = mid;
                break;
            }

            // update low, since our answer can be in mid + 1 section.
            low = mid + 1;
        } else if(mid + 1 == input.size()) {
            if(input[mid] > input[mid-1]) {
                output = mid;
                break;
            }

            // update high, we can have our answer in lower section
            high = mid - 1;
        } else if(mid-1>=0 && mid+1 < input.size()) {
            if(input[mid] > input[mid-1] && input[mid] > input[mid+1]) {
                output = mid;
                break;
            }

            
            if(input[mid-1] > input[mid]) {
                // go lower, our answer can lie there
                high = mid - 1;
            } else if(input[mid+1] > input[mid]) {
                // go higher, our answer can lie there
                low = mid + 1;
            }
        }
    }

    return output;
}

int main() {
    vector<int> input = vector<int>({1, 2, 4, 5});
    cout << "Input vector: " << endl;
    printVector(input);

    int output = peakElement(input);
    cout << "Output: " << output << endl;


    return 0;
}