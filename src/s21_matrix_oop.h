#pragma once
#include <iostream>

class S21Matrix {
 public:
  S21Matrix();
  S21Matrix(int row_col);
  S21Matrix(int rows, int cols);
  S21Matrix(int rows, int cols, std::initializer_list<double> data);
  S21Matrix(const S21Matrix& other);
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  S21Matrix& operator=(S21Matrix&& other);
  void set_cols(int number);
  void set_rows(int number);
  void set_dims(int rows, int cols);
  ~S21Matrix();

  void print() { std::cout << (*this) << "\n"; }
  void fill_matrix(double numbers);
  void byte_matrix(int row, int col, S21Matrix& result);

  double& operator()(int rows, int cols);
  double& operator()(int rows, int cols) const;
  friend std::ostream& operator<<(std::ostream& os, const S21Matrix& matrix) {
    for (int i = 0; i < matrix.rows_; i++) {
      for (int j = 0; j < matrix.cols_; j++) {
        os << matrix.matrix_[i * matrix.cols_ + j] << " ";
      }
      os << "\n";
    }
    return os;
  }

  bool EqMatrixTol(const S21Matrix& other);
  S21Matrix operator+(const S21Matrix& o) const;
  S21Matrix operator*(const S21Matrix& o) const;
  S21Matrix operator-(const S21Matrix& o) const;
  S21Matrix& operator*=(const S21Matrix& o);
  S21Matrix& operator+=(const S21Matrix& o);
  S21Matrix& operator-=(const S21Matrix& o);
  bool operator==(const S21Matrix& other);
  void MulNumber(const double num);
  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void MulMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  int get_rows();  // returning rows
  int get_cols();  // returning cols
  double Determinant();
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  S21Matrix InverseMatrix();

 private:
  int rows_, cols_;
  double* matrix_;
};