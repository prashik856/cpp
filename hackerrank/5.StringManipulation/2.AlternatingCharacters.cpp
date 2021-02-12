#include <bits/stdc++.h>

using namespace std;

// Complete the alternatingCharacters function below.
int alternatingCharacters(string s) {
    int alter = 0;
    for(int i=0; i<s.size(); i++){
        char currentCharacter = s[i];
        int repetitions = 0;
        for(int j=i+1; j<s.size(); j++){
            if(currentCharacter == s[j]){
                repetitions++;
            } else {
                break;
            }
        }
        i = i + repetitions;
        alter = alter + repetitions;
    }
    
    return alter;
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

        int result = alternatingCharacters(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
