/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

    I can be placed before V (5) and X (10) to make 4 and 9.
    X can be placed before L (50) and C (100) to make 40 and 90.
    C can be placed before D (500) and M (1000) to make 400 and 900.

Given a roman numeral, convert it to an integer.

Example 1:

Input: s = "III"
Output: 3
Explanation: III = 3.

Example 2:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Example 3:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.

Constraints:

    1 <= s.length <= 15
    s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
    It is guaranteed that s is a valid roman numeral in the range [1, 3999].

 */
#include<bits/stdc++.h>
using namespace std;

unordered_map<string, int> get_roman_dict() {
    unordered_map<string, int> roman_dict;
    roman_dict.insert({"I", 1});
    roman_dict.insert({"II", 2});
    roman_dict.insert({"III", 3});
    roman_dict.insert({"IV", 4});
    roman_dict.insert({"V", 5});
    roman_dict.insert({"VI", 6});
    roman_dict.insert({"VII", 7});
    roman_dict.insert({"VIII", 8});
    roman_dict.insert({"IX", 9});
    roman_dict.insert({"X", 10});
    roman_dict.insert({"XX", 20});
    roman_dict.insert({"XXX", 30});
    roman_dict.insert({"XL", 40});
    roman_dict.insert({"L", 50});
    roman_dict.insert({"LX", 60});
    roman_dict.insert({"LXX", 70});
    roman_dict.insert({"LXXX", 80});
    roman_dict.insert({"XC", 90});
    roman_dict.insert({"C", 100});
    roman_dict.insert({"CC", 200});
    roman_dict.insert({"CCC", 300});
    roman_dict.insert({"CD", 400});
    roman_dict.insert({"D", 500});
    roman_dict.insert({"DC", 600});
    roman_dict.insert({"DCC", 700});
    roman_dict.insert({"DCCC", 800});
    roman_dict.insert({"CM", 900});
    roman_dict.insert({"M", 1000});
    roman_dict.insert({"MM", 2000});
    roman_dict.insert({"MMM", 3000});
    return roman_dict;
}

int romanToInt(string s) {
    int result = 0;

    unordered_map<string, int> roman_dict = get_roman_dict();

    int index = s.size() - 1;
    string currentString = "";
    string previousString = "";
    while (index >= 0) {
        char val = s[index];
        currentString.insert(0, 1, val);
        // cout << "Previous String: " << previousString << endl;
        // cout << "Current String: " << currentString << endl;
        if (roman_dict.find(currentString) == roman_dict.end()) {
            // not found
            // check previous string
            // cout << "String not found in dict: " << endl;
            int integerValue = roman_dict[previousString];
            result = result + integerValue;
            // update both previous string and currentString
            previousString = "";
            currentString = "";
        } else {
            // found
            // update previous string
            // cout << "String found in dict: " << endl;
            previousString = currentString;
            if (index == 0) {
                result = result + roman_dict[previousString];
            }
            index--;
        }
        // cout << "Current result " << result << endl;
    }

    return result;
}

int main() {
    vector<string> inputs = {"III", "LVIII", "MCMXCIV"};
    vector<int> outputs = {3, 58, 1994};

    for (int i=0; i<inputs.size(); i++) {
        cout << "Input: " << inputs[i] << endl;
        int currentOutput = romanToInt(inputs[i]);
        cout << "Current Output is: " << currentOutput << endl;
        cout << "Expected output is: " << outputs[i] << endl << endl;
    }

    return 0;
}