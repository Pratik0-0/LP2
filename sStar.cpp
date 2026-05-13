#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;


typedef pair<int , int> pr;

vector<pr> graph[10];

vector<int> hist(10);

void aStar(int start, int goal, int n){

    priority_queue<pr, vector<pr>, greater<pr >> pq;

    vector<int> g(n, 1e9);
    vector<int> parent(n, -1);

    g[start] = 0;

    pq.push({hist[start], start});

    while(! pq.empty()){

        int node = pq.top().second;
        pq.pop();

        if(node == goal)
            break ;
        
        for(auto x : graph[node]){
            int neigh = x.second;
            int cost = x.first;

            int new_g = g[node] + cost;

            if(new_g < g[neigh]){
                g[neigh] = new_g;

                int f = new_g + hist[neigh];
                pq.push({f, neigh});

                parent[neigh] = node;
            }
        }
    }
    // Print path

    vector<int> path;

    for (int v = goal; v != -1; v = parent[v])

        path.push_back(v);

    cout << "Path: ";

    for (int i = path.size() - 1; i >= 0; i--)

        cout << path[i] << " ";

    cout << "\nCost: " << g[goal] <<endl;

}

int main()

{

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

    hist[0] = 7;

    hist[1] = 6;

    hist[2] = 2;

    hist[3] = 1;

    hist[4] = 3;

    hist[5] = 0;

    aStar(0, 5, n);

    return 0;

}

