#pragma once
#include <iostream>
#include <exception>
#include <string>


class BadLenght : public std::exception
{
public:
	virtual const char* what() const noexcept override
	{
		return "ERROR: длина контейнера должна быть больше 0!";
	}
};

class BadRange : public std::exception
{
public:
	virtual const char* what() const noexcept override
	{
		return "ERROR: выход за пределы контейнера!";
	}
};



class IntArray
{
public:
	IntArray() = default;
	IntArray(int lenght);
	IntArray(const IntArray& a);
	~IntArray();
	void erase();
	int& operator[](int index);
	IntArray& operator=(const IntArray& a);
	int getLenght() const;
	void reallocate(int newLenght);
	void resize(int newLenght);
	void insertBefore(int value, int index);
	void remove(int index);
	void getElement(int index);
	void getIndex(int value);

private:
	
	int m_length{};
	int* m_data{};
};