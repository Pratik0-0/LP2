#include <iostream>

using namespace std;

int main() {

    int n;

    cout << "Enter number of elements: ";

    cin >> n;

    int arr[n];

    cout << "Enter elements:\n";

    for(int i = 0; i < n; i++) {

        cin >> arr[i];

    }

    // Selection Sort

    for(int i = 0; i < n - 1; i++) {

        int minIndex = i;

        for(int j = i + 1; j < n; j++) {

            if(arr[j] < arr[minIndex]) {

                minIndex = j;

            }

        }

        // Swap

        int temp = arr[i];

        arr[i] = arr[minIndex];

        arr[minIndex] = temp;

    }

    cout << "Sorted array:\n";

    for(int i = 0; i < n; i++) {

        cout << arr[i] << " ";

    }

    return 0;

}

// #include <iostream>
// #include <algorithm>
// using namespace std;

// struct Edge {
//     int src, dest, weight;
// };

// bool compare(Edge a, Edge b) {
//     return a.weight < b.weight;
// }

// int parent[100];

// int find(int i) {
//     while(parent[i] != i)
//         i = parent[i];
//     return i;
// }

// void unionSet(int a, int b) {
//     parent[a] = b;
// }

// int main() {

//     int V = 4;
//     int E = 5;

//     Edge edges[] = {
//         {0, 1, 10},
//         {0, 2, 6},
//         {0, 3, 5},
//         {1, 3, 15},
//         {2, 3, 4}
//     };

//     sort(edges, edges + E, compare);

//     for(int i = 0; i < V; i++)
//         parent[i] = i;

//     cout << "Edges in MST:\n";

//     for(int i = 0; i < E; i++) {

//         int a = find(edges[i].src);
//         int b = find(edges[i].dest);

//         if(a != b) {
//             cout << edges[i].src << " - "
//                  << edges[i].dest
//                  << " : " << edges[i].weight << endl;

//             unionSet(a, b);
//         }
//     }

//     return 0;
// }