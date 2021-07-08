// Problem: https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1
// Inspiration: using the concept learned from max rectangle

#include<bits/stdc++.h>
using namespace std;

void printStack(stack<int> s){
	cout << "Stack Value: " << endl;
	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

void printArray(vector<int> arr){
	cout << "Array is: " << endl;
	for(int i=0; i<arr.size(); i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

// Complete this function
vector<int> getSpan(vector<int> price){
	vector<int> result(price.size(), 0);
	stack<int> pStack;
	stack<int> hStack;
	stack<int> aStack;

	int lastIndex = 0;
	int n = price.size();

	// Start our for loop
	for(int i=0; i<n; i++){
		// cout << i << " | " << price[i] << endl;
		// printStack(aStack);
		// printStack(pStack);
		// printStack(hStack);
		// printArray(result);
		
		// This will run 
		bool useLastIndex = false;

		while(!pStack.empty() && price[i] > hStack.top()){
			useLastIndex = true;
			lastIndex = pStack.top();
			int actualIndex = aStack.top();
			result[actualIndex] = actualIndex - lastIndex + 1;
			pStack.pop();
			hStack.pop();
			aStack.pop();
		}

		if(pStack.empty() || price[i] < hStack.top()) {
			if(useLastIndex){
				pStack.push(lastIndex);
			} else {
				pStack.push(i);
			}
			aStack.push(i);
			hStack.push(price[i]);
		}

		// cout << "After Computations: " << endl;
		// printStack(aStack);
		// printStack(pStack);
		// printStack(hStack);
		// printArray(result);
		// cout << endl;
	}

	while(!pStack.empty()){
		// cout << "Stack not empty" << endl;
		// printStack(aStack);
		// printStack(pStack);
		// printStack(hStack);
		// printArray(result);
		int actualIndex = aStack.top();
		lastIndex = pStack.top();
		result[actualIndex] = actualIndex - lastIndex + 1;
		pStack.pop();
		hStack.pop();
		aStack.pop();
		// cout << "After Computations: " << endl;
		// printStack(aStack);
		// printStack(pStack);
		// printStack(hStack);
		// printArray(result);
		// cout << endl;
	}

	return result;
}

int main(){
	int t;
	cin >> t;
	for(int j=0; j<t; j++){
		int n;
		cin >> n;
		vector<int> price(n);
		for(int i=0; i<n; i++){
			int value;
			cin >> value;
			price[i] = value;
		}

		vector<int> result;
		result = getSpan(price);
		for(int i=0; i<result.size(); i++){
			cout << result[i] << " ";
		}
		cout << endl;
	}

	return 0;
}