#pragma once
// Задача 20 Печовала Володимира Статистика-1
struct People {
	char name_people[15];
};
struct Worked {
	int id_worked;
	int count;
	int experience;
	float hours_worked;
	int id_department;
	int id_item_work;
};
struct Boss {
	int access;
	int number_room;
	float department_budget;
	int id_departaments;
};
struct HelpBoss {
	int help_room_boss;
	int amout_helper;
};
struct Item {
	int id_item;
	float prices;
};
struct Profession {
	float rate;
};
struct ItemWork {
	float price;
	int id;
};
