'''
Our function call is:
solve(string s, int i, int j, bool isTrue):

We know that the values that are changing are:
i, j and isTrue Variables.

So, the size of our Table will be
(N+1, N+1, 2) -> Why 2?
Because value of isTrue can only be True or False.

Our matrix will be 3D matrix.
table[N+1][N+1][2] matrix size

But what will be a better way?
We can just create a Map, where the 
key will be the value "i,j,isTrue"
So, our key will be string "i j isTrue" and we can just 
store this key.

We can just have a global map declaration.
unordered_map<string, int> map;
int main() {
    map.clear();
    solve();
}


'''
mp = {}
def solve(s, i, j, isTrue):
    # Base Condition 1
    if(i>j):
        return 0
    
    if(i==j):
        if isTrue:
            if s[i] == "T":
                return 1
            else:
                return 0
        else:
            if s[i] == "F":
                return 1
            else:
                return 0
    
    # Create key
    key = str(i) + " " + str(j) + " " + str(isTrue)
    if key in mp:
        return mp[key]

    ans = 0
    for k in range(i+1,j,2):
        leftTrue = solve(s,i,k-1,True)
        leftFalse = solve(s,i,k-1,False)
        rightTrue = solve(s,k+1,j,True)
        rightFalse = solve(s,k+1,j,False)

        if(s[k] == '&'):
            if isTrue:
                # // Evaulate to true
                # // && will only evaluate to true when both of the expressions will 
                # // evaluate to true
                ans += leftTrue * rightTrue
            else:
                # // Evaluate to false
                # // when any of them is false
                ans += leftFalse * rightFalse + leftFalse * rightTrue + leftTrue * rightFalse

        if(s[k] == '|'):
            if isTrue:
                # // True
                # // Any one of them is true
                ans += leftTrue * rightTrue + leftTrue * rightFalse + leftFalse * rightTrue
            
            else:
                # // False
                # // Both of them false
                ans += leftFalse * rightFalse

        if(s[k] == '^'):
            if isTrue:
                # // True
                # // Both are different
                ans += leftFalse * rightTrue + leftTrue * rightFalse
            else:
                # // False
                # // Both same
                ans += leftFalse * rightFalse + leftTrue * rightTrue
    mp[key] = ans
    return ans


s = "T|F&T|F|T&F&T|T^F^T|T&F&T^F"
n = len(s)
mp.clear()
print("Pre Map: ")
print(mp)
result = solve(s, 0, n-1, True)
print("Post Map: ")
print(mp)
print("Value of result is: ")
print(result)