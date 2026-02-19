/*
Seven different symbols represent Roman numerals with the following values:
Symbol	Value
I	1
V	5
X	10
L	50
C	100
D	500
M	1000

Roman numerals are formed by appending the conversions of decimal place values from highest to lowest. Converting a decimal place value into a Roman numeral has the following rules:
1. If the value does not start with 4 or 9, select the symbol of the maximal value that can be subtracted from the input, append that symbol to the result, subtract its value, and convert the remainder to a Roman numeral.
2. If the value starts with 4 or 9 use the subtractive form representing one symbol subtracted from the following symbol, for example, 4 is 1 (I) less than 5 (V): IV and 9 is 1 (I) less than 10 (X): IX. Only the following subtractive forms are used: 4 (IV), 9 (IX), 40 (XL), 90 (XC), 400 (CD) and 900 (CM).
3. Only powers of 10 (I, X, C, M) can be appended consecutively at most 3 times to represent multiples of 10. You cannot append 5 (V), 50 (L), or 500 (D) multiple times. If you need to append a symbol 4 times use the subtractive form.

Given an integer, convert it to a Roman numeral.

Example 1:

Input: num = 3749

Output: "MMMDCCXLIX"

Explanation:

3000 = MMM as 1000 (M) + 1000 (M) + 1000 (M)
 700 = DCC as 500 (D) + 100 (C) + 100 (C)
  40 = XL as 10 (X) less of 50 (L)
   9 = IX as 1 (I) less of 10 (X)
Note: 49 is not 1 (I) less of 50 (L) because the conversion is based on decimal places


Example 2:

Input: num = 58

Output: "LVIII"

Explanation:

50 = L
 8 = VIII

Example 3:

Input: num = 1994

Output: "MCMXCIV"

Explanation:

1000 = M
 900 = CM
  90 = XC
   4 = IV

Constraints:
1 <= num <= 3999
 */
#include<bits/stdc++.h>
using namespace std;

unordered_map<int, string> get_roman_dict() {
 unordered_map<int, string> roman_dict;
 roman_dict.insert({1, "I"});
 roman_dict.insert({2, "II"});
 roman_dict.insert({3, "III"});
 roman_dict.insert({4, "IV"});
 roman_dict.insert({5, "V"});
 roman_dict.insert({6, "VI"});
 roman_dict.insert({7, "VII"});
 roman_dict.insert({8, "VIII"});
 roman_dict.insert({9, "IX"});
 roman_dict.insert({10, "X"});
 roman_dict.insert({20, "XX"});
 roman_dict.insert({30, "XXX"});
 roman_dict.insert({40, "XL"});
 roman_dict.insert({50, "L"});
 roman_dict.insert({60, "LX"});
 roman_dict.insert({70, "LXX"});
 roman_dict.insert({80, "LXXX"});
 roman_dict.insert({90, "XC"});
 roman_dict.insert({100, "C"});
 roman_dict.insert({200, "CC"});
 roman_dict.insert({300, "CCC"});
 roman_dict.insert({400, "CD"});
 roman_dict.insert({500, "D"});
 roman_dict.insert({600, "DC"});
 roman_dict.insert({700, "DCC"});
 roman_dict.insert({800, "DCCC"});
 roman_dict.insert({900, "CM"});
 roman_dict.insert({1000, "M"});
 roman_dict.insert({2000, "MM"});
 roman_dict.insert({3000, "MMM"});
 return roman_dict;
}

string intToRoman(int num) {
 int val = 1000;
 int originalNum = num;
 string result = "";
 unordered_map<int, string> roman_dict = get_roman_dict();

 while (originalNum > 0 && val > 0) {
  int quotient = originalNum/ val;
  if (quotient > 0) {
   int value_to_search = quotient * val;
   originalNum = originalNum - value_to_search;
   // it is guaranteed that the value will be here
   string roman_of_vts = roman_dict[value_to_search];
   result = result + roman_of_vts;
  }
  val = val/10;
 }
 return result;
}

int main() {
 int input = 1994;
 cout << "Input value is: " << input << endl;

 string result = intToRoman(input);
 cout << "Result: " << result << endl;

 return 0;
}