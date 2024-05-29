#include <iostream>
using namespace std;

int knapsack(int W, int wt[], int val[], int n) {
    int V[n + 1][W + 1];

    for (int w = 0; w <= W; w++)
        V[0][w] = 0;

    for (int i = 1; i <= n; i++)
        V[i][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i - 1] <= w) {
                if (val[i - 1] + V[i - 1][w - wt[i - 1]] > V[i - 1][w]) {
                    V[i][w] = val[i - 1] + V[i - 1][w - wt[i - 1]];
                } else {
                    V[i][w] = V[i - 1][w];
                }
            } else {
                V[i][w] = V[i - 1][w];
            }
        }
    }
    return V[n][W];
}

int main() {
    int W, n;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;
    cout << "Enter the number of items: ";
    cin >> n;

    int wt[n], val[n];

    cout << "Enter the weights of items: ";
    for (int i = 0; i < n; i++)
        cin >> wt[i];

    cout << "Enter the values of items: ";
    for (int i = 0; i < n; i++)
        cin >> val[i];

    int max_value = knapsack(W, wt, val, n);
    cout << "Maximum value that can be achieved: " << max_value << endl;

    return 0;
}
