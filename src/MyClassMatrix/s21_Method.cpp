#include "s21_matrix.h"

S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

S21Matrix::S21Matrix(int num_r, int num_c) {
  if (num_r <= 0 || num_c <= 0) {
    throw std::out_of_range("Invalid matrix dimensions");
  }
  rows_ = num_r;
  cols_ = num_c;
  initializeMatrix();
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(0), cols_(0), matrix_(nullptr) {
  if (other.cols_ <= 0 || other.rows_ <= 0)
    throw std::out_of_range("Invalid matrix dimensions");

  rows_ = other.rows_;
  cols_ = other.cols_;
  initializeMatrix();
  CopyMatrix(other.matrix_);
}

S21Matrix::S21Matrix(S21Matrix&& other) : rows_(0), cols_(0), matrix_(nullptr) {
  if (other.cols_ <= 0 || other.rows_ <= 0)
    throw std::out_of_range("Invalid matrix dimensions");

  std::swap(rows_, other.rows_);
  std::swap(cols_, other.cols_);
  std::swap(matrix_, other.matrix_);
}

S21Matrix::~S21Matrix() { CleanMatrix(); }
