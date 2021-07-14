// Problem: https://www.hackerrank.com/challenges/ctci-bfs-shortest-reach/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=graphs
// Intuition: When distance is common, bfs helps us find the minimum distance without dijkstras
// just run bfs
#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
        int nodes;
        vector< vector<int> > neighbours;
        vector<int> distance;
        vector<bool> visited;
        Graph(int n) {
            nodes = n;
            neighbours = vector< vector<int> >(nodes, vector<int>());
            distance = vector<int>(nodes, numeric_limits<int>::max());
            visited = vector<bool>(nodes, false);
        }
    
        void add_edge(int u, int v) {
            neighbours[u].push_back(v);
            neighbours[v].push_back(u);
        }
    
        vector<int> shortest_reach(int start) {
            vector<int> result;
            
            distance[start] = 0;
            queue<int> q;
            q.push(start);
            
            while(!q.empty()){
                int currentNode = q.front();
                if(visited[currentNode]){
                    q.pop();
                    continue;
                    
                }
                visited[currentNode] = true;
                q.pop();
                
                for(int i=0; i<neighbours[currentNode].size(); i++){
                    int currentNeighbour = neighbours[currentNode][i];
                    if(!visited[currentNeighbour]){
                        q.push(currentNeighbour);
                        if(distance[currentNeighbour] > distance[currentNode] + 6){
                            distance[currentNeighbour] = distance[currentNode] + 6;
                        }
                    }
                }
                
            }
            
            // now we have some distance array
            //cout << "Distance array is: " << endl;
            for(int i=0; i<distance.size(); i++){
                if(distance[i] == numeric_limits<int>::max()){
                    result.push_back(-1);
                } else {
                    result.push_back(distance[i]);
                }
            }
            
            return result;
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
		int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
		int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}