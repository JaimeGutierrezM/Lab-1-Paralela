#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

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
    vector<int> sizes = {100 ,500,1000}; 

    for (int N : sizes) {
        vector<vector<int>> A(N, vector<int>(N, 1));
        vector<vector<int>> B(N, vector<int>(N, 1));
        vector<vector<int>> C(N, vector<int>(N, 0));

        auto start = high_resolution_clock::now();
        multiplicacion2(A, B, C, N, 64);
        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<milliseconds>(stop - start);

        cout << "Tamano de matriz: " << N << "x" << N << " - Tiempo de ejecucion: " << duration.count() << " ms" << endl;
    }

    return 0;
}