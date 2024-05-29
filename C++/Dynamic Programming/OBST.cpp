#include <iostream>
#include <climits>

void optimal_bst(int n, double q[]) {
    double e[n + 2][n + 1];
    double w[n + 2][n + 1];
    int root[n + 1][n + 1];

    for (int i = 1; i <= n + 1; ++i) {
        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    for (int l = 1; l <= n; ++l) {
        for (int i = 1; i <= n - l + 1; ++i) {
            int j = i + l - 1;
            e[i][j] = INT_MAX;
            w[i][j] = w[i][j - 1] + q[j];

            for (int r = i; r <= j; ++r) {
                double t = e[i][r - 1] + e[r + 1][j] + w[i][j];
                if (t < e[i][j]) {
                    e[i][j] = t;
                    root[i][j] = r;
                }
            }
        }
    }

    // Output e and root tables
    std::cout << "Expected Cost Table (e):" << std::endl;
    for (int i = 1; i <= n + 1; ++i) {
        for (int j = 0; j <= n; ++j) {
            std::cout << e[i][j] << " ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl << "Root Table:" << std::endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            std::cout << root[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cout << "Enter the number of keys: ";
    std::cin >> n;

    double q[n];
    std::cout << "Enter the probabilities of accessing keys: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> q[i];
    }

    optimal_bst(n, q);

    return 0;
}
