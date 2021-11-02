'''
Given a non negative integer A,

following code tries to find all pair of integers (a, b) such that

a and b are positive integers
a <= b, and
a2 + b2 = A.
0 <= A <= 100000
However, the code has a small bug. Correct the bug and submit the code.

'''

'''
Given Code:
vector<vector<int> > Solution::squareSum(int A) {
	vector<vector<int> > ans;
	for (int a = 0; a * a < A; a++) {
		for (int b = 0; b * b < A; b++) {
			if (a * a + b * b == A) {
				vector<int> newEntry; 
				newEntry.push_back(a);
				newEntry.push_back(b);
				ans.push_back(newEntry);
			}
		}
	}
	return ans;
}

'''

'''
Expected Code:
vector<vector<int> > Solution::squareSum(int A) {
	vector<vector<int> > ans;
	for (int a = 0; a * a < A; a++) {
		for (int b = 0; b * b < A; b++) {
			if (a * a + b * b == A && A>=0 && A<= 100000 && a<=b) {
				vector<int> newEntry; 
				newEntry.push_back(a);
				newEntry.push_back(b);
				ans.push_back(newEntry);
			}
		}
	}
	return ans;
}
'''