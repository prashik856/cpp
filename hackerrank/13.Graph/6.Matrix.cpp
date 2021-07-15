// Problem: https://www.hackerrank.com/challenges/matrix/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=graphs
// Intuition: https://www.hackerrank.com/challenges/matrix/forum?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=graphs
// Sorting the edge weights in decending order. Since we need minimum time
// Have a mechanism in disjoint set to check if a set has a machine
// Usage of disjoint set
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'minTime' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. 2D_INTEGER_ARRAY roads
 *  2. INTEGER_ARRAY machines
 */

class FindResult{
    public:
        int node;
        bool isMachine;
        FindResult(int nodeValue, bool isMachineValue) {
            node = nodeValue;
            isMachine = isMachineValue;
        }
};

class DisjointSet{
    public:
        int n;
        vector<int> parent;
        vector<int> rank;
        vector<bool> hasMachine;
        DisjointSet(int nodes, vector<bool> &isMachine){
            n = nodes;
            parent = vector<int>(n, -1);
            rank = vector<int>(n, 0);
            // cout << "isMachine inside" << endl;
            // for(int i=0; i<isMachine.size(); i++){
            //     cout << isMachine[i] << " ";
            // }
            // cout << endl;
            hasMachine = vector<bool>(isMachine.begin(), isMachine.end());
            // cout << "has Machine array: " << endl;
            // for(int i=0; i<hasMachine.size(); i++){
            //     cout << hasMachine[i] << " ";
            // }
            // cout << endl;
        }
    
        FindResult find(int node){
            // We need some node with currentNode == parentNode
            int parentNode = parent[node];
            int currentNode = node;
            while(currentNode != parentNode){
                currentNode = parentNode;
                parentNode = parent[currentNode];
            }
            FindResult result(currentNode, hasMachine[currentNode]);
            return result;
        }
        
        
        
        void Union(int node1, int node2){
            FindResult root1 = find(node1);
            FindResult root2 = find(node2);
            
            // We got our roots
            // Check ranks
            if(rank[root1.node] > rank[root2.node]){
                // parent of root2 is root1
                parent[root2.node] = root1.node;
                // root2 is machine, root1 will be machine too
                if(hasMachine[root2.node]){
                    hasMachine[root1.node] = true;
                }
            } else {
                // parent of root1 is root2
                parent[root1.node] = root2.node;
                // vice versa here
                if(hasMachine[root1.node]){
                    hasMachine[root2.node] = true;
                }
                // If ranks are equal
                if(rank[root1.node] == rank[root2.node]){
                    // Increase rank of root2
                    rank[root2.node]++;
                }
            }
        }
};

int minTime(vector<vector<int>> roads, vector<int> machines) {
    int minTime = 0;
    int n = roads.size() + 1;
    int m = machines.size();
    vector<bool> isMachine(n, false);
    for(int i=0; i<machines.size(); i++){
        int node = machines[i];
        isMachine[node] = true;
    }
    
    // cout << "Is Machine array: " << endl;
    // for(int i=0; i<isMachine.size(); i++){
    //     cout << isMachine[i] << " ";
    // }
    // cout << endl;
    
    DisjointSet set(n, isMachine);
    
    // For sorted list of vertices
    vector< vector<int> > sortedRoads(roads.size(), vector<int>(3,0));
    for(int i=0; i<roads.size(); i++){
        // Initialize the disjoint set with parent
        set.parent[i] = i;
        sortedRoads[i][0] = roads[i][2];
        sortedRoads[i][1] = roads[i][0];
        sortedRoads[i][2] = roads[i][1];
    }
    set.parent[n-1] = n-1;
    sort(sortedRoads.begin(), sortedRoads.end());
    reverse(sortedRoads.begin(), sortedRoads.end());
    
    // cout << "Sorted roads: " << endl;
    // for(int i=0; i<sortedRoads.size(); i++){
    //     cout << sortedRoads[i][0] << " ";
    // }
    // cout << endl;
    
    // cout << "Checking disjoint set: " << endl;
    // cout << "Finding 0: " << set.find(0).node << " | Machine: " << set.find(0).isMachine << endl;
    // cout << "Finding 1: " << set.find(1).node << " | Machine: " << set.find(1).isMachine << endl;
    // cout << "Finding 2: " << set.find(2).node << " | Machine: " << set.find(2).isMachine << endl;
    // cout << "Finding 3: " << set.find(3).node << " | Machine: " << set.find(3).isMachine << endl;
    // cout << "Finding 4: " << set.find(4).node << " | Machine: " << set.find(4).isMachine << endl;
    
    // cout << "Joining 0 and 1, 2. Joining 3 and 4" << endl;
    // set.Union(0, 1);
    // set.Union(1, 2);
    // set.Union(3, 4);
    // cout << "Checking Disjoint set after joing: " << endl;
    // cout << "Finding 0: " << set.find(0).node << " | Machine: " << set.find(0).isMachine << endl;
    // cout << "Finding 1: " << set.find(1).node << " | Machine: " << set.find(1).isMachine << endl;
    // cout << "Finding 2: " << set.find(2).node << " | Machine: " << set.find(2).isMachine << endl;
    // cout << "Finding 3: " << set.find(3).node << " | Machine: " << set.find(3).isMachine << endl;
    // cout << "Finding 4: " << set.find(4).node << " | Machine: " << set.find(4).isMachine << endl;
    
    // Now we join disjoint sets
    for(int i=0; i<sortedRoads.size(); i++){
        int time = sortedRoads[i][0];
        int from = sortedRoads[i][1];
        int to = sortedRoads[i][2];
        
        FindResult fromResult = set.find(from);
        FindResult toResult = set.find(to);
        
        bool fromHasMachine = fromResult.isMachine;
        bool toHasMachine = toResult.isMachine;
        
        if(!(fromHasMachine && toHasMachine)){
            // if both of them don't have machines
            // join both of them
            set.Union(from, to);
        } else {
            minTime = minTime + time;
        }
    }
    
    return minTime;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    vector<vector<int>> roads(n - 1);

    for (int i = 0; i < n - 1; i++) {
        roads[i].resize(3);

        string roads_row_temp_temp;
        getline(cin, roads_row_temp_temp);

        vector<string> roads_row_temp = split(rtrim(roads_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int roads_row_item = stoi(roads_row_temp[j]);

            roads[i][j] = roads_row_item;
        }
    }

    vector<int> machines(k);

    for (int i = 0; i < k; i++) {
        string machines_item_temp;
        getline(cin, machines_item_temp);

        int machines_item = stoi(ltrim(rtrim(machines_item_temp)));

        machines[i] = machines_item;
    }

    int result = minTime(roads, machines);

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
