#include <bits/stdc++.h>

using namespace std;

// Complete the cavityMap function below.
vector<string> cavityMap(vector<string> grid) {
    vector<string> result(grid.size());
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[i].size(); j++){
            result[i].push_back(grid[i][j]);
        }
    }
    
    for(int i=1; i<grid.size()-1; i++){
        for(int j=1; j<grid[i].size()-1; j++){
            int currentValue = (int) grid[i][j];
            char charValue = grid[i][j];
            
            int upValue = (int) grid[i-1][j];
            int downValue = (int) grid[i+1][j];
            int leftValue = (int) grid[i][j-1];
            int rightValue = (int) grid[i][j+1];
            
            if(currentValue > upValue &&
                currentValue > downValue &&
                currentValue > leftValue &&
                currentValue > rightValue){
                    // Found you
                    charValue = 'X';
                    result[i][j] = 'X';
                }
        }
    }
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = cavityMap(grid);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
