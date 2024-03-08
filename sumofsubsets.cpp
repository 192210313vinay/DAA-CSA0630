#include <stdio.h>

void findSubsets(int set[], int n, int subset[], int subsetSize, int total, int index, int target) {
    if (total == target) {
        for (int i = 0; i < subsetSize; i++) printf("%d ", subset[i]);
        printf("\n");
        return;
    }
    for (int i = index; i < n; i++) {
        subset[subsetSize] = set[i];
        findSubsets(set, n, subset, subsetSize + 1, total + set[i], i + 1, target);
    }
}

int main() {
    int set[] = {10, 7, 5, 18, 12};
    int target = 25;
    int n = sizeof(set) / sizeof(set[0]);
    int subset[n]; // Allocate subset array

    printf("Subsets with the sum %d are:\n", target);
    findSubsets(set, n, subset, 0, 0, 0, target);

    return 0;
}

