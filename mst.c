#include <stdio.h>
#include <stdlib.h>


struct Edge {
    int src, dest, weight;
};


struct Subset {
    int parent;
    int rank;
};


int find(struct Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}


void Union(struct Subset subsets[], int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}


void KruskalMST(struct Edge edges[], int V, int E) {
   
    qsort(edges, E, sizeof(edges[0]), [](const void* a, const void* b) {
        return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
    });

   
    struct Subset* subsets = (struct Subset*)malloc(V * sizeof(struct Subset));

    
    for (int i = 0; i < V; i++) {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    printf("Edges in the Minimum Spanning Tree:\n");

    int mstWeight = 0;
    for (int i = 0; i < E; i++) {
        int x = find(subsets, edges[i].src);
        int y = find(subsets, edges[i].dest);

        if (x != y) {
            printf("%d - %d (%d)\n", edges[i].src, edges[i].dest, edges[i].weight);
            mstWeight += edges[i].weight;
            Union(subsets, x, y);
        }
    }

    printf("Total Weight of MST: %d\n", mstWeight);

    // Free allocated memory
    free(subsets);
}

int main() {
    int V = 4;  // Number of vertices
    int E = 5;  // Number of edges

    struct Edge edges[] = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};

    KruskalMST(edges, V, E);

    return 0;
}

