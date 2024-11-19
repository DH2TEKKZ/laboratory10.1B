#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Spec { KN, INF, MATH, PH, LE };

string specStr[] = { "��", "���", "��� �� ��", "Գ� �� ���", "����"};

struct Student
{
	string prizv;
	int curse;
	Spec spec;
	int physics;
	int math;
	union {
		int prog;
		int numMeth;
		int pedagogy;
	} thirdScore;
};

void Create(Student* p, const int N);
void Print(Student* p, const int N);
void  Vidminuk(Student* p, const int N);
int  PhisicFine(Student* p, const int N);


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "������ N: "; cin >> N;

	Student* p = new Student[N];

	Create(p, N);
	Print(p, N);
	Vidminuk(p, N);

	int fivePhisic = PhisicFine(p, N);
	cout << "������� ��������, �� �������� � ������ ������ 5: " << fivePhisic;

	return 0;
}
void Create(Student* p, const int N)
{
	int spec;
	for (int i = 0; i < N; i++)
	{
		cout << "������� �" << i + 1 << ":" << endl;

		cin.get();
		cin.sync();

		cout << " �������: "; getline(cin, p[i].prizv);
		cout << "����: "; cin >> p[i].curse;

		cout << "������������ (0 - ��, 1 - ���, 2 - ��� �� ��, 3 - Գ� �� ���, 4 - �������): ";
		cin >> spec;
		p[i].spec = (Spec)spec;

		cout << "������ � ������: "; cin >> p[i].physics;
		cout << "������ � ����������: "; cin >> p[i].math;
		switch (p[i].spec)
		{
		case KN:
			cout << "������ � �������������: "; cin >> p[i].thirdScore.prog;
			break;
		case INF:
			cout << "������ � ��������� ������: "; cin >> p[i].thirdScore.numMeth;
			break;
		default:
			cout << "������ � ���������: "; cin >> p[i].thirdScore.pedagogy;
		}
		cout << endl;
	}
}

void Print(Student* p, const int N)
{
	cout << "===================================================================================================="
		<< endl;
	cout << "| � | ������� | ���� | ������������ | ��. Գ�. | ��. ���. | ��. ����. | ��. ���. ���. | ��. ���. |"
		<< endl;
	cout << "----------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "|" << setw(3) << right << i + 1
			<< "|" << setw(10) << left << p[i].prizv
			<< "|" << setw(6) << right << p[i].curse
			<< "|" << setw(15) << left << specStr[p[i].spec]
			<< "|" << setw(10) << left << p[i].physics
			<< "|" << setw(10) << left << p[i].math;


		switch (p[i].spec)
		{
		case KN: 
			cout << "|" << setw(11) << left << p[i].thirdScore.prog
				<< "|" << setw(15) << " "  
				<< "|" << setw(10) << " "  
				<< "|";
			break;

		case INF: 
			cout << "|" << setw(11) << " "  
				<< "|" << setw(15) << left << p[i].thirdScore.numMeth
				<< "|" << setw(10) << " "  
				<< "|";
			break;

		default: 
			cout << "|" << setw(11) << " " 
				<< "|" << setw(15) << " "  
				<< "|" << setw(10) << left << p[i].thirdScore.pedagogy
				<< "|";
			break;
		}
		cout << endl;
	}

	cout << "===================================================================================================="
		<< endl;
	cout << endl;
} 
void Vidminuk(Student* p, const int N)
{
	cout << "��������, �� ������� ��� �����:" << endl;
	for (int i = 0; i < N; i++)
	{
		if (p[i].math > 3)
		{
			cout << p[i].prizv << endl;
		}
	}
}

int  PhisicFine(Student* p, const int N)
{
	int n = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].physics == 5)
		{
			n++;
		}
	}
	return n;
}