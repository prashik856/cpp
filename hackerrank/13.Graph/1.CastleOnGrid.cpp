// Problem:  https://www.hackerrank.com/challenges/castle-on-the-grid/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=stacks-queues
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minimumMoves' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING_ARRAY grid
 *  2. INTEGER startX
 *  3. INTEGER startY
 *  4. INTEGER goalX
 *  5. INTEGER goalY
 */

// Using dijkstras algorithm using set and arrays
class Graph {
    public:
        int nodes;
        vector< vector<int> > neighbours;
        set< vector<int> > distance;
        vector<bool> visited;
        int maxValue = numeric_limits<int>::max();
        vector<int> distanceArray;
        
        Graph(int nodesValue, int startValue) {
            nodes = nodesValue;
            neighbours = vector< vector<int> >(nodes, vector<int>());
            distance = set< vector<int> >();
            visited = vector<bool>(nodes, false);
            distanceArray = vector<int>(nodes, maxValue);
            distanceArray[startValue] = 0;
        }
        
        void addEdge(int from, int to){
            neighbours[from].push_back(to);
        }
        
        void printGraph(){
            cout << "Current Graph is: " << endl;
            for(int i=0; i<nodes; i++){
                cout << i << " -> ";
                for(int j=0; j<neighbours[i].size(); j++){
                    cout << neighbours[i][j]  << " ";
                }
                cout << endl;
            }
        }
        
        void printDistance() {
            cout << "Distance set value is: " << endl;
            for(auto it = distance.begin(); it != distance.end(); it++){
                vector<int> distanceNode = *it;
                cout << "distance: " << distanceNode[0] << " | " << "index: " << distanceNode[1] << endl;
            }
            cout << endl;
        }
        
        int dijkstras(int start, int goal){
            vector<int> distanceNode;
            distanceNode.push_back(distanceArray[start]);
            distanceNode.push_back(start);
            distance.insert(distanceNode);
            
            for(int i=0; i<nodes; i++){
                //printDistance();
                vector<int> distanceNode = *distance.begin();
                distance.erase(distance.begin());
                int currentNode = distanceNode[1];
                int nodeDistance = distanceNode[0];
                if(visited[currentNode]){
                    continue;
                }
                //cout << "Visiting node: " << currentNode << endl;
                
                if(currentNode == goal){
                    cout << "Reached Goal" << endl;
                    return nodeDistance;
                }
                visited[currentNode] = true;
                
                for(int j=0; j<neighbours[currentNode].size(); j++){
                    // Update all the neighbours
                    int currentNeighbour = neighbours[currentNode][j];
                    //cout << "Current Neighbour: " << currentNeighbour << endl;
                    if(!visited[currentNeighbour] && distanceArray[currentNeighbour] > 1 + distanceArray[currentNode]) {
                        distanceArray[currentNeighbour] = distanceArray[currentNode] + 1;
                        distanceNode = vector<int>();
                        distanceNode.push_back(distanceArray[currentNeighbour]);
                        distanceNode.push_back(currentNeighbour);
                        distance.insert(distanceNode);
                    }
                }
            }
            
            return 0;
        }
};

int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    int result = 0;
    int n = grid.size();
    // get start and goal
    int start = startX * n + startY;
    int goal = goalX * n + goalY;
    // cout << "Start: " << start << endl;
    // cout << "Goal: " << goal << endl;
    // Create graph here
    Graph graph(n*n, start);
    
    for(int i=0; i<grid.size(); i++){
        for(int j=0; j<grid[i].size(); j++){
            // this is the point.
            char value = grid[i][j];
            
            // Not need to add any edges for blockage
            if(value == 'X'){
                continue;
            }
            
            // first go right
            for(int k=i+1; k<grid.size(); k++){
                char pathValue = grid[k][j];
                if(pathValue == '.'){
                    // add path
                    graph.addEdge(i*n + j, k*n + j);
                } else if(pathValue == 'X') {
                    // break
                    break;
                }
            }
            
            // go left
            for(int k=i-1; k>=0; k--){
                char pathValue = grid[k][j];
                if(pathValue == '.'){
                    // add path
                    graph.addEdge(i*n + j, k*n + j);
                } else if(pathValue == 'X') {
                    // break
                    break;
                }
            }
            
            // go down
            for(int k=j+1; k<grid.size(); k++){
                char pathValue = grid[i][k];
                if(pathValue == '.'){
                    // add path
                    graph.addEdge(i*n + j, i*n + k);
                } else if(pathValue == 'X') {
                    // break
                    break;
                }
            }
            
            // go up
            for(int k=j-1; k>=0; k--){
                char pathValue = grid[i][k];
                if(pathValue == '.'){
                    // add path
                    graph.addEdge(i*n + j, i*n + k);
                } else if(pathValue == 'X') {
                    // break
                    break;
                }
            }
        }
    }
    
    //graph.printGraph();
    //graph.printDistance();
    result = graph.dijkstras(start, goal);
    
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> grid(n);

    for (int i = 0; i < n; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int startX = stoi(first_multiple_input[0]);

    int startY = stoi(first_multiple_input[1]);

    int goalX = stoi(first_multiple_input[2]);

    int goalY = stoi(first_multiple_input[3]);

    int result = minimumMoves(grid, startX, startY, goalX, goalY);

    fout << result << "\n";

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
