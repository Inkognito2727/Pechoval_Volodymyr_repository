#include "Plant.h" 
using namespace std;
// Задача 20 Печовала Володимира Статистика-1
int main() {
	setlocale(LC_ALL, "ukr");
	Profession<int, int> prof[5];//массив структур
	Item<int, int> item[5];
	Worked<int, int> worked[5];
	ItemWork<int, int> item_work[2];
	Boss<int, int> boss[2];
	HelpBoss<int, int> helpboss[2];
	boss[0] = Boss<int, int>(1, 201, 2000, "Завод");//вписывание в массив значений
	boss[1] = Boss<int, int>(1, 301, 20500, "Склад");
	helpboss[0] = HelpBoss<int, int>(1, 2);
	helpboss[1] = HelpBoss<int, int>(2, 5);
	item_work[0] = ItemWork<int, int>(500, 1);
	item_work[1] = ItemWork<int, int>(1000, 2);
	worked[0] = Worked<int, int>(5, 20, 10, "Завод", 1);
	worked[1] = Worked<int, int>(10, 20, 100, "Склад", 2);
	worked[2] = Worked<int, int>(5, 20, 10, "Склад", 2);
	worked[3] = Worked<int, int>(5, 20, 10000, "Завод", 1);
	worked[4] = Worked<int, int>(5, 20, 100, "Завод", 1);
	prof[0] = Profession<int, int>(200);
	prof[1] = Profession<int, int>(800);
	prof[2] = Profession<int, int>(300);
	prof[3] = Profession<int, int>(900);
	prof[4] = Profession<int, int>(200.50);
	item[0] = Item<int, int>("Мило", 10);
	item[1] = Item<int, int>("Закваска", 50);
	item[2] = Item<int, int>("Шампунь", 100);
	item[3] = Item<int, int>("Вода", 4);
	item[4] = Item<int, int>("Телефони", 1000);
	double mass[5];//создание массива для рассчета
	double mass2[2]{ 0,0 };//создание массива для рассчета
	for (int i = 0; i < 5; i++) {
		mass[i] = prof[i].GetRate() * worked[i].GetExperience() + worked[i].GetCount() + item[i].GetPrice();//Формула просчета зарплаты
	}
	int tmp;
	cout << "1-робота з консолью, 2-робота з файлами" << endl;
	cin >> tmp; //пременная для созданя меню
	if (tmp == 1) {
		for (int i = 0; i < 5; i++) {//Вывод зарплаты
			cout << "Заробітна плата " << i + 1 << " працівника" << endl;
			cout << mass[i] << " " << endl;
		}
	}
	for (int i = 0; i < 2; i++) {//просчет стоимости снаряжения
		for (int t = 0; t < 5; t++) {
			if (boss[i].GetDepartaments() == worked[t].GetDepartmen()) {//привязка начальника к рабочему
				for (int y = 0; y < 2; y++) {
					if (worked[t].GetId_item_work() == item_work[y].GetId()) {//привязка оборудования к работнику
						mass2[i] += item_work[y].GetPrice();//просчет стоимости
					}
				}
			}
		}
	}
	if (tmp == 1) {
		for (int i = 0; i < 2; i++) {
			cout << "Вартість обладнення департаменту " << i + 1 << " начальника" << endl;
			cout << mass2[i] << " " << endl;
		}
	}
	if (tmp == 2) {
		fstream inFile("Plant_cross_test.csv", ios::out);//открытие файла для записи
		for (int i = 0; i < 5; i++) {
			inFile << "Заробітна плата №" << i + 1 << " = " << mass[i] << " грн." << "\n";
		}
		for (int i = 0; i < 2; i++) {
			inFile << "Ціна робочого знарядя начальника з департаменту " << boss[i].GetDepartaments() << " = " << mass2[i] << " грн." << "\n";
		}
		inFile.close();
	}
}
