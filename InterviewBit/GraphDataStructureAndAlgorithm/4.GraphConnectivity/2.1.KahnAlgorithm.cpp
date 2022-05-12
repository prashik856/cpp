// Page: https://www.geeksforgeeks.org/topological-sorting-indegree-based-solution/
#include<bits/stdc++.h>
using namespace std;

/*
Algorithm: Steps involved in finding the topological ordering of a DAG: 
Step-1: Compute in-degree (number of incoming edges) for each of the vertex present in the DAG 
and initialize the count of visited nodes as 0.
Step-2: Pick all the vertices with in-degree as 0 and add them into a queue (Enqueue operation)
Step-3: Remove a vertex from the queue (Dequeue operation) and then. 
 -> Increment count of visited nodes by 1.
 -> Decrease in-degree by 1 for all its neighbouring nodes.
 -> If in-degree of a neighbouring nodes is reduced to zero, then add it to the queue.
Step 4: Repeat Step 3 until the queue is empty.
Step 5: If count of visited nodes is not equal to the number of nodes in the graph then the topological sort is not 
possible for the given graph.
*/
int main(){
    int a = 2;
    vector< vector<int> > b = {
        {1, 2},
        {2, 1}
    };
    
    // Create adjacency graph
    vector< vector<int> > adj(a+1, vector<int>());
    // Create degree graph
    vector<int> degree(a+1, 0);

    for(int i=0; i<b.size(); i++){
        int from = b[i][0];
        int to = b[i][1];
        adj[from].push_back(to);
        // Increasing degree of to as it requires from
        degree[to]++;
    }

    // push all nodes inside q whole degree is 0
    queue<int> q;
    for(int i=1; i<degree.size(); i++){
        if(degree[i] == 0){
            q.push(i);
        }
    }

    vector<int> visited;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        // put top in visited
        visited.push_back(top);

        // go through all neighbours
        for(int i=0; i<adj[top].size(); i++){
            int neighbour = adj[top][i];
            // decrease degree of all neighbours
            degree[neighbour]--;
            // if degree of a neighbour reaches 0, push it to queue
            if(degree[neighbour] == 0){
                q.push(neighbour);
            }
        }
    }

    if(visited.size() == a){
        cout << "Topological sort is possible" << endl;
    } else {
        cout << "Not possible" << endl;
    }

    return 0;
}