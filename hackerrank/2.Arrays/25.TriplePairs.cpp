#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the triplets function below.
long long triplets(vector<int> a, vector<int> b, vector<int> c) {
    long long result = 0;
    set<int> setA;
    set<int> setB;
    set<int> setC;
    for(int i=0; i<a.size(); i++){
        setA.insert(a[i]);
    }
    for(int i=0; i<b.size(); i++){
        setB.insert(b[i]);
    }
    for(int i=0; i<c.size(); i++){
        setC.insert(c[i]);
    }
    a = vector<int>();
    b = vector<int>();
    c = vector<int>();
    set<int> :: iterator it;
    for(it = setA.begin(); it != setA.end(); it++){
        a.push_back(*it);
    }
    for(it = setB.begin(); it != setB.end(); it++){
        b.push_back(*it);
    }
    for(it = setC.begin(); it != setC.end(); it++){
        c.push_back(*it);
    }
    
    for(int i=0; i<b.size(); i++){
        long long countA = 0;
        long long countC = 0;
        int indexA = 0;
        int indexC = 0;
        
        int value = b[i];
        vector<int>:: iterator it;
        // if value is found, it returns
        cout << "Value to find: " << value << endl;
        if(binary_search(a.begin(), a.end(), value)){
            // element is found and it is present in 
            // a.begin() - it
            // cout << "Value found in A" << endl;
            it = lower_bound(a.begin(), a.end(), value);
            countA = it - a.begin() + 1;
            // cout << "Value of countA is : " << countA << endl;
        } else {
            // element not found and
            // a.begin() to it - 1 is the value we need
            // cout << "Value not found in A" << endl;
            it = lower_bound(a.begin(), a.end(), value);
            countA = it - a.begin();  
            // cout << "Value of countA is : " << countA << endl;
        }
        
        // if value is found, it returns
        if(binary_search(c.begin(), c.end(), value)){
            // element is found and it is present in 
            // a.begin() - it
            // cout << "Value found in C" << endl;
            it = lower_bound(c.begin(), c.end(), value);
            countC = it - c.begin() + 1;
            // cout << "Value of countC is : " << countC << endl; 
        } else {
            // element not found and
            // a.begin() to it - 1 is the value we need
            // cout << "Value not found in C" << endl;
            it = lower_bound(c.begin(), c.end(), value);
            countC = it - c.begin();    
            // cout << "Value of countC is : " << countC << endl;
        }
        
        result = countA*countC + result;
        // cout << endl;
    }
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string lenaLenbLenc_temp;
    getline(cin, lenaLenbLenc_temp);

    vector<string> lenaLenbLenc = split_string(lenaLenbLenc_temp);

    int lena = stoi(lenaLenbLenc[0]);

    int lenb = stoi(lenaLenbLenc[1]);

    int lenc = stoi(lenaLenbLenc[2]);

    string arra_temp_temp;
    getline(cin, arra_temp_temp);

    vector<string> arra_temp = split_string(arra_temp_temp);

    vector<int> arra(lena);

    for (int i = 0; i < lena; i++) {
        int arra_item = stoi(arra_temp[i]);

        arra[i] = arra_item;
    }

    string arrb_temp_temp;
    getline(cin, arrb_temp_temp);

    vector<string> arrb_temp = split_string(arrb_temp_temp);

    vector<int> arrb(lenb);

    for (int i = 0; i < lenb; i++) {
        int arrb_item = stoi(arrb_temp[i]);

        arrb[i] = arrb_item;
    }

    string arrc_temp_temp;
    getline(cin, arrc_temp_temp);

    vector<string> arrc_temp = split_string(arrc_temp_temp);

    vector<int> arrc(lenc);

    for (int i = 0; i < lenc; i++) {
        int arrc_item = stoi(arrc_temp[i]);

        arrc[i] = arrc_item;
    }

    long long ans = triplets(arra, arrb, arrc);

    fout << ans << "\n";

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
