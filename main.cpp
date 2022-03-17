#include <iostream>
#include <string>
#include <fstream>

double min(double x, double y) //zadanie 1
{
	if (y > x)
	{
		return x;
	}
	else if (x > y)
	{
		return y;
	}
	else
	{
		return x;
	}
}

void box(char a, int amount_of_characters, int amount_of_lines) //zadanie 3
{
	for (int i = amount_of_lines; i > 0; i--)
	{
		for (int j = amount_of_characters; j > 0; j--)
		{
			std::cout << a;
		}
		std::cout << "\n";
	}
}

double harmonic(double x, double y) //zadanie 4
{
	if (x != 0 && y != 0)
	{
		double x_rev = (1 / x);
		double y_rev = (1 / y);
		double avg = ((x_rev + y_rev) / 2);
		return (1 / avg);
	}
}

int letter_to_number(char x) //zadanie 5
{
	if (x == 'a' || x == 'A')
	{
		return 1;
	}
	else if (x == 'b' || x == 'B')
	{
		return 2;
	}
	else if (x == 'c' || x == 'C')
	{
		return 3;
	}
	else if (x == 'd' || x == 'D')
	{

		return 4;
	}
	else if (x == 'e' || x == 'E')
	{
		return 5;
	} //i tak dalej dla ponad 20 znakow...
	else
	{
		return -1;
	}
}

double power(double x, double y) //zadanie 6
{
	if (x == 0)
	{
		x = 0;
		return x;
	}
	const double x_ = x;
	if (y == 0)
	{
		x = 1;
	}
	else if (y < 0) //dla potegi ujemnej
	{
		for (y; y < -1; y++)
		{
			x = x * x_;
		}
		return (1 / x);
	}
	for (y; y > 1; y--) //dla potegi dodatniej
	{
		x = x * x_;
	}
	return x;
}

double power_(double x, double y) //zadanie 7
{
	if (x == 0)
	{
		x = 0;
		return x;
	}
	if (y < 0) //dla potegi ujemnej
	{
		return (1 / x) * power_(x, y + 1);
	}
	if (y == 0) //dla potegi dodatniej
	{
		return 1;
	}
	return x * power_(x	, y - 1);
}

int main()
{
	double a1;
	double b1;	
	std::cout << "podaj dwie liczby: \n";
	std::cin >> a1;
	std::cin >> b1;
	std::cout << "mniejsza liczba to: " << min(a1, b1) << "\n"; //zadanie 1
	char a3;
	int b3, c3;
	std::cout << "podaj znak: ";
	std::cin >> a3;
	std::cout << "podaj liczbe znakow w linii: ";
	std::cin >> b3;
	std::cout << "podaj liczbe linii: ";
	std::cin >> c3;
	box(a3, b3, c3); //zadanie 3
	double a4, b4;
	std::cout << "program zwroci srednia harmoniczna 2 liczb\nPodaj te dwie liczby: ";
	std::cin >> a4;
	std::cin >> b4;
	if (a4 != 0 && b4 != 0)
	{
		std::cout << "srednia harmoniczna: " << harmonic(a4, b4) << "\n"; //zadanie 4
	}
	else
	{
		std::cout << "zadna liczba nie moze byc rowna 0!\n";
	}
	std::fstream file;
	std::string character;
	int j;
	file.open("sample.txt", std::ios::in);
	while (!file.eof())
	{
		file >> character;
		j = character.length();
		for (int i = 0; i < j; i++)
		{
			char y = character[i];
			std::cout << letter_to_number(y); //zadanie 5
		}
	}
	file.close();
	std::cout << "\n";
	double a6 = power(0, 0); //zadanie 6
	std::cout << a6 << "\n";
	double a7 = power_(0, -3); //zadanie 7
	std::cout << a7 << "\n";
	std::cout << "\n";
	system("pause");
	return 0;
}