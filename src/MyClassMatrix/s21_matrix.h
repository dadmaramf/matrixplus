#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <cmath>
#include <iostream>

/**
 * \class S21Matrix
 * \brief Класс, представляющий двумерную матрицу.
 */
class S21Matrix {
 private:
 
  int rows_, cols_; 
  double** matrix_;

  void initializeMatrix();
  void CleanMatrix();
  void CopyMatrix(double** matrix);
  void Result(int rows, int cols);
  S21Matrix MinorMatrix(int rows, int cols);

 public:

  S21Matrix();
  S21Matrix(int num_r, int num_c);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  /**
   * \brief Проверяет, является ли матрица равной другой матрице.
   * \param other Другая матрица.
   * \return `true`, если матрицы равны, иначе `false`.
   */
  bool EqMatrix(const S21Matrix& other);
  /**
   * \brief Складывает матрицу с другой матрицей.
   * \param other Другая матрица.
   */  
  void SumMatrix(const S21Matrix& other);
  /**
   * \brief Вычитает другую матрицу из данной матрицы.
   * \param other Другая матрица.
   */  
  void SubMatrix(const S21Matrix& other);
  /**
   * \brief Умножает матрицу на число.
   * \param num Число.
   */
  void MulNumber(const double num);
  /**
   * \brief Умножает матрицу на другую матрицу.
   * \param other Другая матрица.
   */
  void MulMatrix(const S21Matrix& other);
  /**
   * \brief Вычисляет определитель матрицы.
   * \return Определитель матрицы.
   */
  double Determinant();
  /**
   * \brief Транспонирует матрицу.
   * \return Транспонированная матрица.
   */
  S21Matrix Transpose();
  /**
   * \brief Вычисляет матрицу алгебраических дополнений.
   * \return Матрица алгебраических дополнений.
   */
  S21Matrix CalcComplements();
  /**
   * \brief Вычисляет обратную матрицу.
   * \return Обратная матрица.
   */
  S21Matrix InverseMatrix();

  double* operator[](int row) const;
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(const double num);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator*=(const double num);
  double& operator()(int row, int col);
  bool operator==(const S21Matrix& other);
  friend S21Matrix operator*(const double& num, const S21Matrix& matrix);

  /**
   * \brief Устанавливает количество строк матрицы.
   * \param rows Количество строк.
   */
  void Set_Rows(int rows);
  /**
   * \brief Устанавливает количество столбцов матрицы.
   * \param cols Количество столбцов.
   */
  void Set_Cols(int cols);
  /**
   * \brief Возвращает количество строк матрицы.
   * \return Количество строк.
   */
  int Get_Rows();
  /**
   * \brief Возвращает количество столбцов матрицы.
   * \return Количество столбцов.
   */
  int Get_Cols();
};



#endif