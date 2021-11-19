/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P.......A........H.......N
..A..P....L....S....I...I....G
....Y.........I........R
And then read line by line: PAHNAPLSIIGYIR

Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR"
**Example 2 : **

ABCD, 2 can be written as

A....C
...B....D
and hence the answer would be ACBD.
*/

/*
Solution Approach:
Easy enough. 
Take care when b == 1
*/
#include<bits/stdc++.h>
using namespace std;

void print2DVectors(vector<string> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

string solve(string a, int b){
    string result;
    vector<string> zig(b);
    if(b == 1){
        return a;
    }
    int n = a.size();
    bool increase = true;
    bool decrease = false;
    int index = 0;
    for(int i=0; i<n; i++){
        zig[index].push_back(a[i]);
        
        if(increase){
            index++;
        } else {
            index--;
        }

        if(increase && (index == b)){
            index = b-2;
            increase = false;
            decrease = true;
        }

        if(decrease && (index == -1)){
            index = 1;
            increase = true;
            decrease = false;
        }
    }
    // print2DVectors(zig);
    for(int i=0; i<zig.size(); i++){
        for(int j=0; j<zig[i].size(); j++){
            result.push_back(zig[i][j]);
        }
    }

    return result;
}

int main(){
    string a = "kHAlbLzY8Dr4zR0eeLwvoRFg9r23Y3hEujEqdio0ctLh4jZ1izwLh70R7SAkFsXlZ8UlghCL95yezo5hBxQJ1Td6qFb3jpFrMj8pdvP6M6k7IaXkq21XhpmGNwl7tBe86eZasMW2BGhnqF6gPb1YjCTexgCurS";
    int b = 3;
    string result = solve(a, b);
    cout << "Result is: " << result << endl;
    return 0;
}