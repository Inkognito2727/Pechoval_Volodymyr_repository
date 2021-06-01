#include <iostream>
#include <vector>
#include <string>
using namespace std;
// ������ 20 �������� ���������� ����������-1
class People
{
private:
	string name;
public:
	virtual void SetName(string name) = 0;
};
template <class T, class T2>//������ ������
class Worked : public People {
private:
	string name;
	int count;
	int experience;
	T hours_worked;
	string department;
	int id_item_work;
public:
	Worked() {}//����������� �����������
	Worked(int count, int experience, T hours_worked, string department, int id_item_work) {//�����������
		this->count = count;
		this->experience = experience;
		this->hours_worked = hours_worked;
		this->department = department;
		this->id_item_work = id_item_work;
	}
	void SetCount(int count) {//������
		this->count = count;
	}
	int GetCount() {//������
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
	void InFileWorked(string namefile) {//�������� � ����
		ofstream inFile(namefile, ios::out);
		inFile << "��'� ��������" << " " << this->GetName() << "\n";
		inFile << "ʳ������ ����������� ������" << " " << this->GetCount() << "\n";
		inFile << "³���������� ������" << " " << this->GetHours_worked() << "\n";
		inFile << "������� � ������������" << " " << this->GetDepartmen() << "\n";
		inFile << "����� �������" << " " << this->GetId_item_work() << "\n";
		inFile << "����� ������" << " " << this->GetExperience() << "\n";
	}
	~Worked() {}//���������

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
		inFile << "г���� ������� ����������" << " " << this->GetAccess() << "\n";
		inFile << "����� �������" << " " << this->GetNumber_room() << "\n";
		inFile << "������ ������������" << " " << this->SetDepartment_budget() << "\n";
		inFile << "����� ������������" << " " << this->GetDepartaments() << "\n";
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
		inFile << "������� �������� � �����" << " " << this->help_room_boss << "\n";
		inFile << "ʳ������ ��������" << " " << this->amout_helper << "\n";
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
		inFile << "��'� �������� " << " " << this->GetName() << "\n";
		inFile << "ֳ�� " << " " << this->GetPrice() << "\n";
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
		inFile << "������ �� ������� " << " " << this->GetRate() << "\n";
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
		inFile << "ֳ�� �� ���������� " << " " << this->GetPrice() << "\n";
		inFile << "����� ����������� " << " " << this->GetId() << "\n";
	}
};