/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true

Example 5:

Input: s = "([)]"

Output: false

Constraints:

    1 <= s.length <= 10^4
    s consists of parentheses only '()[]{}'.


 */
#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    bool result = true;

    // Use stack
    stack<char> pstack;
    int index = 0;
    while (index < s.size()) {
        char val = s[index];

        if (val == '(' || val == '[' || val == '{') {
            pstack.push(val);
        } else {
            if (pstack.empty()) {
                return false;
            }

            char topValue = pstack.top();
            if (val == ')' && topValue != '(') {
                return false;
            }

            if (val == ')' && topValue == '(') {
                pstack.pop();
            }

            if (val == ']' && topValue != '[') {
                return false;
            }

            if (val == ']' && topValue == '[') {
                pstack.pop();
            }

            if (val == '}' && topValue != '{') {
                return false;
            }

            if (val == '}' && topValue == '{') {
                pstack.pop();
            }
        }
        index++;
    }

    if (!pstack.empty()) {
        // stack not empty
        return false;
    }

    return result;
}

int main() {
    vector<string> inputs = {"()", "()[]{}", "(]", "([])", "([)]" };
    vector<bool> outputs = {true, true, false, true, false};

    for (int i=0; i<inputs.size(); i++) {
        cout << "Input string: " << inputs[i] << endl;

        bool output = isValid(inputs[i]);
        cout << "Output: " << output << endl;

        cout << "Expected output: " << outputs[i] << endl;
        cout << endl;
    }

    return 0;
}

// Remember to use stack in these kind of questions
