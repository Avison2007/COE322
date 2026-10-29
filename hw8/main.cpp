
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdexcept>

using namespace std;

// Stores the coefficients of the triangle.
// This class only handles storage, reading, and writing.
class TriangleStorage {
private:
    vector<vector<unsigned long long>> data;

public:
    void setvalue(int i, int j, unsigned long long value) {
        if (i < 0 || j < 0 || j > i) {
            throw out_of_range("Invalid triangle index");
        }

        while (static_cast<int>(data.size()) <= i) {
            data.push_back(vector<unsigned long long>());
        }

        if (data[i].size() < static_cast<size_t>(i + 1)) {
            data[i].resize(i + 1, 0);
        }

        data[i][j] = value;
    }

    unsigned long long getvalue(int i, int j) const {
        if (i < 0 || j < 0 || j > i) {
            throw out_of_range("Invalid triangle index");
        }

        return data.at(i).at(j);
    }
};

// Calculates Pascal's Triangle using TriangleStorage.
class Pascal {
private:
    TriangleStorage storage;
    int rows_filled;

    // Calculate rows until the requested row exists.
    void ensureRows(int n) {
        while (rows_filled < n) {
            int i = rows_filled;

            // First coefficient.
            storage.setvalue(i, 0, 1);

            // Interior coefficients.
            for (int j = 1; j < i; ++j) {
                unsigned long long value =
                    storage.getvalue(i - 1, j - 1)
                    + storage.getvalue(i - 1, j);

                storage.setvalue(i, j, value);
            }

            // Last coefficient.
            if (i > 0) {
                storage.setvalue(i, i, 1);
            }

            ++rows_filled;
        }
    }

public:
    // Start with an empty triangle (Exercise 9).
    Pascal() : rows_filled(0) {}

    // Create a triangle containing n rows (Exercise 6).
    Pascal(int n) : rows_filled(0) {
        if (n < 0) {
            throw invalid_argument("Number of rows cannot be negative");
        }

        ensureRows(n);
    }

    // Return a coefficient, calculating missing rows if needed.
    unsigned long long getvalue(int i, int j) {
        if (i < 0 || j < 0 || j > i) {
            throw out_of_range("Invalid triangle index");
        }

        ensureRows(i + 1);
        return storage.getvalue(i, j);
    }

    // Print the complete triangle (Exercise 6).
    void print() {
        for (int i = 0; i < rows_filled; ++i) {
            cout << string(2 * (rows_filled - i - 1), ' ');

            for (int j = 0; j <= i; ++j) {
                cout << setw(4) << getvalue(i, j);
            }

            cout << '\n';
        }
    }

    // Print stars for nonzero remainders (Exercise 10).
    void print(int m) {
        if (m <= 0) {
            throw invalid_argument("Modulo must be positive");
        }

        for (int i = 0; i < rows_filled; ++i) {
            cout << string(2 * (rows_filled - i - 1), ' ');

            for (int j = 0; j <= i; ++j) {
                if (getvalue(i, j) % m != 0) {
                    cout << " * ";
                } else {
                    cout << "   ";
                }
            }

            cout << '\n';
        }
    }
};

int main() {
    int n;

    cout << "Enter the number of rows: ";
    if (!(cin >> n) || n < 0) {
        cerr << "Please enter a nonnegative number.\n";
        return 1;
    }

    Pascal pascal(n);

    cout << "\nPascal's Triangle:\n";
    pascal.print();

    cout << "\nEnter modulo values (0 to stop):\n";

    int m;
    while (cin >> m && m != 0) {
        if (m < 0) {
            cout << "Please enter a positive integer or 0 to stop.\n";
            continue;
        }

        cout << "\nPascal's Triangle modulo " << m << ":\n";
        pascal.print(m);
    }

    return 0;
}
