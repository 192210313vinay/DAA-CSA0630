#include <stdio.h>
#include <stdbool.h>

#define V 5  // Number of vertices

bool isSafe(int v, int path[], int graph[V][V], int pos) {
    if (!graph[path[pos - 1]][v])
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool hamiltonianUtil(int graph[V][V], int path[], int pos) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]])
            return true;
        else
            return false;
    }

    for (int v = 1; v < V; v++) {
        if (isSafe(v, path, graph, pos)) {
            path[pos] = v;
            if (hamiltonianUtil(graph, path, pos + 1))
                return true;
            path[pos] = -1;
        }
    }

    return false;
}

void hamiltonianCycle(int graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;
    
    path[0] = 0;

    if (hamiltonianUtil(graph, path, 1)) {
        printf("Hamiltonian Cycle found: ");
        for (int i = 0; i < V; i++)
            printf("%d ", path[i]);
        printf("%d\n", path[0]);
    } else {
        printf("No Hamiltonian Cycle found.\n");
    }
}

int main() {
    int graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    hamiltonianCycle(graph);

    return 0;
}

