#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <exception>
#include <iomanip>

class Matrix {
private:
    double** data;
    size_t rows;
    size_t cols;

    // Help-функия для умножения
    static double dotProduct(const double* row, const double* col, size_t length);

    // Help-функция для получения столбца матрицы
    double* getColumn(size_t col) const;

public:

    /*==========Конструкторы==========*/

    // Конструтор по умолчанию
    Matrix();

    // Конструкторы с параметрами
    Matrix(size_t, size_t);
    Matrix(size_t, size_t, double);

    // Конструктор копирования
    Matrix(const Matrix&);

    // Деструктор
    ~Matrix();


    /*==========Гетеры==========*/

    size_t getRow() const;
    size_t getCol() const;
    double& operator()(size_t row, size_t col) const;

    /*==========Сетер==========*/

    void setElement(size_t, size_t, double);


    /*==========Операторы==========*/

    // Оператор присваивания
    Matrix& operator=(const Matrix&);

    // Операторы сложения
    Matrix operator+(const Matrix&) const;
    Matrix& operator+=(const Matrix&);

    // Операторы вычитания
    Matrix operator-(const Matrix&) const;
    Matrix& operator-=(const Matrix&);

    // Оператор умножения
    Matrix operator*(const Matrix&) const;

    // Оператор домножения на костанту справа    
    Matrix operator*(double scalar) const;

    // Оператор домножения на костанту слева
    friend Matrix operator*(double scalar, const Matrix& matrix);

    //Оператор деления на костанту
    Matrix operator/(double scalar) const;

    // Оператор сранения матриц
    bool operator==(const Matrix& other) const;
    bool operator!=(const Matrix& other) const;


    /*=====Поточные операторы=====*/

    // Оператор вывода
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);

    // Оператор ввода
    friend std::istream& operator>>(std::istream& is, Matrix& matrix);
};
#endif
