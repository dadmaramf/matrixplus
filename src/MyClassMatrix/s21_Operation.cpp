#include "s21_matrix.h"

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  if (rows_ <= 0 || cols_ <= 0 || other.cols_ != cols_ || other.rows_ != rows_)
    return false;

  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++)
      if (std::fabs((*this)[i][j] - other[i][j]) > 1e-07) return false;

  return true;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ <= 0 || cols_ <= 0 || other.cols_ != cols_ || other.rows_ != rows_)
    throw std::out_of_range("Invalid matrix dimensions");

  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) matrix_[i][j] += other.matrix_[i][j];
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ <= 0 || cols_ <= 0 || other.cols_ != cols_ || other.rows_ != rows_)
    throw std::out_of_range("Invalid matrix dimensions");

  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) matrix_[i][j] -= other.matrix_[i][j];
}

void S21Matrix::MulNumber(const double num) {
  if (rows_ <= 0 || cols_ <= 0)
    throw std::out_of_range("Invalid matrix dimensions");
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) matrix_[i][j] *= num;
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (rows_ <= 0 || cols_ <= 0 || cols_ != other.rows_)
    throw std::out_of_range("Invalid matrix dimensions");

  S21Matrix result(rows_, other.cols_);

  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < other.cols_; j++)
      for (int k = 0; k < other.rows_; k++)
        result.matrix_[i][j] += (matrix_[i][k] * other.matrix_[k][j]);

  *this = result;
}

S21Matrix S21Matrix::Transpose() {
  if (rows_ <= 0 || cols_ <= 0)
    throw std::out_of_range("Invalid matrix dimensions");

  S21Matrix result(cols_, rows_);

  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) result.matrix_[j][i] = matrix_[i][j];

  return result;
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ <= 0 || cols_ <= 0 || cols_ != rows_)
    throw std::out_of_range("Matrix is not square");

  S21Matrix complem(rows_, cols_);

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      S21Matrix minor = MinorMatrix(i, j);
      double minorDeterm = minor.Determinant();
      double complement = (i + j) % 2 == 0 ? minorDeterm : -minorDeterm;
      complem.matrix_[i][j] = complement;
    }
  }

  return complem;
}

double S21Matrix::Determinant() {
  if (rows_ <= 0 || cols_ <= 0 || rows_ != cols_)
    throw std::out_of_range("Matrix is not square");

  if (rows_ == 1) return matrix_[0][0];

  if (rows_ == 2)
    return matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];

  double determinant = 0.0;

  for (int j = 0; j < cols_; j++) {
    S21Matrix minor(MinorMatrix(0, j));
    double minorDeterminant = minor.Determinant();
    determinant += (j % 2 == 0 ? 1 : -1) * matrix_[0][j] * minorDeterminant;
  }

  return determinant;
}

S21Matrix S21Matrix::InverseMatrix() {
  if (rows_ <= 0 || cols_ <= 0 || rows_ != cols_)
    throw std::out_of_range("Matrix is not square");

  double determinant = Determinant();
  if (determinant == 0.0) throw std::out_of_range("Matrix is not invertible");

  S21Matrix Inverse = CalcComplements().Transpose();

  if (rows_ == 1)
    Inverse.matrix_[0][0] = 1.0 / determinant;
  else
    Inverse.MulNumber(1.0 / determinant);

  return Inverse;
}