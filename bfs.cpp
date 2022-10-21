#include <iostream>
#include<vector>
#include<list>
#include<unordered_map>
#include<queue>
using namespace std;

class graph {
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction, vector<pair<int, int>>& edges) {
        pair<int, int> p1;

        p1 = make_pair(u,v);
        edges.push_back(p1);
    }

    void MakeAdjList(vector<pair<int, int>>& edges) {
        for(int i=0; i<edges.size(); i++) {
            int u = edges[i].first;
            int v = edges[i].second;

            adj[u].push_back(v);
            adj[v].push_back(u);

        }
    }

    void print(vector<int> ans) {
        // for(auto i : adj) {
        //     cout<<i.first<<"-> ";
        //     for(auto j : i.second) {
        //         cout<<j<<", ";
        //     }
        //     cout<<endl;
        // }
        for(auto x : ans) {
            cout<<x<<" ";
        }

    }

    void bfsTraversal(unordered_map<int, bool>& visited, vector<int>& ans, int node) {

       queue<int> q;
       q.push(node);
       visited[node] = 1;

       while(!q.empty()) {
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for(auto i : adj[node]) {
            if(!visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
        }

       }


    }

};

int main() {
    vector<pair<int, int>> edges;
    graph g;

    int m;
    cout<<"Enter the number of nodes"<<endl;
    cin>>m;

    int n;
    cout<<"Enter the number of edges"<<endl;
    cin>>n;

    for(int i=0; i<n; i++) {
        int u, v;
        cin>>u>>v;
        g.addEdge(u, v, 0, edges);
    }
    cout<<endl;

    g.MakeAdjList(edges);

    // g.print();

    unordered_map<int, bool> visited;
    vector<int> ans;

    for(int i=0; i<m; i++) {
        if(!visited[i]) {
            g.bfsTraversal(visited, ans, i);
        }
    }



    g.print(ans);


    return 0;
}