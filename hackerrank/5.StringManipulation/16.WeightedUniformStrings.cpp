#include <bits/stdc++.h>

using namespace std;

// Complete the weightedUniformStrings function below.
vector<string> weightedUniformStrings(string s, vector<int> queries) {
    unordered_map<long, long> weightSet;
    vector<string> result;
    long previousWeight=0;
    long currentWeight;
    long count = 0;    
    for(int i=0; i<s.size(); i++){
        currentWeight = (long) s[i] - 97 + 1;
        // cout << "CurrentWeight: " << currentWeight << endl;
        // cout << "PreviousWeight: " << previousWeight << endl;
        if(previousWeight == 0){
            // First character
            count++;
            previousWeight = currentWeight;
            // Add this to our map
            weightSet[currentWeight] = 1;
            //cout << "Storing Value: " << currentWeight << endl;
        }
        
        else if(currentWeight == previousWeight){
            // Not first character.
            // Repeat count times;
            count++;
            weightSet[currentWeight*count] = 1;
            //cout << "Storing Value: " << currentWeight*count << endl;
        }
        
        else if(currentWeight != previousWeight){
            // First time occurence of character.
            count = 1;
            weightSet[currentWeight*count] = 1;
            //cout << "Storing Value: " << currentWeight*count << endl;
            previousWeight = currentWeight;
        }
        cout << endl;
    }
    
    // unordered_map<long,long> :: iterator itr;
    // for(itr = weightSet.begin(); itr!=weightSet.end(); itr++){
    //     cout << "First: " << itr->first << " Second: " << itr->second << endl;
    // }
    
    for(int i=0; i<queries.size(); i++){
        int value = queries[i];
        int present = weightSet[value];
        if(present == 1){
            result.push_back("Yes");
        }
        else{
            result.push_back("No");
        }
    }
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    int queries_count;
    cin >> queries_count;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> queries(queries_count);

    for (int i = 0; i < queries_count; i++) {
        int queries_item;
        cin >> queries_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        queries[i] = queries_item;
    }

    vector<string> result = weightedUniformStrings(s, queries);

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
