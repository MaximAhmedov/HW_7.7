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
		std::cout << "�������� ������ ���������� ����� �����:\n";
		int range = 0;
		std::cin >> range;
		IntArray a(range);
		if (range <= 0)
			condition = false;
		if (range > 0)
			condition = true;
		while (condition)
		{
			std::cout << "��������� ����������:\n" << "\t1 - ��������� ������ �������\n" << "\t2 - ��������� ��� ������ ����� ���������\n"
				<< "\t3 - �������� ������ � ������ �������� ���������� �� ������\n" << "\t4 - �������� ������ ����������\n" << "\t5 - �������� ������� � ���������\n"
				<< "\t6 - �������� ����� �������� �� ��������\n" << "\t7 - ������� ������� �� ����������\n" << "\t0 - ������� ��������� � ������� ���������.\n";
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
					std::cout << "������� " << a.getLenght() << " ����� �����:\n";
					for (int i = 0; i < a.getLenght(); ++i)
					{
						std::cin >> element;
						a[i] = element;
					}
					std::cout << "��������� ��������\n";
					break;
				}
				case 2:
				{
					std::cout << "������� ����� ����� ��� ���������� ����������:\n";
					std::cin >> element;
					for (int i = 0; i < a.getLenght(); ++i)
					{
						a[i] = element;
					}
					std::cout << "��������� ��������\n";
					break;
				}
				case 3:
				{
					std::cout << "������� ����� ��������:\n";
					std::cin >> element;
					a.getElement(element);
					break;
				}
				case 4:
				{
					std::cout << "������� ����� ������ ����������:\n";
					std::cin >> element;
					a.resize(element);
					if (element <= 0)
						condition = false;
					break;
				}
				case 5:
				{
					int index = 0;
					std::cout << "������� �����:\n";
					std::cin >> element;
					std::cout << "������� ����� ������:\n";
					std::cin >> index;
					a.insertBefore(element, index);
					break;
				}
				case 6:
				{
					std::cout << "������� �������� �����, ����� �������� ������ ��������:\n";
					std::cin >> element;
					a.getIndex(element);
					break;
				}
				case 7:
				{
					std::cout << "������� ����� �������� ������� ������ �������:\n";
					std::cin >> element;
					a.remove(element);
					break;
				}
			}
		}
	}
	return 0;
};