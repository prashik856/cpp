#include<bits/stdc++.h>
using namespace std;

void printTable(vector< vector<int> > table) {
	cout << "Table value is: " << endl;
	for(int i=0; i<table.size(); i++) {
		cout << "Table index: " << i << " | " << table[i].size() << endl;
		for(int j=0; j<table[i].size(); j++){
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int getSum(vector<int> arr) {
	int sum = 0;
	for(int i=0; i<arr.size(); i++){
		sum = sum + arr[i];
	}

	return sum;
}

vector<int> bestSum(int targetSum, vector<int> numbers) {
	vector< vector<int> > table(targetSum + 1, vector<int>());
	vector<bool> isPossible(targetSum + 1, false);

	isPossible[0] = true;
	for(int i=0; i<= targetSum; i++){
		if(isPossible[i]){
			for(int j=0; j<numbers.size(); j++){
				vector<int> value = table[i];
				value.push_back(numbers[j]);
				int sumValue = getSum(value);
				if(sumValue <= targetSum) {
					isPossible[sumValue] = true;
					vector<int> targetValue = table[sumValue];

					// if targetValue is empty or if our current vector size is less than targetValue size
					if(targetValue.size() == 0 || value.size() < targetValue.size()) {
						table[sumValue] = value;
					}
				}
			}
		}
	}

	return table[targetSum];
}

int main(){
	int t;
	cin >> t;
	cout << "Number of test Cases is: " << t << endl;
	for(int z=0; z<t; z++){
		int targetSum;
		int numbersLength;
		cin >> targetSum >> numbersLength;
		cout << "Target Sum is: " << targetSum << endl;
		cout << "Length of numbers array is: " << numbersLength << endl;
		vector<int> numbers(numbersLength);
		cout << "Numbers list is: " << endl;
		for(int i=0; i<numbersLength; i++){
			int temp;
			cin >> temp;
			numbers[i] = temp;
			cout << numbers[i] << " ";
		}
		cout << endl;
		vector<int> result;
		result = bestSum(targetSum, numbers);
		cout << "Result: " << endl;
		for(int i=0; i<result.size(); i++){
			cout << result[i] << " ";
		}
		cout << endl;
		cout << endl;
	}
}