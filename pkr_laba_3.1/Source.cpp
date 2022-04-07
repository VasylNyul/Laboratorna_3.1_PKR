#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

enum Specialty { КН, ІТ, ПЗ, ВП, СА };

string strSpecialty[] = { "КН","ІТ","ПЗ","ВП","СА" };

struct Student
{
	string prizv;
	Specialty specialty;
	short unsigned kyrs;
	short unsigned physics;
	short unsigned math;
	short unsigned informatics;
};

void Create(Student* s, const int N);
void Print(Student* s, const int N);
void BestMedium(Student* s, const int N);
int Percent(Student* s, const int N);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Введіть кількість студентів: "; cin >> N;
	Student* s = new Student[N];
	Create(s, N);
	Print(s, N);

	cout << "| Процент студентів, які вчаться на відмінно: " << char(34) << ": " << fixed << setw(6) << setprecision(2) << Percent(s, N) << setw(23) << "|" << endl;
	cout << "| Студент, у якого середній бал найбільший:   " << fixed << setprecision(2); BestMedium(s, N); cout << setw(29) << "   |" << endl;
	cout << "================================================================================" << endl;
	delete[] s;
}


void Create(Student* s, const int N)
{
	int specialty;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент№ " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << "  прізвище: "; getline(cin, s[i].prizv);
		cout << "  курс: "; cin >> s[i].kyrs;
		cout << "  спеціальність (0 - КН, 1 - ІТ, 2 - ПЗ, 3 - ВП, 4 - СА): "; cin >> specialty;
		s[i].specialty = (Specialty)specialty;
		cout << "  оцінка з фізики: "; cin >> s[i].physics;
		cout << "  оцінка з математики: "; cin >> s[i].math;
		cout << "  оцінка з інформатики: "; cin >> s[i].informatics;
	}
}

void Print(Student* s, const int N)
{
	cout << "================================================================================"
		<< endl;
	cout << "| №  | Прізвище     | Курс | Спеціальність | Фізика | Математика | Інформатика |"
		<< endl;
	cout << "--------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << right << i + 1			<< " "
			 << "| " << setw(13) << left << s[i].prizv
			 << "| " << setw(3) << right << s[i].kyrs		<< "  "
			 << "| " << setw(8) << right << strSpecialty[s[i].specialty] << "      "
			 << "| " << setw(4) << right << s[i].physics	 << "   "
			 << "| " << setw(6) << right << s[i].math		 << "      "
			 << "| " << setw(6) << right << s[i].informatics << "     |" << endl;
	}
	cout << "================================================================================" << endl;
}

void BestMedium(Student* s, const int N)
{
	for (int i = 0; i < N; i++)
	{
		double A = 0;
		double B = 0;
		for (int i = 0; i < N; i++)
		{
			 A = (s[i].physics + s[i].math + s[i].informatics) / 3;
			 B = (s[i+1].physics + s[i+1].math + s[i+1].informatics) / 3;

		}
		if (A > B)
			cout << s[i].prizv;
		if (A < B)
			cout << s[i+1].prizv;
		if (A == B)
			cout << "Середній бал рівний" ;
		break;
		
		
	}
}

int Percent(Student* s, const int N)
{
	int res;
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		if ((s[i].physics + s[i].math + s[i].informatics) / 3 == 5)
			k++;
	}

	return res = (k * 100 / N);
}


