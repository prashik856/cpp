#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumBribes function below.
void minimumBribes(vector<int> q) {
    // Since we only need to calculate the number of bribes
    int noOfBribes = 0;
    int isNotFine = 0;
    int sizeOfArray = q.size();
    vector<int> line(sizeOfArray);
    int maxDistance = -999999;
    for(int i=0; i<sizeOfArray; i++){
        line[i] = i+1;
        int distance = q[i] - line[i];
        if(distance > 2){
            // too chaotic
            isNotFine = 1;
            break;
        }
        maxDistance = max(maxDistance, abs(distance));
    }
    // Max movement is 2
    maxDistance = maxDistance + 2;
    
    // Calculate distance from normal line
    for(int i=0; i<sizeOfArray && isNotFine == 0; i++){
        int count = 0;
        for(int j=i+1; j<= i + maxDistance && j < sizeOfArray; j++){
            if(q[i] > q[j]){
                count++;
            }
            if(count > 2){
                isNotFine = 1;
                break;
            }
        }
        noOfBribes = noOfBribes + count;
    }
    
    if(isNotFine == 1){
        cout << "Too chaotic" << endl;
    }
    else{
        cout << noOfBribes << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string q_temp_temp;
        getline(cin, q_temp_temp);

        vector<string> q_temp = split_string(q_temp_temp);

        vector<int> q(n);

        for (int i = 0; i < n; i++) {
            int q_item = stoi(q_temp[i]);

            q[i] = q_item;
        }

        minimumBribes(q);
    }

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
