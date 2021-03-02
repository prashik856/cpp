#include <bits/stdc++.h>

using namespace std;

// Complete the happyLadybugs function below.
string happyLadybugs(string b) {
    int emptyCount = 0;
    vector<int> count(26,0);
    for(int i=0; i<b.size(); i++){
        if(b[i] == '_'){
            emptyCount++;
        } else {
            int value = (int)b[i];
            int index = value - 65;
            count[index]++;    
        }
    }
    
    if(emptyCount == b.size()){
        return "YES";
    }
    
    for(int i=0; i<count.size(); i++){
        int value = count[i];
        if(value == 1){
            return "NO";
        }
    }
    
    if(emptyCount != 0){
        // emptyCount is not zero
        // And every count is either zero or 1
        return "YES";
    } else if(emptyCount == 0){
        // If every adjacent guy
        for(int i=1; i<b.size()-1; i++){
            char value = b[i];
            char leftValue = b[i-1];
            char rightValue = b[i+1];
            if(value != leftValue && value != rightValue){
                return "NO";
            }
            if(value == leftValue || value == rightValue){
                continue;
            }
        }
    }
    
    return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int g;
    cin >> g;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int g_itr = 0; g_itr < g; g_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string b;
        getline(cin, b);

        string result = happyLadybugs(b);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
