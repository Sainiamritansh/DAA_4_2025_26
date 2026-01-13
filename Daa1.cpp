#include <iostream>
#include<vector>
#include<ctime>
using namespace std;

long long operations;
int maxDepth;

void complexRec(int n, int depth) {
    maxDepth = max(maxDepth, depth);

    if (n <= 2) return;

    int p = n;
    while (p > 0) {
        for (int i = 0; i < n; i++) {
            operations++;
        }
        p /= 2;
    }

    for (int i = 0; i < n; i++) {
        operations++;
    }

    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
    complexRec(n / 2, depth + 1);
}

int main() {

    vector<int> inputs = {8, 16, 32, 64, 128};

    for (int n : inputs) {
        operations = 0;
        maxDepth = 0;

        clock_t start = clock();
        complexRec(n, 1);
        clock_t end = clock();

        double timeTaken = (double)(end - start) * 1000 / CLOCKS_PER_SEC;

        cout << "n = " << n << endl;
        cout << "Operations = " << operations << endl;
        cout << "Recursion Depth = " << maxDepth << endl;
        cout << "Time = " << timeTaken << " ms" << endl;
    }

    return 0;
}
