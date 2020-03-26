/*
** EPITECH PROJECT, 2020
** 108trigo
** File description:
** 108trigo
*/

#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <iostream>
#include <vector>
 
class Matrix
{
    public:
 
    Matrix(int width, int height);
    Matrix(std::vector<std::vector<double>> board);
    Matrix(int width, int height, double **board);
    void Display();
    int getWidth() const;
    int getHeight() const;
    void re(int width, int height);
    void oppose(const Matrix& matrix);
    std::vector<std::vector<double>> getBoard() const;
    double getAt(int x, int y) const;
    std::vector<double> getLine(int y) const;
    void setAt(int x, int y, double value);
    void add(const Matrix& matrix);
    void add(const int& nb);
    void add(const double& nb);
    void sub(const Matrix& matrix);
    void sub(const int& nb);
    void sub(const double& nb);
    void mul(const int& nb);
    void mul(const double& nb);
    void mul(const Matrix& m);
    Matrix& operator+=(const Matrix& a);
    Matrix& operator+=(const int& a);
    Matrix& operator+=(const double& a);
    Matrix& operator-=(const Matrix& a);
    Matrix& operator-=(const int& a);
    Matrix& operator-=(const double& a);
    Matrix& operator*=(const double& a);
    Matrix& operator*=(const int& a);
    Matrix& operator*=(const Matrix& a);
 
    private:
 
    int _width;
    int _height;
    std::vector<std::vector<double>> _board;
};
 
Matrix operator+(Matrix const& a, Matrix const& b);
Matrix operator+(Matrix const& a, int const& b);
Matrix operator+(Matrix const& a, double const& b);
Matrix operator-(Matrix const& a, Matrix const& b);
Matrix operator-(Matrix const& a, int const& b);
Matrix operator-(Matrix const& a, double const& b);
Matrix operator*(Matrix const& a, double const& b);
Matrix operator*(Matrix const& a, int const& b);
Matrix operator*(Matrix const& a, Matrix const& b);

#endif /*_MATRIX_H_*/