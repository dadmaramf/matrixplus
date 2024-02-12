#include "s21_matrix.h"

void S21Matrix::initializeMatrix() {
  matrix_ = new double*[rows_];
  if (matrix_ == nullptr) throw std::out_of_range("  ");
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
    if (matrix_[i] == nullptr) {
      rows_ = i + 1;
      CleanMatrix();
      throw std::out_of_range("  ");
    }
  }

  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) matrix_[i][j] = 0.0;
}

void S21Matrix::CleanMatrix() {
  if (matrix_)
    for (int i = 0; i < rows_; i++) delete[] matrix_[i];

  delete[] matrix_;
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

void S21Matrix::CopyMatrix(double** matrix) {
  for (int i = 0; i < rows_; i++)
    std::copy(matrix[i], matrix[i] + cols_, matrix_[i]);
}

S21Matrix S21Matrix::MinorMatrix(int rows, int cols) {
  if (rows_ == 1 && cols_ == 1) return *this;
  S21Matrix minor(rows_ - 1, cols_ - 1);

  int minorR = 0, minorC = 0;
  for (int i = 0; i < rows_; i++) {
    if (i == rows) continue;
    for (int j = 0; j < cols_; j++) {
      if (j == cols) continue;
      minor.matrix_[minorR][minorC++] = matrix_[i][j];
    }
    minorR++;
    minorC = 0;
  }
  return minor;
}

void S21Matrix::Set_Rows(int rows) {
  if (rows <= 0 || cols_ <= 0)
    throw std::length_error("Array size can't be zero");
  S21Matrix new_matrix(rows, cols_);
  for (int i = 0; i < (rows_ < rows ? rows_ : rows); i++)
    std::copy(matrix_[i], matrix_[i] + cols_, new_matrix.matrix_[i]);
  *this = std::move(new_matrix);
}

void S21Matrix::Set_Cols(int cols) {
  if (cols <= 0 || rows_ <= 0)
    throw std::length_error("Array size can't be zero");
  S21Matrix new_matrix(rows_, cols);
  for (int i = 0; i < rows_; i++)
    std::copy(matrix_[i], matrix_[i] + (cols_ < cols ? cols_ : cols),
              new_matrix.matrix_[i]);
  *this = std::move(new_matrix);
}

int S21Matrix::Get_Rows() { return rows_; }

int S21Matrix::Get_Cols() { return cols_; }