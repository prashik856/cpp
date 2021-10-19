/*
Given an array of real numbers greater than zero in form of strings.

Find if there exists a triplet (a,b,c) such that 1 < a+b+c < 2 . 

 Return 1 for true or 0 for false.

Example:

Given [0.6, 0.7, 0.8, 1.2, 0.4] ,

You should return 1

as

0.6+0.7+0.4=1.7

1<1.7<2

Hence, the output is 1.

O(n) solution is expected.

Note: You can assume the numbers in strings don’t overflow the primitive data type and there are no leading zeroes in numbers. Extra memory usage is allowed.
*/

/*
Solution approach:
I got no clue.
Got the technique from this, understood it. But didn't understand how to get the range.
https://stackoverflow.com/questions/19557505/triplet-whose-sum-in-range-1-2
*/

/*
Compiling this file:
$ g++ -std=c++11 your_file.cpp -o your_program

*/

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<string> arr) {
    cout << "Give array is: " << endl;
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printSet(set<double> st){
    cout << "Given set is: " << endl;
    set<double>::iterator itr;
    for(itr=st.begin(); itr!=st.end(); itr++){
        cout << *itr << " ";
    }
    cout << endl;
}

int solve(vector<string> arr){
    int result = 0;

    set<double> x;
    set<double> y;
    set<double> z;

    // we need 3 ranges => x(0,2/3), y[2/3, 1], and z(1,2)
    for(int i=0; i<arr.size(); i++){
        double value = stod(arr[i]);

        if(value > 0 && value < 0.666667){
            x.insert(value);
        } 
        if(value >= 0.666667 && value <=1) {
            y.insert(value);
        }
        if(value >1 && value < 2) {
            z.insert(value);
        }
    }
    cout << "X: " << endl;
    printSet(x);

    cout << "Y: " << endl;
    printSet(y);

    cout << "Z: " << endl;
    printSet(z);

    double xmin1,xmin2,xmin3,xmax1,xmax2,xmax3;
    double ymin1,ymin2,ymax1;
    double zmin1;
    set<double>::iterator itr;
    // Now that we have our ranges
    // Test 1
    if(x.size() > 0 && y.size() > 0 && z.size()>0){
        zmin1 = *z.begin();
        xmin1 = *x.begin();
        ymin1 = *y.begin();

        if(xmin1 + ymin1 + zmin1 > 1 && xmin1 + ymin1 + zmin1 < 2){
            result = 1;
            return result;
        }
    }

    // Test 2
    if(x.size() >= 3){
        itr = x.end();
        itr--;
        xmax1 = *itr;
        itr--;
        xmax2 = *itr;
        itr--;
        xmax3 = *itr;
        if(xmax1 + xmax2 + xmax3 > 1 && xmax1 + xmax2 + xmax3 < 2){
            result = 1;
            return result;
        }
    }

    // Test 3
    if(x.size() >= 2 && z.size() >= 1){
        // xmin
        itr = x.begin();
        xmin1 = *itr;
        itr++;
        xmin2 = *itr;

        // zmin
        zmin1 = *z.begin();

        if(xmin1 + xmin2 + zmin1 > 1 && xmin1 + xmin2 + zmin1 < 2){
            result = 1;
            return result;
        }
    }

    // Test 4
    if(x.size() >= 1 && y.size() >= 2){
        // xmin
        xmin1 = *x.begin();

        // ymin
        itr = y.begin();
        ymin1 = *itr;
        itr++;
        ymin2 = *itr;

        if(ymin1 + ymin2 + xmin1 > 1 && ymin1 + ymin2 + xmin1 < 2){
            result = 1;
            return result;
        }
    }

    // Test 5
    if(x.size() >=2 && y.size() >=1){
        // xmin 
        itr = x.begin();
        xmin1 = *itr;
        itr++;
        xmin2 = *itr;

        // ymin
        ymin1 = *y.begin();

        // xmax
        itr = x.end();
        itr--;
        xmax1 = *itr;
        itr--;
        xmax2 = *itr;

        // ymax
        itr = y.end();
        itr--;
        ymax1 = *itr;

        if((xmin1 + xmin2 + ymax1 > 1 && xmin1 + xmin2 + ymax1 < 2) ||
            (xmax1 + xmax2 + ymin1 > 1 && xmax1 + xmax2 + ymin1 < 2)){
                result = 1;
                return result;
            }
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
        vector<string> arr;
        cout << "Given input array is: " << endl;
        for(int i=0; i<n; i++){
            string temp;
            cin >> temp;
            arr.push_back(temp);
            cout << temp << " ";
        }
        cout << endl;

        int result = solve(arr);
        cout << "Result: " << result << endl;;
        cout << endl;
    }
    return 0;
}
