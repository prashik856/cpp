// Problem: https://www.hackerrank.com/challenges/torque-and-development/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=graphs
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'roadsAndLibraries' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER c_lib
 *  3. INTEGER c_road
 *  4. 2D_INTEGER_ARRAY cities
 */

class Graph{
  public:
    int nodes;
    vector< vector<int> > neighbours;
    vector<bool> visited;
    Graph(int nodesValue, vector< vector<int> > cities) {
        nodes = nodesValue;
        neighbours = vector< vector<int> > (nodes, vector<int>());
        for(int i=0; i<cities.size(); i++){
            int from = cities[i][0] - 1;
            int to = cities[i][1] - 1;
            neighbours[from].push_back(to);
            neighbours[to].push_back(from);
        }
        visited = vector<bool> (nodes, false);
    }
    
    int BFS(int node){
        // cout << "Starting BFS for node: " << node << endl;
        int count = 0;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int nodeVisited = q.front();
            if(visited[nodeVisited]){
                // Node is already visited
                // cout << "Node: " << nodeVisited << " is already visited" << endl;
                q.pop();
                continue;
            }
            visited[nodeVisited] = true;
            // cout << "Visiting node: " << nodeVisited << endl;
            count++;
            q.pop();
            // Go to all neighbours
            for(int i=0; i<neighbours[nodeVisited].size(); i++){
                int currentNeighbour = neighbours[nodeVisited][i];
                // if neighbour is unvisited, put it inside queue
                if(!visited[currentNeighbour]){
                    q.push(currentNeighbour);
                }
            }
        }
        return count;
    }
};

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities) {
    long result = 0;
    
    // base case
    if(n==1){
        result = (long) c_lib;
        return result;
    }
    
    // c_lib == c_road
    if(c_lib == c_road) {
        long tempN = (long) n;
        long tempCRoad = (long) c_road;
        result = tempN * tempCRoad;
        return result;
    }
    
    // Initialising our graph
    Graph graph(n, cities);
    
    long road = c_road;
    long lib = c_lib;
    for(int i=0; i<n; i++){
        long constructRoadCost = 0;
        long constructLibraryCost = 0;
        long mstCost = 0;
        int node = i;
        // if node is already visited, continue
        if(graph.visited[node]){
            continue;
        } else {
            // cout << "Running bfs on " << i << endl;
            // node is not visited
            // run bfs and get all connected nodes
            long nodesConnected = graph.BFS(node);
            // cout << "Nodes connected: " << nodesConnected << endl;
            constructRoadCost = (nodesConnected - 1) * road;
            constructLibraryCost = lib;
            mstCost = constructRoadCost + constructLibraryCost;
            result = result + mstCost;
        }
    }
    
    long constructOnlyLibraries = n * lib;
    if(constructOnlyLibraries < result){
        result = constructOnlyLibraries;
    }
    // cout << endl;
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int c_lib = stoi(first_multiple_input[2]);

        int c_road = stoi(first_multiple_input[3]);

        vector<vector<int>> cities(m);

        for (int i = 0; i < m; i++) {
            cities[i].resize(2);

            string cities_row_temp_temp;
            getline(cin, cities_row_temp_temp);

            vector<string> cities_row_temp = split(rtrim(cities_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                int cities_row_item = stoi(cities_row_temp[j]);

                cities[i][j] = cities_row_item;
            }
        }

        long result = roadsAndLibraries(n, c_lib, c_road, cities);

        fout << result << "\n";
    }

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
