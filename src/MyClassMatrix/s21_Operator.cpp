#include "s21_matrix.h"

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (other.cols_ <= 0 || other.rows_ <= 0)
    throw std::out_of_range("Invalid matrix dimensions");
  if (this == &other) return *this;

  CleanMatrix();

  rows_ = other.rows_;
  cols_ = other.cols_;
  initializeMatrix();
  CopyMatrix(other.matrix_);

  return *this;
}

S21Matrix& S21Matrix::operator=(S21Matrix&& other) {
  if (other.cols_ <= 0 || other.rows_ <= 0)
    throw std::out_of_range("Invalid matrix dimensions");
  if (this == &other) return *this;

  CleanMatrix();
  std::swap(rows_, other.rows_);
  std::swap(cols_, other.cols_);
  std::swap(matrix_, other.matrix_);

  return *this;
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix result = *this;
  result.SumMatrix(other);

  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix result = *this;
  result.SubMatrix(other);

  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix result = *this;
  result.MulMatrix(other);

  return result;
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix result = *this;
  result.MulNumber(num);

  return result;
}

S21Matrix operator*(const double& num, const S21Matrix& matrix) {
  S21Matrix result = matrix;

  return result *= num;
}

bool S21Matrix::operator==(const S21Matrix& other) { return EqMatrix(other); }

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);

  return *this;
}
S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);

  return *this;
}
S21Matrix& S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);

  return *this;
}
S21Matrix& S21Matrix::operator*=(const double num) {
  MulNumber(num);

  return *this;
}

double& S21Matrix::operator()(int row, int col) {
  if (row >= rows_ || row < 0 || col >= cols_ || col < 0)
    throw std::out_of_range("Incorrect input, index is out of range");

  return matrix_[row][col];
}

double* S21Matrix::operator[](int row) const {
  if (row >= rows_ || row < 0)
    throw std::out_of_range("Incorrect input, index is out of range");

  return matrix_[row];
}