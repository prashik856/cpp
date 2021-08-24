'''
DP on Trees General Syntax.

Tree Recursion

Example function:
int function(Input) {
    Base Condition

    Hypothesis -> Giving us the answer of left and right tree
    (Of children)

    Induction -> Using answers from left and right, we 
    find the answer for the current node
    
    Then the induction will send it's answer to it's parent   
}

Code:

Return type depends on the question
Need to pass by reference
int solve(Node *root, int &result) {
    BC 
    if(root == 0) {
        return 0
    }

    H
    int left = solve(root->left, result)
    int right = solve(root->right, result)

    I
    int temp = calculate temp answer()
    int ans = max(temp, someRelation)
    res = max(res, ans)

    Return step:
    return temp
}

We would like to initialize the result with some value
int res = INT_MIN or INT_MAX

Stored result in res
'''

