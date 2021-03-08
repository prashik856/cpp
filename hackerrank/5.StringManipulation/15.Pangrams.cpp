#include <bits/stdc++.h>

using namespace std;

// Complete the pangrams function below.
string pangrams(string s) {
    vector<int> count(26, 0);
    for(int i=0; i<s.size(); i++){
        char charValue = tolower(s[i]);
        int value = (int) charValue - 97;
        count[value]++;
    }
    for(int i=0; i<count.size(); i++){
        if(count[i] == 0){
            return "not pangram";
        }
    }

    return "pangram";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
