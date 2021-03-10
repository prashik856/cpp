#include <bits/stdc++.h>

using namespace std;

// Complete the gameOfThrones function below.
string gameOfThrones(string s) {
    int n = s.size();
    vector<int> count(26, 0);
    for(int i=0; i<s.size(); i++){
        int val = (int) s[i] - 97;
        count[val]++;
    }
    if(n%2 == 0){
        for(int i=0; i<26; i++){
            int value = count[i];
            if(value == 0){
                continue;
            } else {
                if(value % 2 != 0){
                    return "NO";
                }
            }
        }
    } else{
        // Odd numbers
        bool foundExtra = false;
        for(int i=0; i<26; i++){
            int value = count[i];
            if(value == 0){
                continue;
            } else {
                if(value % 2 != 0 && foundExtra){
                    // NO way
                    return "NO";
                }
                else if(value % 2 != 0 && !foundExtra){
                    foundExtra = true;
                }
            }
        }
    }
    
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
