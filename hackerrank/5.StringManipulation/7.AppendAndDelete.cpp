#include <bits/stdc++.h>

using namespace std;

// Complete the appendAndDelete function below.
string appendAndDelete(string s, string t, int k) {
    int l=0;
    if(t.size() > s.size()){
        for(int i=0; i<s.size(); i++){
            if(t[i] == s[i]){
                l++;
            }
            else{
                break;
            }
        }
    } else {
        for(int i=0; i<t.size(); i++){
            if(t[i]==s[i]){
                l++;
            }
            else{
                break;
            }
        }
    }
    
    int del = s.size() - l;
    int add = t.size() - l;
    int mink = add + del;
    //cout << "mink: " << mink << endl;
    if(k < mink){
        return "No";
    } else if(k == mink){
        return "Yes";
    } else if( k > mink){
        int diff = k - mink;
        if(diff >= 2*l){
            return "Yes";
        }
        if(diff % 2 == 0){
            return "Yes";
        } else {
            return "No";
        }
    }
    return "No";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string t;
    getline(cin, t);

    int k;
    cin >> k;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string result = appendAndDelete(s, t, k);

    fout << result << "\n";

    fout.close();

    return 0;
}
