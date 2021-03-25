#include <bits/stdc++.h>

using namespace std;

// Complete the separateNumbers function below.
void separateNumbers(string s) {
    //cout << "Input: " << s << endl;
    int n = s.size();
    int length = 1;
    int maxLength = n/2 + 1;
    bool found = false;
    long long firstNumber;
    while(length <= maxLength){
        //cout << "Current Length: " << length << endl;
        string firstNumberString;
        int index = 0;
        for(int i=index; i<index + length; i++){
            firstNumberString.push_back(s[i]);
        }
        if(firstNumberString[0] == '0'){
            found = false;
            break;
        }
        //cout << "First Number: " << firstNumberString << endl;
        firstNumber = stoll(firstNumberString);
        
        // What if there is no second number
        if(firstNumberString.size() == s.size()){
            found = false;
            break;
        }
        
        // Constructing String
        int count = 1;
        while(firstNumberString.size() < s.size()){
            long long nextNumber = firstNumber + count;
            //cout << "Next Number: " << nextNumber << endl;;
            string nextNumberString = to_string(nextNumber);
            for(int i=0; i<nextNumberString.size(); i++){
                firstNumberString.push_back(nextNumberString[i]);
            }
            //cout << "Current constructed string: " << firstNumberString << endl;
            count++;       
        }
        //cout << "Finally String constructed: " << firstNumberString << endl;
        
        // Check constructed string and string
        if(firstNumberString.size() == s.size()){
            if(firstNumberString == s){
                found = true;
                break;
            } else {
                found = false;
            }
        } else if(firstNumberString.size() != s.size()) {
            found = false;
        }
        length++;
    }
    //cout << "Found value: " << found << endl;
    if(found){
        cout << "YES " << firstNumber << endl;
    } else{
        cout << "NO" << endl;
    }
    //cout << endl;
}

int main()
{
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        separateNumbers(s);
    }

    return 0;
}
