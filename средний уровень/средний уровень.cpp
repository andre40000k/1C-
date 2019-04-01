#include "pch.h"
#include <iostream>
#include <Windows.h>
using namespace std;

struct raspisanie
{
	char nambe[10];
	char in[30];
	int timeinhour;
	int timeinmin;
	int yearin;
	int monthin;
	int dayin;
	char out[30];
	int timeouthour;
	int timeoutmin;
	int yearout;
	int monthout;
	int dayout;
};

void GetData(raspisanie *M, int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << '\n';
		cout << "Ноомер поезда: ";
		cin >> M[i].nambe, 10;

		cout << "Куда прибывает: ";
		cin >> M[i].in, 30;
		cout << "Час прибытия: ";
		cin >> M[i].timeinhour;
		cout << "Минут: ";
		cin >> M[i].timeinmin;
		cout << "День прибытия: ";
		cin >> M[i].dayin;
		cout << "Месяц(1-12): ";
		cin >> M[i].monthin;
		cout << "Год: ";
		cin >> M[i].yearin;
		cout << endl;

		cout << "Откуда отправляется: ";
		cin >> M[i].out, 30;
		cout << "Время отбытия: ";
		cin >> M[i].timeouthour;
		cout << "Минута: ";
		cin >> M[i].timeoutmin;
		cout << "День отбытия: ";
		cin >> M[i].dayout;
		cout << "Месяц(1-12): ";
		cin >> M[i].monthout;
		cout << "Год: ";
		cin >> M[i].yearout;
	}
}

void ShowData(raspisanie *M, int N)
{
	cout << endl << "В пути больше 7 часов 20 минут: " << endl << endl;
	for (int i = 0; i < N; i++)
	{
		if ((M[i].yearin - M[i].yearout) > 1)
		{
			cout << "Номер поезда: " << M[i].nambe << "\nМесто и время отправки: " << M[i].out << " " << M[i].timeouthour << ":" << M[i].timeoutmin << " " << M[i].dayout << "." << M[i].monthout << "." << M[i].yearout;
			cout << "\nМесто и время прибытия: " << M[i].in << " " << M[i].timeinhour << ":" << M[i].timeinmin << " " << M[i].dayin << "." << M[i].monthin << "." << M[i].yearin;
		}
		else
		{
			if ((M[i].monthin - M[i].monthout) > 1)
			{
				cout << "Номер поезда: " << M[i].nambe << "\nМесто и время отправки: " << M[i].out << " " << M[i].timeouthour << ":" << M[i].timeoutmin << " " << M[i].dayout << "." << M[i].monthout << "." << M[i].yearout;
				cout << "\nМесто и время прибытия: " << M[i].in << " " << M[i].timeinhour << ":" << M[i].timeinmin << " " << M[i].dayin << "." << M[i].monthin << "." << M[i].yearin;
			}
			else
			{
				if ((M[i].dayout - M[i].dayin) == 1 || (M[i].dayin - M[i].dayout) == -29)
				{
					int t;
					int k;
					k = ((24 - M[i].timeouthour) + abs(0 - M[i].timeinhour)) * 60;
					if (M[i].timeinmin < 31)
					{
						t = (60 - M[i].timeoutmin) + abs(0 - M[i].timeinmin) + k;
						if (k > 440)
						{
							cout << "Номер поезда: " << M[i].nambe << "\nМесто и время отправки: " << M[i].out << " " << M[i].timeouthour << ":" << M[i].timeoutmin << " " << M[i].dayout << "." << M[i].monthout << "." << M[i].yearout;
							cout << "\nМесто и время прибытия: " << M[i].in << " " << M[i].timeinhour << ":" << M[i].timeinmin << " " << M[i].dayin << "." << M[i].monthin << "." << M[i].yearin;
						}
						else
						{
							cout << "Поездов нету!!!";
						}
					}
					else
					{
						t = (60 - M[i].timeoutmin) + (60 - M[i].timeinmin) + k;
						if (k > 440)
						{
							cout << "Номер поезда: " << M[i].nambe << "\nМесто и время отправки: " << M[i].out << " " << M[i].timeouthour << ":" << M[i].timeoutmin << " " << M[i].dayout << "." << M[i].monthout << "." << M[i].yearout;
							cout << "\nМесто и время прибытия: " << M[i].in << " " << M[i].timeinhour << ":" << M[i].timeinmin << " " << M[i].dayin << "." << M[i].monthin << "." << M[i].yearin;
						}
						else
						{
							cout << "Поездов нету!!!";
						}
					}
				}
				if ((M[i].dayout - M[i].dayin) == 0)
				{
					int t;
					int k;
					if (M[i].timeouthour < 13 && M[i].timeinhour < 13)
					{
						k = (abs(0 - M[i].timeouthour) + abs(0 - M[i].timeinhour)) * 60;
						if (M[i].timeinmin < 31)
						{
							t = (60 - M[i].timeoutmin) + abs(0 - M[i].timeinmin) + k;
							if (k > 440)
							{
								cout << "Номер поезда: " << M[i].nambe << "\nМесто и время отправки: " << M[i].out << " " << M[i].timeouthour << ":" << M[i].timeoutmin << " " << M[i].dayout << "." << M[i].monthout << "." << M[i].yearout;
								cout << "\nМесто и время прибытия: " << M[i].in << " " << M[i].timeinhour << ":" << M[i].timeinmin << " " << M[i].dayin << "." << M[i].monthin << "." << M[i].yearin;
							}
							else
							{
								cout << "Поездов нету!!!";
							}
						}
						else
						{
							t = (60 - M[i].timeoutmin) + (60 - M[i].timeinmin) + k;
							if (k > 440)
							{
								cout << "Номер поезда: " << M[i].nambe << "\nМесто и время отправки: " << M[i].out << " " << M[i].timeouthour << ":" << M[i].timeoutmin << " " << M[i].dayout << "." << M[i].monthout << "." << M[i].yearout;
								cout << "\nМесто и время прибытия: " << M[i].in << " " << M[i].timeinhour << ":" << M[i].timeinmin << " " << M[i].dayin << "." << M[i].monthin << "." << M[i].yearin;
							}
							else
							{
								cout << "Поездов нету!!!";
							}
						}
						break;
					}
					if (M[i].timeinhour > 12 && M[i].timeouthour > 12)
					{
						k = ((24 - M[i].timeouthour) + (24 - M[i].timeinhour)) * 60;
						if (M[i].timeinmin < 31)
						{
							t = (60 - M[i].timeoutmin) + abs(0 - M[i].timeinmin) + k;
							if (k > 440)
							{
								cout << "Номер поезда: " << M[i].nambe << "\nМесто и время отправки: " << M[i].out << " " << M[i].timeouthour << ":" << M[i].timeoutmin << " " << M[i].dayout << "." << M[i].monthout << "." << M[i].yearout;
								cout << "\nМесто и время прибытия: " << M[i].in << " " << M[i].timeinhour << ":" << M[i].timeinmin << " " << M[i].dayin << "." << M[i].monthin << "." << M[i].yearin;
							}
							else
							{
								cout << "Поездов нету!!!";
							}
						}
						else
						{
							t = (60 - M[i].timeoutmin) + (60 - M[i].timeinmin) + k;
							if (k > 440)
							{
								cout << "Номер поезда: " << M[i].nambe << "\nМесто и время отправки: " << M[i].out << " " << M[i].timeouthour << ":" << M[i].timeoutmin << " " << M[i].dayout << "." << M[i].monthout << "." << M[i].yearout;
								cout << "\nМесто и время прибытия: " << M[i].in << " " << M[i].timeinhour << ":" << M[i].timeinmin << " " << M[i].dayin << "." << M[i].monthin << "." << M[i].yearin;
							}
							else
							{
								cout << "Поездов нету!!!";
							}
						}
						break;
					}
					if (M[i].timeouthour > 12 && M[i].timeinhour < 13)
					{
						k = ((24 - M[i].timeouthour) + abs(0 - M[i].timeinhour)) * 60;
						if (M[i].timeinmin < 31)
						{
							t = (60 - M[i].timeoutmin) + abs(0 - M[i].timeinmin) + k;
							if (k > 440)
							{
								cout << "Номер поезда: " << M[i].nambe << "\nМесто и время отправки: " << M[i].out << " " << M[i].timeouthour << ":" << M[i].timeoutmin << " " << M[i].dayout << "." << M[i].monthout << "." << M[i].yearout;
								cout << "\nМесто и время прибытия: " << M[i].in << " " << M[i].timeinhour << ":" << M[i].timeinmin << " " << M[i].dayin << "." << M[i].monthin << "." << M[i].yearin;
							}
							else
							{
								cout << "Поездов нету!!!";
							}
						}
						else
						{
							t = (60 - M[i].timeoutmin) + (60 - M[i].timeinmin) + k;
							if (k > 440)
							{
								cout << "Номер поезда: " << M[i].nambe << "\nМесто и время отправки: " << M[i].out << " " << M[i].timeouthour << ":" << M[i].timeoutmin << " " << M[i].dayout << "." << M[i].monthout << "." << M[i].yearout;
								cout << "\nМесто и время прибытия: " << M[i].in << " " << M[i].timeinhour << ":" << M[i].timeinmin << " " << M[i].dayin << "." << M[i].monthin << "." << M[i].yearin;
							}
							else
							{
								cout << "Поездов нету!!!";
							}
						}
						break;
					}

					else
					{
						k = (abs(0 - M[i].timeouthour) + (24 - M[i].timeinhour)) * 60;
						if (M[i].timeinmin < 31)
						{
							t = (60 - M[i].timeoutmin) + abs(0 - M[i].timeinmin) + k;
							if (k > 440)
							{
								cout << "Номер поезда: " << M[i].nambe << "\nМесто и время отправки: " << M[i].out << " " << M[i].timeouthour << ":" << M[i].timeoutmin << " " << M[i].dayout << "." << M[i].monthout << "." << M[i].yearout;
								cout << "\nМесто и время прибытия: " << M[i].in << " " << M[i].timeinhour << ":" << M[i].timeinmin << " " << M[i].dayin << "." << M[i].monthin << "." << M[i].yearin;
							}
							else
							{
								cout << "Поездов нету!!!";
							}
						}
						else
						{
							t = (60 - M[i].timeoutmin) + (60 - M[i].timeinmin) + k;
							if (k > 440)
							{
								cout << "Номер поезда: " << M[i].nambe << "\nМесто и время отправки: " << M[i].out << " " << M[i].timeouthour << ":" << M[i].timeoutmin << " " << M[i].dayout << "." << M[i].monthout << "." << M[i].yearout;
								cout << "\nМесто и время прибытия: " << M[i].in << " " << M[i].timeinhour << ":" << M[i].timeinmin << " " << M[i].dayin << "." << M[i].monthin << "." << M[i].yearin;
							}
							else
							{
								cout << "Поездов нету!!!";
							}
						}
					}

				}
				else
				{
					cout << "Номер поезда: " << M[i].nambe << "\nМесто и время отправки: " << M[i].out << " " << M[i].timeouthour << ":" << M[i].timeoutmin << " " << M[i].dayout << "." << M[i].monthout << "." << M[i].yearout;
					cout << "\nМесто и время прибытия: " << M[i].in << " " << M[i].timeinhour << ":" << M[i].timeinmin << " " << M[i].dayin << "." << M[i].monthin << "." << M[i].yearin;
				}
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N;
	cout << "(В одном месяце 30 дней)" << endl;
	cout << "Количество поeздов: ";
	cin >> N;
	raspisanie *M = new raspisanie[N];
	GetData(M, N);
	ShowData(M, N);
}