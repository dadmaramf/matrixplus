#include <gtest/gtest.h>

#include "../MyClassMatrix/s21_matrix.h"

TEST(S21MatrixTest, EqMatrixTest1) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(1, 0) = 3;
  matrix(1, 1) = 4;

  S21Matrix other(2, 2);
  other(0, 0) = 1;
  other(0, 1) = 2;
  other(1, 0) = 3;
  other(1, 1) = 4;

  ASSERT_TRUE(matrix.EqMatrix(other));
}

TEST(S21MatrixTest, EqMatrixTest2) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(1, 0) = 3;
  matrix(1, 1) = 4;

  S21Matrix other(2, 2);
  other(0, 0) = 1;
  other(0, 1) = 2;
  other(1, 0) = 8;
  other(1, 1) = 4;

  ASSERT_FALSE(matrix.EqMatrix(other));
}

TEST(S21MatrixTest, EqMatrixTest3) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(1, 0) = 3;
  matrix(1, 1) = 4;

  S21Matrix other(1, 2);
  other(0, 0) = 1;
  other(0, 1) = 2;

  ASSERT_FALSE(matrix.EqMatrix(other));
}

// -----------------------------------------------------------------------------------------------------------------------
// Тест для функции SumMatrix
TEST(S21MatrixTest, SumMatrixTest1) {
  S21Matrix matrix1(2, 2);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  S21Matrix matrix2(2, 2);
  matrix2(0, 0) = 5;
  matrix2(0, 1) = 6;
  matrix2(1, 0) = 7;
  matrix2(1, 1) = 8;

  matrix1.SumMatrix(matrix2);
  ASSERT_EQ(matrix1(0, 0), 6);
  ASSERT_EQ(matrix1(0, 1), 8);
  ASSERT_EQ(matrix1(1, 0), 10);
  ASSERT_EQ(matrix1(1, 1), 12);
}

TEST(S21MatrixTest, SumMatrixTest2) {
  S21Matrix matrix1(5, 5);
  matrix1(0, 4) = 3;
  matrix1(1, 1) = 75;
  matrix1(1, 3) = 9;
  matrix1(3, 1) = 12;
  matrix1(4, 2) = 4;

  S21Matrix matrix2(5, 5);
  matrix2(0, 4) = 5;
  matrix2(0, 2) = 9;
  matrix2(1, 1) = 30;
  matrix2(1, 3) = 1;
  matrix2(3, 1) = 100;
  matrix2(4, 2) = 5;

  matrix1.SumMatrix(matrix2);
  ASSERT_EQ(matrix1(0, 4), 8);
  ASSERT_EQ(matrix1(0, 2), 9);
  ASSERT_EQ(matrix1(1, 1), 105);
  ASSERT_EQ(matrix1(1, 3), 10);
  ASSERT_EQ(matrix1(3, 1), 112);
  ASSERT_EQ(matrix1(4, 2), 9);
}

TEST(S21MatrixTest, SumMatrix_InvalidDimensionsTest1) {
  S21Matrix matrix1(2, 7);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;

  S21Matrix matrix2(2, 2);
  matrix2(0, 0) = 5;
  matrix2(0, 1) = 6;

  // Проверяем, что выбрасывается исключение std::out_of_range при вызове
  // SumMatrix
  ASSERT_THROW(matrix1.SumMatrix(matrix2), std::out_of_range);
}

TEST(S21MatrixTest, SumMatrix_InvalidDimensionsTest2) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(1, 0) = 3;
  matrix(1, 1) = 4;

  S21Matrix other(1, 2);
  other(0, 0) = 1;
  other(0, 1) = 2;

  // Проверяем, что выбрасывается исключение std::out_of_range при вызове
  // SumMatrix
  ASSERT_THROW(matrix.SumMatrix(other), std::out_of_range);
}

// //
// -----------------------------------------------------------------------------------------------------------------------
// // Тест для функции SubMatrix
TEST(S21MatrixTest, SubMatrixTest) {
  // Создаем и заполняем матрицы
  S21Matrix matrix1(2, 2);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  S21Matrix matrix2(2, 2);
  matrix2(0, 0) = 5;
  matrix2(0, 1) = 6;
  matrix2(1, 0) = 7;
  matrix2(1, 1) = 8;

  // Вычитаем матрицу matrix2 из matrix1
  matrix1.SubMatrix(matrix2);

  // Проверяем, что значения матрицы matrix1 изменились соответствующим образом
  ASSERT_EQ(matrix1(0, 0), -4);
  ASSERT_EQ(matrix1(0, 1), -4);
  ASSERT_EQ(matrix1(1, 0), -4);
  ASSERT_EQ(matrix1(1, 1), -4);
}

// -----------------------------------------------------------------------------------------------------------------------

// Тест для функции MulNumber
TEST(S21MatrixTest, MulNumberTest1) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(1, 0) = 3;
  matrix(1, 1) = 4;

  matrix.MulNumber(2);

  ASSERT_EQ(matrix(0, 0), 2);
  ASSERT_EQ(matrix(0, 1), 4);
  ASSERT_EQ(matrix(1, 0), 6);
}

TEST(S21MatrixTest, MulNumberTest2) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(1, 0) = 5;
  matrix(1, 1) = 4;

  matrix.MulNumber(0.1);
  ASSERT_EQ(matrix(0, 0), 0.1);
  ASSERT_EQ(matrix(0, 1), 0.2);
  ASSERT_EQ(matrix(1, 0), 0.5);
  ASSERT_EQ(matrix(1, 1), 0.4);
}

TEST(S21MatrixTest, MulMatrixTest2) {
  S21Matrix matrix1(5, 2);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  S21Matrix matrix2(2, 5);

  matrix2(0, 0) = 5;
  matrix2(0, 1) = 6;
  matrix2(1, 0) = 7;
  matrix2(1, 1) = 8;

  matrix1.MulMatrix(matrix2);

  ASSERT_EQ(matrix1(0, 0), 19);
  ASSERT_EQ(matrix1(0, 1), 22);
  ASSERT_EQ(matrix1(1, 0), 43);
  ASSERT_EQ(matrix1(1, 1), 50);
}

// -----------------------------------------------------------------------------------------------------------------------

// Тест для функции MulMatrix
TEST(S21MatrixTest, MulMatrixTest) {
  S21Matrix matrix1(2, 2);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  S21Matrix matrix2(2, 2);
  matrix2(0, 0) = 5;
  matrix2(0, 1) = 6;
  matrix2(1, 0) = 7;
  matrix2(1, 1) = 8;

  matrix1.MulMatrix(matrix2);

  ASSERT_EQ(matrix1(0, 0), 19);
  ASSERT_EQ(matrix1(0, 1), 22);
  ASSERT_EQ(matrix1(1, 0), 43);
  ASSERT_EQ(matrix1(1, 1), 50);
}

TEST(S21MatrixTest, TransposeTest) {
  S21Matrix matrix(3, 2);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(1, 0) = 3;
  matrix(1, 1) = 4;
  matrix(2, 0) = 5;
  matrix(2, 1) = 6;

  S21Matrix transposed = matrix.Transpose();

  ASSERT_EQ(transposed(0, 0), 1);
  ASSERT_EQ(transposed(0, 1), 3);
  ASSERT_EQ(transposed(0, 2), 5);
  ASSERT_EQ(transposed(1, 0), 2);
  ASSERT_EQ(transposed(1, 1), 4);
  ASSERT_EQ(transposed(1, 2), 6);
}

TEST(S21MatrixTest, CalcComplementsTest) {
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(1, 0) = 4;
  matrix(1, 1) = 5;
  matrix(1, 2) = 6;
  matrix(2, 0) = 7;
  matrix(2, 1) = 8;
  matrix(2, 2) = 9;

  S21Matrix complements = matrix.CalcComplements();

  ASSERT_EQ(complements(0, 0), -3);
  ASSERT_EQ(complements(0, 1), 6);
  ASSERT_EQ(complements(0, 2), -3);
}

TEST(S21MatrixTest, DeterminantTest) {
  S21Matrix matrix(3, 3);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(0, 2) = 3;
  matrix(1, 0) = 4;
  matrix(1, 1) = 5;
  matrix(1, 2) = 6;
  matrix(2, 0) = 7;
  matrix(2, 1) = 8;
  matrix(2, 2) = 9;

  double determinant = matrix.Determinant();

  ASSERT_EQ(determinant, 0);
}

TEST(test_class, basic_constructor) {
  S21Matrix m;
  EXPECT_EQ(m.Get_Cols(), 0);
  EXPECT_EQ(m.Get_Rows(), 0);
}

TEST(test_class, rc_constructor) {
  S21Matrix m(69, 420);
  EXPECT_EQ(m.Get_Rows(), 69);
  EXPECT_EQ(m.Get_Cols(), 420);
}

TEST(test_class, copy_constructor) {
  S21Matrix m(12, 12);
  S21Matrix copy(m);

  EXPECT_EQ(copy.Get_Cols(), 12);
  EXPECT_EQ(copy.Get_Rows(), 12);
}

TEST(test_class, move_constructor) {
  S21Matrix m(12, 12);
  S21Matrix moved(std::move(m));

  EXPECT_EQ(m.Get_Cols(), 0);
  EXPECT_EQ(m.Get_Rows(), 0);
  EXPECT_EQ(moved.Get_Cols(), 12);
  EXPECT_EQ(moved.Get_Rows(), 12);
}

TEST(test_class, brackets_operator) {
  S21Matrix m(6, 9);
  EXPECT_EQ(m(0, 0), 0);

  m(0, 1) = 69;
  EXPECT_EQ(m(0, 1), 69);

  m(5, 8) = 69.420;
  EXPECT_EQ(m(5, 8), 69.420);
}

TEST(test_class, square_brackets_operator) {
  S21Matrix m(6, 9);
  EXPECT_EQ(m[0][0], 0);

  m[5][5] = 69;
  EXPECT_EQ(m[5][5], 69);

  m[5][8] = 69.420;
  EXPECT_EQ(m[5][8], 69.420);
}

TEST(test_setters, Set_Rows_up) {
  S21Matrix m(2, 2);
  m[1][1] = 6.9;

  m.Set_Rows(5);

  EXPECT_EQ(m.Get_Rows(), 5);
  EXPECT_EQ(m[1][1], 6.9);
}

TEST(test_setters, Set_Rows_down) {
  S21Matrix m(2, 2);
  m[0][0] = 6.9;

  m.Set_Rows(1);
  EXPECT_EQ(m.Get_Rows(), 1);
  EXPECT_EQ(m[0][0], 6.9);
}

TEST(test_setters, Set_Rows_zero) {
  S21Matrix m;

  EXPECT_ANY_THROW(m.Set_Rows(0));
}

TEST(test_setters, Set_Cols_up) {
  S21Matrix m(2, 2);
  m[1][1] = 6.9;

  m.Set_Cols(5);
  EXPECT_EQ(m.Get_Cols(), 5);
  EXPECT_EQ(m[1][1], 6.9);
}

TEST(test_setters, Set_Cols_down) {
  S21Matrix m(2, 2);
  m[0][0] = 6.9;

  m.Set_Cols(1);

  EXPECT_EQ(m.Get_Cols(), 1);
  EXPECT_EQ(m[0][0], 6.9);
}

TEST(test_setters, Set_Cols_zero) {
  S21Matrix m;

  EXPECT_ANY_THROW(m.Set_Cols(0));
}

TEST(test_overload, equal_lvalue) {
  S21Matrix m;
  S21Matrix x(3, 6);
  x(1, 2) = 3;
  x(2, 2) = 3;

  m = x;

  EXPECT_EQ(m.Get_Rows(), 3);
  EXPECT_EQ(m.Get_Cols(), 6);
  EXPECT_EQ(m(1, 2), 3);
  EXPECT_EQ(m(2, 2), 3);
}

TEST(test_overload, equal_rvalue) {
  S21Matrix m(2, 2);
  S21Matrix n;

  n = std::move(m);

  EXPECT_EQ(n.Get_Cols(), 2);
  EXPECT_EQ(n.Get_Rows(), 2);
}

TEST(test_functional, eq_matrix) {
  S21Matrix m(2, 2);
  S21Matrix n(2, 2);

  ASSERT_TRUE(m == n);
}

TEST(test_functional, eq_matrix1) {
  S21Matrix m(3, 2);
  S21Matrix n;

  m[0][1] = 69;
  n = m;

  ASSERT_TRUE(m == n);
}

TEST(test_functional, sum_matrix) {
  S21Matrix m(2, 2);
  S21Matrix n(2, 2);

  m(0, 0) = 1;
  n(0, 0) = 1;

  m(1, 1) = 1;
  n(1, 1) = 1;

  m.SumMatrix(n);

  EXPECT_EQ(m(0, 0), 2);
  EXPECT_EQ(m(1, 1), 2);
}

TEST(test_functional, add_operator_overload) {
  S21Matrix m(2, 2);
  S21Matrix n(2, 2);

  m(0, 0) = 1;
  n(0, 0) = 1;

  m(1, 1) = 1;
  n(1, 1) = 1;

  m = m + n;

  EXPECT_EQ(m(0, 0), 2);
  EXPECT_EQ(m(1, 1), 2);
}

TEST(test_functional, eqadd_operator_overload) {
  S21Matrix m(2, 2);
  S21Matrix n(2, 2);

  m(0, 0) = 1;
  n(0, 0) = 1;

  m(1, 1) = 1;
  n(1, 1) = 1;

  m += m + n;

  EXPECT_EQ(m(0, 0), 3);
  EXPECT_EQ(m(1, 1), 3);
}

TEST(test_functional, sub_matrix) {
  S21Matrix m(2, 2);
  S21Matrix n(2, 2);

  m(0, 0) = 1;
  n(0, 0) = 1;

  m(1, 1) = 1;
  n(1, 1) = 1;

  m.SubMatrix(n);

  EXPECT_EQ(m(0, 0), 0);
  EXPECT_EQ(m(1, 1), 0);
}

TEST(test_functional, eqsub_overloaded_operator) {
  S21Matrix m(2, 2);
  S21Matrix n(2, 2);

  m(0, 0) = 1;
  n(0, 0) = 1;

  m(1, 1) = 1;
  n(1, 1) = 1;

  m -= n;

  EXPECT_EQ(m(0, 0), 0);
  EXPECT_EQ(m(1, 1), 0);
}

TEST(test_functional, sub_operator_overload) {
  S21Matrix m(2, 2);
  S21Matrix n(2, 2);

  m(0, 0) = 1;
  n(0, 0) = 1;

  m(1, 1) = 1;
  n(1, 1) = 1;

  m = m - n;

  EXPECT_EQ(m(0, 0), 0);
  EXPECT_EQ(m(1, 1), 0);
}

TEST(test_functional, mul_matrices) {
  const int rows = 2;
  const int cols = 3;

  S21Matrix m(rows, cols);
  S21Matrix n(cols, rows);

  for (int i = 0, c = 1; i < rows; i++)
    for (int j = 0; j < cols; j++) m[i][j] = c++;

  for (int i = 0, c = 7; i < cols; i++)
    for (int j = 0; j < rows; j++) n[i][j] = c++;

  m.MulMatrix(n);

  S21Matrix res(2, 2);
  res[0][0] = 58;
  res[0][1] = 64;
  res[1][0] = 139;
  res[1][1] = 154;

  ASSERT_TRUE(m.EqMatrix(res));
}

TEST(test_functional, eqmul_operator) {
  const int rows = 2;
  const int cols = 3;

  S21Matrix m(rows, cols);
  S21Matrix n(cols, rows);

  for (int i = 0, c = 1; i < rows; i++)
    for (int j = 0; j < cols; j++) m[i][j] = c++;

  for (int i = 0, c = 7; i < cols; i++)
    for (int j = 0; j < rows; j++) n[i][j] = c++;

  m *= n;

  S21Matrix res(2, 2);
  res[0][0] = 58;
  res[0][1] = 64;
  res[1][0] = 139;
  res[1][1] = 154;

  ASSERT_TRUE(m.EqMatrix(res));
}

TEST(test_functional, eqmul_operator_num) {
  const int rows = 2;
  const int cols = 3;

  S21Matrix m(rows, cols);

  for (int i = 0, c = 1; i < rows; i++)
    for (int j = 0; j < cols; j++) m[i][j] = c++;

  m *= 2;

  S21Matrix res(2, 3);
  res[0][0] = 2;
  res[0][1] = 4;
  res[0][2] = 6;
  res[1][0] = 8;
  res[1][1] = 10;
  res[1][2] = 12;

  ASSERT_TRUE(m.EqMatrix(res));
}

TEST(test_functional, mul_operator) {
  const int rows = 2;
  const int cols = 3;

  S21Matrix m(rows, cols);
  S21Matrix n(cols, rows);

  for (int i = 0, c = 1; i < rows; i++)
    for (int j = 0; j < cols; j++) m[i][j] = c++;

  for (int i = 0, c = 7; i < cols; i++)
    for (int j = 0; j < rows; j++) n[i][j] = c++;

  m = m * n;

  S21Matrix res(2, 2);
  res[0][0] = 58;
  res[0][1] = 64;
  res[1][0] = 139;
  res[1][1] = 154;

  ASSERT_TRUE(m == res);
}

TEST(test_functional, mul_operator_num) {
  const int rows = 2;
  const int cols = 3;

  S21Matrix m(rows, cols);

  for (int i = 0, c = 1; i < rows; i++)
    for (int j = 0; j < cols; j++) m[i][j] = c++;

  m = 2 * m;

  S21Matrix res(2, 3);
  res[0][0] = 2;
  res[0][1] = 4;
  res[0][2] = 6;
  res[1][0] = 8;
  res[1][1] = 10;
  res[1][2] = 12;

  ASSERT_TRUE(m == res);
}

TEST(test_functional, transpose) {
  const int rows = 2;
  const int cols = 3;

  S21Matrix m(rows, cols);
  S21Matrix res(cols, rows);

  for (int i = 0, c = 1; i < rows; i++)
    for (int j = 0; j < cols; j++, c++) {
      m[i][j] = c;
      res[j][i] = c;
    }

  m = m.Transpose();
  ASSERT_TRUE(m == res);
}

TEST(test_functional, determinant) {
  S21Matrix m(2, 3);

  EXPECT_ANY_THROW(m.Determinant());
}

TEST(test_functional, determinant_zero) {
  const int size = 5;
  S21Matrix m(5, 5);

  for (int i = 0; i < size; i++)
    for (int j = 0; j < size; j++) m[i][j] = j;

  ASSERT_NEAR(0, m.Determinant(), 1e-06);
}

TEST(test_functional, determinant_5x5) {
  int size = 5;
  S21Matrix m(size, size);

  m[0][1] = 6;
  m[0][2] = -2;
  m[0][3] = -1;
  m[0][4] = 5;
  m[1][3] = -9;
  m[1][4] = -7;
  m[2][1] = 15;
  m[2][2] = 35;
  m[3][1] = -1;
  m[3][2] = -11;
  m[3][3] = -2;
  m[3][4] = 1;
  m[4][0] = -2;
  m[4][1] = -2;
  m[4][2] = 3;
  m[4][4] = -2;

  double res = m.Determinant();
  ASSERT_NEAR(res, 2480, 1e-6);
}

TEST(test_functional, determinant_3x3) {
  const int size = 3;
  S21Matrix m(size, size);

  m[0][0] = 2;
  m[0][1] = 3;
  m[0][2] = 1;
  m[1][0] = 7;
  m[1][1] = 4;
  m[1][2] = 1;
  m[2][0] = 9;
  m[2][1] = -2;
  m[2][2] = 1;

  double res = m.Determinant();
  ASSERT_NEAR(res, -32, 1e-6);
}

TEST(test_functional, determinant_2x2) {
  const int size = 2;
  S21Matrix m(size, size);

  m[0][0] = -5;
  m[0][1] = -4;
  m[1][0] = -2;
  m[1][1] = -3;

  double res = m.Determinant();
  ASSERT_NEAR(res, 7, 1e-6);
}

TEST(test_functional, complements_3x3) {
  const int rows = 3;
  const int cols = 3;

  S21Matrix given(rows, cols);
  S21Matrix expected(rows, cols);

  expected[0][0] = 0;
  expected[0][1] = 10;
  expected[0][2] = -20;
  expected[1][0] = 4;
  expected[1][1] = -14;
  expected[1][2] = 8;
  expected[2][0] = -8;
  expected[2][1] = -2;
  expected[2][2] = 4;

  given[0][0] = 1;
  given[0][1] = 2;
  given[0][2] = 3;
  given[1][0] = 0;
  given[1][1] = 4;
  given[1][2] = 2;
  given[2][0] = 5;
  given[2][1] = 2;
  given[2][2] = 1;

  S21Matrix res = given.CalcComplements();

  ASSERT_TRUE(res == expected);
}

TEST(test_functional, CalcComplements_throw) {
  S21Matrix m(3, 12);
  EXPECT_ANY_THROW(m.CalcComplements());
}

TEST(test_functional, complements_3x3_1) {
  const int rows = 3;
  const int cols = 3;

  S21Matrix given(rows, cols);
  S21Matrix expected(rows, cols);

  given[0][0] = 1.0;
  given[0][1] = 2.0;
  given[0][2] = 3.0;
  given[1][0] = 0.0;
  given[1][1] = 4.0;
  given[1][2] = 2.0;
  given[2][0] = 5.0;
  given[2][1] = 2.0;
  given[2][2] = 1.0;

  expected[0][0] = 0.0;
  expected[0][1] = 10.0;
  expected[0][2] = -20.0;
  expected[1][0] = 4.0;
  expected[1][1] = -14.0;
  expected[1][2] = 8.0;
  expected[2][0] = -8.0;
  expected[2][1] = -2.0;
  expected[2][2] = 4.0;

  S21Matrix res = given.CalcComplements();

  ASSERT_TRUE(res == expected);
}

TEST(test_class, zero_size) { EXPECT_ANY_THROW(S21Matrix(0, 1)); }

TEST(test_functional, complements_3x3_2) {
  const int rows = 3;
  const int cols = 3;

  S21Matrix given(rows, cols);
  S21Matrix expected(rows, cols);

  given[0][0] = 1;
  given[0][1] = 2;
  given[0][2] = 3;
  given[1][1] = 4;
  given[1][2] = 2;
  given[2][0] = 5;
  given[2][1] = 2;
  given[2][2] = 1;

  expected[0][1] = 10;
  expected[0][2] = -20;
  expected[1][0] = 4;
  expected[1][1] = -14;
  expected[1][2] = 8;
  expected[2][0] = -8;
  expected[2][1] = -2;
  expected[2][2] = 4;

  S21Matrix res = given.CalcComplements();
  ASSERT_TRUE(res == expected);
}

TEST(test_functional, inverese_3x3) {
  const int size = 3;
  S21Matrix given(size, size);
  S21Matrix expected(size, size);

  expected[0][0] = 44300.0 / 367429.0;
  expected[0][1] = -236300.0 / 367429.0;
  expected[0][2] = 200360.0 / 367429.0;
  expected[1][0] = 20600.0 / 367429.0;
  expected[1][1] = 56000.0 / 367429.0;
  expected[1][2] = -156483.0 / 367429.0;
  expected[2][0] = 30900.0 / 367429.0;
  expected[2][1] = 84000.0 / 367429.0;
  expected[2][2] = -51010.0 / 367429.0;

  given[0][0] = 2.8;
  given[0][1] = 1.3;
  given[0][2] = 7.01;
  given[1][0] = -1.03;
  given[1][1] = -2.3;
  given[1][2] = 3.01;
  given[2][0] = 0;
  given[2][1] = -3;
  given[2][2] = 2;
  ASSERT_TRUE(given.InverseMatrix() == expected);
}

TEST(test_functional, inverese_3x3_1) {
  const int size = 3;
  S21Matrix given(size, size);
  S21Matrix expected(size, size);
  expected[0][0] = 1.0;
  expected[0][1] = -1.0;
  expected[0][2] = 1.0;
  expected[1][0] = -38.0;
  expected[1][1] = 41.0;
  expected[1][2] = -34.0;
  expected[2][0] = 27.0;
  expected[2][1] = -29.0;
  expected[2][2] = 24.0;

  given[0][0] = 2.0;
  given[0][1] = 5.0;
  given[0][2] = 7.0;
  given[1][0] = 6.0;
  given[1][1] = 3.0;
  given[1][2] = 4.0;
  given[2][0] = 5.0;
  given[2][1] = -2.0;
  given[2][2] = -3.0;

  ASSERT_TRUE(given.InverseMatrix() == expected);
}

TEST(test_functional, inverse_throw) {
  S21Matrix m(2, 3);
  EXPECT_ANY_THROW(m.InverseMatrix());

  S21Matrix n(2, 2);
  EXPECT_ANY_THROW(n.InverseMatrix());
}

TEST(test_functional, inverse_1x1) {
  S21Matrix m(1, 1);
  m[0][0] = 69.420;
  double expected = 1.0 / m[0][0];
  double result = m.InverseMatrix()[0][0];
  ASSERT_NEAR(expected, result, 1e-06);
}

TEST(test_functional, inverese_3x3_2) {
  const int size = 3;
  S21Matrix given(size, size);
  S21Matrix expected(size, size);

  given[0][0] = 2;
  given[0][1] = 5;
  given[0][2] = 7;
  given[1][0] = 6;
  given[1][1] = 3;
  given[1][2] = 4;
  given[2][0] = 5;
  given[2][1] = -2;
  given[2][2] = -3;

  expected[0][0] = 1;
  expected[0][1] = -1;
  expected[0][2] = 1;
  expected[1][0] = -38;
  expected[1][1] = 41;
  expected[1][2] = -34;
  expected[2][0] = 27;
  expected[2][1] = -29;
  expected[2][2] = 24;
  ASSERT_TRUE(given.InverseMatrix() == expected);
}

TEST(test_functional, inverese_3x3_3) {
  const int size = 3;
  S21Matrix given(size, size);
  S21Matrix expected(size, size);

  given[0][0] = 2;
  given[0][1] = 5;
  given[0][2] = 7;
  given[1][0] = 6;
  given[1][1] = 3;
  given[1][2] = 4;
  given[2][0] = 5;
  given[2][1] = -2;
  given[2][2] = -3;

  expected[0][0] = 1;
  expected[0][1] = -1;
  expected[0][2] = 1;
  expected[1][0] = -38;
  expected[1][1] = 41;
  expected[1][2] = -34;
  expected[2][0] = 27;
  expected[2][1] = -29;
  expected[2][2] = 24;
  ASSERT_TRUE(given.InverseMatrix() == expected);
}

TEST(test_functional, brackets_const) {
  S21Matrix n;
  S21Matrix g(2, 2);
  S21Matrix v;
  ASSERT_THROW(g.MulMatrix(v), std::out_of_range);
  ASSERT_THROW(v = n, std::out_of_range);
  ASSERT_THROW(g[-1], std::out_of_range);
  ASSERT_THROW(S21Matrix m(n), std::out_of_range);
  ASSERT_THROW(S21Matrix v(std::move(n)), std::out_of_range);
}

TEST(S21MatrixTest, Constructor) {
  S21Matrix mat(3, 4);

  // Check that all elements are initialized to zero
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 4; j++) {
      ASSERT_EQ(mat(i, j), 0.0);
    }
  }
  // Check that an exception is thrown if rows or columns are less than 1
  ASSERT_THROW(S21Matrix mat2(0, 4), std::out_of_range);
  ASSERT_THROW(S21Matrix mat3(3, -1), std::out_of_range);
}

TEST(S21MatrixTest, CopyConstructor) {
  S21Matrix A(3, 4);
  S21Matrix B(A);
  EXPECT_EQ(1, A == B);
}
TEST(S21MatrixTest, SumMatrixTesto) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix expected(2, 2);

  a(0, 0) = 1;
  a(0, 1) = 2;
  a(1, 0) = 3;
  a(1, 1) = 4;

  b(0, 0) = 5;
  b(0, 1) = 6;
  b(1, 0) = 7;
  b(1, 1) = 8;

  expected(0, 0) = 6;
  expected(0, 1) = 8;
  expected(1, 0) = 10;
  expected(1, 1) = 12;

  a.SumMatrix(b);
  EXPECT_TRUE(a == expected);
}
TEST(S21MatrixTest, SubMatrixTesto) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix expected(2, 2);

  a(0, 0) = 4;
  a(0, 1) = 4;
  a(1, 0) = 6;
  a(1, 1) = 6;

  b(0, 0) = 2;
  b(0, 1) = 2;
  b(1, 0) = 3;
  b(1, 1) = 3;

  expected(0, 0) = 2;
  expected(0, 1) = 2;
  expected(1, 0) = 3;
  expected(1, 1) = 3;

  a.SubMatrix(b);
  EXPECT_TRUE(a == expected);
}

TEST(S21MatrixTest, MulMatrixTesto) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix expected(2, 2);

  a(0, 0) = 1;
  a(0, 1) = 2;
  a(1, 0) = 3;
  a(1, 1) = 4;

  b(0, 0) = 5;
  b(0, 1) = 6;
  b(1, 0) = 7;
  b(1, 1) = 8;

  expected(0, 0) = 19;
  expected(0, 1) = 22;
  expected(1, 0) = 43;
  expected(1, 1) = 50;

  a.MulMatrix(b);

  EXPECT_TRUE(a == expected);
}
TEST(S21MatrixTest, MulNumberTesto) {
  S21Matrix a(2, 2);
  S21Matrix expected(2, 2);

  a(0, 0) = 1;
  a(0, 1) = 2;
  a(1, 0) = 3;
  a(1, 1) = 4;

  expected(0, 0) = 2;
  expected(0, 1) = 4;
  expected(1, 0) = 6;
  expected(1, 1) = 8;

  a.MulNumber(2);

  EXPECT_TRUE(a == expected);
}
TEST(S21MatrixTest, EqTest) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);

  a(0, 0) = 1;
  a(0, 1) = 2;
  a(1, 0) = 3;
  a(1, 1) = 4;

  b(0, 0) = 1;
  b(0, 1) = 2;
  b(1, 0) = 3;
  b(1, 1) = 4;

  EXPECT_TRUE(a.EqMatrix(b));
}

TEST(S21MatrixTest, operator_plus) {
  S21Matrix A(3, 4);
  S21Matrix B(3, 4);

  B(0, 0) = 1;
  B(0, 1) = 2;
  B(0, 2) = 3;
  B(0, 3) = 4;
  B(1, 0) = 5;
  B(1, 1) = 6;
  B(1, 2) = 7;
  B(1, 3) = 8;
  B(2, 0) = 9;
  B(2, 1) = 10;
  B(2, 2) = 11;
  B(2, 3) = 12;
  A = B + B;
  EXPECT_FALSE(A == B);
}

TEST(S21MatrixTest, operator_minus) {
  S21Matrix A(3, 4);
  S21Matrix B(3, 4);
  B(0, 0) = 1;
  B(0, 1) = 2;
  B(0, 2) = 3;
  B(0, 3) = 4;
  B(1, 0) = 5;
  B(1, 1) = 6;
  B(1, 2) = 7;
  B(1, 3) = 8;
  B(2, 0) = 9;
  B(2, 1) = 10;
  B(2, 2) = 11;
  B(2, 3) = 12;
  A = B - B;
  EXPECT_FALSE(A == B);
}
TEST(S21MatrixTest, inverst_test) {
  S21Matrix result(3, 3);
  result(0, 0) = 0;
  result(0, 1) = 1;
  result(0, 2) = -0.75;
  result(1, 0) = -0.5;
  result(1, 1) = 3;
  result(1, 2) = -2;
  result(2, 0) = 0.5;
  result(2, 1) = -3.5;
  result(2, 2) = 2.5;

  S21Matrix R(3, 3);
  R(0, 0) = 8;
  R(0, 1) = 2;
  R(0, 2) = 4;
  R(1, 0) = 4;
  R(1, 1) = 6;
  R(1, 2) = 6;
  R(2, 0) = 4;
  R(2, 1) = 8;
  R(2, 2) = 8;

  S21Matrix result_inverse(3, 3);
  result_inverse = R.InverseMatrix();
  EXPECT_EQ(1, result == result_inverse);
}
TEST(S21MatrixTest, operator_pluseq) {
  S21Matrix A(3, 4);
  S21Matrix B(3, 4);
  B(0, 0) = 1;
  B(0, 1) = 2;
  B(0, 2) = 3;
  B(0, 3) = 4;
  B(1, 0) = 5;
  B(1, 1) = 6;
  B(1, 2) = 7;
  B(1, 3) = 8;
  B(2, 0) = 9;
  B(2, 1) = 10;
  B(2, 2) = 11;
  B(2, 3) = 12;
  A += B;
  EXPECT_EQ(1, A == B);
}

TEST(S21MatrixTest, operator_minuseq) {
  S21Matrix A(3, 4);
  S21Matrix B(3, 4);
  B(0, 0) = 1;
  B(0, 1) = 2;
  B(0, 2) = 3;
  B(0, 3) = 4;
  B(1, 0) = 5;
  B(1, 1) = 6;
  B(1, 2) = 7;
  B(1, 3) = 8;
  B(2, 0) = 9;
  B(2, 1) = 10;
  B(2, 2) = 11;
  B(2, 3) = 12;

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(0, 2) = 3;
  A(0, 3) = 4;
  A(1, 0) = 5;
  A(1, 1) = 6;
  A(1, 2) = 7;
  A(1, 3) = 8;
  A(2, 0) = 9;
  A(2, 1) = 10;
  A(2, 2) = 11;
  A(2, 3) = 12;
  A -= B;
  B -= B;
  EXPECT_EQ(1, A == B);
}
TEST(S21MatrixTest, operator_mulNumbereq) {
  S21Matrix B(3, 4);
  S21Matrix A(3, 4);
  B(0, 0) = 1;
  B(0, 1) = 2;
  B(0, 2) = 3;
  B(0, 3) = 4;
  B(1, 0) = 5;
  B(1, 1) = 6;
  B(1, 2) = 7;
  B(1, 3) = 8;
  B(2, 0) = 9;
  B(2, 1) = 10;
  B(2, 2) = 11;
  B(2, 3) = 12;

  A(0, 0) = 2;
  A(0, 1) = 4;
  A(0, 2) = 6;
  A(0, 3) = 8;
  A(1, 0) = 10;
  A(1, 1) = 12;
  A(1, 2) = 14;
  A(1, 3) = 16;
  A(2, 0) = 18;
  A(2, 1) = 20;
  A(2, 2) = 22;
  A(2, 3) = 24;

  B *= 2;
  EXPECT_EQ(1, B == A);
}
TEST(S21MatrixTest, operator_mulMatrixeq) {
  S21Matrix B(2, 2);
  S21Matrix A(2, 2);
  S21Matrix expected(2, 2);
  B(0, 0) = 1;
  B(0, 1) = 2;
  B(1, 0) = 5;
  B(1, 1) = 6;

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 5;
  A(1, 1) = 6;

  expected(0, 0) = 11;
  expected(0, 1) = 14;
  expected(1, 0) = 35;
  expected(1, 1) = 46;

  B *= A;
  EXPECT_EQ(1, B == expected);
}
TEST(S21MatrixTest, operator_mulMatrix) {
  S21Matrix B(2, 2);
  S21Matrix A(2, 2);
  S21Matrix expected(2, 2);
  B(0, 0) = 1;
  B(0, 1) = 2;
  B(1, 0) = 5;
  B(1, 1) = 6;

  A(0, 0) = 1;
  A(0, 1) = 2;
  A(1, 0) = 5;
  A(1, 1) = 6;

  expected(0, 0) = 11;
  expected(0, 1) = 14;
  expected(1, 0) = 35;
  expected(1, 1) = 46;

  B = B * A;
  EXPECT_EQ(1, B == expected);
}
TEST(S21MatrixTest, operator_mulNumber) {
  S21Matrix B(3, 4);
  S21Matrix A(3, 4);
  B(0, 0) = 1;
  B(0, 1) = 2;
  B(0, 2) = 3;
  B(0, 3) = 4;
  B(1, 0) = 5;
  B(1, 1) = 6;
  B(1, 2) = 7;
  B(1, 3) = 8;
  B(2, 0) = 9;
  B(2, 1) = 10;
  B(2, 2) = 11;
  B(2, 3) = 12;

  A(0, 0) = 2;
  A(0, 1) = 4;
  A(0, 2) = 6;
  A(0, 3) = 8;
  A(1, 0) = 10;
  A(1, 1) = 12;
  A(1, 2) = 14;
  A(1, 3) = 16;
  A(2, 0) = 18;
  A(2, 1) = 20;
  A(2, 2) = 22;
  A(2, 3) = 24;

  B = B * 2;
  EXPECT_EQ(1, B == A);
}

TEST(Test, Error1) {
  S21Matrix A;
  EXPECT_THROW(A.CalcComplements(), std::out_of_range);
}
TEST(Test, Error2) {
  S21Matrix A;
  EXPECT_THROW(A.Determinant(), std::out_of_range);
}
TEST(Test, Error6) {
  S21Matrix A(1, 2);
  EXPECT_THROW(A.InverseMatrix(), std::out_of_range);
}
TEST(S21MatrixTest, Error7) {
  S21Matrix A(1, 3);
  S21Matrix B(2, 3);
  EXPECT_THROW(A.SumMatrix(B), std::out_of_range);
}
TEST(S21MatrixTest, Error8) {
  S21Matrix A(2, 3);
  S21Matrix B(1, 3);
  EXPECT_THROW(A.SubMatrix(B), std::out_of_range);
}

TEST(S21MatrixTest, operator_error) {
  S21Matrix B(2, 2);
  EXPECT_THROW((B(0, 5) = 2), std::out_of_range);
}
TEST(S21MatrixTest, OperatorConst) {
  S21Matrix A(1, 1);
  A(0, 0) = 1;
  EXPECT_EQ(A(0, 0), 1);
}
TEST(S21MatrixTest, OperatorConstError) {
  S21Matrix A(1, 1);
  EXPECT_THROW((A(0, 5) = 1), std::out_of_range);
}

// ---SumMatrix--------------------------------------------------------------------------------------------------------------------

// ---Transpose--------------------------------------------------------------------------------------------------------------------

TEST(S21MatrixTest, TransposeTest_1) {
  S21Matrix matrix1(2, 2);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  S21Matrix result = matrix1.Transpose();

  ASSERT_EQ(result.Get_Rows(), 2);
  ASSERT_EQ(result.Get_Cols(), 2);
  ASSERT_EQ(result(0, 0), 1);
  ASSERT_EQ(result(0, 1), 3);
  ASSERT_EQ(result(1, 0), 2);
  ASSERT_EQ(result(1, 1), 4);
}

TEST(S21MatrixTest, TransposeTest_2) {
  S21Matrix matrix2(3, 1);
  matrix2(0, 0) = 5;
  matrix2(1, 0) = 6;
  matrix2(2, 0) = 7;

  S21Matrix result = matrix2.Transpose();

  ASSERT_EQ(result.Get_Rows(), 1);
  ASSERT_EQ(result.Get_Cols(), 3);
  ASSERT_EQ(result(0, 0), 5);
  ASSERT_EQ(result(0, 1), 6);
  ASSERT_EQ(result(0, 2), 7);
}

TEST(S21MatrixTest, TransposeTest_3) {
  S21Matrix matrix3(1, 3);
  matrix3(0, 0) = 8;
  matrix3(0, 1) = 9;
  matrix3(0, 2) = 10;

  S21Matrix result = matrix3.Transpose();

  ASSERT_EQ(result.Get_Rows(), 3);
  ASSERT_EQ(result.Get_Cols(), 1);
  ASSERT_EQ(result(0, 0), 8);
  ASSERT_EQ(result(1, 0), 9);
  ASSERT_EQ(result(2, 0), 10);
}

// ---CalcComplements--------------------------------------------------------------------------------------------------------------------

TEST(S21MatrixTest, CalcComplements1) {
  S21Matrix test1(3, 3);
  test1(0, 0) = 1;
  test1(0, 1) = 2;
  test1(0, 2) = 3;
  test1(1, 0) = 0;
  test1(1, 1) = 4;
  test1(1, 2) = 2;
  test1(2, 0) = 5;
  test1(2, 1) = 2;
  test1(2, 2) = 1;
  test1 = test1.CalcComplements();
  S21Matrix test2(3, 3);
  test2(0, 0) = 0;
  test2(0, 1) = 10;
  test2(0, 2) = -20;
  test2(1, 0) = 4;
  test2(1, 1) = -14;
  test2(1, 2) = 8;
  test2(2, 0) = -8;
  test2(2, 1) = -2;
  test2(2, 2) = 4;
  EXPECT_EQ(1, test1 == test2);
}

TEST(S21MatrixTest, CalcComplements_DifferentValues1) {
  S21Matrix test1(3, 1);
  ASSERT_THROW(test1.CalcComplements();, std::out_of_range);
  S21Matrix test2;
  ASSERT_THROW(test1 = std::move(test2), std::out_of_range);
}

TEST(S21MatrixTest, CalcComplements_DifferentValues2) {
  S21Matrix test1(70, 100);
  ASSERT_THROW(test1.CalcComplements();, std::out_of_range);
}

// ---Determinant--------------------------------------------------------------------------------------------------------------------

TEST(S21MatrixTest, Determinant1) {
  S21Matrix test1(3, 3);
  test1(0, 0) = 1;
  test1(0, 1) = 2;
  test1(0, 2) = 3;
  test1(1, 0) = 0;
  test1(1, 1) = 4;
  test1(1, 2) = 2;
  test1(2, 0) = 5;
  test1(2, 1) = 2;
  test1(2, 2) = 1;
  double det = test1.Determinant();
  EXPECT_DOUBLE_EQ(det, -40);
}

TEST(S21MatrixTest, Determinant_DifferentValues1) {
  S21Matrix test1(3, 7);
  ASSERT_THROW(test1.Determinant(), std::out_of_range);
}

// ---InverseMatrix--------------------------------------------------------------------------------------------------------------------

TEST(S21MatrixTest, InverseMatrix) {
  auto test1 = S21Matrix(3, 3);
  test1(0, 0) = 2;
  test1(0, 1) = 5;
  test1(0, 2) = 7;
  test1(1, 0) = 6;
  test1(1, 1) = 3;
  test1(1, 2) = 4;
  test1(2, 0) = 5;
  test1(2, 1) = -2;
  test1(2, 2) = -3;
  test1 = test1.InverseMatrix();
  auto test2 = S21Matrix(3, 3);
  test2(0, 0) = 1;
  test2(0, 1) = -1;
  test2(0, 2) = 1;
  test2(1, 0) = -38;
  test2(1, 1) = 41;
  test2(1, 2) = -34;
  test2(2, 0) = 27;
  test2(2, 1) = -29;
  test2(2, 2) = 24;
  EXPECT_EQ(1, test1 == test2);
}

// --- оператора сравнения ==
// --------------------------------------------------------------------------------------------------------------------

TEST(S21MatrixTest, OperatorEqualsTest1) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(1, 0) = 3;
  matrix(1, 1) = 4;

  S21Matrix other(2, 2);
  other(0, 0) = 1;
  other(0, 1) = 2;
  other(1, 0) = 3;
  other(1, 1) = 4;

  ASSERT_TRUE(matrix == other);
}

TEST(S21MatrixTest, OperatorEqualsTest2) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(1, 0) = 3;
  matrix(1, 1) = 4;

  S21Matrix other(2, 2);
  other(0, 0) = 1;
  other(0, 1) = 2;
  other(1, 0) = 8;
  other(1, 1) = 4;

  ASSERT_FALSE(matrix == other);
}

TEST(S21MatrixTest, OperatorEqualsTest3) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(1, 0) = 3;
  matrix(1, 1) = 4;

  S21Matrix other(2, 3);
  other(0, 0) = 1;
  other(0, 1) = 2;
  other(1, 0) = 3;
  other(1, 1) = 4;

  ASSERT_FALSE(matrix == other);
}

// --- оператор сложения +
// --------------------------------------------------------------------------------------------------------------------

TEST(S21MatrixTest, OperatorPlusTest) {
  S21Matrix matrix1(2, 2);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  S21Matrix matrix2(2, 2);
  matrix2(0, 0) = 2;
  matrix2(0, 1) = 3;
  matrix2(1, 0) = 4;
  matrix2(1, 1) = 5;

  S21Matrix expected(2, 2);
  expected(0, 0) = 3;
  expected(0, 1) = 5;
  expected(1, 0) = 7;
  expected(1, 1) = 9;

  S21Matrix result = (matrix1 + matrix2);

  ASSERT_TRUE(result == expected);
}

TEST(S21MatrixTest, OperatorPlusTest_DifferentValues1) {
  S21Matrix matrix1(2, 5);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  S21Matrix matrix2(2, 2);
  matrix2(0, 0) = 2;
  matrix2(0, 1) = 3;
  matrix2(1, 0) = 4;
  matrix2(1, 1) = 5;

  ASSERT_THROW(S21Matrix result = (matrix1 + matrix2);, std::out_of_range);
}

// --- оператора вычитания -
// --------------------------------------------------------------------------------------------------------------------

TEST(S21MatrixTest, OperatorMinusTest) {
  S21Matrix matrix1(2, 2);
  matrix1(0, 0) = 5;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 7;
  matrix1(1, 1) = 4;

  S21Matrix matrix2(2, 2);
  matrix2(0, 0) = 3;
  matrix2(0, 1) = 1;
  matrix2(1, 0) = 2;
  matrix2(1, 1) = 5;

  S21Matrix expected(2, 2);
  expected(0, 0) = 2;
  expected(0, 1) = 1;
  expected(1, 0) = 5;
  expected(1, 1) = -1;

  S21Matrix result = matrix1 - matrix2;

  ASSERT_TRUE(result == expected);
}

TEST(S21MatrixTest, OperatorMinusTest_DifferentValues1) {
  S21Matrix matrix1(2, 2);
  matrix1(0, 0) = 5;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 7;
  matrix1(1, 1) = 4;

  S21Matrix matrix2(9, 2);
  matrix2(0, 0) = 3;
  matrix2(0, 1) = 1;
  matrix2(1, 0) = 2;
  matrix2(1, 1) = 5;

  ASSERT_THROW(S21Matrix result = (matrix1 - matrix2);, std::out_of_range);
}

// --- оператор умножения на число *
// --------------------------------------------------------------------------------------------------------------------

TEST(S21MatrixTest, OperatorMultiplyByNumTest) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(1, 0) = 3;
  matrix(1, 1) = 4;

  double num = 2;

  S21Matrix expected(2, 2);
  expected(0, 0) = 2;
  expected(0, 1) = 4;
  expected(1, 0) = 6;
  expected(1, 1) = 8;

  S21Matrix result = matrix * num;

  ASSERT_TRUE(result == expected);
}

// --- оператор равенства =
// --------------------------------------------------------------------------------------------------------------------

TEST(S21MatrixTest, OperatorEqualsiplyByNumTest) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(1, 0) = 3;
  matrix(1, 1) = 4;

  S21Matrix result = matrix;

  ASSERT_TRUE(result == matrix);
}

// --- суммы матриц +=
// --------------------------------------------------------------------------------------------------------------------

TEST(S21MatrixTest, SumMatrixTest3) {
  S21Matrix matrix1(5, 5);
  matrix1(0, 4) = 3;
  matrix1(1, 1) = 75;
  matrix1(1, 3) = 9;
  matrix1(3, 1) = 12;
  matrix1(4, 2) = 4;

  S21Matrix matrix2(5, 5);
  matrix2(0, 4) = 5;
  matrix2(0, 2) = 9;
  matrix2(1, 1) = 30;
  matrix2(1, 3) = 1;
  matrix2(3, 1) = 100;
  matrix2(4, 2) = 5;

  matrix1 += matrix2;
  ASSERT_EQ(matrix1(0, 4), 8);
  ASSERT_EQ(matrix1(0, 2), 9);
  ASSERT_EQ(matrix1(1, 1), 105);
  ASSERT_EQ(matrix1(1, 3), 10);
  ASSERT_EQ(matrix1(3, 1), 112);
  ASSERT_EQ(matrix1(4, 2), 9);
}

// --- Назначение разности -=
// --------------------------------------------------------------------------------------------------------------------

TEST(S21MatrixTest, SubMatrixTest2) {
  S21Matrix matrix1(2, 2);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  S21Matrix matrix2(2, 2);
  matrix2(0, 0) = 5;
  matrix2(0, 1) = 6;
  matrix2(1, 0) = 7;
  matrix2(1, 1) = 8;

  matrix1 -= matrix2;

  ASSERT_EQ(matrix1(0, 0), -4);
  ASSERT_EQ(matrix1(0, 1), -4);
  ASSERT_EQ(matrix1(1, 0), -4);
  ASSERT_EQ(matrix1(1, 1), -4);
}

// --- Назначение умножения *=
// --------------------------------------------------------------------------------------------------------------------

TEST(S21MatrixTest, MulMatrixTest3) {
  S21Matrix matrix1(5, 2);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  S21Matrix matrix2(2, 5);

  matrix2(0, 0) = 5;
  matrix2(0, 1) = 6;
  matrix2(1, 0) = 7;
  matrix2(1, 1) = 8;

  matrix1 *= matrix2;

  ASSERT_EQ(matrix1(0, 0), 19);
  ASSERT_EQ(matrix1(0, 1), 22);
  ASSERT_EQ(matrix1(1, 0), 43);
  ASSERT_EQ(matrix1(1, 1), 50);
}

TEST(S21MatrixTest, MulNumberTest4) {
  S21Matrix matrix(2, 2);
  matrix(0, 0) = 1;
  matrix(0, 1) = 2;
  matrix(1, 0) = 3;
  matrix(1, 1) = 4;

  matrix *= 2;

  ASSERT_EQ(matrix(0, 0), 2);
  ASSERT_EQ(matrix(0, 1), 4);
  ASSERT_EQ(matrix(1, 0), 6);
  ASSERT_EQ(matrix(1, 1), 8);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

// void S21Matrix::PrintMatrix() {
//   for (int i = 0; i < rows_; i++) {
//     for (int j = 0; j < cols_; j++) std::cout << matrix_[i][j] << " ";

//     std::cout << std::endl;
//   }
// }