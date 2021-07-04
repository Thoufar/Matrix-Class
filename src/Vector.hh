/*
 * Vector.hh
 *
 * Author: thoufar Basheer
 * Email:  thoufarbasheer@gmail.com
 *
 * Created on: March 20, 2021
 *
 */

#ifndef SOLUTION__VECTOR_HH_
#define SOLUTION__VECTOR_HH_

#include <bits/stdc++.h>
using namespace std;
class MyVector {
   public:
    /**
     * @Brief Adds data into Vector
     *
     * Populates the data into Vector
     *
     * @param[in] value Value to be added
     */
    void push_back(int value);

    /**
     * @Brief Size of the Vector
     *
     * Returns the size of the vector
     *
     * @return size Returns size of the vector
     */
    int Size();

    /**
     * @Brief Prints the vector
     *
     * Prints the elements of the Vector
     */
    void printVec();

    /**
     * @Brief Returns value at index
     *
     * Returns the value at an index
     *
     * @return value
     */
    int operator()(int index);

   private:
    int* arr = new int[1];
    int size = 1, count = 0, scale = 2;
};

#endif  // SOLUTION__VECTOR_HH_
