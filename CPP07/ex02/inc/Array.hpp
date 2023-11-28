#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>
#include <stdexcept>

using std::cout;
using std::endl;

template <typename T>
class Array
{
	private :

		size_t _size;
		T * _array ;

	public :

		Array(){
			_array = new T[0];
			_size = 0;
		}

		Array(unsigned int n){
			_array = new T[n];
			_size = n;
		}

		Array(Array const& copy){
			if(this != &copy) {
				_size = copy._size;
				_array = new T[copy._size];
				for(size_t i = 0; i < _size; i++) {
					_array[i] = copy._array[i];
				}
			}
		}

		Array & operator=(Array const& copy){
			if(this != &copy) {
				delete [] _array;
				_size = copy._size;
				_array = new T[copy._size];
				for(size_t i = 0; i < _size; i++) {
					_array[i] = copy._array[i];
				}
			}
			return *this;
		}

		~Array(){ delete [] _array; }

		T & operator[](unsigned int const& idx){
			if(_size < idx)
				throw std::invalid_argument("invalid index");
			return _array[idx];
		}
		
		size_t size()const { return _size; }
};
#endif