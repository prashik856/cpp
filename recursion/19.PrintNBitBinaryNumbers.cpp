/**
 * Print N-Bit binary numbers having more 1s than 0s.
 * 
 * Given a positive integer n, our task is to generate a string list 
 * of all n-bit binary numbers where for any prefix, there are more or an equal number
 * of 1s than 0s. 
 * 
 * E.g. 
 * n = 2
 * Output:
 * ["11", "10"]
 * 
 * n=3
 * Output:
 * ["111", "110", "101"]
 * 
 * We can again use input output method for this.
 * BC will be when ones + zeroes == n && ones >= zeroes
 * We get our output.
 * 
 * 
 */
#include<bits/stdc++.h>
using namespace std;

void getAllBinaryNumbers(int n, int ones, int zeroes, string &currentOutput, 
    vector<string> &allOutputs) {
        if(ones + zeroes == n && ones >= zeroes) {
            // got some output
            allOutputs.push_back(currentOutput);
            return;
        } else if(ones + zeroes == n && ones < zeroes) {
            // bad output
            return;
        }

        // put 1
        if(ones+1 >= zeroes) {
            currentOutput.push_back('1');
            getAllBinaryNumbers(n, ones + 1, zeroes, currentOutput, allOutputs);

            // backtrack
            currentOutput.pop_back();
        }

        // put 0
        if(ones >= zeroes + 1) {
            currentOutput.push_back('0');
            getAllBinaryNumbers(n, ones, zeroes + 1, currentOutput, allOutputs);

            // backtrack
            currentOutput.pop_back();
        }

        return;
    }

int main() {
    int n = 10;
    cout << "Input: " << n << endl;

    vector<string> allOutputs = vector<string>();
    // binary numbers will start from 1
    string currentOutput = "1";

    // initialize ones and zeros
    int zeroes = 0;
    int ones = 1;

    getAllBinaryNumbers(n, ones, zeroes, currentOutput, allOutputs);

    cout << "Output: " << endl;
    for(int i=0; i<allOutputs.size(); i++) {
        cout << allOutputs[i] << " ";
    }
    cout << endl;

    return 0;
}