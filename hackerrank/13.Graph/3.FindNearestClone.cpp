// Problem: https://www.hackerrank.com/challenges/find-the-nearest-clone/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=graphs
// Intuition: BFS for constant length gives minimum distance to a node.
// Run bfs to all same colour nodes
#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the findShortest function below.

/*
 * For the unweighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] to <name>_to[i].
 *
 */
 class Graph{
    public:
        int nodes;
        vector< vector<int> > neighbours;
        vector<int> bfsRequired;
        vector<bool> visited;
        vector<int> distance;
        Graph(int nodesValue, vector<int> graph_to, vector<int> graph_from, vector<long> ids, int idVal){
            nodes = nodesValue;
            neighbours = vector< vector<int> >(nodes, vector<int>());
            visited = vector<bool>(nodes, false);
            distance = vector<int>(nodes, numeric_limits<int>::max());
            for(int i=0; i<graph_to.size(); i++){
                int from = graph_from[i] - 1;
                int to = graph_to[i] - 1;
                neighbours[from].push_back(to);
                neighbours[to].push_back(from);
            }
            for(int i=0; i<ids.size(); i++){
                long value = ids[i];
                if(value == idVal){
                    bfsRequired.push_back(i);
                }
            }
        }
        
        int runBFS(vector<long> ids, int val){
            int result = numeric_limits<int>::max();
            
            for(int i=0; i<bfsRequired.size(); i++){
                // cout << "Starting bfs from node: " << bfsRequired[i] << endl;
                visited = vector<bool>(nodes, false);
                distance = vector<int>(nodes, numeric_limits<int>::max());
                int node = bfsRequired[i];
                
                if(visited[node]){
                    continue;
                } 
                
                // start bfs from node
                queue<int> q;
                q.push(node);
                long nodeColour = val;
                distance[node] = 0;
                
                while(!q.empty()){
                    int currentNode = q.front();
                    if(visited[currentNode]){
                        q.pop();
                        continue;
                    }
                    visited[currentNode] = true;
                    long currentNodeColour = ids[currentNode];
                    if(currentNode != node && currentNodeColour == nodeColour){
                        // we found a node with minimum distance from node
                        result = min(distance[currentNode], result);
                        break;
                    }
                    
                    for(int j=0; j<neighbours[currentNode].size(); j++){
                        int currentNeighbour = neighbours[currentNode][j];
                        if(!visited[currentNeighbour]){
                            q.push(currentNeighbour);
                            if(distance[currentNeighbour] > distance[currentNode] + 1){
                                distance[currentNeighbour] = distance[currentNode] + 1;
                            }
                        }
                    }
                }
            }
            return result;
        }      
         
 };
 
int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val) {
    // solve here
    
    int result = -1;
    Graph graph(graph_nodes, graph_to, graph_from, ids, val);
    // cout << "ID : " << val << endl;
    // cout << "Run bfs on : " << endl;
    // for(int i=0; i<graph.bfsRequired.size(); i++){
    //     cout << graph.bfsRequired[i] << " ";
    // }

    result = graph.runBFS(ids, val);
    if(result == numeric_limits<int>::max()){
        result = -1;
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int graph_nodes;
    int graph_edges;

    cin >> graph_nodes >> graph_edges;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> graph_from(graph_edges);
    vector<int> graph_to(graph_edges);

    for (int i = 0; i < graph_edges; i++) {
        cin >> graph_from[i] >> graph_to[i];
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string ids_temp_temp;
    getline(cin, ids_temp_temp);

    vector<string> ids_temp = split_string(ids_temp_temp);

    vector<long> ids(graph_nodes);

    for (int i = 0; i < graph_nodes; i++) {
        long ids_item = stol(ids_temp[i]);

        ids[i] = ids_item;
    }

    int val;
    cin >> val;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    int ans = findShortest(graph_nodes, graph_from, graph_to, ids, val);

    fout << ans << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
