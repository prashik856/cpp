// Problem: https://www.hackerrank.com/challenges/friend-circle-queries/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=miscellaneous
// Intuition: Disjoint Sets
#include <bits/stdc++.h>

using namespace std;

class DisjointSet {
    public: 
        unordered_map<int, int> parent;
        unordered_map<int, int> members;
        unordered_map<int, int> rank;
        int lasgestMembers = -1;
        vector<int> sizeOfParent;
        DisjointSet(){}
    
        void addNumbers(int a, int b){
            // Add these guys to disjoint set
            int isPresentA = parent[a];
            int isPresentB = parent[b];
            
            if(isPresentA == 0){
                // If not present
                // members are 1, and parent is self
                parent[a] = a;
                members[a] = 1;
                rank[a] = 0;
            }
            if(isPresentB == 0){
                parent[b] = b;
                members[b] = 1;
                rank[b] = 0;
            }
        }
        
        int find(int node){
            int temp = node;
            int parentOfTemp = parent[node];
            while(temp != parentOfTemp) {
                temp = parentOfTemp;
                parentOfTemp = parent[temp];
            }
            return temp;
        }
        
        void dsUnion(int a, int b){
            int roota = find(a);
            int rootb = find(b);
            
            // They already have a same root
            if(roota == rootb){
                return;
            }
            
            if(rank[roota] > rank[rootb]){
                // b is the child of a
                parent[rootb] = roota;
                members[roota] = members[roota] + members[rootb];
                lasgestMembers = max(lasgestMembers, members[roota]);
            } else {
                parent[roota] = rootb;
                members[rootb] = members[rootb] + members[roota];
                lasgestMembers = max(lasgestMembers, members[rootb]);
                if(rank[roota] == rank[rootb]){
                    // since b is parent, increase rank of rootb
                    rank[rootb] = rank[rootb] + 1;
                }
            }
        }
        
    
};

// Complete the maxCircle function below.
vector<int> maxCircle(vector<vector<int>> queries) {
    vector<int> result;
    
    // Test our disjoint set
    DisjointSet dsSet;
    for(int i=0; i<queries.size(); i++){
        int a = queries[i][0];
        int b = queries[i][1];
        dsSet.addNumbers(a, b);
        dsSet.dsUnion(a, b);
        result.push_back(dsSet.lasgestMembers);
    }
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> queries(q);
    for (int i = 0; i < q; i++) {
        queries[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> queries[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    vector<int> ans = maxCircle(queries);

    for (int i = 0; i < ans.size(); i++) {
        fout << ans[i];

        if (i != ans.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
