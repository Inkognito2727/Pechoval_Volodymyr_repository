#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Plant.c"
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
// Задача 20 Печовала Володимира Статистика-1
int main() {
	setlocale(LC_ALL, "ukr");
	int x, y;
	printf("%s", "Вести кількість робітників\n");
	scanf("%d", &x);
	printf("%s", "Вести кількість босів\n");
	scanf("%d", &y);
	struct Profession *prof=malloc(x*sizeof(float));
	for (int i = 0; i < x; i++) {
		printf_s("%s %d\n", " Вести ставку нової професії під № ", i + 1);
		scanf_s(" %f", &prof[i].rate);
	}
	struct Item *item = malloc(x * sizeof(float));
	for (size_t i = 0; i < x; i++) {
		printf_s(" %s\n", "Вести номер нового виробу ");
		scanf_s(" %d", &item[i].id_item);
		printf_s(" %s %d %s\n", "Вести ціну ", item[i].id_item, " виробу");
		scanf_s(" %f", &item[i].prices);
	}
	struct Worked *work = malloc(x * sizeof(float));
	for (int i = 0; i < x; i++) {
		printf_s(" %s \n", "Вести досвід нового робітника");
		scanf_s(" %d", &work[i].experience);
		printf_s(" %s \n", "Вести дерпатамент нового робітника");
		scanf_s(" %d", &work[i].id_department);
		printf_s(" %s\n", "Вести кількість зроблених виробів нового робітника");
		scanf_s(" %d", &work[i].count);
		printf_s(" %s\n", "Вести кількість відпрацьованих годин новим робітником");
		scanf_s(" %d", &work[i].hours_worked);
		printf_s(" %s\n", "Вести номер приладдя працівника");
		scanf_s(" %d", &work[i].id_item_work);
		printf_s(" %s\n", "Вести номер працівника");
		scanf_s(" %d", &work[i].id_worked);
	}
	struct ItemWork *itemwork=malloc(y * sizeof(float));
	for (int i = 0; i < y; i++) {
		printf_s(" %s\n", "Вести номер приладдя");
		scanf_s(" %d", &itemwork[i].id);
		printf_s(" %s %d %s\n", "Вести ціну ", itemwork[i].id, " приладдя");
		scanf_s(" %f", &itemwork[i].price);
	}
	struct Boss *boss= malloc(y * sizeof(float));
	for (int i = 0; i < y; i++) {
		printf_s(" %s\n", "Вести доступ начальника");
		scanf_s(" %d", &boss[i].access);
		printf_s(" %s\n", "Вести номер департаменту нового начальника");
		scanf_s(" %d", &boss[i].id_departaments);
		printf_s(" %s\n", "Вести бюджет департаменту нового начальника");
		scanf_s(" %f", &boss[i].department_budget);
		printf_s(" %s\n ", "Вести номер кабінету начальника");
		scanf_s(" %d", &boss[i].number_room);
	}
	struct HelpBoss* helpboss = malloc(y * sizeof(float));
	for (int i = 0; i < y; i++) {
		printf_s(" %s\n", "Робітник допомагає в кібінеті");
		scanf_s(" %d", &helpboss[i].help_room_boss);
		printf_s(" %s\n", "Кідькість помічників ");
		scanf_s(" %d", &helpboss[i].amout_helper);
	}
	float *mass = malloc(x * sizeof(float));
	float *mass2= malloc(y * sizeof(float));
	for (int i = 0; i < y; i++) {
		mass2[i] = 0;
	}
	for (int i = 0; i < x; i++) {
		mass[i] = prof[i].rate;
		mass[i] *= work[i].experience;
		mass[i] += work[i].count * item[i].prices;
	};
	int tmp;
	printf_s("%s", "1- робота з консолью, 2- робота з файлами\n");
	scanf_s("%d", &tmp);
	if (tmp == 1) {
		for (int i = 0; i < x; i++) {
			printf_s("%.2f ", mass[i]);
			printf_s("%s ", " ");
		};
	}
	for (int i = 0; i < y; i++) {
		for (int t = 0; t < x; t++) {
			if (boss[i].id_departaments == work[t].id_department) {
				for (int p = 0; p < y; p++) {
					if (work[t].id_item_work == itemwork[p].id) {
						mass2[i] += itemwork[p].price;
					}
				}
			}
		}
	}
	if (tmp == 1) {
		for (int i = 0; i < y; i++) {
			printf_s("%.2f ", mass2[i]);
		}
	}
	if (tmp == 2) {
		FILE* S1;
		S1 = fopen("Plant_cross_test.txt", "w");
		for (int i = 0; i < x; i++) {
			fprintf(S1,"%.2f ", mass[i]);
		}
		for (int i = 0; i < y; i++) {
			fprintf(S1,"%.2f ",mass2[i]);
		}
		fclose(S1);
	}
}
