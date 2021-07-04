#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'whatFlavors' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY cost
 *  2. INTEGER money
 */

void whatFlavors(vector<int> cost, int money) {
    // cout << "Money value is: " << money << endl;
    int n = cost.size();
    unordered_map< int, vector<int> > costHash;
    
    int id1 = -1;
    int id2 = -1;
    bool positionsFound = false;
    // Fill the hash map
    for(int i=0; i<n; i++){
        int value = cost[i];
        vector<int> hashValue = costHash[value];
        if(hashValue.size() <= 0){
            // no has entry present
            costHash[value] = vector<int>();
            costHash[value].push_back(i+1);
        } else {
            costHash[value].push_back(i+1);
        }
    }
    
    // Go through the array
    for(int i=0; i<n && !positionsFound; i++){
        int currentCost = cost[i];
        int moneyLeft = money - cost[i];
        id1 = i+1;
        // cout << "Money Left: " << moneyLeft << endl;
        if(moneyLeft <= 0){
            // cout << "Skipping. Money left is less than 0" << endl;
            continue;
        }
        
        // Check if there is any entry of moneyLeft in hashmap
        vector<int> hashValue = costHash[moneyLeft];
        // cout << "Size of HashValue: " << hashValue.size() << endl;
        if(hashValue.size() <= 0){
            // no recored present
            // cout << "No record of " << moneyLeft << " present." << endl;
            continue;
        } else {
            // record present
            // got throught the array
            for(int j=0; j<hashValue.size(); j++){
                int value = hashValue[j];
                if(value == id1){
                    // id1 != id2
                    continue;
                }
                id2 = value;
                // cout << "Position 1: " << id1 << endl;
                // cout << "Position 2: " << id2 << endl;
                positionsFound = true;
                break;
            }
        }
        // cout << endl;
    }
    // cout << endl;
    cout << id1 << " " << id2 << endl;
}

int main()
{
    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string money_temp;
        getline(cin, money_temp);

        int money = stoi(ltrim(rtrim(money_temp)));

        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string cost_temp_temp;
        getline(cin, cost_temp_temp);

        vector<string> cost_temp = split(rtrim(cost_temp_temp));

        vector<int> cost(n);

        for (int i = 0; i < n; i++) {
            int cost_item = stoi(cost_temp[i]);

            cost[i] = cost_item;
        }

        whatFlavors(cost, money);
    }

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
