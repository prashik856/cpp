/*
key=str(tempa) + "-" + str(tempb)
        
        if(tempa >= a or tempb >= b):
            return 0
        if(tempa == a-1 and tempb == b-1):
            return 1
        if(key in allWays):
            return allWays[key]

        result = self.getResult(tempa + 1, tempb, a, b) + self.getResult(tempa, tempb+1, a, b)
        allWays[key] = result
        return result
*/
#include<bits/stdc++.h>
using namespace std;
int solve(int tempa, int tempb, int A, int B, unordered_map<string, int> allWays) {
    string key = to_string(tempa) + "-" + to_string(tempb);

    if(tempa >= A || tempb >= B) {
        return 0;
    }
    if(tempa == A-1 && tempb == B-1) {
        return 1;
    }

    if(allWays.find(key) != allWays.end()){
        return allWays[key];
    }

    int result = solve(tempa + 1, tempb, A, B, allWays) + solve(tempa, tempb + 1, A, B, allWays);
    allWays[key] = result;

    return result;
}

int uniquePaths(int A, int B) {
    unordered_map<string, int> allWays;
    return solve(0,0,A,B,allWays);
}

int main(){
    int A = 15, B=12;
    int result = uniquePaths(A, B);
    cout << "Result: " << result << endl;
    return 0;
}

