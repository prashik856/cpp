/*
Given a list of non negative integers, arrange them such that they form the largest number.

For example:

Given [3, 30, 34, 5, 9], the largest formed number is 9534330.

Note: The result may be very large, so you need to return a string instead of an integer.
*/

/*
Solution Approach in Interviewbit:
Sorting all numbers in descending order is the simplest solution that occurs to us. But this doesn’t work.

For example, 548 is greater than 60, but in the output, 60 comes before 548. 
As a second example, 98 is greater than 9, but 9 comes before 98 in the output.

The solution is to use any comparison based sorting algorithm. 
Thus, instead of using the default comparison, write a comparison function myCompare() and use it to sort numbers.

Given two numbers X and Y, how should myCompare() decide which number to put first – 
we compare two numbers XY (Y appended at the end of X) and YX (X appended at the end of Y).

If XY is larger, then, in the output, X should come before Y, else Y should come before X.

For example, let X and Y be 542 and 60. 
To compare X and Y, we compare 54260 and 60542. Since 60542 is greater than 54260, we put Y first.
*/
/*
Interview bit solution:
static bool compareNum(string a, string b) {
    return a + b > b + a;
}

string Solution::largestNumber(const vector<int> &A) {
string result;
vector<string> str;
// Converted all numbers to string
for (int i = 0; i < A.size(); i++) {
    str.push_back(to_string(A[i]));
}
// Sort them
sort(str.begin(), str.end(), compareNum);

// Push inside the result
for (int i = 0; i < str.size(); i++) {
    result += str[i];
}

int pos = 0;
// What does this do?
// Removing extra zeroes
while (result[pos] == '0' && pos + 1 < result.size()){
    pos++;
} 
return result.substr(pos);

}
*/
#include<bits/stdc++.h>
using namespace std;

unordered_map<int, int> decimalsMap;
void printVector(vector<int> arr) {
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print2DVector(vector< vector<int> > arr) {
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int getDecimals(int a) {
    int result = 0;
    if(a < 10) {
        return 1;
    }

    while(a>0){
        a = a / 10;
        result++;
    }
    return result;
}

bool myCompare(int a, int b) {
    unsigned long long ab;
    unsigned long long ba;

    int lenA = decimalsMap[a];
    int lenB = decimalsMap[b];

    long long numberToMultiplyA = (long long) pow(10,lenA);
    long long numberToMultiplyB = (long long) pow(10,lenB);

    ab = a * numberToMultiplyB;
    ab += b;

    ba = b * numberToMultiplyA;
    ba += a;

    if(ab > ba) {
        return true;
    } else {
        return false;
    }
}

string solve(vector<int> arr) {
    string result;
    int n = arr.size();
    int maxValue = numeric_limits<int>::min();
    for(int i=0; i<arr.size(); i++){
        int length = getDecimals(arr[i]);
        decimalsMap[arr[i]] = length;
        maxValue = max(maxValue, arr[i]);
    }
    if(maxValue == 0){
        return "0";
    }
    sort(arr.begin(), arr.end(), myCompare);
    //printVector(arr);

    for(int i=0; i<arr.size(); i++) {
        result = result + to_string(arr[i]);
    }

    int pos = 0;
    // What does this do?
    while (result[pos] == '0' && pos + 1 < result.size()){
        pos++;
    } 

    return result;
}

int main() {
    int t;
    cin >> t;
    for(int z=0; z<t; z++) {
        int n; 
        cin >> n;
        cout << n << endl;
        vector<int> arr;
        cout << "Given input array is: " << endl;
        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            arr.push_back(temp);
            cout << temp << " ";
        }
        cout << endl;

        string result = solve(arr);
        cout << "Result: "<< result << endl;
        cout << endl;
    }
    return 0;
}
