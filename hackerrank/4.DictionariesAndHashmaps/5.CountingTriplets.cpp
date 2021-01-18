#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

void printArray(vector<int> &arr){
    int sizeOfArray = arr.size();
    cout << "Current elements in array: " << endl;
    for(int i=0; i<sizeOfArray; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void printMap(unordered_map<int, int> &map){
    cout << "Current elements in map: " << endl;
    for(auto x: map){
        cout << "Key: " << x.first << " -> " << x.second << endl;
    }
}

void addInArray(vector<int> &arr, int key){
    arr.push_back(key);
}

int findIndex(vector<int> &arr, int key){
    int sizeOfArray = arr.size();
    int index = -1;
    for(int i=0; i<sizeOfArray; i++){
        if(arr[i] == key){
            index = i;
        }
    }
    return index;
}

void deleteFromArray(vector<int> &arr, int index){
    if(index == -1){
        return;
    } else {
        arr.erase(arr.begin()+index);
    }
}

int addInMap(unordered_map<int, int> &occurance, int element){
    int currentOccurance=0;
    int previousValue = occurance[element];
    if(previousValue == 0){
        occurance[element] = 1;
    } else {
        occurance[element] = previousValue + 1;
    }
    currentOccurance = occurance[element];
    return currentOccurance;
}

int deleteFromMap(unordered_map<int, int> &occurance, int element){
    int currentOccurance = -1;
    int previousValue = occurance[element];
    // Just remove occurance here
    // We will take care of adding in freq map.
    if(previousValue == 0){
        // There is nothing here
        // The element is not present.
        // just return
        return currentOccurance;
    } else {
        occurance[element] = previousValue - 1;
        currentOccurance = occurance[element];
    }
    return currentOccurance;
}

void addInFreqMap(unordered_map<int, int> &occurFreq, int elementOccurance){
    int previousValue = occurFreq[elementOccurance];
    if(elementOccurance == 0){
        return;
    }
    if(previousValue == 0){
        occurFreq[elementOccurance] = 1;
    } else {
        occurFreq[elementOccurance] = previousValue + 1;
    }
}

void deleteFromFreqMap(unordered_map<int, int> &occurFreq, int elementOccurance){
    int previousValue = occurFreq[elementOccurance];
    if(previousValue == 0){
        occurFreq[elementOccurance] = 0;
    } else {
        occurFreq[elementOccurance] = previousValue - 1;
    }
}

// Complete the freqQuery function below.
vector<int> freqQuery(vector<vector<int>> queries) {
    int sizeOfQueries = queries.size();
    vector<int> arr;
    vector<int> freq;
    unordered_map<int, int> occurance;
    unordered_map<int, int> occurFreq;
    for(int i=0; i<sizeOfQueries; i++){
        int operation = queries[i][0];
        int element = queries[i][1];
        
        if(operation == 1){
            // Add
            // Delete previous occurance
            // Add new occurance.
            //addInArray(arr, element);
            int elementOccurance = addInMap(occurance, element);
            deleteFromFreqMap(occurFreq, elementOccurance - 1);
            addInFreqMap(occurFreq, elementOccurance);
            // cout << "Add: " << element << endl;
            // cout << "Occurance Map: " << endl;
            // printMap(occurance);
            // cout << "Frequency Map: " << endl;
            // printMap(occurFreq);
            // cout << endl;
        }
        
        if(operation == 2){
            // Delete
            // 
            int index = findIndex(arr, element);
            //deleteFromArray(arr, index);
            int elementOccurance = deleteFromMap(occurance, element);
            if(elementOccurance == -1){
                // No element was deleted
                //cout << "Nothing to delete" << endl;
            } else {
                // the element was deleted
                deleteFromFreqMap(occurFreq, elementOccurance + 1);
                addInFreqMap(occurFreq, elementOccurance);
            }
            // cout << "Delete: " << element << endl;
            // cout << "Occurance Map: " << endl;
            // printMap(occurance);
            // cout << "Frequency Map: " << endl;
            // printMap(occurFreq);
            // cout << endl;
        }
        
        if(operation == 3){
            // show
            // printArray(arr);
            // cout << "Show Frequency of: " << element << endl;
            // cout << "Occurance Map: " << endl;
            // printMap(occurance);
            // cout << "Frequency Map: " << endl;
            // printMap(occurFreq);
            // cout << endl;
            int previousValue = occurFreq[element];
            if(previousValue == 0){
                freq.push_back(0);
            } else {
                freq.push_back(1);
            }
        }
    }
    
    return freq;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    vector<vector<int>> queries(q);

    for (int i = 0; i < q; i++) {
        queries[i].resize(2);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    vector<int> ans = freqQuery(queries);

    for (int i = 0; i < ans.size(); i++) {
        fout << ans[i];

        if (i != ans.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
