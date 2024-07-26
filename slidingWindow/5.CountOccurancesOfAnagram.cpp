/**
 * Count Occurances of Anagram
 * 
 * Flow:
 * 1) Problem Statement Input output
 * 2) Identification
 * 3) Break down - Sliding Window
 * 4) Explanation + Code
 * 
 * Input:
 * Two Strings: 
 * String 1: forxxorfxaofr
 * String 2: for
 * 
 * Basically, we need to find all patterns of string 2, and check if they are present in string 1.
 * For example:
 * for - fro, rfo, rof, ofr, orf , these are all the anagrams of for.
 * 
 */
#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int countOccurancesOfAnagram(string strValue, string pattern) {
    int output = 0;
    int i=0,j=0;

    vector<int> mapping = vector<int>(26, 0);
    vector<int> strMapping = vector<int>(26);
    int count = 0;
    for(int i=0; i<pattern.size(); i++) {
        int item = int(pattern[i]) - int('a');
        mapping[item] = mapping[item] + 1;
    }
    cout << "Mapping vector: " << endl;
    printVector(mapping);

    for(int i=0; i<26; i++) {
        if(mapping[i] > 0) {
            count ++;
            strMapping[i] = mapping[i];
        }
        if(mapping[i] == 0) {
            strMapping[i] = 999999;
        }
    }
    cout << "String Mapping Vector: " << endl;
    printVector(strMapping);

    cout << "Non zero values: " << count << endl;

    int n = pattern.size();
    while(j<strValue.size()) {
        int item = int(strValue[j]) - int('a');
        if(j-i+1 < n) {
            strMapping[item]--;
            if(strMapping[item] == 0) {
                count--;
            }
            
            j++;
        } else if(j-i+1 == n) {
            strMapping[item]--;
            if(strMapping[item] == 0) {
                count--;
            }

            if(count == 0) {
                output++;
            }

            char iItem = int(strValue[i]) - int('a');
            if(strMapping[iItem] == 0) {
                // if mappint value is 0, we update count.
                count++;
            }
            strMapping[iItem]++;

            i++;
            j++;
        }
    }

    return output;
}

int main() {
    string strValue = "forxxorfxaofr";
    string pattern = "for";
    cout << "Input String is: " << strValue << endl;
    cout << "Pattern: " << pattern << endl;

    int output = countOccurancesOfAnagram(strValue, pattern);
    cout << "Output: " << output << endl;
}