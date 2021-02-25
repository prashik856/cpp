#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

void printArray(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Complete the cutTheSticks function below.
vector<int> cutTheSticks(vector<int> arr) {
    vector<int> result;
    sort(arr.begin(), arr.end(), greater<int>());
    //printArray(arr);
    int n = arr.size();
    int maxValue;
    int minValue;
    result.push_back(n);
    while(true){
        maxValue = arr[0];
        minValue = arr[arr.size() - 1];
        
        // If all values are equal, discard them all
        if(maxValue == minValue){
            break;
        }
        
        // Delete min value from array
        for(int i=0; i<arr.size(); i++){
            arr[i] = arr[i] - minValue;
        }
        
        // Delete all values which are zero
        int index = arr.size() - 1;
        while(true){
            if(arr[index] == 0){
                arr.pop_back();
                index--;
            }
            else {
                break;
            }
        }
        //printArray(arr);
        result.push_back(arr.size());
    }
    
    return result;
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

    vector<int> result = cutTheSticks(arr);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
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
