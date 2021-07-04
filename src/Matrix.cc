/*
 * Matrix.cc
 *
 * Author: Thoufar
 * Email:  thoufarbasheer@gmail.com
 *
 * Created on: March 20, 2021
 *
 */

#include "Matrix.hh"

void Matrix::printMat(Mats &output) {
    std::cout << std::endl;
    for (int n = 0; n < output.rows; n++) {
        for (int m = 0; m < output.cols; m++) {
            std::cout << output.vec[n][m] << ", ";
        }
        std::cout << std::endl;
    }
}

void Matrix::setMat(Mats &output) {
    for (int i = 0; i < output.rows; i++) {
        std::vector<int> v1;
        for (int j = 0; j < output.cols; j++) {
            int num;
            std::cin >> num;
            v1.push_back(num);
        }
        output.vec.push_back(v1);
    }
}

Mats operator+(const Mats &mat1, const Mats &mat2) {
    if ((mat1.cols != mat2.cols) || (mat1.rows != mat2.rows)) {
        std::cout << std::endl << "Matrix addition not possible" << std::endl;
        return {};
    }
    Mats output;
    std::vector<std::vector<int> > vec(mat1.rows, std::vector<int>(mat2.cols));
    for (unsigned i = 0; i < mat1.rows; i++) {
        for (unsigned j = 0; j < mat1.cols; j++) {
            vec[i][j] = mat1.vec[i][j] + mat2.vec[i][j];
        }
    }
    output.cols = mat2.cols;
    output.rows = mat1.rows;
    output.vec = vec;
    return output;
}

Mats operator*(const Mats &mat1, const Mats &mat2) {
    if (mat1.cols != mat2.rows) {
        std::cout << std::endl << "Matrix multiplication not possible" << std::endl;
        return {};
    }
    Mats output;
    std::vector<std::vector<int> > vec(mat1.rows, std::vector<int>(mat2.cols));
    for (unsigned i = 0; i < mat1.rows; i++) {
        for (unsigned j = 0; j < mat2.cols; j++) {
            for (unsigned k = 0; k < mat2.rows; k++) {
                vec[i][j] += mat1.vec[i][k] * mat2.vec[k][j];
            }
        }
    }
    output.cols = mat2.cols;
    output.rows = mat1.rows;
    output.vec = vec;
    return output;
}

MyVector operator*(const Mats &mat, MyVector &v) {
    if (mat.cols != v.Size()) {
        std::cout << std::endl << "Matrix multiplication with Vector not possible" << std::endl;
        return {};
    }
    MyVector res;
    for (unsigned i = 0; i < mat.rows; i++) {
        int sum = 0;
        for (unsigned j = 0; j < mat.cols; j++) {
            sum += mat.vec[i][j] * v(j);
        }
        res.push_back(sum);
    }
    return res;
}

template <class scalar>
Mats operator*(const Mats &mat, const scalar &value) {
    Mats output;
    std::vector<std::vector<int> > vec(mat.rows, std::vector<int>(mat.cols));
    for (unsigned i = 0; i < mat.rows; i++) {
        for (unsigned j = 0; j < mat.cols; j++) {
            vec[i][j] = mat.vec[i][j] * value;
        }
    }
    output.cols = mat.cols;
    output.rows = mat.rows;
    output.vec = vec;
    return output;
}

int main() {
    // Declaring two matrix's
    Mats A, B;

    // Declaring Matrix class
    std::shared_ptr<Matrix> obj;

    // Populating matrix elements from file
    freopen("test.txt", "r", stdin);
    std::cin >> A.rows >> A.cols >> B.rows >> B.cols;

    // Setting and printing the values in Matrix
    std::cout << "A:";
    obj->setMat(A);
    obj->printMat(A);
    std::cout << std::endl << "B:";
    obj->setMat(B);
    obj->printMat(B);

    std::cout << std::endl << "Addition of two matrix's \n \nA + B:";
    Mats A_add_B = A + B;
    obj->printMat(A_add_B);

    std::cout << std::endl << "Multiplication of a matrix with scalar value \n \nA * 2:";
    Mats sc = A * 2;
    obj->printMat(sc);

    std::cout << std::endl << "Multiplication of two matrix's \n  \nA * B:";
    Mats AB = A * B;
    obj->printMat(AB);

    // Custom Vector class
    MyVector v, AV;
    v.push_back(2);
    v.push_back(1);
    v.push_back(3);
    std::cout << std::endl << "Multiplication of a matrix with vector \n \nA * Vector:";
    AV = A * v;
    AV.printVec();
    return 0;
}
