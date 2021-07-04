# Matrix Class
A general matrix class which performs the operations like Matrix addition, multiplication and Matrix Vector multiplication

## Features
- Matrix has `int` datatype
- Takes matrix elements input  from a file
- Can add, multiply two matrix's
- Can multiply matrix with a `scalar` value
- Can multiply matrix with a `Vector`

### How to
You can change the input matrix values in test.txt file and check the efficiency
```bash
git clone https://github.com/Thoufar/Matrix-Class.git
cd MatrixClass/src
g++ --std=c++11 Vector.cc Matrix.cc -o matrix
./matrix
```
### Example code
```c++
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
```

### Output
![output](https://github.com/Thoufar/Matrix-Class/blob/master/docs/Matrix%20out.png)
