#include <iostream>
using namespace std;

class SparseMatrix {
    int data[20][3]; // [row, col, value]
    int rows, cols, terms;

public:
    void read() {
        cout << "Enter number of rows, columns and non-zero terms: ";
        cin >> rows >> cols >> terms;

        cout << "Enter triplet (row col value):\n";
        for (int i = 0; i < terms; i++)
            cin >> data[i][0] >> data[i][1] >> data[i][2];
    }

    void display() {
        cout << "\nRow\tCol\tValue\n";
        for (int i = 0; i < terms; i++)
            cout << data[i][0] << "\t" << data[i][1] << "\t" << data[i][2] << endl;
    }

    // Transpose of Sparse Matrix
    SparseMatrix transpose() {
        SparseMatrix t;
        t.rows = cols;
        t.cols = rows;
        t.terms = terms;

        int k = 0;
        for (int i = 0; i < cols; i++) {
            for (int j = 0; j < terms; j++) {
                if (data[j][1] == i) {
                    t.data[k][0] = data[j][1];
                    t.data[k][1] = data[j][0];
                    t.data[k][2] = data[j][2];
                    k++;
                }
            }
        }
        return t;
    }

    // Addition of two sparse matrices
    SparseMatrix add(SparseMatrix b) {
        SparseMatrix c;
        if (rows != b.rows || cols != b.cols) {
            cout << "Addition not possible!\n";
            c.terms = 0;
            return c;
        }

        c.rows = rows;
        c.cols = cols;
        int i = 0, j = 0, k = 0;

        while (i < terms && j < b.terms) {
            if (data[i][0] == b.data[j][0] && data[i][1] == b.data[j][1]) {
                c.data[k][0] = data[i][0];
                c.data[k][1] = data[i][1];
                c.data[k][2] = data[i][2] + b.data[j][2];
                i++; j++; k++;
            } else if (data[i][0] < b.data[j][0] ||
                      (data[i][0] == b.data[j][0] && data[i][1] < b.data[j][1])) {
                c.data[k][0] = data[i][0];
                c.data[k][1] = data[i][1];
                c.data[k][2] = data[i][2];
                i++; k++;
            } else {
                c.data[k][0] = b.data[j][0];
                c.data[k][1] = b.data[j][1];
                c.data[k][2] = b.data[j][2];
                j++; k++;
            }
        }

        while (i < terms) {
            c.data[k][0] = data[i][0];
            c.data[k][1] = data[i][1];
            c.data[k][2] = data[i][2];
            i++; k++;
        }

        while (j < b.terms) {
            c.data[k][0] = b.data[j][0];
            c.data[k][1] = b.data[j][1];
            c.data[k][2] = b.data[j][2];
            j++; k++;
        }

        c.terms = k;
        return c;
    }

    // Multiplication of two sparse matrices
    SparseMatrix multiply(SparseMatrix b) {
        SparseMatrix c;
        if (cols != b.rows) {
            cout << "Multiplication not possible!\n";
            c.terms = 0;
            return c;
        }

        b = b.transpose(); // transpose for easy column matching
        c.rows = rows;
        c.cols = b.rows;
        int k = 0;

        for (int i = 0; i < terms; i++) {
            for (int j = 0; j < b.terms; j++) {
                if (data[i][1] == b.data[j][1]) {
                    c.data[k][0] = data[i][0];
                    c.data[k][1] = b.data[j][0];
                    c.data[k][2] = data[i][2] * b.data[j][2];
                    k++;
                }
            }
        }

        c.terms = k;
        return c;
    }
};

int main() {
    SparseMatrix A, B, C;

    cout << "Enter first matrix:\n";
    A.read();

    cout << "\nEnter second matrix:\n";
    B.read();

    cout << "\nMatrix A:";
    A.display();

    cout << "\nMatrix B:";
    B.display();

    cout << "\nTranspose of A:";
    C = A.transpose();
    C.display();

    cout << "\nAddition (A + B):";
    C = A.add(B);
    C.display();

    cout << "\nMultiplication (A x B):";
    C = A.multiply(B);
    C.display();

    return 0;
}
