#include <bits/stdc++.h>

using namespace std;

// Complete the reverseShuffleMerge function below.
string reverseShuffleMerge(string s) {
    string result;
    vector<int> count(26,0);
    for(int i=0; i<s.size(); i++){
        int val = s[i];
        count[val-97]++;
    }
    // for(int i=0; i<count.size(); i++){
    //     cout << count[i] << " ";
    // }
    // cout << endl;
    for(int i=0; i<count.size(); i++){
        if(count[i] == 0){
            continue;
        } else {
            int val = count[i];
            val = val/2;
            for(int j=0; j<val; j++){
                int character = i + 97;
                result.push_back((char)character);
            }
        }
    }
    cout << result << endl;
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = reverseShuffleMerge(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
