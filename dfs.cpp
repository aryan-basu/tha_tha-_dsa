#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

class graph {
public:
    unordered_map<int, list<int>> adj;

    void insertEdges(int u, int v, vector<pair<int, int>>& edges) {
        pair<int, int> p = make_pair(u, v);
        edges.push_back(p);
    }

    void makeAdjList(vector<pair<int, int>>& edges) {
        for(auto i : edges) {
            int u =i.first;
            int v = i.second;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    void dfsTraversal(int node, unordered_map<int, bool>& visited, vector<int>& temp) {
        temp.push_back(node);
        visited[node] = 1;

        for(auto i : adj[node]) {
            if(!visited[i]) {
                dfsTraversal(i, visited, temp);
            }
        }

    }

    void print(vector<vector<int>>& ans) {
        // for(auto i : adj) {
        //     cout<<i.first<<"-> ";
        //     for(auto j : i.second) {
        //         cout<<j<<", ";
        //     }
        //     cout<<endl;
        // }
        for(auto i : ans) {
            for(auto j : i) {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

};

int main() {
    int m;
    cout<<"Enter the number of nodes"<<endl;
    cin>>m;

    int n;
    cout<<"Enter the number of edges"<<endl;
    cin>>n;

    graph g;
    vector<pair<int, int>> edges;

    for(int i=0; i<n; i++) {
        int u, v;
        cin>>u>>v;
        g.insertEdges(u, v, edges);
    }

    g.makeAdjList(edges);

    vector<vector<int>> ans;
    unordered_map<int, bool> visited;
    for(int i=0; i<m; i++) {
        if(!visited[i]) {
            vector<int> temp;
            g.dfsTraversal(i, visited, temp);
            ans.push_back(temp);
        }
    }

    g.print(ans);


    return 0;
}