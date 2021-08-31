class Solution:
    # @param A : integer
    # @return a strings
    def solve(self, A):
        if(A == 1):
            return 1
        value = 1
        for i in range(1,A+1):
            value = value * i
        return value