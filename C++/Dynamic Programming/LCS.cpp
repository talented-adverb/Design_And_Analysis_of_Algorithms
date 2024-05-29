#include <iostream>
#include <string>
#include <vector>
using namespace std;

pair<vector<vector<int>>, vector<vector<char>>> LCS_LENGTH(const string& X, const string& Y) {
    int m = X.length();
    int n = Y.length();
    
    vector<vector<int>> c(m + 1, vector<int>(n + 1, 0));
    vector<vector<char>> b(m + 1, vector<char>(n + 1, ' '));

    for (int i = 1; i <= m; i++)
        c[i][0] = 0;
    for (int j = 0; j <= n; j++)
        c[0][j] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'x';
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = '↑';
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = '←';
            }
        }
    }
    return {c, b};
}

void PRINT_LCS(const vector<vector<char>>& b, const string& X, int i, int j) {
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == 'x') {
        PRINT_LCS(b, X, i - 1, j - 1);
        cout << X[i - 1];
    } else if (b[i][j] == '↑') {
        PRINT_LCS(b, X, i - 1, j);
    } else {
        PRINT_LCS(b, X, i, j - 1);
    }
}

int main() {
    string X, Y;
    cout << "Enter the first sequence: ";
    cin >> X;
    cout << "Enter the second sequence: ";
    cin >> Y;

    auto result = LCS_LENGTH(X, Y);
    vector<vector<int>> c = result.first;
    vector<vector<char>> b = result.second;

    cout << "Length of Longest Common Subsequence: " << c[X.length()][Y.length()] << endl;
    cout << "Longest Common Subsequence: ";
    PRINT_LCS(b, X, X.length(), Y.length());
    cout << endl;

    return 0;
}
