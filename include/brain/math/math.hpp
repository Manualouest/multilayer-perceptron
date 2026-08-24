/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 15:13:04 by mbirou            #+#    #+#             */
/*   Updated: 2026/08/13 19:39:56 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_HPP
# define MATH_HPP

# include <defines.hpp>
# include <iostream>
# include <stdexcept>
# include <cmath>
# include <initializer_list>


namespace Mmath
{
	template <typename T>
	struct vec
	{
		vec(const size_t &size = 1, const T &defaultVal = 0)	: _size(size)			{_data = new T[_size]; for (size_t i = 0; i < _size; ++i) _data[i] = defaultVal;}
		vec(const vec &src)	 									: _size(src._size)		{*this = src;}
		vec(std::initializer_list<T> init)						: _size(init.size())
		{
			_data = new T[_size];

			int	i = 0;
			for (T elem : init)
			{
				_data[i] = elem;
				i ++;
			}
		}
		~vec()	{delete [] _data; _data = NULL;}

		size_t	_size = 0;
		T		*_data = NULL;

		T	compare(const vec &b)
		{
			T	result = 0;

			for (size_t i = 0; i < _size; ++i)
				result += _data[i] == b[i];
			
			return (result / (T)_size);
		}
		vec	checkRes(const T &checkValue)
		{
			vec	nVec(_size);

			for (size_t i = 0; i < _size; ++i)
				nVec[i] = _data[i] >= checkValue;
			
			return (nVec);
		}

		T	max() const
		{
			T	max = _data[0];

			for (size_t i = 0; i < _size; ++i)
				if (_data[i] > max)
					max = _data[i];
			
			return (max);
		}
		T	min() const
		{
			T	min = _data[0];

			for (size_t i = 0; i < _size; ++i)
				if (_data[i] < min)
					min = _data[i];
			
			return (min);
		}
		vec	normalize()
		{
			T	nmax = max();
			T	nmin = min();
			vec	nVec;

			nVec = *this;
			nVec = (nVec - nmin) / (nmax - nmin);

			return (nVec);
		}

		T	average()
		{
			T	result = 0;

			for (size_t i = 0; i < _size; ++i)
				result += _data[i];
			
			return (result / (T)_size);
		}

		vec	log()
		{
			vec	nVec(_size);

			for (size_t i = 0; i < _size; ++i)
				nVec[i] = std::log(_data[i]);
			
			return (nVec);
		}

		T	sum() const
		{
			T	result = 0;

			for (size_t i = 0; i < _size; ++i)
				result += _data[i];
			
			return (result);
		}

		T	dot(const vec &b)
		{
			if (_size != b._size)
				throw (std::runtime_error(RED BOLD "Dot product cannot occure; vectors are of different size." CLR));
			
			T	total = 0;
			if constexpr (std::is_arithmetic<T>::value)
				for (size_t i = 0; i < _size; ++i)
					total = std::fma(_data[i], b._data[i], total);
			else
				throw (std::runtime_error(RED BOLD "Dot product cannot occure; vector's type isn't numeric." CLR));

			return (total);
		}

		vec	&operator =(const vec &src)
		{
			// if (_size != src._size)
			// 	throw (std::runtime_error(RED BOLD "Assignment operator cannot be executed; vectors are of different size." CLR));

			_size = src._size;

			if (_data)
				delete [] _data;
			_data = new T[_size];
			
			for (size_t i = 0; i < _size; ++i)
				_data[i] = src._data[i];
			return (*this);
		}
		
		T	&operator [](const int &i)
		{
			return (_data[i]);
		}
		T	operator [](const int &i) const
		{
			return (_data[i]);
		}

		// Basic Operations with T
		vec	operator +(const T &n)
		{
			vec	nVec(_size);

			for (size_t i = 0; i < _size; ++i)
				nVec[i] = _data[i] + n;
			
			return (nVec);
		}
		vec	operator -(const T &n)
		{
			vec	nVec(_size);

			for (size_t i = 0; i < _size; ++i)
				nVec[i] = _data[i] - n;
			
			return (nVec);
		}
		vec	operator *(const T &n)
		{
			vec	nVec(_size);

			for (size_t i = 0; i < _size; ++i)
				nVec[i] = _data[i] * n;
			
			return (nVec);
		}
		vec	operator /(const T &n)
		{
			vec	nVec(_size);

			for (size_t i = 0; i < _size; ++i)
				nVec[i] = _data[i] / n;
			
			return (nVec);
		}

		// Basic Operation with another vector
		vec	operator +(const vec &b)
		{
			vec	nVec(_size);

			for (size_t i = 0; i < _size; ++i)
				nVec[i] = _data[i] + b[i];
			
			return (nVec);
		}
		vec	operator -(const vec &b)
		{
			vec	nVec(_size);

			for (size_t i = 0; i < _size; ++i)
				nVec[i] = _data[i] - b[i];
			
			return (nVec);
		}
		vec	operator *(const vec &b)
		{
			vec	nVec(_size);

			for (size_t i = 0; i < _size; ++i)
				nVec[i] = _data[i] * b[i];
			
			return (nVec);
		}
		vec	operator /(const vec &b)
		{
			vec	nVec(_size);

			for (size_t i = 0; i < _size; ++i)
				nVec[i] = _data[i] / b[i];
			
			return (nVec);
		}

		friend	vec	operator +(const T n, const vec &b)
		{
			vec	nVec(b._size);

			for (size_t i = 0; i < b._size; ++i)
				nVec[i] = n + b._data[i];
			
			return (nVec);
		}
		friend	vec	operator -(const T n, const vec &b)
		{
			vec	nVec(b._size, 0);

			for (size_t i = 0; i < b._size; ++i)
				nVec[i] = n - b._data[i];
			
			return (nVec);
		}
		friend	vec	operator /(const T n, const vec &b)
		{
			vec	nVec(b._size);

			for (size_t i = 0; i < b._size; ++i)
				nVec[i] = n / b._data[i];
			
			return (nVec);
		}
		friend	vec	operator *(const T n, const vec &b)
		{
			vec	nVec(b._size);

			for (size_t i = 0; i < b._size; ++i)
				nVec[i] = n * b._data[i];
			
			return (nVec);
		}
		

		friend std::ostream& operator<<(std::ostream& out, vec vec)
		{
			for (size_t i = 0; i < vec._size - 1; ++i)
				out AND vec._data[i] SAND "";
			out AND vec._data[vec._size - 1];

			return (out);
		}
	};


	template <typename T>
	struct mat
	{
		mat(const size_t &row = 0, const size_t &col = 0, const T &defaultVal = 0, const double RandGen[2] = (double [2]){0, 0})	: _row(row), _col(col), _data(Mmath::vec<vec<T>>(_row, vec<T>(_col, defaultVal)))
		{
			if (RandGen[0] != 0 || RandGen[1] != 0)
				for (size_t y = 0; y < row; ++y)
					for (size_t x = 0; x < _col; ++x)
						_data[y][x] = (double)std::rand() / (double)RAND_MAX * (RandGen[1] - RandGen[0]) + RandGen[0];
		}
		mat(const mat &src)	: _row(src._row), _col(src._col)	{*this = src;}

		size_t		_row;
		size_t		_col;
		vec<vec<T>>	_data;

		Mmath::vec<T>	flatten() const
		{
			Mmath::vec<T>	flat(_row * _col);

			int	i = 0;
			for (size_t y = 0; y < _row; ++y)
			{
				for (size_t x = 0; x < _col; ++x)
				{
					flat[i] = _data[y][x];
					++i;
				}
			}
			
			return (flat);
		}

		Mmath::vec<int>	shape() const
		{
			return ((Mmath::vec<int>){(int)_row, (int)_col});
		}

		mat	transpose() const
		{
			mat<T>	nMat(_col, _row);

			for (size_t y = 0; y < _row; ++y)
				for (size_t x = 0; x < _col; ++x)
					nMat[x][y] = _data[y][x];
			
			return (nMat);
		}

		mat	sumRows() const
		{
			mat	sumMat(_row, 1);

			for (size_t y = 0; y < _row; ++y)
				for (size_t x = 0; x < _col; ++x)
					sumMat[y][0] += _data[y][x];
			
			return (sumMat);
		}

		bool operator ==(const mat &b)
		{
			if (_row != b.row || _col != b.col)
				return (false);

			for (size_t y = 0; y < _row; ++y)
				for (size_t x = 0; x < _col; ++x)
					if (_data[y][x] != b._data[y][x])
						return (false);

			return (true);
		}

		bool operator !=(const mat &b)
		{
			if (_row != b._row || _col != b._col)
				return (true);

			for (size_t y = 0; y < _row; ++y)
				for (size_t x = 0; x < _col; ++x)
					if (_data[y][x] != b._data[y][x])
						return (true);

			return (false);
		}

		mat	&operator =(const mat &src)
		{
			_row = src._row;
			_col = src._col;

			_data = src._data;
			return (*this);
		}

		Mmath::vec<T>	&operator [](const int &i)
		{
			return (_data[i]);
		}
		Mmath::vec<T>	operator [](const int &i) const
		{
			return (_data[i]);
		}

		mat	operator +(const mat &m)
		{
			mat	nMat(_row, _col);

			for (size_t y = 0; y < _row; ++y)
				for (size_t x = 0; x < _col; ++x)
					nMat[y][x] = _data[y][x] + m[(m._row != 1 ? y : 0)][(m._col != 1 ? x : 0)];
			
			return (nMat);
		}
		mat	operator -(const mat &m)
		{
			mat	nMat(_row, _col);

			for (size_t y = 0; y < _row; ++y)
				for (size_t x = 0; x < _col; ++x)
					nMat[y][x] = _data[y][x] - m[(m._row != 1 ? y : 0)][(m._col != 1 ? x : 0)];
			
			return (nMat);
		}
		mat	operator *(const mat &m)
		{
			// if (_row != m._row || _col != m._col)
			// 	throw (std::runtime_error(RED BOLD "Fake Multiplication cannot occure; first matrices' size aren't the same." CLR));

			mat	nMat(_row, _col);

			for (size_t y = 0; y < _row; ++y)
				for (size_t x = 0; x < _col; ++x)
					nMat[y][x] = _data[y][x] * m[(m._row != 1 ? y : 0)][(m._col != 1 ? x : 0)];

			return (nMat);
		}
		

		// void	operator /(const mat &m)
		// {
		// 	;
		// }


		// template <typename TB>
		mat<T>	dot(const mat<T> &b)
		{
			if (_col != b._row)
				throw (std::runtime_error(RED BOLD "Multiplication cannot occure; first matrix's columns aren't equal to the other's rows." CLR));
			
			mat<T>	nMat(_row, b._col);
			mat<T>	bT = b.transpose();

			for (size_t y = 0; y < _row; ++y)
				for (size_t x = 0; x < b._col; ++x)
					nMat[y][x] = _data[y].dot(bT[x]);
		
			return (nMat);
		}

		friend	mat	exp(mat m)
		{
			mat	nMat(m._row, m._col);

			for (size_t y = 0; y < m._row; ++y)
				for (size_t x = 0; x < m._col; ++x)
					nMat[y][x] = std::exp(m._data[y][x]);
			
			return (nMat);
		}
		friend	mat	operator +(const T n, const mat &m)
		{
			mat	nMat(m._row, m._col);

			for (size_t y = 0; y < m._row; ++y)
				for (size_t x = 0; x < m._col; ++x)
					nMat[y][x] = n + m._data[y][x];
			
			return (nMat);
		}
		friend	mat	operator -(const T n, const mat &m)
		{
			mat	nMat(m._row, m._col);

			for (size_t y = 0; y < m._row; ++y)
				for (size_t x = 0; x < m._col; ++x)
					nMat[y][x] = n - m._data[y][x];
			
			return (nMat);
		}
		friend	mat	operator /(const T n, const mat &m)
		{
			mat	nMat(m._row, m._col);

			for (size_t y = 0; y < m._row; ++y)
				for (size_t x = 0; x < m._col; ++x)
					nMat[y][x] = n / m._data[y][x];
			
			return (nMat);
		}
		friend	mat	operator *(const T n, const mat &m)
		{
			mat	nMat(m._row, m._col);

			for (size_t y = 0; y < m._row; ++y)
				for (size_t x = 0; x < m._col; ++x)
					nMat[y][x] = n * m._data[y][x];
			
			return (nMat);
		}
		friend	std::ostream& operator<<(std::ostream& out, mat mat)
		{
			for (size_t y = 0; y < mat._row; ++y)
			{
				for (size_t x = 0; x < mat._col - 1; ++x)
					out AND mat[y][x] SAND "";
				out AND mat[y][mat._col - 1] ENDL;
			}

			return (out);
		}
	};
}

#endif