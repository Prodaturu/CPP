template <typename T>
Array<T>::Array() : _data(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _data(NULL), _size(n)
{
	if (_size > 0)
		_data = new T[_size]();
}

template <typename T>
Array<T>::Array(Array const &other) : _data(NULL), _size(0)
{
	*this = other;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other)
{
	if (this != &other)
	{
		delete[] _data;
		_size = other._size;
		_data = NULL;
		if (_size > 0)
		{
			_data = new T[_size];
			for (unsigned int i = 0; i < _size; ++i)
				_data[i] = other._data[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] _data;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _data[index];
}

template <typename T>
T const &Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _data[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template <typename T>
const char *Array<T>::OutOfBoundsException::what() const throw()
{
	return "Array index out of bounds";
}