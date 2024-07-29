/**
 * Pick Toys
 * 
 * Flow:
 * 1. Problem Statement - Input and Output
 * 2. Identification
 * 3. Reduce it into something that we have already solved.
 * 
 * Jon goes to mall with his mother. He sees some toys in a rack.
 * Jon can buy toys only when he can buys toys in a line (cannot pick random toys),
 * and he can buy only two types of toys.
 * At the moment, the number of types of toys cannot exceed more than two.
 * Jon can buy unlimited number of toys.
 * 
 * E.g. one type toy: car, another type toy: animal.
 * So, jon can buy unlimited number of toys of two types.
 * 
 * Output:
 * Jon wants the maximum number of toys. We need to maximize the number of toys with respecting
 * the given conditions.
 * Output: int: number of toys
 * 
 * E.g.
 * Input: String: abaccab
 * Every letter indicates a type of toy.
 * Output: 4 [acca]
 * 
 * This problem is like longest substring with 2 unique characters!
 */
#include<bits/stdc++.h>
using namespace std;

int pickToys(string &input) {
    int output = 0;

    int i=0,j=0;
    unordered_map<char, int> mapping = unordered_map<char,int>();
    while(j<input.size()) {
        char item = input[j];
        
        if(mapping.size() < 2) {
            // process j
            if(mapping.find(item) == mapping.end()) {
                mapping[item] = 1;
            } else {
                mapping[item] = mapping[item] + 1;
            }
            j++;
        } else if(mapping.size() == 2) {
            int width = j - i;

            // potential output
            if(width > output) {
                output = width;
            }

            // process j
            if(mapping.find(item) == mapping.end()) {
                mapping[item] = 1;
            } else {
                mapping[item] = mapping[item] + 1;
            }
            j++;
        } else if(mapping.size() > 2) {
            while(mapping.size() > 2) {
                char iValue = input[i];
                if(mapping[iValue] == 1) {
                    mapping.erase(iValue);
                } else {
                    mapping[iValue] = mapping[iValue] - 1;
                }
                i++;
            }
        }

        if(j == input.size()) {
            // On the last element, process the map
            if(mapping.size() == 2) {
                int width = j - i;
                if(width > output) {
                    output = width;
                }
            }
        }
    }

    return output;
}

int main() {
    string input = "aabacbebebe";
    cout << "Input: " << input << endl;

    int output = pickToys(input);
    cout << "Output: " << output << endl;
    return 0;
}