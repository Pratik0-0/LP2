#include<iostream>
#include<algorithm>
#include<vector>
#include <queue>>

using namespace std;


class Graph{

    int n;
    vector<vector<int>> mat;

    public:
    Graph(int v){
        n = v;
        mat.resize(v, vector<int>(v, 0));
    }

    void g_print(){

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << mat[i][j];
            }
            cout << endl;
        }
    }

    void DFS (vector<bool> & visited, int start){
        cout << start << " ";
        visited[start] = true;
        for(int i = 0; i < n; i++){
            if(mat[start][i] == 1 && !visited[i]){
                
                DFS(visited, i);
            }
        }
    }

    void BFS(int start){
        

        queue<int> que;
        que.push(start);
        vector<bool> visited(n, false);
        visited[start] = true;

        while(!que.empty()){

            int cur = que.front();
            que.pop();
            cout << cur << " ";
            
            for(int i = 0; i < n; i++){
                if(mat[cur][i] == 1 && !visited[i]){
                    visited[i] = true;
                    que.push(i);
                }
            }
        }
    }

    void addEdge(int a, int b){
        mat[a][b] = mat[b][a] = 1;
    }
};

int main(){

    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(4, 1);
    g.addEdge(5, 3);
    g.g_print();

    vector<bool> visited(6, false);
    g.DFS(visited, 0);
    cout << "\n BFS" << endl;
    g.BFS(0);

    return 0;
}