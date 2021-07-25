#include<bits/stdc++.h>
using namespace std;

class BestSumReturn {
public:
	bool isPresent;
	vector<int> result;

	BestSumReturn(bool isPresentValue, vector<int> resultValue){
		isPresent = isPresentValue;
		result = vector<int> (resultValue.begin(), resultValue.end());
	}
};

unordered_map<int, vector<int> > memo;

BestSumReturn bestSum(int targetSum, vector<int> numbers){
	
	// Return cached value
	if(memo.find(targetSum) != memo.end()){
		vector<int> result = memo[targetSum];
		BestSumReturn returnValue(false, result);
		if(result.size() > 0){
			returnValue.isPresent = true;
		}
		return returnValue;
	}

	// Base case
	if(targetSum == 0){
		vector<int> result;
		BestSumReturn returnValue(true, result);
		return returnValue;
	}

	// base case 2
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
	memo[targetSum] = shortestCombination;
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


// Memoized complexity
/*
time: O(n*m*m)
Space: O(m*m)
*/

/*
bestSum
m = targetSum
n = array length

brute force: 
time: O(n^m * m)
Space: O(m*m)

Memoized:
time: O(n*m*m)
Space: O(m*m)
*/