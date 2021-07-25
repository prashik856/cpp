#include<bits/stdc++.h>
using namespace std;

unordered_map<string, vector< vector<string> > > memo;

vector< vector<string> >  allConstruct(string targetString, vector<string> wordBank) {
	if(memo.find(targetString) != memo.end()){
		return memo[targetString];
	}

	if(targetString.size() == 0) {
		// Create empty string
		vector< vector<string> > result;
		// push back empty string of vectors
		result.push_back(vector<string>());
		return result;
	}

	vector< vector<string> > result;

	for(int i=0; i<wordBank.size(); i++){
		bool isPrefix = false;
		int index = 0;

		for(int j=0; j<wordBank[i].size(); j++){
			if(targetString[index] == wordBank[i][j]){
				index++;
			} else {
				break;
			}
		}

		if(index == wordBank[i].size()){
			isPrefix = true;
		} else {
			isPrefix = false;
		}

		if(isPrefix){
			string suffix;
			for(int j=index; j<targetString.size(); j++){
				suffix.push_back(targetString[j]);
			}

			vector< vector<string> >  suffixWays = allConstruct(suffix, wordBank);
			vector< vector<string> > targetWays = suffixWays;

			for(int j=0; j<targetWays.size(); j++) {
				targetWays[j].insert(targetWays[j].begin(), wordBank[i]);
				result.push_back(targetWays[j]);
			}

		}
	}

	memo[targetString] = result;
	return result;
}

int main(){
	int t;
	cin >> t;
	cout << "The number of test cases is: " << t << endl;
	for(int z=0; z<t; z++){
		string targetString;
		cin >> targetString;
		cout << "The target string is: " << targetString << endl;
		int n;
		cin >> n;
		cout << "The size of wordBank is " << n << endl;

		vector<string> wordBank(n);
		cout << "The WordBank is: " << endl;
		for(int i=0; i<n; i++){
			string tmp;
			cin >> tmp;
			wordBank[i] = tmp;
			cout << wordBank[i] << "|" << wordBank[i].size() << " " ;
		}
		cout << endl;
		vector< vector<string> > result = allConstruct(targetString, wordBank);
		cout << "Result: " << endl;
		for(int i=0; i<result.size(); i++){
			for(int j=0; j<result[i].size(); j++){
				cout << result[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl << endl;
	}

	return 0;
}