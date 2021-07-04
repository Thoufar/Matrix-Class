/*
 * Matrix.hh
 *
 * Author: Thoufar Basheer
 * Email:  thoufarbasheer@gmail.com
 *
 * Created on: March 20, 2021
 *
 */

#ifndef SOLUTION__MATRIX_HH_
#define SOLUTION__MATRIX_HH_

#include <bits/stdc++.h>

#include "Vector.hh"

/**
 * @struct Mats
 *
 * @brief To store elements of a Matrix
 */
struct Mats {
    int rows, cols;
    std::vector<std::vector<int> > vec;
};

/**
 * @class Matrix
 *
 * @brief Adds two Matrix's
 *        Multiply two Matrix's
 *        Multiply Matrix with a vector
 *        Multiply Matrix with a scalar value
 */
class Matrix {
   public:
    Matrix();

    /**
     * @Brief Set the Matrix
     *
     * Populate the elements of a Matrix
     *
     * @param[in] mat Matrix to be populated
     */
    void setMat(Mats &mat);

    /**
     * @Brief Print the Matrix
     *
     * To print the elements of Matrix
     *
     * @param[in] mat Matrix
     */
    void printMat(Mats &mat);

    /**
     * @Brief Add two Matrix's
     *
     * To add two matrix's
     *
     * @param[in] mat1 Input matrix 1
     * @param[in] mat2 Input matrix 2
     * @return output Result matrix
     */
    friend Mats operator+(const Mats &mat1, const Mats &mat2);

    /**
     * @Brief Mutliply two Matrix's
     *
     * To multiply two matrix's
     *
     * @param[in] mat1 Input matrix 1
     * @param[in] mat2 Input matrix 2
     * @return output Result matrix
     */
    friend Mats operator*(const Mats &mat1, const Mats &mat2);

    /**
     * @Brief Mutliply Matrix and Vector
     *
     * To multiply matrix and a Vector
     *
     * @param[in] mat Input matrix
     * @param[in] vec Input custom vector
     * @return output Result matrix
     */
    friend MyVector operator*(const Mats &mat, MyVector &vec);

    /**
     * @Brief Scalar multiplication
     *
     * To multiply matrix with a scalar value
     *
     * @param[in] mat1 Input matrix
     * @param[in] mat2 Input the scalar value
     * @return output Result matrix
     */
    template <class scalar>
    friend Mats operator*(const Mats &mat, const scalar &value);

    ~Matrix();
};

#endif  // SOLUTION__MATRIX_HH_
