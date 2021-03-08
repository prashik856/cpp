#include <bits/stdc++.h>

using namespace std;

// Complete the funnyString function below.
string funnyString(string s) {
    string normalString;
    for(int i=s.size()-1; i>=0; i--){
        normalString.push_back(s[i]);
    }
    s.reserve();
    // cout << "Normal String: " << normalString << endl;
    // cout << "Reverse String: " << s << endl;
    for(int i=0; i<s.size() - 1; i++){
        int normalFront1 = (int) normalString[i];
        int normalFront2 = (int) normalString[i+1];
        int normalDiff = abs(normalFront1 - normalFront2);
        
        int reverseFront1 = (int) s[i];
        int reverseFront2 = (int) s[i+1];
        int reverseDiff = abs(reverseFront1 - reverseFront2);
        
        if(normalDiff != reverseDiff){
            return "Not Funny";
        }
        else{
            continue;
        }
    }
    
    return "Funny";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        string result = funnyString(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
