#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 10000; 
    int maxDifference = 0;
    int countPairs = 0;

    int* sequence = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        sequence[i] = rand() % 10000 + 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int difference = abs(sequence[i] - sequence[j]);

        if ((difference % 45 == 0) && (sequence[i] % 18 == 0 || sequence[j] % 18 == 0)) {
                countPairs++;

        if (difference > maxDifference) {
           maxDifference = difference;
                }
            }
        }
    }
    printf("Number of pairs with difference a multiple of 45 and at least one multiple of 18: %d\n", countPairs);
    printf("Maximum difference among such pairs: %d\n", maxDifference);
    return 0;
}