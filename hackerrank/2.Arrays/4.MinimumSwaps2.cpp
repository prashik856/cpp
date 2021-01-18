#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the minimumSwaps function below.
int minimumSwaps(vector<int> arr) {
    int requiredSwaps = 0;
    int sizeOfVector = arr.size();
    vector<bool> visited(sizeOfVector, false);
    for(int i=0; i<sizeOfVector; i++){
        int currentPosition = arr[i];
        if(visited[currentPosition - 1]){
            continue;
        }
        int actualPosition = i+1;
        visited[currentPosition - 1] = true;
        cout << "Visiting Position: " << currentPosition << endl;
        cout << "Current Position: " << currentPosition << endl ;
        int itemInActualPosition = arr[currentPosition-1];
        cout << "Item in actual Position: " << itemInActualPosition << endl;
        int cycleCount = 0;
        if(currentPosition == actualPosition){
            // No need of swap
            continue;
        }
        while(!visited[itemInActualPosition - 1]){
            currentPosition = arr[currentPosition - 1];
            itemInActualPosition = arr[currentPosition - 1];
            visited[currentPosition - 1] = true;
            cout << "Visitin Position: " << currentPosition << endl;
            cout << "Current Position after visiting: " << currentPosition << endl ;
            cout << "Item in actual Position after visiting: " << itemInActualPosition << endl;
            cycleCount++;
        }
        requiredSwaps = requiredSwaps + cycleCount;
    }
    
    return requiredSwaps;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int res = minimumSwaps(arr);

    fout << res << "\n";

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
