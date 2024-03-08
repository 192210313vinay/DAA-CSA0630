#include <stdio.h>


struct Item {
    int value;
    int weight;
};


int compare(const void *a, const void *b) {
    double ratioA = (double)(((struct Item *)a)->value) / ((struct Item *)a)->weight;
    double ratioB = (double)(((struct Item *)b)->value) / ((struct Item *)b)->weight;
    return (ratioB > ratioA) - (ratioB < ratioA);
}


void knapsackGreedy(struct Item items[], int n, int capacity) {
    
    qsort(items, n, sizeof(items[0]), compare);

    
    int currentWeight = 0;
    double totalValue = 0.0;

    
    int i;
    for ( i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            
            currentWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            
            double remainingCapacity = capacity - currentWeight;
            totalValue += (remainingCapacity / items[i].weight) * items[i].value;
            break;
        }
    }

    
    printf("Maximum value in the knapsack: %.2lf\n", totalValue);
}

int main() {
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;

    knapsackGreedy(items, n, capacity);

    return 0;
}

