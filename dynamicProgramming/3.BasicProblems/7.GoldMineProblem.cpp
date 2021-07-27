/*
Problem: https://www.geeksforgeeks.org/gold-mine-problem/
Intuition: Either tabulation or Memoization. Use optimization while selecting value
*/

#include<bits/stdc++.h>
using namespace std;

unordered_map<int, int> memo;
int GoldMine(int row, int col, vector< vector<int> > grid) {
	int n = grid.size();
	int m = grid[0].size();

	int key = row * m + col;
	if(memo.find(key) != memo.end()) {
		return memo[key];
	}

	if(row < 0 || row >= n || col < 0 || col >= m) {
		return 0;
	}

	int rightUp = GoldMine(row - 1, col + 1, grid);
	int right = GoldMine(row, col + 1, grid);
	int rightDown = GoldMine(row + 1, col + 1, grid);

	memo[key] = grid[row][col] + max(max(rightUp, right), max(rightDown, right));
	return memo[key];
}

void printTable(vector< vector<int> > table) {
	cout << "Table value is: " << endl;
	for(int i=0; i<table.size(); i++){
		for(int j=0; j<table[0].size(); j++){
			cout << table[i][j] << " ";
		}
		cout << endl;
	}
}

int GoldMineTabulated(vector< vector<int> > grid) {
	int n = grid.size();
	int m = grid[0].size();
	int result = numeric_limits<int>::min();

	// When n == 0 or m == 0, value is always zero
	vector< vector<int> > table(n, vector<int>(m, 0));

	// Starting positions are fixed and their values are fixed.
	for(int i=0; i<n; i++){
		table[i][0] = grid[i][0];
	}

	// print the initial table
	printTable(table);
	int maxValue = numeric_limits<int>::min();
	for(int j=1; j<m; j++){
		for(int i=0; i<n; i++){
			// start i,j affects (i-1, j+1), (i, j+1), and (i+1, j+1)
			// right state

			int leftValue = numeric_limits<int>::min();
			int leftUpValue = numeric_limits<int>::min();
			int leftDownValue = numeric_limits<int>::min();
			maxValue = numeric_limits<int>::min();

			if( j - 1 >= 0){
				leftValue = table[i][j-1];
				maxValue = max(maxValue, leftValue);
			}

			if( j-1 >= 0 && i-1 >= 0) {
				leftUpValue = table[i-1][j-1];
				maxValue = max(maxValue, leftUpValue);
			}

			// diag up state
			if(j-1 >=0 && i+1 < n){
				leftDownValue = table[i+1][j-1];
				maxValue = max(maxValue, leftDownValue);
			}

			table[i][j] = grid[i][j] + maxValue;
			result = max(result, table[i][j]);
		}
	}

	printTable(table);
	return result;
}

int main(){
	int t;
	cin >> t;
	cout << "Number of test cases: " << t << endl;
	for(int z=0; z<t; z++){
		memo = unordered_map<int, int>();
		int n,m;
		cin >> n >> m;
		cout << "Value of n and m are: " << n << " | " << m << endl;
		vector< vector<int> > grid(n, vector<int>(m, 0));
		cout << "Given grid is: " << endl;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				int temp;
				cin >> temp;
				grid[i][j] = temp;
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}
		int result = numeric_limits<int>::min();
		for(int i=0; i<n; i++){
			int startRow = i;
			int startCol = 0;
			int value = GoldMine(startRow, startCol, grid);
			cout << "Start Position: " << startRow << " | " << startCol << endl;
			cout << "Max for current position: " << value << endl;
			result = max(result, value);
		}
		cout << "Result: " << result << endl;

		result = GoldMineTabulated(grid);
		cout << "Result using Tabulated: " << result << endl;

		cout << endl;
	}
	return 0;
}