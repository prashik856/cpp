#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the maximumPerimeterTriangle function below.
vector<int> maximumPerimeterTriangle(vector<int> sticks) {
    vector<int> result;
    sort(sticks.begin(), sticks.end());
    int n = sticks.size();
    int maxPerimeter = numeric_limits<int>::min();
    for(int i=n-1; i>=0; i--){
        int val1 = sticks[i];
        for(int j=i-1; j>=0; j--){
            int val2 = sticks[j];
            for(int k=j-1; k>=0; k--){
                int val3 = sticks[k];
                int sum12 = val1 + val2;
                int sum23 = val2 + val3;
                int sum13 = val1 + val3;
                if(sum12 > val3 && sum23 > val1 && sum13 > val2){
                    // Found it
                    int peri = val1 + val2 + val3;
                    if(peri > maxPerimeter){
                        // new values here
                        maxPerimeter = peri;
                        result.clear();
                        result.push_back(val3);
                        result.push_back(val2);
                        result.push_back(val1);
                    }
                }
            }
        }
    }
    
    if(result.size() == 0){
        result.push_back(-1);
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string sticks_temp_temp;
    getline(cin, sticks_temp_temp);

    vector<string> sticks_temp = split_string(sticks_temp_temp);

    vector<int> sticks(n);

    for (int i = 0; i < n; i++) {
        int sticks_item = stoi(sticks_temp[i]);

        sticks[i] = sticks_item;
    }

    vector<int> result = maximumPerimeterTriangle(sticks);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

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
