/*
** EPITECH PROJECT, 2020
** 108trigo
** File description:
** 108trigo
*/

//libC
#include <iostream>
#include <iomanip>
#include <vector>

//mylibs
#include "trigo.h"
#include "matrix.h"

//namespaces
using namespace std;


Matrix::Matrix(int width, int height) {
    _width = width;
    _height = height;
    _board = vector<vector<double>>(height);
    
    for (int i = 0; i < height; i++) {
        _board[i] = vector<double>(width);
        for (int x = 0; x < width; x++)
            _board[i][x] = 0;
    }
}

Matrix::Matrix(vector<vector<double>> board) {
    if (board.size() < 1)
        throw "no board";
    _height = board.size();
    _width = board[0].size();
    _board = board;

    for (int i = 0; i < board.size(); i++) {
        if (board[i].size() != _width)
            throw "wrong board";
    }
}

Matrix::Matrix(int width, int height, double **board) {
    _width = width;
    _height = height;
    _board = vector<vector<double>>(height);
    
    try {
        for (int i = 0; i < height; i++) {
            _board[i] = vector<double>(width);
            for (int x = 0; x < width; x++)
                _board[i][x] = board[i][x];
        }
    } catch (const out_of_range& e) {
        throw "wrong board";
    }
}

void Matrix::Display() {
    for (int y = 0; y < _height; y++) {
        for (int x = 0; x < _width; x++) {
            if (x - 1 != _width)
                display_number_with_space(_board[y][x], 8);
            else
                display_number_with_space(_board[y][x], 0);
        }
        cout << endl;
    }
}

int Matrix::getWidth() const {
    return _width;
}

int Matrix::getHeight() const {
    return _height;
}

vector<vector<double>> Matrix::getBoard() const {
    return _board;
}

double Matrix::getAt(int x, int y) const {
    if (x >= 0 && x < _width && y >= 0 && y < _height)
        return _board[y][x];
    return 0;
}

void Matrix::setAt(int x, int y, double value) {
    if (x >= 0 && x < _width && y >= 0 && y < _height)
        _board[y][x] = value;
}

vector<double> Matrix::getLine(int y) const
{
    if (y >= 0 && y < _height)
        return _board[y];
    return vector<double>();
}

void Matrix::re(int width, int height) {
    _width = width;
    _height = height;
    _board = vector<vector<double>>(height);
    
    for (int i = 0; i < height; i++) {
        _board[i] = vector<double>(width);
        for (int x = 0; x < width; x++)
            _board[i][x] = 0;
    }
}

void Matrix::oppose(const Matrix& matrix) {
    for (int y = 0; y < _height; y++)
        for (int x = 0; x < _width; x++)
            setAt(x, y, - getAt(x, y));
}

//ADDITION

void Matrix::add(const Matrix& matrix) {
    if (_width != matrix.getWidth() || _height != matrix.getHeight())
        ;
    else {
        for (int y = 0; y < _height; y++)
            for (int x = 0; x < _width; x++)
                setAt(x, y, getAt(x, y) + matrix.getAt(x, y));
    }
}

void Matrix::add(const int& nb) {
    for (int y = 0; y < _height; y++)
        for (int x = 0; x < _width; x++)
            setAt(x, y, getAt(x, y) + nb);
}

void Matrix::add(const double& nb) {
    for (int y = 0; y < _height; y++)
        for (int x = 0; x < _width; x++)
            setAt(x, y, getAt(x, y) + nb);
}

//substraction

void Matrix::sub(const Matrix& matrix) {
    if (_width != matrix.getWidth() || _height != matrix.getHeight())
        ;
    else {
        for (int y = 0; y < _height; y++)
            for (int x = 0; x < _width; x++)
                setAt(x, y, getAt(x, y) - matrix.getAt(x, y));
    }
}

void Matrix::sub(const int& nb) {
    for (int y = 0; y < _height; y++)
        for (int x = 0; x < _width; x++)
            setAt(x, y, getAt(x, y) - nb);
}

void Matrix::sub(const double& nb) {
    for (int y = 0; y < _height; y++)
        for (int x = 0; x < _width; x++)
            setAt(x, y, getAt(x, y) - nb);
}

//MULTIPLICATION

void Matrix::mul(const Matrix& m) {
    Matrix copy(*this);

    if (_width == m.getHeight()) {
        re(_height, m.getWidth());
        for (int y = 0; y < _height; y++)
            for (int x = 0; x < _width; x++) {
                double result = 0;
                for (int i = 0; i < m.getHeight(); i++)
                    result += copy.getAt(i, y) * m.getAt(x, i);
                setAt(x, y, result);
            }
    }
}

void Matrix::mul(const double& nb) {
    for (int y = 0; y < _height; y++)
        for (int x = 0; x < _width; x++)
            setAt(x, y, getAt(x, y) * nb);
}

void Matrix::mul(const int& nb) {
    for (int y = 0; y < _height; y++)
        for (int x = 0; x < _width; x++)
            setAt(x, y, getAt(x, y) * nb);
}

//operators


//ADDITION
Matrix& Matrix::operator+=(const Matrix& a)
{
    add(a);
    return *this;
}

Matrix operator+(Matrix const& a, Matrix const& b)
{
    Matrix copy(a);
    copy.add(b);
    return copy;
}

Matrix& Matrix::operator+=(const int& a)
{
    add(a);
    return *this;
}

Matrix operator+(Matrix const& a, int const& b)
{
    Matrix copy(a);
    copy.add(b);
    return copy;
}

Matrix& Matrix::operator+=(const double& a)
{
    add(a);
    return *this;
}

Matrix operator+(Matrix const& a, double const& b)
{
    Matrix copy(a);
    copy.add(b);
    return copy;
}

//Substraction
Matrix& Matrix::operator-=(const Matrix& a)
{
    sub(a);
    return *this;
}

Matrix operator-(Matrix const& a, Matrix const& b)
{
    Matrix copy(a);
    copy.sub(b);
    return copy;
}

Matrix& Matrix::operator-=(const int& a)
{
    sub(a);
    return *this;
}

Matrix operator-(Matrix const& a, int const& b)
{
    Matrix copy(a);
    copy.sub(b);
    return copy;
}

Matrix& Matrix::operator-=(const double& a)
{
    sub(a);
    return *this;
}

Matrix operator-(Matrix const& a, double const& b)
{
    Matrix copy(a);
    copy.sub(b);
    return copy;
}

//MULTIPMICATION
Matrix& Matrix::operator*=(const double& a)
{
    mul(a);
    return *this;
}

Matrix operator*(Matrix const& a, double const& b)
{
    Matrix copy(a);
    copy.mul(b);
    return copy;
}

Matrix& Matrix::operator*=(const int& a)
{
    mul(a);
    return *this;
}

Matrix operator*(Matrix const& a, int const& b)
{
    Matrix copy(a);
    copy.mul(b);
    return copy;
}

Matrix& Matrix::operator*=(const Matrix& a)
{
    mul(a);
    return *this;
}

Matrix operator*(Matrix const& a, Matrix const& b)
{
    Matrix copy(a);
    copy.mul(b);
    return copy;
}