#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <string>

struct STUDENT
{
	std::string name;
	char Kurs[10];
	int SES[5];
	void print()
	{
		std::cout << "\nИмя: " << name;
	}
};

void GetData(STUDENT *STUD, int N)
{
	for (int i = 0; i < N; i++)
	{
		std::cout << "\n";
		std::cout << "Имя и иницеалы: ";
		std::cin >> STUD[i].name, 30;

		std::cout << "Група: ";
		std::cin >> STUD[i].Kurs, 10;

		std::cout << "Оценки: ";
		for (int j = 0; j < 5; j++)
		{
			std::cin >> STUD[i].SES[j];
		}
	}
}
float SES(STUDENT *STUD, int N, int srednibalkurs)
{
	float a;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			srednibalkurs += STUD[i].SES[j];
		}
	}
	a = srednibalkurs / (5 * N);
		return (a);
}
void sort(STUDENT *STUD, int N)	
{	
	for (int i = 0; i < N + 1; i++)
	{
		for(int j = i + 1; j < N; j++)
		if (strcmp(STUD[i].name.c_str(), STUD[j].name.c_str()) > 0)
		{
			std::swap(STUD[i], STUD[j]);
		}
	}
}
int main()
{
	setlocale(LC_ALL, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N, srednibalkurs = 0;
	std::cout << "Введите количество студентов: ";
	std::cin >> N;
	STUDENT *STUD = new STUDENT[N];
	GetData(STUD, N);
	sort(STUD, N);
	for (int i = 0; i < N; i++)
	{
		float srednibalstud = 0;
		for (int j = 0; j < 5; j++)
		{
			srednibalstud += STUD[i].SES[j];
		}
		srednibalstud = srednibalstud / 5;
		if (srednibalstud > SES(STUD, N, srednibalkurs))
		{
			STUD[i].print();
		}
	}
	for (int i = 0; i < N; i++)
	{
		float srednibalstud = 0;
		for (int j = 0; j < 5; j++)
		{
			srednibalstud += STUD[i].SES[j];
		}
		srednibalstud = srednibalstud / 5;
		if (srednibalstud <= SES(STUD, N, srednibalkurs))
		{
			int proverka = i+1;
			if (proverka == N)
				std::cout << "Студентов с среднем балом по предметам который больше среднего бала курса в списке нет!!!";
		}
	}
}

