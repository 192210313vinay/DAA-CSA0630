#include <stdio.h>
#include <stdbool.h>

#define V 4  // Number of vertices in the graph
#define COLORS 3  // Number of colors

bool isSafe(int v, bool graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;
    return true;
}

bool graphColoringUtil(bool graph[V][V], int m, int color[], int v) {
    if (v == V) return true;

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;
            if (graphColoringUtil(graph, m, color, v + 1))
                return true;
            color[v] = 0;
        }
    }
    return false;
}

bool graphColoring(bool graph[V][V], int m) {
    int color[V] = {0};
    if (!graphColoringUtil(graph, m, color, 0)) {
        printf("Solution does not exist\n");
        return false;
    }
    printf("Solution Exists: Assigned colors: ");
    for (int i = 0; i < V; i++)
        printf("%d ", color[i]);
    printf("\n");
    return true;
}

int main() {
    bool graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0},
    };
    int m = COLORS;
    graphColoring(graph, m);
    return 0;
}

