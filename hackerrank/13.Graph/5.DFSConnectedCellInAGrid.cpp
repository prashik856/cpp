// Problem: https://www.hackerrank.com/challenges/ctci-connected-cell-in-a-grid/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=graphs
// Intuition: Simple bfs to every cell. Count connected components
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'maxRegion' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY grid as parameter.
 */

class Graph{
  public:
    int nodes;
    vector< vector<int> > neighbours;
    vector<bool> visited;
    Graph(int nodesValue){
        nodes = nodesValue;
        neighbours = vector< vector<int> >(nodesValue, vector<int>());
        visited = vector<bool>(nodesValue, false);
    }
    
    void addEdge(int from, int to){
        neighbours[from].push_back(to);
    }
    
    void printGraph() {
        cout << "Current Graph is: " << endl;
        for(int i=0; i<neighbours.size(); i++){
            cout << "Current Node: " << i << " -> ";
            for(int j=0; j<neighbours[i].size(); j++){
                cout << neighbours[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    
    int runBFS(){
        int result = 0;
        for(int i=0; i<nodes; i++){
            int node = i;
            // run bfs for node
            if(visited[node]){
                continue;
            }
            
            queue<int> q;
            q.push(node);
            int count = 0;
            
            while(!q.empty()){
                int currentNode = q.front();
                if(visited[currentNode]){
                    // node already visited
                    q.pop();
                    continue;
                }
                visited[currentNode] = true;
                count++;
                q.pop();
                for(int j=0; j<neighbours[currentNode].size(); j++){
                    int currentNeighbour = neighbours[currentNode][j];
                    if(!visited[currentNeighbour]) {
                        q.push(currentNeighbour);
                    }
                }
            }
            result = max(result, count);
        }
        return result;
    }
};

int maxRegion(vector<vector<int>> grid) {
    int result = 0;
    int m = grid[0].size();
    int n = grid.size();
    Graph graph(n*m);
    // cout << "total number of nodes: " << n*m << endl;
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[i].size(); j++){
            // Current value
            int value = grid[i][j];
            
            if(value == 0){
                continue;
            }
            
            int from = i * m + j;
            
            // horizontal left
            if(j-1 >= 0 && grid[i][j-1] == 1){
                int to = i * m + j - 1;
                // add edge
                graph.addEdge(from, to);
            }
            
            // horizontal right
            if(j + 1 < m && grid[i][j+1] == 1){
                int to = i * m + j + 1;
                graph.addEdge(from, to);
            }
            
            // vertical up
            if(i - 1 >=0 && grid[i-1][j] == 1){
                int to = (i-1)*m + j;
                graph.addEdge(from, to);
            }
            
            // vertical down
            if(i + 1 < n && grid[i + 1][j] == 1){
                int to = (i+1)*m + j;
                graph.addEdge(from, to);
            }
            
            // diagonal left up
            if(i - 1 >= 0 && j - 1 >= 0 && grid[i-1][j-1] == 1){
                int to = (i-1)*m + j - 1;
                graph.addEdge(from, to);
            }
            
            // diagonal left down
            if(i + 1 < n && j - 1 >= 0 && grid[i+1][j-1] == 1){
                int to = (i+1)*m + j - 1;
                graph.addEdge(from, to);
            }
            
            // diagonal right up
            if(i - 1 >= 0 && j + 1 < m && grid[i-1][j+1] == 1){
                int to = (i-1)*m + j + 1;
                graph.addEdge(from, to);
            }
            
            // diagonal right down
            if(i + 1 < n && j + 1 < m && grid[i+1][j+1] == 1){
                int to = (i+1)*m + j + 1;
                graph.addEdge(from, to);
            }
        }
    }
    // graph.printGraph();
    // cout << "Graph Created successfully" << endl;
    result = graph.runBFS();
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    vector<vector<int>> grid(n);

    for (int i = 0; i < n; i++) {
        grid[i].resize(m);

        string grid_row_temp_temp;
        getline(cin, grid_row_temp_temp);

        vector<string> grid_row_temp = split(rtrim(grid_row_temp_temp));

        for (int j = 0; j < m; j++) {
            int grid_row_item = stoi(grid_row_temp[j]);

            grid[i][j] = grid_row_item;
        }
    }

    int res = maxRegion(grid);

    fout << res << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
