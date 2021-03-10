#include <bits/stdc++.h>

using namespace std;

// Complete the stringConstruction function below.
int stringConstruction(string s) {
    int result = 0;
    unordered_map<char, int> dict;
    for(int i=0; i<s.size(); i++){
        char value = s[i];
        int subString = dict[value];
        if(subString == 0){
            // Substring not present
            dict[value] = 1;
            result++;
        } else if(subString == 1) {
            // Substring present
            continue;
        }
    }
    return result;
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

        int result = stringConstruction(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
