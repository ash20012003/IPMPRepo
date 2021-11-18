// Prims Algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#define V 8
#define I 32767

using namespace std;
 
void PrintMST(int T[][V-2], int G[V][V]){
    cout << "\nMinimum Spanning Tree Edges (w/ cost)\n" << endl;
    int sum {0};
    for (int i {0}; i<V-2; i++){
        int c = G[T[0][i]][T[1][i]];
        cout << "[" << T[0][i] << "]---[" << T[1][i] << "] cost: " << c << endl;
        sum += c;
    }
    cout << endl;
    cout << "Total cost of MST: " << sum << endl;
}
 
void PrimsMST(int G[V][V], int n){
    int u;
    int v;
    int min {I};
    int track [V];
    int T[2][V-2] {0};
 
    // Initial: Find min cost edge
    for (int i {1}; i<V; i++){
        track[i] = I;  // Initialize track array with INFINITY
        for (int j {i}; j<V; j++){
            if (G[i][j] < min){
                min = G[i][j];
                u = i;
                v = j;
            }
        }
    }
    T[0][0] = u;
    T[1][0] = v;
    track[u] = track[v] = 0;
 
    // Initialize track array to track min cost edges
    for (int i {1}; i<V; i++){
        if (track[i] != 0){
            if (G[i][u] < G[i][v]){
                track[i] = u;
            } else {
                track[i] = v;
            }
        }
    }
 
    // Repeat
    for (int i {1}; i<n-1; i++){
        int k;
        min = I;
        for (int j {1}; j<V; j++){
            if (track[j] != 0 && G[j][track[j]] < min){
                k = j;
                min = G[j][track[j]];
            }
        }
        T[0][i] = k;
        T[1][i] = track[k];
        track[k] = 0;
 
        // Update track array to track min cost edges
        for (int j {1}; j<V; j++){
            if (track[j] != 0 && G[j][k] < G[j][track[j]]){
                track[j] = k;
            }
        }
    }
    PrintMST(T, G);
}
 
int main() {
 
    int cost [V][V] {
            {I, I, I, I, I, I, I, I},
            {I, I, 25, I, I, I, 5, I},
            {I, 25, I, 12, I, I, I, 10},
            {I, I, 12, I, 8, I, I, I},
            {I, I, I, 8, I, 16, I, 14},
            {I, I, I, I, 16, I, 20, 18},
            {I, 5, I, I, I, 20, I, I},
            {I, I, 10, I, 14, 18, I, I},
    };
 
    int n = sizeof(cost[0])/sizeof(cost[0][0]) - 1;
 
    PrimsMST(cost, n);
 
    return 0;
}

/*
Data structures required are :
i) Adjacency matrix (instead of zeroes, we use INT_MAX here)
ii) a 2d array with 2 rows and (n-1) columns that store the vertices of traversal
iii) a 1d array of size n which is going to be called as the near array

1) Find the minimum weighted edge by iterating through the adjacency matrix
2) update the t matrix with the first pair of vertices that had the minimum cost. Let the vertices be u and v.
3) update near[u] and near[v] to zero.
4)now iterate i from 1 to n:
	now check the column of u and v and compare the value. 
		if u's value is less then put near[i] = u else vice versa
(Still here was the initial stage. Only from now the actual algorithm starts)

// if near[i] = 0  then it means that node has been considered for minimum spanning tree.

5) for i from 1 to n-2:
		have a min variable
		for j from 1 to n:
			traverse through the near array, if the cost of (j, unused vertex i.e near[j] if it is not zero) is less than min 
			=> update min
			assign a variable k to j(k stores the value of the vertex and its near that hold the next minimum weighted edge)
		update t[0][i] to k
		update t[1][i] to near[k]
		since k is now used for mst, make near[k] = 0

		now the near array must be updated again
		for j from 1 to n:
			if a vertex is unused in mst and cost[j][k] < cost[j][near[j]]:
				update near[j] to k
6) print the data of t.

*/