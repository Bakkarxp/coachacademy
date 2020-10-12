//
// Created by HKP28 on 10/10/2020.
//

#ifndef COACHACADEMY_MATRIX_H
#define COACHACADEMY_MATRIX_H

#include <vector>
using std::vector;

template<typename T>
class Matrix {
private:
    vector<vector<T>> matrix;
    int rows, cols;

public:
    Matrix();

    Matrix operator+(const Matrix& matrix);

private:
    vector<vector<T>> AddMatrix(vector<vector<T>>matrix1,vector<vector<T>> matrix2);
    vector<vector<T>> subtractMatrix(vector<vector<T>>matrix1,vector<vector<T>> matrix2);
    vector<vector<T>> MultiplyMatrix(vector<vector<T>>matrix1,vector<vector<T>> matrix2);
    vector<vector<T>> TransposeMatrix(vector<vector<T>> matrix);
};

template<typename T>
Matrix<T>::Matrix() {

}

template<typename T>
vector<vector<T>> Matrix<T>::AddMatrix(vector<vector<T>> matrix1, vector<vector<T>> matrix2) {
    vector<vector<T>> result;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols ; ++j) {
            result[i][j] = matrix1[i][j] +  matrix1[i][j];
        }
    }
    return result;
}

template<typename T>
vector<vector<T>> Matrix<T>::subtractMatrix(vector<vector<T>> matrix1, vector<vector<T>> matrix2) {
    return vector<vector<T>>();
}

template<typename T>
vector<vector<T>> Matrix<T>::MultiplyMatrix(vector<vector<T>> matrix1, vector<vector<T>> matrix2) {
    return vector<vector<T>>();
}

template<typename T>
vector<vector<T>> Matrix<T>::TransposeMatrix(vector<vector<T>> matrix) {
    return vector<vector<T>>();
}


#endif //COACHACADEMY_MATRIX_H

