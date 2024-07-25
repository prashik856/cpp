/**
 * Sudoku
 * 
 * Given a partially filled 9×9 2D array ‘grid[9][9]’, 
 * the goal is to assign digits (from 1 to 9) to the empty cells so that every row, 
 * column, and subgrid of size 3×3 contains exactly one instance of the digits from 1 to 9. 
 * 
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

void printDictionaryKeys(unordered_map<int, int> &mapping) {
    for(auto kv:mapping) {
        cout << kv.first << " ";
    }
    cout << endl;
}

void printListOfDictionarys(vector<unordered_map<int,int>> &mappings) {
    for(int i=0; i<mappings.size(); i++) {
        printDictionaryKeys(mappings[i]);
    }
}

bool isValuesValid(set<int> &values) {
    int count = 1;
    for(set<int>::iterator it=values.begin(); it!=values.end(); it++) {
        if(*it != count) {
            return false;
        }
        count++;
    }
    return true;
}

bool checkSigleGrid(int row, int col, int rowMax, int colMax, 
    vector<vector<int>> &grid, set<int> &values) {
    values.clear();
    for(int i=row; i<=rowMax; i++) {
        for(int j=col; j<=colMax; j++) {
            values.insert(grid[i][j]);
        }
    }

    if(values.size() != 9) {
        return false;
    }

    if(!isValuesValid(values)) {
        return false;
    }
    return true;
}

bool checkGrids(vector<vector<int>> &grid, set<int> &values) {
    int row=0, col = 0;
    int rowMax = 2, colMax=2;

    if(!checkSigleGrid(row, col, rowMax, colMax, grid, values)) {
        return false;
    }

    row=0; col = 3;
    rowMax=2; colMax=5;
    if(!checkSigleGrid(row,col,rowMax,colMax,grid,values)) {
        return false;
    }

    row=0; col=6;
    rowMax=2; colMax=8;
    if(!checkSigleGrid(row,col,rowMax,colMax,grid,values)) {
        return false;
    }

    row=3; col=0;
    rowMax=5; colMax=2;
    if(!checkSigleGrid(row,col,rowMax,colMax,grid,values)) {
        return false;
    }

    row=3; col=3;
    rowMax=5; colMax=5;
    if(!checkSigleGrid(row,col,rowMax,colMax,grid,values)) {
        return false;
    }

    row=3; col=6;
    rowMax=5; colMax=8;
    if(!checkSigleGrid(row,col,rowMax,colMax,grid,values)) {
        return false;
    }

    row=6; col=0;
    rowMax=8; colMax=2;
    if(!checkSigleGrid(row,col,rowMax,colMax,grid,values)) {
        return false;
    }

    row=6; col=3;
    rowMax=8; colMax=5;
    if(!checkSigleGrid(row,col,rowMax,colMax,grid,values)) {
        return false;
    }

    row=6; col=6;
    rowMax=8; colMax=8;
    if(!checkSigleGrid(row,col,rowMax,colMax,grid,values)) {
        return false;
    }

    return true;
}

bool isSudokuValid(vector<vector<int>>&grid) {
    set<int> values = set<int>();

    // rows
    for(int i=0; i<9; i++) {
        values.clear();
        for(int j=0; j<9; j++) {
            values.insert(grid[i][j]);
        }

        if(values.size() != 9) {
            return false;
        }

        if(!isValuesValid(values)) {
            return false;
        }
    }

    // column
    for(int i=0; i<9; i++) {
        values.clear();
        for(int j=0; j<9; j++) {
            values.insert(grid[j][i]);
        }

        if(values.size() != 9) {
            return false;
        }

        if(!isValuesValid(values)) {
            return false;
        }
    }

    if(!checkGrids(grid, values)) {
        return false;
    }

    return true;
}

int getGridIndex(int row, int col) {
    if(row >=0 && row <=2 && col >=0 && col <=2) {
        return 0;
    }

    if(row>=0 && row <=2 && col >=3 && col <=5) {
        return 1;
    }

    if(row>=0 && row <=2 && col >=6 && col <=8) {
        return 2;
    }

    if(row>=3 && row<=5 && col >=0 && col <=2) {
        return 3;
    }

    if(row>=3 && row<=5 && col >=3 && col <=5) {
        return 4;
    }

    if(row>=3 && row <=5 && col >=6 && col <=8) {
        return 5;
    }

    if(row>=6 && row <=8 && col >=0 && col <=2) {
        return 6;
    }

    if(row>=6 && row <=8 && col >=3 && col <=5) {
        return 7;
    }

    if(row>=6 && row <=8 && col >=6 && col <=8) {
        return 8;
    }
    return 0;
}

bool isValid(int value, 
    unordered_map<int, int> &row_mapping,
    unordered_map<int, int> &col_mapping,
    unordered_map<int,int> &grid_mapping) {
    if(row_mapping.find(value) == row_mapping.end()
        && col_mapping.find(value) == col_mapping.end() 
        && grid_mapping.find(value) == grid_mapping.end()) {
            return true;
        }
    return false;
}

void solve(vector<vector<int>>&grid, int row, int col, 
    int count, vector<vector<int>>&output, bool &solved,
    vector<unordered_map<int,int>> &rows_mapping,
    vector<unordered_map<int,int>> &cols_mapping,
    vector<unordered_map<int,int>> &grids_mapping) {
    // cout << "Input Grid: " << endl;
    // cout << "Row: " << row << " | Col: " << col << endl;
    // print2DVector(grid);

    // break point
    if(solved) {
        // cout << "Question already solved. Returing" << endl;
        return;
    }

    if(count == 81) {
        // cout << "Count Value reached 81. Checking if sudoku obtained is valid: " << endl;
        if(isSudokuValid(grid)) {
            // cout << "Sudoku obtained is valid: " << endl;
            output = grid;
            solved = true;
        }
        // cout << "Sudoku obtained is not valid: " << endl;
        return;
    }
    
    for(int i=row; i<9; i++) {
        for(int j=col; j<9; j++) {
            if(grid[i][j] == 0) {
                for(int value=1; value<=9; value++) {
                    int gridIndex = getGridIndex(i, j);
                    if(isValid(value, rows_mapping[i], 
                                cols_mapping[j], grids_mapping[gridIndex])) {
                            // cout << "Grid Index Obtained: " << gridIndex << endl;
                            // cout << "Value " << value << " is a valid value for " << i << ", " << j << endl;
                            // cout << endl;

                            count++;
                            grid[i][j] = value;
                            rows_mapping[i][grid[i][j]] = 1;
                            cols_mapping[j][grid[i][j]] = 1;
                            grids_mapping[gridIndex][grid[i][j]] = 1;

                            solve(grid, 0, 0, count, output, solved, rows_mapping, cols_mapping, grids_mapping);
                            
                            // bactrack by unsetting
                            // decrease count
                            // cout << "Backtracking." << endl;
                            count--;
                            rows_mapping[i].erase(grid[i][j]);
                            cols_mapping[j].erase(grid[i][j]);
                            grids_mapping[gridIndex].erase(grid[i][j]);
                            grid[i][j] = 0;
                        }
                }
                // cout << "No valid values from 1 to 9 obtained for index " << i << ", " << j << ". Returning." << endl;
                return;
            }
        }
    }
}

vector<vector<int> > sudoku(vector<vector<int>>&grid) {
    vector<vector<int>> output = vector<vector<int>>();
    int count = 0;
    bool solved = false;
    vector<unordered_map<int,int>> rows_mapping = vector<unordered_map<int,int>>(9);
    vector<unordered_map<int,int>> cols_mapping = vector<unordered_map<int,int>>(9);
    vector<unordered_map<int,int>> grids_mapping = vector<unordered_map<int,int>>(9);

    // cout << "Initializing mappings" << endl;
    for(int i=0; i<9; i++) {
        unordered_map<int,int> col_mapping = unordered_map<int,int>();
        unordered_map<int,int> row_mapping = unordered_map<int,int>();
        unordered_map<int, int> grid_mapping = unordered_map<int, int>();
        rows_mapping[i] = row_mapping;
        cols_mapping[i] = col_mapping;
        grids_mapping[i] = grid_mapping;
    }
    
    // cout << "Reading grid to initialize maps: " << endl;
    for(int i=0; i<9; i++) {
        unordered_map<int,int> col_mapping = cols_mapping[i];
        unordered_map<int,int> row_mapping = rows_mapping[i];
        for(int j=0; j<9; j++) {
            int gridIndex = getGridIndex(i,j);
            if(grid[i][j]!=0){
                if(row_mapping.find(grid[i][j]) == row_mapping.end()
                    && grids_mapping[gridIndex].find(grid[i][j]) == grids_mapping[gridIndex].end()) {
                        count++;
                        row_mapping[grid[i][j]] = 1;
                        grids_mapping[gridIndex][grid[i][j]] = 1;
                    } else {
                        // no valid output
                        return output;
                    }
            }

            if(grid[j][i]!=0){
                if(col_mapping.find(grid[j][i]) == col_mapping.end()) {
                    col_mapping[grid[j][i]] = 1;
                } else {
                    // invalid input
                    return output;
                }
            }
        }
        cols_mapping[i] = col_mapping;
        rows_mapping[i] = row_mapping;
    }

    // cout << "Rows Mapping: " << endl;
    // printListOfDictionarys(rows_mapping);

    // cout << "Cols Mapping" << endl;
    // printListOfDictionarys(cols_mapping);

    // cout << "Grid Mapping: " << endl;
    // printListOfDictionarys(grids_mapping);

    // cout << "Initial Count: " << count << endl;

    // cout << "Solving Sudoku" << endl;
    solve(grid, 0, 0, count, output, solved, rows_mapping, cols_mapping, grids_mapping);

    return output;
}

int main() {
    vector<vector<int>> grid = vector<vector<int>>(
          { { 3, 1, 6, 5, 7, 8, 4, 9, 2 },
{ 5, 2, 9, 1, 3, 4, 7, 6, 8 },
{ 4, 8, 7, 6, 2, 9, 5, 3, 1 },
{ 2, 6, 3, 0, 1, 5, 9, 8, 7 },
{ 9, 7, 4, 8, 6, 0, 1, 2, 5 },
{ 8, 5, 1, 7, 9, 2, 6, 4, 3 },
{ 1, 3, 8, 0, 4, 7, 2, 0, 6 },
{ 6, 9, 2, 3, 5, 1, 8, 7, 4 },
{ 7, 4, 5, 0, 8, 6, 3, 1, 0 } });

    cout << "Input Sudoku: " << endl;
    print2DVector(grid);

    vector<vector<int>> output = sudoku(grid);
    cout << "Output: " << endl;
    print2DVector(output);

    return 0;
}