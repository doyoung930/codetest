#include "header.h"

using namespace std;

// land_rows�� 2���� �迭 land�� �� ����, land_cols�� 2���� �迭 land�� �� �����Դϴ�.
int solution(int** land, size_t land_rows, size_t land_cols) {
    int answer = 0;


    
    return answer;
}
int main() {

    int land[5][8] = { {0, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0},
        {1, 1, 0, 0, 0, 1, 1, 0},
        {1, 1, 1, 0, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 0, 1, 1} };

    size_t rows = 5;
    size_t cols = 8;
    int** landPtr = new int* [rows];
    for (size_t i = 0; i < rows; ++i) {
        landPtr[i] = new int[cols];
        for (size_t j = 0; j < cols; ++j) {
            landPtr[i][j] = land[i][j];
        }
    }
    std::cout << solution(landPtr, rows, cols) << std::endl;

    for (size_t i = 0; i < rows; ++i) {
        delete[] landPtr[i];
    }
    delete[] landPtr;
    return 0;
}
 