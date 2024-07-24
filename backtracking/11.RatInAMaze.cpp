/*
 * Rat in a Maze

 Flow: 
 1. Input Output of Problem Statement
 2. Choices : Controlled : Out of Bound, Repeated, Blocked
 3. Backtracking
 4. Code

    Input: NxN matrix
    1, 0, 0, 0
    1, 1, 0, 1
    1, 1, 0, 0
    0, 1, 1, 1

    Rat is at the position (0,0) start of the matrix. 
    0 indicates that there is no way to go there.
    1 indicates rat can go there.

    Print all the ways that rat can go.
    The rat can move in U,D,L,R directions.
    Exit is at the bottom right. 

    Output:
    DDRDRR
    DRDDRR
    
    Output needs to be vector of strings.


   Choices for rat.
   NxN square matrix is given. Maybe constraint can be single digit N.
   Rat can go U, D, L, R.
   It is not always possible to go through all locations.
   Wherever there is 0, it cannot go there.
   Valid choice should be in inside the bounds.
   Valid choice should not be repeated.

   BASE CONDITION?
   1. Reached final point? -> Save this path.
   2. Choices will already exhaust. -> Automatically this will happen.

 */ 

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print2DVector(vector< vector<int> > arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void print2DVector(vector< vector<long> > arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void print2DVector(vector< vector<bool> > arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void print2DVector(vector< vector<char> > arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void print4DVector(vector< vector< vector< vector<int>>>> arr) {
    for(int i=0; i<arr.size(); i++) {
        cout << i << " : " << endl;
        for(int j=0; j<arr[i].size(); j++) {
            cout << j << " : " << endl;
            for(int k=0; k<arr[j].size(); k++) {
                for(int l=0; l<arr[k].size(); l++) {
                    cout << arr[i][j][k][l] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
    }
}

void printStrings(vector<string> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << endl;
    }
    cout << endl;
}

void print2DStrings(vector< vector<string> > arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int getPosition(int row, int col, int n) {
   return (row + col * n);
}

int getFinalPosition(int n) {
   return ((n-1) + (n-1)*(n));
}

bool isValid(int row, int col, int position, int n,
   vector< vector<int> > &maze, unordered_map<int, int> &visited_path) {
      // bound check
      if(row >=0 && row <= n-1 && col >=0 && col <= n-1) {
         // value check and not visited check.
         if(maze[row][col] != 0 && visited_path.find(position) == visited_path.end()) {
            return true;
         }
      }
      return false;
}

void solve(vector< vector<int> > &maze, 
            vector<string> &output,
            int row, int col, 
            string &currentPath, unordered_map<int, int> &visited_path) {
   int n = maze.size();
   int currentPosition = getPosition(row, col, n);
   int finalPosition = getFinalPosition(n);
   // cout << "Current Position: " << currentPosition << endl;
   // cout << "Current Location: " << row << "," << col << endl;

   // base condition
   if(currentPosition == finalPosition) {
      // reached the end.
      // cout << "Current Path: " << currentPath << endl;
      output.push_back(currentPath);
      return;
   }

   // Go Left
   // row, col - 1 should be in bounds, and it should not be already visited, 
   // and should not be zero
   int leftPosition = getPosition(row, col-1, n);
   if(isValid(row, col-1, leftPosition, n, maze, visited_path)) {
      // cout << "Going Left";
      currentPath.push_back('L');
      visited_path[leftPosition] = 1;

      solve(maze, output, row, col-1, currentPath, visited_path);

      // backtrack
      currentPath.pop_back();
      visited_path.erase(leftPosition);
   }

   // Go Right
   // row, col + 1
   int rightPosition = getPosition(row, col+1, n);
   if(isValid(row, col+1, rightPosition, n, maze, visited_path)) {
      // cout << "Going Right";
      currentPath.push_back('R');
      visited_path[rightPosition] = 1;

      solve(maze, output, row, col+1, currentPath, visited_path);

      // backtrack
      currentPath.pop_back();
      visited_path.erase(rightPosition);
   }

   // Go Up
   // row - 1, col
   int upPosition = getPosition(row-1, col, n);
   if(isValid(row-1, col, upPosition, n, maze, visited_path)) {
      // cout << "Going Up";
      currentPath.push_back('U');
      visited_path[upPosition] = 1;

      solve(maze, output, row-1, col, currentPath, visited_path);

      currentPath.pop_back();
      visited_path.erase(upPosition);
   }

   // Do Down
   // row +1, col
   int downPosition = getPosition(row+1, col, n);
   if(isValid(row+1, col, downPosition, n, maze, visited_path)) {
      // cout << "Going Down";
      currentPath.push_back('D');
      visited_path[downPosition] = 1;

      solve(maze, output, row+1, col, currentPath, visited_path);

      currentPath.pop_back();
      visited_path.erase(downPosition);
   }

   // cout << endl;
}

vector<string> ratInAMaze(vector< vector<int> > &maze) {
   vector<string> output = vector<string>();
   // base conditions of input
   if(maze.size() == 0) {
      return output;
   }

   if(maze.size() > 0 && maze[0][0] == 0) {
      // landed on 0
      return output;
   }
   
   string currentPath = "";
   unordered_map<int, int> visited_path = unordered_map<int, int>();
   // visited this node as we have already landed on 0.
   visited_path[0] = 1;
   solve(maze, output,0, 0, currentPath, visited_path);
   return output;
}

int main(){
   vector< vector<int> > maze = vector<vector<int>>({ {1,1,1,1},
                                                      {1,1,1,1},
                                                      {1,1,1,1},
                                                      {1,1,1,1}});
   cout << "Input Maze: " << endl;
   print2DVector(maze);

   vector<string> output = ratInAMaze(maze);
   cout << "Output: " << endl;
   printStrings(output);
}
// g++ -std=c++11