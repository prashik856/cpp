#include <bits/stdc++.h>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2) {
    unordered_map<char, int> umap;
    // store the first string
    for(int i=0; i<s1.size(); i++){
        char currentCharacter = s1[i];
        int previousValue = umap[currentCharacter];
        if(previousValue == 0){
            umap[currentCharacter] = 1;
        } else {
            umap[currentCharacter] = previousValue + 1;
        }
    }
    
    // We created our hashmap
    // Go through string 2
    for(int i=0; i<s2.size(); i++){
        char currentCharacter = s2[i];
        int valueInMap = umap[currentCharacter];
        if(valueInMap == 0){
            continue;
        } else if(valueInMap > 0){
            return "YES";
        }
    }
    
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
