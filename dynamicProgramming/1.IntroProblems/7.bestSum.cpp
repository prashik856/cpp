#include<bits/stdc++.h>
using namespace std;

// unordered_map<int, vector<int>> memo;

class BestSumReturn {
public:
	bool isPresent;
	vector<int> result;

	BestSumReturn(bool isPresentValue, vector<int> resultValue){
		isPresent = isPresentValue;
		result = vector<int> (resultValue.begin(), resultValue.end());
	}
};

BestSumReturn bestSum(int targetSum, vector<int> numbers){

	if(targetSum == 0){
		vector<int> result;
		BestSumReturn returnValue(true, result);
		return returnValue;
	}

	if(targetSum < 0){
		vector<int> result;
		BestSumReturn returnValue(false, result);
		return returnValue;
	}

	vector<int> shortestCombination;

	for(int i=0; i<numbers.size(); i++){
		int remainder = targetSum - numbers[i];
		BestSumReturn remainderCombination = bestSum(remainder, numbers);

		if(remainderCombination.isPresent){
			remainderCombination.result.push_back(numbers[i]);
			if(shortestCombination.size() == 0 || remainderCombination.result.size() < shortestCombination.size()) {
				shortestCombination = vector<int>(remainderCombination.result.begin(), remainderCombination.result.end());
			}
		}
	}

	BestSumReturn returnValue(true, shortestCombination);
	if(shortestCombination.size() == 0){
		returnValue.isPresent = false;
	}
	return returnValue;
}

void printArray(vector<int> arr){
	for(int i=0; i<arr.size(); i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(){
	int t; 
	cin >> t;
	for(int z=0; z<t; z++){
		int targetSum, numbersSize;
		cin >> targetSum >> numbersSize;
		vector<int> numbers(numbersSize, -1);
		for(int i=0; i<numbersSize; i++){
			int value;
			cin >> value;
			numbers[i] = value;
		}
		BestSumReturn resultValue = bestSum(targetSum, numbers);
		if(resultValue.isPresent){
			printArray(resultValue.result);
		} else {
			cout << "None" << endl;
		}
	}
	
	return 0;
}