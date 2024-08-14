/**
 * Next Alphabetical Letter
 * 
 * Given an array of letters sorted in ascending order, find the smallest 
 * letter in the array which is greater than the key letter.
 * 
 * Input:
 * arr[]: {a, c, f, h}
 * int key = f
 * 
 * Output: f
 * 
 * This is just the same ceil question, but instead of numbers, we are given alphabets.
 * 
 * The question is to find the smallest alphabet which is greater than or equal to given key.
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<char> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int nextAlphabeticalLetter(vector<char> &input, char key) {
    int output = -1;

    int low = 0;
    int high = input.size() - 1;
    while(high >= low) {
        int mid = (high + low)/2;

        if(input[mid] >= key) {
            // potential output
            output = mid;
            // go left for efficient solution
            high = mid - 1;
        } else if(input[mid] < key) {
            // no can do
            // go right
            low = mid + 1;
        }
    }

    return output;
}

int main() {
    vector<char> input = vector<char>({'a', 'c', 'f', 'h'});
    cout << "Input: " << endl;
    printVector(input);
    char key = 'a';
    cout << "Key: " << key << endl;

    int output = nextAlphabeticalLetter(input, key);
    cout << "Output: " << output << endl;
    if(output >= 0) {
        cout << "Value: " << input[output] << endl;
    }

    return 0;
}