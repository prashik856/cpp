/**
 * Find the Safe Position
 * This Problem is also called Josephus Problem
 * 
 * There are n people stading in a circle (numbered clockwise 1 to n) waiting to be executed.
 * Counting starts from 1 clockwise in a fixed direction.
 * In each step, a certain number of people are skipped, and the next person is executed.
 * The elemination process continues until the last person remains, he gets freedom.
 * 
 * Given total number of persons n and a number k which indicates that k-1 persons are skipped,
 * and kth person is killed in a circle,
 * Task is to choose the place in the initial circle so that we are the last on remaining.
 * 
 * Input
 * n=2, k=1
 * Output
 * 2
 * 
 * 
 * Input:
 * n=4, k=2
 * Output:
 * 1
 * 
 * We need to do this problem using IBH.
 * 
 * How is this a recursion problem?
 * This problem is defined recursively.
 * 
 * We are doing the same work on less number of people everytime.
 * This problem can be solved recursively.
 * 
 * Explanation:
 * Since the problem is recursively defined, we can solve using IBH.
 * 
 * Hypothesis
 * We are going to represent the persons using arrays.
 * And for every new operation, the array will keep on getting smaller.
 * 
 * We can use array and mod operation.
 * 
 * Problems with representing in array.
 * When index value reaches end of array, we can use modular operation.
 * 
 * For every deletion, 
 * for every index, we are doing (index + k - 1)
 * When this value exceeds array.size(), our new index will be index = index % array.size().
 * 
 * In our recursive function, we pass our array, value of k-1, current index
 * And using this index, the next person to be deleted will be (index + k)%array.size()
 * 
 * 
 * Induction:
 * There is no use of any person that dies
 * So, we just call the solve function with smaller input and updated index.
 * 
 * 
 * Base Condition
 * if(number of people == 1) {
 *  this guy is safe
 *  output = this guy;
 *  return;
 * }
 * 
 * 
 * I guess we can reduce the time even more by using linked lists.
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> &input) {
    for(int i=0; i<input.size(); i++) {
        cout << input[i] << " ";
    }
    cout << endl;
}

void solve(vector<int> input, int k, int index, int *output) {
    // cout << "Current Input: " << endl;
    // printVector(input);
    // cout << "Current Input Index: " << index << endl;

    if(input.size() == 1 || *output != -1) {
        // got our output
        // cout << "Got our output: " << endl;
        *output = input[0];
        // cout << "Output: " << *output << endl << endl;
        return;
    }

    // index to be deleted
    index = (index + k - 1) % input.size();
    // cout << "Index to be deleted: " << index << endl;

    input.erase(input.begin() + index);
    // cout << "Array after deletion: " << endl;
    // printVector(input);
    // cout << endl;

    // solve for new smaller input
    solve(input, k, index, output);
    
    return;
}

int main() {
    int n=500,k=500;
    cout << "Input: N: " << n << " | K: " << k << endl;

    int output = -1;
    vector<int> input = vector<int>();

    for(int i=1; i<=n; i++) {
        input.push_back(i);
    }

    solve(input, k, 0, &output);

    cout << "Final Output: " << output << endl;

    return 0;
}
