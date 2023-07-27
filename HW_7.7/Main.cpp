#include <iostream>
#include "IntArray.h"

int main()
{
	setlocale(LC_ALL, "");
	int choice = 0;
	int element = 0;
	bool condition = true;
	bool condition2 = true;
	while(condition2)
	{
		std::cout << "Выберите размер контейнера целых чисел:\n";
		int range = 0;
		std::cin >> range;
		IntArray a(range);
		if (range <= 0)
			condition = false;
		if (range > 0)
			condition = true;
		while (condition)
		{
			std::cout << "Доступный функционал:\n" << "\t1 - заполнить ячейки вручную\n" << "\t2 - заполнить все ячейки одним элементом\n"
				<< "\t3 - получить доступ к любому элементу контейнера по номеру\n" << "\t4 - изменить размер контейнера\n" << "\t5 - положить элемент в контейнер\n"
				<< "\t6 - получить номер элемента по значению\n" << "\t7 - удалить элемент из контейнера\n" << "\t0 - удалить контейнер и закрыть программу.\n";
			std::cin >> choice;
			if (choice == 0)
			{
				a.erase();
				condition = false;
				condition2 = false;
				break;
			}
			switch (choice)
			{
				case 1:
				{
					std::cout << "Введите " << a.getLenght() << " целых чисел:\n";
					for (int i = 0; i < a.getLenght(); ++i)
					{
						std::cin >> element;
						a[i] = element;
					}
					std::cout << "Контейнер заполнен\n";
					break;
				}
				case 2:
				{
					std::cout << "Введите целое число для заполнения контейнера:\n";
					std::cin >> element;
					for (int i = 0; i < a.getLenght(); ++i)
					{
						a[i] = element;
					}
					std::cout << "Контейнер заполнен\n";
					break;
				}
				case 3:
				{
					std::cout << "Введите номер элемента:\n";
					std::cin >> element;
					a.getElement(element);
					break;
				}
				case 4:
				{
					std::cout << "Введите новый размер контейнера:\n";
					std::cin >> element;
					a.resize(element);
					if (element <= 0)
						condition = false;
					break;
				}
				case 5:
				{
					int index = 0;
					std::cout << "Введите число:\n";
					std::cin >> element;
					std::cout << "Введите номер ячейки:\n";
					std::cin >> index;
					a.insertBefore(element, index);
					break;
				}
				case 6:
				{
					std::cout << "Введите значение числа, номер которого хотите получить:\n";
					std::cin >> element;
					a.getIndex(element);
					break;
				}
				case 7:
				{
					std::cout << "Введите номер элемента который хотите удалить:\n";
					std::cin >> element;
					a.remove(element);
					break;
				}
			}
		}
	}
	return 0;
};