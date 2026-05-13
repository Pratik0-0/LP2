#include<algorithm>
#include<iostream>
#include<queue>
#include <algorithm>

using namespace std;


typedef pair<int, int> pr;

// for storing the graph edge cost to  neighbour
vector<pr> graph[10];
//heuristic values
int h[10];

void aStar(int start, int goal, int n){

    //priority queue to handle the smales heuristic cost

    priority_queue<pr, vector<pr>, greater<pr>> pq;

    vector<int> g(n, 1e9);// meaure shortest path
    vector<int> parent(n, -1);// -1 means no parent

    g[start] = 0;

    pq.push({h[start], start});

    while(! pq.empty()){
        int node = pq.top().second;

        pq.pop();

        if(node == goal)
            break;
        
        for(auto x : graph[node]){
            int neigh = x.first;
            int cost = x.second;

            int temp_g = cost + g[node];

            if(temp_g < g[neigh]){
                g[neigh] = temp_g;

                int f = cost + h[neigh];

                pq.push({f, neigh});

                parent[neigh] = node;
            }

        }


        
    }
    vector<int> path;

        for(int e = goal; e != -1; e = parent[e]){
            path.push_back(e);
        }
        reverse(path.begin(), path.end());

        for(int i : path){
            cout << i << " ";


        }

        cout << "\n Cost is " << g[goal];
}




int main(){
    int n = 6;

    // Add edges

    graph[0].push_back({1, 2});

    graph[0].push_back({2, 4});

    graph[1].push_back({3, 7});

    graph[1].push_back({4, 3});

    graph[2].push_back({4, 1});

    graph[3].push_back({5, 1});

    graph[4].push_back({5, 5});

    // Heuristic values to goal node 5

    h[0] = 7;

    h[1] = 6;

    h[2] = 2;

    h[3] = 1;

    h[4] = 3;

    h[5] = 0;

    aStar(0, 5, n);

    return 0;
}