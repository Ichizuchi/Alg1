#include <stdio.h>
#include <cmath>

int calculateF(int n) {
    if (n == 1) {
        return 1;
    }
    else {
        return calculateF(n - 1) + (pow(2,(n - 1)));
    }
}

int main() {
    int n = 12;
    int result = calculateF(n);

    printf("F(%d) = %d\n", n, result);

    return 0;
}