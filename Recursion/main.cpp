//Recursion
#include<iostream>
#include<conio.h>
using namespace std;

//TODO:
//1. Написать рекурсивную функцию, которая принимает число, и возвращает Факториал этого числа;
//2. Написать Рекурсивную функцию, которая возводит число в степень;
//3. Написать рекурсивную функцию, которая выводит на экран ряд Фибоначчи до заданного предела;
//4. Написать рекурсивную функцию, которая выводит на экран заданное количество членов из ряда Фибоначчи;

int factorial(int n);
double power(int degree_basis, int degree_indicator);
void fibonacci_limit(int limit, int a = 0, int b = 1);
void fibonacci_count(int count, int a = 0, int b = 1);
int menu();

void main()
{
	setlocale(LC_ALL, "Russian");
	int n, degree_basis, degree_indicator, limit, count;
	bool exit = true;
	do
	{
		int input = menu();
		switch (input)
		{
		case 1: cout << "Введите число, факториал которого нужно вычислить: "; cin >> n; cout << "Факториал числа " << n << " равен " << factorial(n); break;
		case 2:
		{
			cout << "Введите число, которое нужно возвести в степень, и степень, в которую нужно возвести: ";
			cin >> degree_basis >> degree_indicator;
			cout << "Число " << degree_basis << " в степени " << degree_indicator << " равно " << power(degree_basis, degree_indicator);
			break;
		}
		case 3: cout << "Введите предел, до которого нужно вывести ряд Фибоначчи: "; cin >> limit; fibonacci_limit(limit); break;
		case 4: cout << "Введите количество членов ряда Фибоначчи, которое нужно вывести: "; cin >> count; fibonacci_count(count); break;
		case 5: cout << "Вы выходите из программы. До новых встреч!"; exit = false; break;
		default: cout << "Вы ввели неверное число! Попробуйте ещё раз";
		}
		cout << "\n\tДля продолжения нажмите любую клавишу.\n";
		_getch();
	} while (exit);
}

int menu()
{
	system("cls");
	cout << "\n\n\n\t\t\tВыберите номер пункта, который желаете выполнить:\n\n";
	cout << "\t\t1. Факториал числа\n";
	cout << "\t\t2. Возведение числа в степень\n";
	cout << "\t\t3. Вывод на экран ряда Фибоначчи до заданного предела\n";
	cout << "\t\t4. Вывод на экран заданное количество членов из ряда Фибоначчи\n";
	int n; cin >> n;
	return n;
}

int factorial(int n)
{
	return n > 0 ? n * factorial(n - 1) : 1;
}

double power(int degree_basis, int degree_indicator)
{
	if (degree_indicator == 0) return 1;
	else if (degree_indicator > 0) return degree_basis *= power(degree_basis, degree_indicator - 1);
	else return (double) 1 / (degree_basis * power(degree_basis, -degree_indicator - 1));
}

void fibonacci_limit(int limit, int a, int b)
{
	if (a > limit) return;
	cout << '\t' << a;
	fibonacci_limit(limit, b, a + b);
}

void fibonacci_count(int count, int a, int b)
{
	if (count == 0) return;
	cout << '\t' << a;
	fibonacci_count(count - 1, b, a + b);
}