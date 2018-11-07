//
// Created by aSUSS on 2018/11/7.
//
#include "Dijkstra.h"

void Dijkstra(Graph g, int *dist, int *path, int source) {
    bool *visit = (bool *) malloc(sizeof(bool));

    for (int i = 0; i < g.n; ++i) {
        if (g.matrix[source][i] > 0) {
            dist[i] = g.matrix[source][i];
            path[i] = source;
        } else {
            dist[i] = INT_MAX;
            path[i] = -1;
        }
        visit[i] = false;
    }
    path[source]=source;
    dist[source]=0;
    visit[source] = true;
    for (int i = 1; i < g.n; ++i) {
        int min = INT_MAX;
        int bestNode;
        for (int j = 0; j < g.n; ++j) {
            if (!visit[j] && dist[j] < min) {
                min = dist[j];
                bestNode = j;
            }
        }
        visit[bestNode] = true;
        for (int k = 0; k < g.n; ++k) {
            if (!visit[k] && g.matrix[bestNode][k] > 0 && (min + g.matrix[bestNode][k]) < dist[k]) {
                dist[k] = min + g.matrix[bestNode][k];
                path[k] = bestNode;
            }
        }
    }
}

//int main() {
//    int dist[6];
//    int path[6];
//    Graph graph;
//    graph.n = 6;
//    graph.e = 8;
//    int a[6][6] = {-1, -1, 10, -1, 30, 100, -1, -1, 5, -1, -1, -1, -1, -1, -1, 50, -1, -1, -1, -1, -1, -1, -1, 10, -1,
//                   -1, -1, 20, -1, 60, -1, -1, -1, -1, -1, -1};
//    graph.matrix = (int **) malloc(sizeof(int *) * graph.n);
//    for (int i = 0; i < graph.n; i++)
//        graph.matrix[i] = (int *) malloc(sizeof(int) * graph.n);
//    for (int j = 0; j < graph.n; ++j) {
//        for (int i = 0; i < graph.n; ++i) {
//            graph.matrix[j][i] = a[j][i];
//        }
//    }
//    Dijkstra(graph, dist, path, 1);
//    for (int k = 0; k < graph.n; ++k) {
//        printf("%d ", path[k]);
//    }
//    printf("\n");
//    for (int k = 0; k < graph.n; ++k) {
//        printf("%d ", dist[k]);
//    }
//}

