#include <iostream>
#include <conio.h>
#include <string>
#include <Windows.h>

using namespace std;

class Animal {
protected:
	string name;
	string ms;
public:
	Animal();
	Animal(string, string);
	void show() {
		cout << "Название: " << name << endl << "Место обитания: " << ms << endl;
	}
	void Type() {
		cout << "\nЖивотные\n\n";
	}
	~Animal();
};

class HomeAnimal :virtual public Animal {
protected:
	string sch;
	string color;
public:
	HomeAnimal();
	HomeAnimal(string, string, string, string);
	void show() {
		cout << "Шерсть: " << sch << endl << "Цвет: " << color << endl;
	}
	void Type() {
		cout << "Домашние животные -> ";
	}
	~HomeAnimal();
};

class WildAnimal :virtual public Animal {
protected:
	string pt;
	int razmer;
public:
	WildAnimal();
	WildAnimal(string, string, string, int);
	void show() {
		cout << "Питание: " << pt << endl << "Размер: " << razmer << endl;
	}
	void Type() {
		cout << "Дикие животные ->";
	}
	~WildAnimal();
};

class Rodent :public HomeAnimal, public WildAnimal {
	int kolzub;
	int age;
public:
	Rodent();
	Rodent(string, string, string, string, string, int, int, int);
	void showData() {
		Animal::show();
		HomeAnimal::show();
		WildAnimal::show();
		cout << "Количество зубов: " << kolzub << endl << "Продолжительность жизни: " << razmer << endl;
	}
	void Type() {
		cout << "Грызун -> ";
		HomeAnimal::Type();
		WildAnimal::Type();
		Animal::Type();
	}
	~Rodent();
};

int menu();
int getInt();
string writeWords();

int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string nam, mesto, tp, clr, sh;
	int ag, kol, vib, rz, n = 0;
	Rodent* p = new Rodent[n];
	while (true) {
		vib = menu();
		if (vib == 0) {
			cout << "Название: ";
			nam = writeWords();
			cout << "Место обитания: ";
			mesto = writeWords();
			cout << "Шерсть: ";
			sh = writeWords();
			cout << "Цвет: ";
			clr = writeWords();
			cout << "Тип питания: ";
			tp = writeWords();
			cout << "Размер(см): ";
			rz = getInt();
			cout << "Количество зубов: ";
			kol = getInt();
			cout << "Продолжительность жизни(лет): ";
			ag = getInt();
			Rodent rod(nam, mesto, sh, clr, tp, rz, kol, ag);
			Rodent* p1 = new Rodent[n + 1];
			copy(p, p + n, p1);
			p1[n] = rod;
			n++;
			delete[]p;
			p = p1;
		}
		else if (vib == 1) {
			if (n == 0) {
				cout << "Нет введенной информации!!!" << endl;
			}
			else {
				for (int i = 0; i < n; i++) {
					p[i].Type();
					p[i].showData();
				}
			}
			system("pause");
		}
		else break;
	}
	delete[]p;
	return 0;
}

Animal::Animal()
{

}

Animal::Animal(string n, string m) {
	name = n;
	ms = m;
}

Animal::~Animal() {
	
}

HomeAnimal::HomeAnimal()
{

}

HomeAnimal::HomeAnimal(string n, string m, string s, string c) :Animal(n, m) {
	sch = s;
	color = c;
}

HomeAnimal::~HomeAnimal() {

}

WildAnimal::WildAnimal()
{
	razmer = 0;
}

WildAnimal::WildAnimal(string n, string m, string p, int r) :Animal(n, m) {
	pt = p;
	razmer = r;
}

WildAnimal::~WildAnimal() {

}

Rodent::Rodent()
{
	kolzub = 0;
	age = 0;
}

Rodent::Rodent(string n, string m, string s, string c, string p, int r, int k, int a) :HomeAnimal(n, m, s, c), WildAnimal(n, m, p, r), Animal(n, m) {
	kolzub = k;
	age = a;
}

Rodent::~Rodent() {

}

int menu()
{
	int choiceButton = 0, button = 0;
	system("cls");
	while (true)
	{
		choiceButton = (choiceButton + 3) % 3;

		if (choiceButton == 0) cout << "->Ввод информации" << endl;
		else cout << "Ввод информации" << endl;

		if (choiceButton == 1) cout << "->Просмотр информации" << endl;
		else cout << "Просмотр иинформации" << endl;

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
