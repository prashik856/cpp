#include <bits/stdc++.h>

using namespace std;

// Complete the superReducedString function below.
string superReducedString(string s) {
    string result;
    bool runLoop = true;
    bool pairFound = false;
    while(runLoop && s.size() > 0){
        for(int i=0; i<s.size()-1; i++){
            if(s[i] == s[i+1]){
                // Delete i and i + 1
                s.erase(i, 2);
                runLoop = true;
                break;
            }
            runLoop = false;
        } 
        
    }
    if(s.size() == 0){
        return "Empty String";
    }
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
