/*

Given a matrix of m * n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example:

Given the following matrix:

[
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
]
You should return

[1, 2, 3, 6, 9, 8, 7, 4, 5]
Problem Approach :

Complete solution in the hints.
*/

vector<int> Solution::spiralOrder(const vector<vector<int> > &A) {
    int row = A.size();
    int col = A[0].size();
    vector<int> result;

    int x1 = 0;
    int x2 = row - 1;
    int y1 = 0;
    int y2 = col - 1;
    // // four points are (x1, y1), (x1,y2), (x2,y1), (x2,y1)
    // cout << "x1: " << x1 << endl;
    // cout << "x2: " << x2 << endl;
    // cout << "y1: " << y1 << endl;
    // cout << "y2: " << y2 << endl;

    while(x1 <= x2 && y1 <= y2){
        // single point
        if(x1 == x2 && x1 == y1 && x1 == y2){
            result.push_back(A[x1][x1]);
            break;
        }

        // only row
        if(x1 == x2) {
            // go right
            for(int i=y1; i<=y2; i++){
                result.push_back(A[x1][i]);
            }
            break;
        }

        // only column
        if(y1 == y2){
            // go down
            for(int i=x1; i<=x2; i++){
                result.push_back(A[i][y1]);
            }
            break;
        }

        // go right 
        for(int i=y1; i<y2; i++){
            result.push_back(A[x1][i]);
        }

        // go down 
        for(int i=x1; i<x2; i++){
            result.push_back(A[i][y2]);
        }

        // go left 
        for(int i=y2; i>y1; i--){
            result.push_back(A[x2][i]);
        }

        // go up
        for(int i=x2; i>x1; i--){
            result.push_back(A[i][y1]);
        }

        x1++;
        x2--;
        y1++;
        y2--;
    }
    
    // cout << "Printing Result" << endl;
    // for(int i=0; i<result.size(); i++){
    //     cout << result[i] << " ";
    // }
    // cout << endl;

    return result;
}
