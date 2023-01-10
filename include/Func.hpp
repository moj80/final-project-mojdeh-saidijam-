#ifndef FUNC_H
#define FUNC_H
#include <iostream>
#include <string>
#include <fstream>
#include "windows.h"
#include <sstream>

void gotoxy(int x, int y);
void showProductList(Drug *dr[]);
void showOrderList(Drug *dr, int found);
void save(Drug *dr[]);
void readPharmacy(Drug *dr[]);
int searchByID(int id, Drug *dr[]);
int searchByName(string name, Drug *dr[]);
bool inputDate(int &day, int &month, int &year);
void positive(int &input);
int castToInt(string x);
bool checkInt(string x);
void readNoskhe(Noskhe *no[]);
void showNoskhe(Noskhe *no[]);

#endif
