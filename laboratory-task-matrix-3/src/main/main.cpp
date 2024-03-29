#include "src/Matrix/Matrix.hpp"
int main() {
  try
  {
    // Конструкторы
    Matrix mat1(2, 3, 1.0);
    Matrix mat2(2, 3);
    Matrix mat3(3, 2);

    std::cout << "Matrix 1:" << std::endl << mat1 << std::endl;
    std::cout << "Matrix 2:" << std::endl << mat2 << std::endl;
    std::cout << "Matrix 3:" << std::endl << mat3 << std::endl;

    // Гетеры и сеторы
    size_t rows = mat3.getRow();
    size_t cols = mat3.getCol();

    std::cout << "Rows: " << rows << ", Cols: " << cols << std::endl;
    mat2.setElement(1, 1, 5.5);
    std::cout << "Modified Matrix:" << std::endl;
    std::cout << mat2 << std::endl;


    // Ввод и вывод
    std::cout << "Enter values for Matrix 2 (2x3):" << std::endl;
    std::cin >> mat2;
    std::cout << "Matrix 2 after input:" << std::endl << mat2 << std::endl;

    std::cout << "Enter values for Matrix 3 (3x2):" << std::endl;
    std::cin >> mat3;
    std::cout << "Matrix 3 after input:" << std::endl << mat3 << std::endl;


    // Операции с матрицей
    Matrix mat4 = mat1 + mat2;
    Matrix mat5 = mat1 - mat2;
    Matrix mat6 = mat1 * mat3;

    std::cout << "Matrix 1 + Matrix 2:" << std::endl << mat4 << std::endl;
    std::cout << "Matrix 1 - Matrix 2:" << std::endl << mat5 << std::endl;
    std::cout << "Matrix 1 * Matrix 3:" << std::endl << mat6 << std::endl;

    // Операции со скаляром
    Matrix mat7 = mat1 * 2.0;
    Matrix mat8 = 3.0 * mat3;
    Matrix mat9 = mat4 / 2.0;

    std::cout << "Matrix 1 * 2.0:" << std::endl << mat7 << std::endl;
    std::cout << "3.0 * Matrix 3:" << std::endl << mat8 << std::endl;
    std::cout << "Matrix 1 + Matrix 2 / 2.0:" << std::endl << mat9 << std::endl;

    // Операции сравнения
    std::cout << "Matrix 1 == Matrix 1:" << (mat1 == mat1 ? " true" : " false") << std::endl;
    std::cout << "Matrix 2 != Matrix 2:" << (mat2 != mat2 ? " true" : " false") << std::endl;
	
  }
  catch (const std::out_of_range& error)
  {
    std::cerr << "Exception: " << error.what() << std::endl;
  }
  catch (const std::invalid_argument& error)
  {
    std::cerr << "Exception: " << error.what() << std::endl;
  }
  return 0;
}
