#include <bits/stdc++.h>

using namespace std;

// Complete the kaprekarNumbers function below.
void kaprekarNumbers(int p, int q) {
    vector<long> result;
    for(int i=p; i<=q; i++){
        long val = i;
        //cout << "Value: " << val << endl;
        
        // Get d
        string valString = to_string(val);
        //cout << "Value converted to string: " << valString << endl;
        long d = valString.size();
        //cout << "Number of digits in value: " << d << endl;
        
        // Square it
        long square = val*val;
        //cout << "Square of Value: " << square << endl;
        // Convert to string
        string squareString = to_string(square);
        //cout << "String value of square: " << squareString << endl;
        
        // Take substring till d
        string l;
        string r;
        for(int j=0; j<squareString.size() - d; j++){
            l.push_back(squareString[j]);
        }
        
        for(int j=squareString.size() - d; j<squareString.size(); j++){
            r.push_back(squareString[j]);
        }
        
        
        // Convert the numbers back
        long lNum = -1;
        long rNum = -1;
        
        if(l.size() > 0){
            lNum = stoi(l);
        }
        
        if(r.size() > 0){
            rNum = stoi(r);
        }
        
        //cout << lNum << " " << rNum << endl;
        long sumValue = -1;
        if(lNum == -1){
            sumValue = rNum;
        } else if(rNum == -1){
            sumValue = lNum;
        } else if(lNum != -1 && rNum != -1 && rNum != 0){
            sumValue = lNum + rNum;
        }
        
        if(sumValue == val){
            result.push_back(val);
        }
    }
    
    if(result.size() == 0){
        cout << "INVALID RANGE" << endl;
    } else {
        for(int i=0; i<result.size(); i++){
            cout << result[i] << " ";
        }
    }
}

int main()
{
    int p;
    cin >> p;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    kaprekarNumbers(p, q);

    return 0;
}
