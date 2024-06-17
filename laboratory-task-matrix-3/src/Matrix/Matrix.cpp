#include "Matrix.hpp"

// Help-функия для умножения
double Matrix::dotProduct(const double* row, const double* col, size_t length) {
    double result = 0.0;
    for (size_t i = 0; i < length; ++i) {
        result += row[i] * col[i];
    }
    return result;
}

// Help-функция для получения столбца матрицы
double* Matrix::getColumn(size_t col) const {
    double* column = new double[rows];
    for (size_t i = 0; i < rows; ++i) {
        column[i] = data[i][col];
    }
    return column;
}


/*==========================================================*/
/*====================Конструкторы==========================*/
/*==========================================================*/

// Конструктор по умолчанию
Matrix::Matrix() : rows(0), cols(0), data(nullptr) {}

// Конструкторы с параметрами
Matrix::Matrix(size_t rows, size_t cols) : rows(rows), cols(cols) {
    data = new double* [rows];
    for (size_t i = 0; i < rows; ++i) {
        data[i] = new double[cols];
        for (size_t j = 0; j < cols; ++j) {
            data[i][j] = 0.0;
        }
    }
}

Matrix::Matrix(size_t rows, size_t cols, double value) : rows(rows), cols(cols) {
    data = new double* [rows];
    for (size_t i = 0; i < rows; ++i) {
        data[i] = new double[cols];
        for (size_t j = 0; j < cols; ++j) {
            data[i][j] = value;
        }
    }
}

// Конструктор копирования
Matrix::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    data = new double* [rows];
    for (size_t i = 0; i < rows; ++i) {
        data[i] = new double[cols];
        for (size_t j = 0; j < cols; ++j) {
            data[i][j] = other.data[i][j];
        }
    }
}

// Деструктор
Matrix::~Matrix() {
    if (data != nullptr) {
        for (size_t i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }
}


/*==========================================================*/
/*=======================Гетеры=============================*/
/*==========================================================*/

// Получение строк 
size_t Matrix::getRow() const {
    return rows;
}

// Получение столбца
size_t Matrix::getCol() const {
    return cols;
}

// Получение элемента
double& Matrix::operator()(size_t row, size_t col) const{
    if (row >= rows || col >= cols) {
        throw std::out_of_range("Index out of range.");
    }
    return data[row][col];
}


/*==========================================================*/
/*=======================Cетеры=============================*/
/*==========================================================*/

// Установка элемента
void Matrix::setElement(size_t row, size_t col, double value) {
    if (row >= rows || col >= cols) {
        throw std::out_of_range("Index out of range.");
    }
    data[row][col] = value;
}


/*==========================================================*/
/*==========================================================*/
/*=====================Операторы============================*/
/*==========================================================*/
/*==========================================================*/

/*==========================================================*/
/*=================Бинарные операторы=======================*/
/*==========================================================*/

// Перегрузка оператора присваивания
Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        for (size_t i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;

        rows = other.rows;
        cols = other.cols;
        data = new double* [rows];
        for (size_t i = 0; i < rows; ++i) {
            data[i] = new double[cols];
            for (size_t j = 0; j < cols; ++j) {
                data[i][j] = other.data[i][j];
            }
        }
    }
    return *this;
}

// Перегрузки операторов сложения 
Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrix dimensions do not match for addition.");
    }
    Matrix result(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

Matrix& Matrix::operator+=(const Matrix& other) {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrix dimensions do not match for addition.");
    }
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            data[i][j] += other.data[i][j];
        }
    }
    return *this;
}

// Перегрузки операторов вычитания
Matrix Matrix::operator-(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrix dimensions do not match for subtraction.");
    }
    Matrix result(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

Matrix& Matrix::operator-=(const Matrix& other) {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrix dimensions do not match for subtraction.");
    }
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            data[i][j] -= other.data[i][j];
        }
    }
    return *this;
}

// Перегрузка оператороа умножения
Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("Matrix dimensions do not match for multiplication.");
    }
    Matrix result(rows, other.cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < other.cols; ++j) {
            result.data[i][j] = dotProduct(data[i], other.getColumn(j), cols);
        }
    }
    return result;
}

// Перегрузка оператора домножения на констант справа
Matrix Matrix::operator*(double scalar) const {
    Matrix result(rows, cols);
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] * scalar;
        }
    }
    return result;
}

// Перегрузка оператора домножения на констант слева
Matrix operator*(double scalar, const Matrix& matrix) {
    return matrix * scalar;
}

// Перегрузка оператора деления на константу
Matrix Matrix::operator/(double scalar) const {
    if (scalar == 0) {
        throw std::invalid_argument("Division by zero.");
    }
    return *this * (1 / scalar);
}

/*==========================================================*/
/*================Логические операторы======================*/
/*==========================================================*/

//Операторы сравнения матриц
bool Matrix::operator==(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        return false;
    }
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            if (data[i][j] != other.data[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& other) const {
    return !(*this == other);
}

/*==========================================================*/
/*==================Поточные операторы======================*/
/*==========================================================*/

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
    for (size_t i = 0; i < matrix.rows; ++i) {
        for (size_t j = 0; j < matrix.cols; ++j) {
            os << std::setw(4) << matrix.data[i][j];
        }
        os << std::endl;
    }
    return os;
}

// Перегрузка оператора ввода
std::istream& operator>>(std::istream& in, Matrix& matrix) {
    for (size_t i = 0; i < matrix.rows; ++i) {
        for (size_t j = 0; j < matrix.cols; ++j) {
            if (!(in >> matrix.data[i][j])) {
                throw std::invalid_argument("Invalid input.");
            }
        }
    }
    return in;
}