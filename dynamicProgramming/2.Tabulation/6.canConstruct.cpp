/*
given wordbank, check if we can construct targetString?

*/

#include<bits/stdc++.h>
using namespace std;

void printTable(vector<bool> arr){
	cout << "Table value is: " << endl;
	for(int i=0; i<arr.size(); i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

bool canConstruct(string targetString, vector<string> wordbank){
	vector<bool> table(targetString.size() + 1, false);
	// if targetString is '', it is possible to construct targetString
	// we just don't select anything
	table[0] = true;
	for(int i=0; i<=targetString.size(); i++){
		if(table[i]){
			for(int j=0; j<wordbank.size(); j++){
				// check if wordbank[j] is a prefix
				int index = i;
				// cout << "Index: " << i << endl;
				// cout << "Target String: " << targetString << endl;
				int count = 0;
				bool isPrefix = false;

				for(int k=0; k<wordbank[j].size(); k++){
					if(index < targetString.size() && wordbank[j][k] == targetString[index]){
						index++;
						count++;
					} else {
						break;
					}
				}

				// if count is equal to 
				if(count == wordbank[j].size()){
					// is Prefix
					isPrefix = true;
				}

				// if we get our prefix
				if(isPrefix){
					// cout << wordbank[j] << " is prefix" << endl;
					if(i + count <= targetString.size()){
						table[i + count] = true;
						// printTable(table);
					}
				}
			}
		}
		// cout << endl;
	}

	return table[targetString.size()];
}

int main(){
	int t;
	cin >> t;
	cout << "The number of test cases is: " << t << endl;
	for(int z=0; z<t; z++){
		string targetString;
		cin >> targetString;
		cout << "Target String is: " << targetString << endl;

		int lengthOfWordBank;
		cin >> lengthOfWordBank;
		cout << "The length of wordbank is: " << lengthOfWordBank << endl;

		cout << "The given wordBank is: " << endl;
		vector<string> wordbank(lengthOfWordBank);
		for(int i=0; i<lengthOfWordBank; i++){
			string temp;
			cin >> temp;
			wordbank[i] = temp;
			cout << wordbank[i] << " ";
		}
		cout << endl;

		bool result = canConstruct(targetString, wordbank);
		cout << "Result: " << endl;
		if(result) {
			cout << "TRUE" << endl;
		} else {
			cout << "FALSE" << endl;
		}

		cout << endl;
	}
	return 0;
}