#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

struct student
{
	char name[10];
	char group[10];
	int physics;
	int computerscience;
	int histori;
};

void GetData(student *M, int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << "\n";
		cout << "Имя: ";
		cin >> M[i].name, 10;

		cout << "Група: ";
		cin >> M[i].group, 10;

		cout << "Физика: ";
		cin >> M[i].physics;

		cout << "Иформатика: ";
		cin >> M[i].computerscience;

		cout << "История: ";
		cin >> M[i].histori;
	}
}

void ShowData(student *M, int N)
{
	int k;
	for (int i = 0; i < N; i++)
	{
		k = (M[i].physics + M[i].computerscience + M[i].histori) / 3;
		if (k >= 4)
		{
			cout << endl << "Имя: " << M[i].name << endl;
			cout << "Група: " << M[i].group << endl;
			cout << "Физика: " << M[i].physics << endl;
			cout << "Иформатика: " << M[i].computerscience << endl;
			cout << "История: " << M[i].histori << endl;
		}
	}
}

int main()
{
	int N;
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << "Введите количество студентов: ";
	cin >> N;
	student *M = new student[N];
	GetData(M, N);
	ShowData(M, N);
}
