// this is the code to rotate the array by the given number:
/*

The following code is supposed to rotate the array A by B positions.

So, for example,


A : [1 2 3 4 5 6]
B : 1

The output :

[2 3 4 5 6 1]

*/
vector<int> Solution::rotateArray(vector<int> &A, int B) {
	vector<int> ret; 
	for (int i = 0; i < A.size(); i++) {
		ret.push_back(A[(i + B)%A.size()]);
	}
	return ret; 
}