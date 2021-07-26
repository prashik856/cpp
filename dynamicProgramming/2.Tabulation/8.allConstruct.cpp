#include<bits/stdc++.h>
using namespace std;

void printTable(vector< vector< vector<string> > > table) {
	cout << "Table is: " << endl;
	for(int i=0; i<table.size(); i++){
		cout << "Table index: " << i << endl;
		for(int j=0; j<table[i].size(); j++){
			for(int k=0; k<table[i][j].size(); k++){
				cout << table[i][j][k] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << endl;
}

vector< vector<string> > allConstruct(string targetString, vector<string> wordbank) {
	int m = targetString.size();
	vector< vector< vector<string> > > table(m + 1, vector< vector<string> >());
	vector<bool> isPossible(m+1, false);

	isPossible[0] = true;

	for(int i=0; i<=targetString.size(); i++){
		if(isPossible[i]){
			for(int j=0; j<wordbank.size(); j++){
				int index = i;
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

				if(isPrefix){
					// cout << wordbank[j] << " is a prefix" << endl;
					if(i + count <= targetString.size()){
						// cout << "Adding prefix to table" << endl;
						// add wordbank[j] to the end
						vector< vector<string> > value = table[i];

						if(value.size() == 0){
							vector<string> temp;
							temp.push_back(wordbank[j]);
							value.push_back(temp);
						} else {
							for(int k=0; k<value.size(); k++){
								vector<string> temp = value[k];
								temp.push_back(wordbank[j]);
								value[k] = temp;
							}
						}
						

						// if table is empty, just assign value
						if(table[i+count].size() == 0){
							table[i + count] = value;
						} else {
							for(int k=0; k<value.size(); k++){
								table[i+count].push_back(value[k]);
							}
						}

						isPossible[i + count] = true;
						// printTable(table);
					}
				}
			}
		}
	}

	return table[m];
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

		vector< vector<string> > result = allConstruct(targetString, wordbank);
		cout << "Result: " << endl;
		for(int i=0; i<result.size(); i++){
			for(int j=0; j<result[i].size(); j++){
				cout << result[i][j] << " ";
			}
			cout << endl;
		}

		cout << endl;
	}
	return 0;
}