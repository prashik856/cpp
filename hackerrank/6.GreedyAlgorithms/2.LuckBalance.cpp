#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void printArray(vector< vector<int>> arr){
    for(int i=0; i<arr.size(); i++){
        cout << "Luck: " << arr[i][0] << "| Imp: " << arr[i][1] << endl;
    }
    cout << endl;
}

// Complete the luckBalance function below.
int luckBalance(int k, vector<vector<int>> contests) {
    int result = 0;
    cout << "Can Loose: " << k << endl;
    //printArray(contests);
    sort(contests.begin(), contests.end());
    //printArray(contests);
    for(int i=contests.size()-1; i>=0; i--){
        int luck = contests[i][0];
        int imp = contests[i][1];
        if(imp == 0){
            result = result + luck;
        }
        else{
            if(k>0){
                result = result + luck;
                k--;
            } else {
                result = result - luck;
            }
        }
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    vector<vector<int>> contests(n);
    for (int i = 0; i < n; i++) {
        contests[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> contests[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = luckBalance(k, contests);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
