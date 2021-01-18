#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

void printBefore(unordered_map<long, long> &before){
    cout << "Values stored in Before: " << endl;
    for(auto x:before){
        cout << "Key: " << x.first << " -> " << x.second << endl;
    }
    cout << endl;
}

void printAfter(unordered_map<long, long> &after){
    cout << "Values stored in After: " << endl;
    for(auto x:after){
        cout << "Key: " << x.first << " -> " << x.second << endl;
    }
    cout << endl;
}

void initialize(vector<long> &arr, 
                int sizeOfArray, 
                unordered_map<long, long> &before,
                unordered_map<long, long> &after){
    for(int i=0; i<sizeOfArray; i++){
        // Current value of arr
        long val = arr[i];
        
        // Set before to 0
        before[val] = 0;
        
        // get previous value of after
        long previousValue = after[val];
        if(previousValue == 0){
            // First time
            after[val] = 1;
        } else {
            after[val] = after[val] + 1;
        }
    }                    
}

// Complete the countTriplets function below.
long countTriplets(vector<long> arr, long r) {
    long noOfTriplets = 0;
    int sizeOfArray = arr.size();
    if(sizeOfArray==1){
        return noOfTriplets;
    }
    else if(sizeOfArray==2){
        return noOfTriplets;
    }
    // Initialize before array and after array
    unordered_map<long, long> before;
    unordered_map<long, long> after;
    
    initialize(arr, 
                sizeOfArray, 
                before, 
                after);
    printBefore(before);
    printAfter(after);
    
    // Our array is initialized.
    for(int i=0; i<sizeOfArray; i++){
        // Store value of ar
        long value_ar = arr[i];
        
        // Decrease the value from after
        after[value_ar] = after[value_ar] - 1;
        
        // Check if ar is divisible by r
        if(value_ar % r == 0){
            // Divisible 
            
            // Get value of a
            long value_a = value_ar / r;
            
            // Check if value_a is present in before
            long b_count = before[value_a];
            
            if(b_count <= 0){
                // continue here. Not a triplet.
                before[value_ar] = before[value_ar] + 1;
                continue;
            }
            
            // Get value of ar
            long value_arr = value_ar * r;
            
            // Check if value_arr is present in after
            long a_count = after[value_arr];
            
            if(a_count <= 0){
                // Not a triplet
                before[value_ar] = before[value_ar] + 1;
                continue;
            }
            
            // Loop still running.
            // Possibility of triplet
            
            // No of available triplets for this item 
            long availableTriplets = a_count * b_count;
            cout << "Available Triplets: " << availableTriplets << endl;
            
            // Increase the value of noOfTriplets
            noOfTriplets = noOfTriplets + availableTriplets;
        }
        
        // Update before
        before[value_ar] = before[value_ar] + 1;
        
    }

    return noOfTriplets;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nr_temp;
    getline(cin, nr_temp);

    vector<string> nr = split(rtrim(nr_temp));

    int n = stoi(nr[0]);

    long r = stol(nr[1]);

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<long> arr(n);

    for (int i = 0; i < n; i++) {
        long arr_item = stol(arr_temp[i]);

        arr[i] = arr_item;
    }

    long ans = countTriplets(arr, r);

    fout << ans << "\n";

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
