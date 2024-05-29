#include <iostream>
#include <climits>
using namespace std;

void matrixChainOrder(int p[], int n, int m[][100], int s[][100]) {
    for (int i = 1; i <= n; i++)
        m[i][i] = 0;

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void printOptimalParentheses(int s[][100], int i, int j) {
    if (i == j)
        cout << "A" << i;
    else {
        cout << "(";
        printOptimalParentheses(s, i, s[i][j]);
        printOptimalParentheses(s, s[i][j] + 1, j);
        cout << ")";
    }
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    int p[n + 1];
    cout << "Enter the dimensions of matrices: ";
    for (int i = 0; i <= n; i++)
        cin >> p[i];

    int m[100][100], s[100][100];
    matrixChainOrder(p, n, m, s);

    cout << "Minimum number of multiplications: " << m[1][n] << endl;
    cout << "Optimal Parenthesization: ";
    printOptimalParentheses(s, 1, n);
    cout << endl;

    return 0;
}
