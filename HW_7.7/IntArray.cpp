#include "IntArray.h"

IntArray::IntArray(int lenght) : m_length(lenght)
{

	try
	{
		if (lenght <= 0)
		{
			throw BadLenght();
		}
		m_data = new int[lenght] {};
		for (int i = 0; i < lenght; ++i)
		{
			m_data[i] = 0;
		}
		std::cout << "Создан контейнер, все ячейки проинициализированы нулями.\n";
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

IntArray::~IntArray()
{
	delete[] m_data;
}

void IntArray::erase()
{
	delete[] m_data;
	m_data = nullptr;
	m_length = 0;
}

IntArray::IntArray(const IntArray& a)
{
	reallocate(a.getLenght());
	for (int i = 0; i < m_length; ++i)
	{
		m_data[i] = a.m_data[i];
	}
}

IntArray& IntArray::operator=(const IntArray& a)
{
	if (&a == this)
		return *this;
	reallocate(a.getLenght());
	for (int i = 0; i < m_length; ++i)
		m_data[i] = a.m_data[i];
	return *this;
}

int& IntArray::operator[](int index)
{
	return m_data[index];
}

int IntArray::getLenght() const
{
	return m_length;
}

void IntArray::reallocate(int newLenght)
{
	erase();
	if (newLenght <= 0)
		return;
	m_data = new int[newLenght];
	m_length = newLenght;
}

void IntArray::resize(int newLenght)
{
	if (newLenght == m_length)
	{
		std::cout << "Размер не изменен\n";
	}
	if (newLenght <= 0)
	{
		erase();
		std::cout << "Контейнер удален\n";
	}
	int* data{ new int[newLenght] };
	if (m_length > 0)
	{
		int elementsToCopy{ (newLenght > m_length) ? m_length : newLenght };
		for (int i = 0; i < elementsToCopy; ++i)
		{
			data[i] = m_data[i];
		}
	}
	if (newLenght > m_length)
	{
		for (int i = m_length; i < newLenght; ++i)
		{
			data[i] = 0;
		}
		std::cout << "Размер контейнера изменен\n";
	}
	delete[] m_data;
	m_data = data;
	m_length = newLenght;
}

void IntArray::insertBefore(int value, int index)
{
	try
	{
		if (index <= 0 || index > m_length)
		{
			throw BadRange();
		}
		int* data{ new int[m_length + 1] };
		for (int i = 0; i < index - 1; ++i)
		{
			data[i] = m_data[i];
		}
		data[index - 1] = value;
		for (int after = index - 1; after < m_length; ++after)
		{
			data[after + 1] = m_data[after];
		}
		delete[] m_data;
		m_data = data;
		++m_length;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void IntArray::remove(int index)
{
	try
	{
		if (index <= 0 || index > m_length)
		{
			throw BadRange();
		}
		if (m_length == 1)
		{
			erase();
			return;
		}
		int* data{ new int[m_length - 1] };
		for (int i = 0; i < index; ++i)
		{
			data[i] = m_data[i];
		}
		for (int after{index}; after < m_length; ++after)
		{
			data[after - 1] = m_data[after];
		}
		delete[] m_data;
		m_data = data;
		--m_length;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}


void IntArray::getElement(int index)
{
	try
	{
		if (index <= 0 || index > m_length)
		{
			throw BadRange();
		}
		std::cout << m_data[index - 1] << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void IntArray::getIndex(int value)
{
	int counter = 0;
	for (int i = 0; i < m_length; ++i)
	{
		if (m_data[i] == value)
		{
			std::cout << ++i << std::endl;
			counter++;
			break;
		}
	}
	if (counter == 0)
	{
		std::cout << "Указанное число отсутствует в контейнере\n";
	}
}
