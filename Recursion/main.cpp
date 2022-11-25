//Recursion
#include<iostream>
#include<conio.h>
using namespace std;

//TODO:
//1. �������� ����������� �������, ������� ��������� �����, � ���������� ��������� ����� �����;
//2. �������� ����������� �������, ������� �������� ����� � �������;
//3. �������� ����������� �������, ������� ������� �� ����� ��� ��������� �� ��������� �������;
//4. �������� ����������� �������, ������� ������� �� ����� �������� ���������� ������ �� ���� ���������;

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
		case 1: cout << "������� �����, ��������� �������� ����� ���������: "; cin >> n; cout << "��������� ����� " << n << " ����� " << factorial(n); break;
		case 2:
		{
			cout << "������� �����, ������� ����� �������� � �������, � �������, � ������� ����� ��������: ";
			cin >> degree_basis >> degree_indicator;
			cout << "����� " << degree_basis << " � ������� " << degree_indicator << " ����� " << power(degree_basis, degree_indicator);
			break;
		}
		case 3: cout << "������� ������, �� �������� ����� ������� ��� ���������: "; cin >> limit; fibonacci_limit(limit); break;
		case 4: cout << "������� ���������� ������ ���� ���������, ������� ����� �������: "; cin >> count; fibonacci_count(count); break;
		case 5: cout << "�� �������� �� ���������. �� ����� ������!"; exit = false; break;
		default: cout << "�� ����� �������� �����! ���������� ��� ���";
		}
		cout << "\n\t��� ����������� ������� ����� �������.\n";
		_getch();
	} while (exit);
}

int menu()
{
	system("cls");
	cout << "\n\n\n\t\t\t�������� ����� ������, ������� ������� ���������:\n\n";
	cout << "\t\t1. ��������� �����\n";
	cout << "\t\t2. ���������� ����� � �������\n";
	cout << "\t\t3. ����� �� ����� ���� ��������� �� ��������� �������\n";
	cout << "\t\t4. ����� �� ����� �������� ���������� ������ �� ���� ���������\n";
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