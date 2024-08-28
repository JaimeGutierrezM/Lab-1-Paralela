#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void multiplicacion(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void multiplicacion2(
    const vector<vector<int>>& A,
    const vector<vector<int>>& B,
    vector<vector<int>>& C, int N,
    int blockSize) {
    for (int i = 0; i < N; i += blockSize) {
        for (int j = 0; j < N; j += blockSize) {
            for (int k = 0; k < N; k += blockSize) {
                for (int ii = i; ii < min(i + blockSize, N); ++ii) {
                    for (int jj = j; jj < min(j + blockSize, N); ++jj) {
                        int sum = 0;
                        for (int kk = k; kk < min(k + blockSize, N); ++kk) {
                            sum += A[ii][kk] * B[kk][jj];
                        }
                        C[ii][jj] += sum;
                    }
                }
            }
        }
    }
}

int main() {
    vector<int> sizes = {100, 200, 500, 1000}; 
    int blockSize = 64;

    for (int N : sizes) {
        vector<vector<int>> A(N, vector<int>(N, 1));
        vector<vector<int>> B(N, vector<int>(N, 1));
        vector<vector<int>> C(N, vector<int>(N, 0));

        auto start = high_resolution_clock::now();
        multiplicacion(A, B, C, N);
        auto stop = high_resolution_clock::now();
        auto durationClassic = duration_cast<milliseconds>(stop - start);
        cout << "Tamano de matriz: " << N << "x" << N << " - Tiempo clasico: " << durationClassic.count() << " ms" << endl;

        fill(C.begin(), C.end(), vector<int>(N, 0));

        start = high_resolution_clock::now();
        multiplicacion2(A, B, C, N, blockSize);
        stop = high_resolution_clock::now();
        auto durationBlocked = duration_cast<milliseconds>(stop - start);
        cout << "Tamano de matriz: " << N << "x" << N << " - Tiempo por bloques: " << durationBlocked.count() << " ms" << endl;
    }

    return 0;
}
