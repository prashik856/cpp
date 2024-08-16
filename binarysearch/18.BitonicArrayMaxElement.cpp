/**
 * Bitonic Array: Find Maximum Element
 * 
 * Given a bitonic array, we need to find the maximum element.
 * 
 * Input: 
 * arr[]: {1, 3, 8, 12, 4, 2}
 * 
 * Output: 3
 * 
 * A bitonic array is a array which will have only one peak.
 * Monotonically increasing and then monotonically decreasing.
 * It will first increase and then reach peak, and then decrease.
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int maxElement(vector<int> &input) {
    if(input.size() == 1) {
        return 0;
    }

    int output = -1;

    int low = 0;
    int high = input.size() - 1;

    while(high >= low) {
        cout << "low: " << low << " | high: " << high << endl;
        int mid = low + (high - low)/2;
        cout << "Mid: " << mid << endl;

        if(mid == 0) {
            if(input[mid] > input[mid+1]) {
                output = mid;
                break;
            }

            // go forward
            low = mid + 1;
        } else if(mid == input.size() - 1) {
            if(input[mid] > input[mid - 1]) {
                output = mid;
                break;
            }

            // go backward
            high = mid - 1;
        } else if(mid-1>=0 && mid+1<input.size()) {
            if(input[mid] > input[mid-1] && input[mid] > input[mid+1]) {
                output = mid;
                break;
            }

            // else
            if(input[mid-1] > input[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << endl;
    }

    return output;
}

int main() {
    vector<int> input = vector<int>({1, 3, 8, 12, 4, 2});
    cout << "Input vector: " << endl;
    printVector(input);

    int output = maxElement(input);
    cout << "Output: " << output << endl;


    return 0;
}