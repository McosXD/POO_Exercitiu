#include <iostream>
#include <stdio.h>
#include <list>

using namespace std;

class Student 
{
private:
	int id;
	char *nume;
	char *prenume;

public:

	Student(int idi, char *num, char *prenum)
	{
		id = idi;
		nume = new char[strlen(num) + 1];
		strcpy(nume, num);
		prenume = new char[strlen(prenum) + 1];
		strcpy(prenume, prenum);
	};

	void set_ID(int idi) {
		id = idi;
	}


	int get_ID() {
		return id;
	}

	char *Nume() {
		return nume;
	}

	virtual void afisare() 
	{
		cout << "------------ Student -------------" << endl;
		cout << "ID: " << id << endl;
		cout << "Nume: " << nume << endl;
		cout << "Prenume: " << prenume << endl;
	}
};

class Detalii : public Student
{
private:
	int varsta;
	int an;
	char* grupa;

public:
	Detalii(int idi, char *num, char *prenum, int varst, int anul, char* grup) : Student(idi, num, prenum) 
	{
		varsta = varst;
		an = anul;
		grupa = new char[strlen(grup) + 1];
		strcpy(grupa, grup);
	}

	void afisare() {
		Student::afisare();
		cout << "Varsta: " << varsta << endl;
		cout << "Anul: " << an << endl;
		cout << "Grupa: " << grupa << endl;
	}
};

void adaugare(list<Student*> &stud) {
	Student* newS;
	int id;
	char nume[20];
	char prenume[20];
	int varsta;
	int an;
	char grupa[20];

	cout << endl;
	cout << "Introduceti id-ul : ";
	cin >> id;
	cout << "Introduceti numele : ";
	cin >> nume;
	cout << "Introduceti prenumele: ";
	cin >> prenume;
	cout << "Introduceti varsta: ";
	cin >> varsta;
	cout << "Introduceti anul: ";
	cin >> an;
	cout << "Introduceti grupa : ";
	cin >> grupa;

	newS = new Detalii(id, nume, prenume, varsta, an, grupa);
	stud.push_back(newS);

	cout << "Student adaugat!"<<endl;
}

void afisare(list<Student*> &stud) {
	for (Student* s : stud)
		s->afisare();
}

void cautare(list<Student*> &stud, int index)
{
	for (Student* s : stud) {
		if (s->get_ID() == index) {
			s->afisare();
		}
	}
}

void cautare2(list<Student*>& stud, char *c)
{
	for (Student* s : stud) {
		if (!strcmp(s->Nume(), c)) {
			s->afisare();
		}
	}
}

void stergere(list<Student*>& stud, int index)
{
	for (auto it = stud.begin(); it != stud.end(); it++)
	{
		if ((*it)->get_ID() == index) {
			stud.erase(it);
			break;
		}
	}
}

int main() {
	list<Student*> stud;

	int opt, indx;
	char c[20];

	do
	{
		cout << "\n---------------------------------" << endl;
		cout << "0.Iesire" << endl;
		cout << "1.Adaugare" << endl;
		cout << "2.Afisare" << endl;
		cout << "3.Cautare dupa ID" << endl;
		cout << "4.Cautare dupa nume" << endl;
		cout << "5.Stergere dupa ID" << endl;
		cout << "Introduceti  o optiune: ";
		cin >> opt;

		switch (opt)
		{
		case 0:exit(0);
			break;
		case 1:adaugare(stud);
			break;
		case 2:afisare(stud);
			break;
		case 3:cout << "Introduceti id-ul cautat: ";
			cin >> indx;
			cautare(stud, indx);
		case 4:cout << "Introduceti numele cautat: ";
			cin >> c;
			cautare2(stud, c);
			break;
		case 5:
			cout << "Introduceti id-ul cel doriti sters: ";
			cin >> indx; 
			stergere(stud, indx);
			break;
		default:cout << "Optiune gresita!" << endl;
			break;
		}

	} while (true);
}