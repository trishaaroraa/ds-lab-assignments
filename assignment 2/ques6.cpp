#include <iostream>
using namespace std;

struct Term {
    int row, col, val;
};

class SparseMatrix {
public:
    int rows, cols, terms;
    Term data[100];    

    void read() {
        cout << "Enter number of rows, columns and non-zero terms: ";
        cin >> rows >> cols >> terms;

        cout << "Enter row col value for each non-zero element:\n";
        for (int i = 0; i < terms; i++) {
            cin >> data[i].row >> data[i].col >> data[i].val;
        }
    }

    void display() const {
        cout << "\nRow\tCol\tVal\n";
        for (int i = 0; i < terms; i++) {
            cout << data[i].row << "\t" 
                 << data[i].col << "\t" 
                 << data[i].val << "\n";
        }
    }

    SparseMatrix transpose() const {
        SparseMatrix t;     
        t.rows = cols;      
        t.cols = rows;
        t.terms = terms;

        for (int i = 0; i < terms; i++) {
            t.data[i].row = data[i].col;  
            t.data[i].col = data[i].row;
            t.data[i].val = data[i].val;
        }
        return t;
    }

    SparseMatrix add(const SparseMatrix& b) const {
        SparseMatrix c;   

        if (rows != b.rows || cols != b.cols) {
            cout << "Addition not possible!\n";
            c.rows = c.cols = c.terms = 0;
            return c;
        }

        c.rows = rows;
        c.cols = cols;

        int i = 0, j = 0, k = 0;

        while (i < terms && j < b.terms) {
            if (data[i].row < b.data[j].row ||
               (data[i].row == b.data[j].row && data[i].col < b.data[j].col)) {
                c.data[k++] = data[i++];
            }
            else if (b.data[j].row < data[i].row ||
                    (b.data[j].row == data[i].row && b.data[j].col < data[i].col)) {
                c.data[k++] = b.data[j++];
            }
            else {
                int sum = data[i].val + b.data[j].val;
                if (sum != 0) {
                    c.data[k].row = data[i].row;
                    c.data[k].col = data[i].col;
                    c.data[k].val = sum;
                    k++;
                }
                i++; j++;
            }
        }

        while (i < terms) c.data[k++] = data[i++];
        while (j < b.terms) c.data[k++] = b.data[j++];

        c.terms = k;
        return c;
    }

    SparseMatrix multiply(const SparseMatrix& b) const {
        SparseMatrix result;

        if (cols != b.rows) {
            cout << "Multiplication not possible!\n";
            result.rows = result.cols = result.terms = 0;
            return result;
        }

        result.rows = rows;
        result.cols = b.cols;
        result.terms = 0;

        SparseMatrix bT = b.transpose();
        int k = 0;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < b.cols; j++) {
                int sum = 0;

                for (int a = 0; a < terms; a++) {
                    if (data[a].row == i) {
                        for (int bt = 0; bt < bT.terms; bt++) {
                            if (bT.data[bt].row == j && bT.data[bt].col == data[a].col) {
                                sum += data[a].val * bT.data[bt].val;
                            }
                        }
                    }
                }

                if (sum != 0) {
                    result.data[k].row = i;
                    result.data[k].col = j;
                    result.data[k].val = sum;
                    k++;
                }
            }
        }

        result.terms = k;
        return result;
    }
};

int main() {
    SparseMatrix A, B, C;

    cout << "Enter first matrix:\n";
    A.read();
    cout << "First Matrix (Triplet form):";
    A.display();

    cout << "\nEnter second matrix:\n";
    B.read();
    cout << "Second Matrix (Triplet form):";
    B.display();

    cout << "\nMultiplication of matrices:";
    C = A.multiply(B);
    C.display();

    return 0;
}
