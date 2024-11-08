#include <iostream>
#include <vector>

using namespace std;

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

vector<vector<int>> multiplyMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int rowsB = B.size();
    int colsB = B[0].size();

    vector<vector<int>> result(rowsA, vector<int>(colsB, 0));

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return result;
}

vector<vector<int>> addMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int rows = A.size();
    int cols = A[0].size();

    vector<vector<int>> result(rows, vector<int>(cols));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}

int main() {
    vector<vector<int>> matrix2x2 = {{1, 2}, {3, 4}};
    vector<vector<int>> matrix2x3 = {{1, 2, 3}, {4, 5, 6}};
    vector<vector<int>> matrix3x2 = {{1, 2}, {3, 4}, {5, 6}};
    vector<vector<int>> matrix3x3 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int choice1, choice2, operation;

    cout << "Select matrix M (1: 2x2, 2: 2x3, 3: 3x2, 4: 3x3): ";
    cin >> choice1;
    cout << "Select matrix N (1: 2x2, 2: 2x3, 3: 3x2, 4: 3x3): ";
    cin >> choice2;

    vector<vector<int>> M, N;
    switch (choice1) {
        case 1: M = matrix2x2; break;
        case 2: M = matrix2x3; break;
        case 3: M = matrix3x2; break;
        case 4: M = matrix3x3; break;
        default: cout << "Invalid choice for M!"; return 1;
    }
    switch (choice2) {
        case 1: N = matrix2x2; break;
        case 2: N = matrix2x3; break;
        case 3: N = matrix3x2; break;
        case 4: N = matrix3x3; break;
        default: cout << "Invalid choice for N!"; return 1;
    }

    cout << "Select operation (1: Add, 2: Multiply): ";
    cin >> operation;

    cout << "\nMatrix M:\n";
    printMatrix(M);
    cout << "Matrix N:\n";
    printMatrix(N);

    if (operation == 1) {
        if (M.size() == N.size() && M[0].size() == N[0].size()) {
            vector<vector<int>> result = addMatrices(M, N);
            cout << "\nResult of Addition:\n";
            printMatrix(result);
        } else {
            cout << "\nERROR: Cannot add these Matrices.\n";
        }
    } else if (operation == 2) {
        if (M[0].size() == N.size()) {
            vector<vector<int>> result = multiplyMatrices(M, N);
            cout << "\nResult of Multiplication:\n";
            printMatrix(result);
        } else {
            cout << "\nERROR: Cannot multiply these matrices.\n";
        }
    } else {
        cout << "Invalid operation!\n";
    }

    return 0;
}
