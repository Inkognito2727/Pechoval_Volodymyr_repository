#include <iostream>
#include <vector>
#include <string>
using namespace std;
// Задача 20 Печовала Володимира Статистика-1
class People
{
private:
	string name;
public:
	virtual void SetName(string name) = 0;
};
template <class T, class T2>//шаблон класса
class Worked : public People {
private:
	string name;
	int count;
	int experience;
	T hours_worked;
	string department;
	int id_item_work;
public:
	Worked() {}//стандартный конструктор
	Worked(int count, int experience, T hours_worked, string department, int id_item_work) {//конструктор
		this->count = count;
		this->experience = experience;
		this->hours_worked = hours_worked;
		this->department = department;
		this->id_item_work = id_item_work;
	}
	void SetCount(int count) {//сеттер
		this->count = count;
	}
	int GetCount() {//геттер
		return this->count;
	}
	void SetExperience(int experience) {
		this->experience = experience;
	}
	int GetExperience() {
		return this->experience;
	}
	void SetHours_worked(T  hours_worked) {
		this->hours_worked = hours_worked;
	}
	T GetHours_worked() {
		return this->hours_worked;
	}
	void SetDepartmen(string department) {
		this->department;
	}
	string GetDepartmen() {
		return this->department;
	}
	void SetName(string name) {
		this->name = name;
	}
	string GetName() {
		return this->name;
	}
	int GetId_item_work() {
		return this->id_item_work;
	}
	void SetId_item_work(int id_item_work) {
		this->id_item_work = id_item_work;
	}
	void InFileWorked(string namefile) {//загрузка в файл
		ofstream inFile(namefile, ios::out);
		inFile << "Ім'я робітника" << " " << this->GetName() << "\n";
		inFile << "Кількість виробленого товару" << " " << this->GetCount() << "\n";
		inFile << "Відпрацьовані години" << " " << this->GetHours_worked() << "\n";
		inFile << "Робітник з департаменту" << " " << this->GetDepartmen() << "\n";
		inFile << "Номер приладя" << " " << this->GetId_item_work() << "\n";
		inFile << "Досвід роботи" << " " << this->GetExperience() << "\n";
	}
	~Worked() {}//дєструктор

};
template <typename T, typename T2>
class Boss : Worked<int, double> {
private:
	int access;
	int number_room;
	T department_budget;
	string departaments;
public:
	Boss() {}
	Boss(int access, int number_room, T departament_budget, string departaments) {
		this->access = access;
		this->number_room = number_room;
		this->department_budget = departament_budget;
		this->departaments = departaments;
	}
	void SetAccess(int access) {
		this->access = access;
	}
	int GetAccess() {
		return this->access;
	}
	void SetNumber_room(int number_room) {
		this->number_room = number_room;
	}
	int GetNumber_room() {
		return this->number_room;
	}
	void SetDepartment_budget(T department_budget) {
		this->department_budget = department_budget;
	}
	T Department_budgetm() {
		return this->department_budget;
	}
	void SetDepartaments(int departaments) {
		this->departaments = departaments;
	}
	string GetDepartaments() {
		return this->departaments;
	}
	void InFileBoss(string namefile) {
		ofstream inFile(namefile, ios::out);
		inFile << "Рівень доступу начальника" << " " << this->GetAccess() << "\n";
		inFile << "Номер кабінету" << " " << this->GetNumber_room() << "\n";
		inFile << "Бюджет департаменту" << " " << this->SetDepartment_budget() << "\n";
		inFile << "Назва департаменту" << " " << this->GetDepartaments() << "\n";
	}
	~Boss() {};
};
template <typename T, typename T2>
class HelpBoss : public Boss<int, double> {
private:
	int help_room_boss;
	int amout_helper;
public:
	HelpBoss() {}
	HelpBoss(int help_room_boss, int amount_helper) {
		this->help_room_boss = help_room_boss;
		this->amout_helper = amount_helper;
	}
	void InFileBoss(string namefile) {
		ofstream inFile(namefile, ios::out);
		inFile << "Робітник допомагає в кібінеті" << " " << this->help_room_boss << "\n";
		inFile << "Кідькість помічників" << " " << this->amout_helper << "\n";
	}
	~HelpBoss() {}
};
template <typename T, typename T2>
class Item {
private:
	string name;
	double prices;

public:
	Item() {};
	Item(string name, double prices)
	{
		this->name = name;
		this->prices = prices;
	}
	void SetName(string name) {
		this->name = name;
	}
	string GetName() {
		return name;
	}
	void Cout() {
		cout << this->name << " " << this->prices;
	}
	void SetPrice(double prices) {
		this->prices = prices;
	}
	double GetPrice() {
		return this->prices;
	}
	void InFileBoss(string namefile) {
		ofstream inFile(namefile, ios::out);
		inFile << "Ім'я елементу " << " " << this->GetName() << "\n";
		inFile << "Ціна " << " " << this->GetPrice() << "\n";
	}
};
template <typename T, typename T2>
class Profession {
private:
	double rate;
public:
	Profession() {};
	Profession(double rate) {
		this->rate = rate;
	}
	void SetRate(double rate) {
		this->rate = rate;
	}
	double GetRate() {
		return rate;
	}
	void InFileBoss(string namefile) {
		ofstream inFile(namefile, ios::out);
		inFile << "Ставка за професію " << " " << this->GetRate() << "\n";
	}

};
template <typename T, typename T2>
class ItemWork {
private:
	double price;
	int id;
public:
	ItemWork() {};
	ItemWork(double price, int id) {
		this->price = price;
		this->id = id;
	}
	void SetPrice(double price) {
		this->price = price;
	}
	double GetPrice() {
		return price;
	}
	void SetId(int id) {
		this->id = id;
	}
	double GetId() {
		return id;
	}
	void InFileBoss(string namefile) {
		ofstream inFile(namefile, ios::out);
		inFile << "Ціна за інтсрумент " << " " << this->GetPrice() << "\n";
		inFile << "Номер інструменту " << " " << this->GetId() << "\n";
	}
};