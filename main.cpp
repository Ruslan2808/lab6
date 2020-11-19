#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>

using namespace std;

class Animal {
protected:
	char* name;
	char* ms;
public:
	virtual void show() = 0;
	virtual void Type() = 0;
	Animal(char*, char*);
	virtual ~Animal() = 0;
};

class HomeAnimal :virtual public Animal {
protected:
	char* sch;
	char* color;
public:
	HomeAnimal(char*, char*, char*, char*);
	~HomeAnimal();
	void show();
	void Type();
};

class WildAnimal :virtual public Animal {
protected:
	char* pt;
	int razmer;
public:
	WildAnimal(char*, char*, char*, int);
	~WildAnimal();
	void show();
	void Type();
};

class Rodent :public HomeAnimal, public WildAnimal {
	int kolzub;
	int age;
public:
	Rodent(char*, char*, char*, char*, char*, int, int, int);
	~Rodent();
	void show();
	void Type();
};

int menu();
int menuMain();
int getInt();
string writeWords();

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char nam[80], mesto[80], tp[80], clr[80], sh[80];
	int ag, kol, vib, vibm, rz, n = 0;
	Animal** p = new Animal * [n];
	while (true) {
		vibm = menuMain();
		if (vibm == 0) {
			while (true) {
				vib = menu();
				if (vib == 0) {
					cout << "Название: ";
					string nam1 = writeWords();
					strcpy_s(nam, nam1.c_str());
					cout << "Место обитания: ";
					string mesto1 = writeWords();
					strcpy_s(mesto, mesto1.c_str());
					cout << "Тип шерсти: ";
					string sh1 = writeWords();
					strcpy_s(sh, sh1.c_str());
					cout << "Цвет: ";
					string clr1 = writeWords();
					strcpy_s(clr, clr1.c_str());
					Animal** p1 = new Animal * [n + 1];
					copy(p, p + n, p1);
					p1[n] = new HomeAnimal(nam, mesto, sh, clr);
					n++;
					delete[]p;
					p = p1;
				}
				else if (vib == 1) {
					cin.clear();
					cout << "Название: ";
					string nam1 = writeWords();
					strcpy_s(nam, nam1.c_str());
					cout << "Место обитания: ";
					string mesto1 = writeWords();
					strcpy_s(mesto, mesto1.c_str());
					cout << "Тип питания: ";
					string tp1 = writeWords();
					strcpy_s(tp, tp1.c_str());
					cout << "Размер(см): ";
					rz = getInt();
					Animal** p1 = new Animal * [n + 1];
					copy(p, p + n, p1);
					p1[n] = new WildAnimal(nam, mesto, tp, rz);
					n++;
					delete[]p;
					p = p1;
				}
				else if (vib == 2) {
					cin.clear();
					cout << "Название: ";
					string nam1 = writeWords();
					strcpy_s(nam, nam1.c_str());
					cout << "Место обитания: ";
					string mesto1 = writeWords();
					strcpy_s(mesto, mesto1.c_str());
					cout << "Тип шерсти: ";
					string sh1 = writeWords();
					strcpy_s(sh, sh1.c_str());
					cout << "Цвет: ";
					string clr1 = writeWords();
					strcpy_s(clr, clr1.c_str());
					cout << "Тип питания: ";
					string tp1 = writeWords();
					strcpy_s(tp, tp1.c_str());
					cout << "Размер(см): ";
					rz = getInt();
					cout << "Количество зубов: ";
					kol = getInt();
					cout << "Продолжительность жизни(лет): ";
					ag = getInt();
					Animal** p1 = new Animal * [n + 1];
					copy(p, p + n, p1);
					p1[n] = new Rodent(nam, mesto, sh, clr, tp, rz, kol, ag);
					n++;
					delete[]p;
					p = p1;
				}
				else break;
				system("pause");
			}
		}
		else if (vibm == 1) {
			if (n == 0) {
				cout << "Нет введенной информации!!!" << endl;
			}
			else {
				for (int i = 0; i < n; i++) {
					p[i]->Type();
					p[i]->show();
				}
			}
			system("pause");
		}
		else break;
	}
	for (int i = 0; i < n; i++) {
		delete p[i];
	}
	delete[]p;
	return 0;
}

Animal::Animal(char* n, char* m) {
	name = new char[strlen(n) + 1];
	strcpy_s(name, strlen(n) + 1, n);
	ms = new char[strlen(m) + 1];
	strcpy_s(ms, strlen(m) + 1, m);
}

Animal::~Animal() {
	delete[] name;
	delete[] ms;
}

HomeAnimal::HomeAnimal(char* n, char* m, char* s, char* c) :Animal(n, m) {
	sch = new char[strlen(s) + 1];
	strcpy_s(sch, strlen(s) + 1, s);
	color = new char[strlen(c) + 1];
	strcpy_s(color, strlen(c) + 1, c);
}

void HomeAnimal::show() {
	cout << endl;
	cout << "Название: " << name << endl
		<< "Место обитания: " << ms << endl
		<< "Тип шерсти: " << sch << endl
		<< "Цвет: " << color << endl << endl;
}

void HomeAnimal::Type()
{
	cout << "Домашнее животное" << endl;
}

HomeAnimal::~HomeAnimal() {
	delete[] sch;
	delete[] color;
}

WildAnimal::WildAnimal(char* n, char* m, char* p, int r) :Animal(n, m) {
	pt = new char[strlen(p) + 1];
	strcpy_s(pt, strlen(p) + 1, p);
	razmer = r;
}

void WildAnimal::show() {
	cout << endl;
	cout << "Название: " << name << endl
		<< "Место обитания: " << ms << endl
		<< "Тип питания: " << pt << endl
		<< "Размер: " << razmer << " см" << endl << endl;
}

void WildAnimal::Type()
{
	cout << "Дикое животное" << endl;
}

WildAnimal::~WildAnimal() {
	delete[] pt;
}

Rodent::Rodent(char* n, char* m, char* s, char* c, char* p, int r, int k, int a) :HomeAnimal(n, m, s, c), WildAnimal(n, m, p, r), Animal(n, m) {
	kolzub = k;
	age = a;
}

void Rodent::show() {
	cout << endl;
	cout << "Название: " << name << endl
		<< "Место обитания: " << ms << endl
		<< "Тип шерсти: " << sch << endl
		<< "Цвет: " << color << endl
		<< "Тип питания: " << pt << endl
		<< "Размер: " << razmer << " см" << endl
		<< "Кол-во зубов: " << kolzub << endl
		<< "Продолжительность жизни: " << age << " лет" << endl << endl;
}

void Rodent::Type()
{
	cout << "Грызун" << endl;
}

Rodent::~Rodent() {

}

int menu()
{
	int choiceButton = 0, button = 0;
	system("cls");
	while (true)
	{
		choiceButton = (choiceButton + 4) % 4;

		if (choiceButton == 0) cout << "->Домашние животные" << endl;
		else cout << "Домашние животные" << endl;

		if (choiceButton == 1) cout << "->Дикие животные" << endl;
		else cout << "Дикие животные" << endl;

		if (choiceButton == 2) cout << "->Грызуны" << endl;
		else cout << "Грызуны" << endl;

		if (choiceButton == 3) cout << "->Выход" << endl;
		else cout << "Выход" << endl;

		button = _getch();
		if (button == 224)
		{
			button = _getch();
			if (button == 72) choiceButton--;
			if (button == 80) choiceButton++;
		}
		if (button == 13) {
			system("cls");
			return choiceButton;
		}

		system("cls");
	}
}

int menuMain()
{
	int choiceButton = 0, button = 0;
	system("cls");
	while (true)
	{
		choiceButton = (choiceButton + 3) % 3;

		if (choiceButton == 0) cout << "->Ввод информации" << endl;
		else cout << "Ввод информации" << endl;

		if (choiceButton == 1) cout << "->Просмотр информации" << endl;
		else cout << "Просмотр" << endl;

		if (choiceButton == 2) cout << "->Выход" << endl;
		else cout << "Выход" << endl;

		button = _getch();
		if (button == 224)
		{
			button = _getch();
			if (button == 72) choiceButton--;
			if (button == 80) choiceButton++;
		}
		if (button == 13) {
			system("cls");
			return choiceButton;
		}

		system("cls");
	}
}

int getInt() {
	string numbers;
	while (true) {
		int key;
		key = _getch();
		if (key == 224) {
			key = _getch();
		}
		else
			if (key == 8) {
				if (numbers.length() != 0) {
					cout << '\b' << " " << '\b';
					numbers.erase(numbers.length() - 1);
				}
			}
			else
				if (key == 13 && numbers.length() != 0) break;
				else
					if (key >= '0' && key <= '9') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	cout << endl;
	return stoi(numbers);
}

string writeWords() {
	string word;
	int Knopka;
	char simvol;
	while (true) {
		Knopka = _getch();
		if (Knopka == 8) {
			if (word.length() != 0) {
				cout << '\b' << " " << '\b';
				word.erase(word.length() - 1);
			}
		}
		else
			if (Knopka == 13 && word.length() != 0) break;
			else {
				simvol = (char)Knopka;
				if ((simvol >= 'а' && simvol <= 'я') || (simvol >= 'А' && simvol <= 'Я') || simvol == '-' || simvol == ' ' || simvol == '.') {
					word = word + simvol;
					cout << simvol;
				}
			}
	}
	cout << endl;
	return word;
}