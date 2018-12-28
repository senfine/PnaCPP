#include "pch.h"
#include <iostream>
#include <map>
#include <string>

using namespace std;
void RENAME (map<string, string>& dr, string old_country){
	auto it = dr.find(old_country);
	string capital = it->second;
	dr.erase(old_country);
	cout << "Введите новое название страны" << endl;
	string new_country;
	cin >> new_country;
	dr[new_country] = capital;
}
void ABOUT(map<string, string>& dr, string country) {
	auto it = dr.find(country);
	if (it != dr.end()) {
		cout << country << "\t" << it->second << endl;
	}
	else {
		cout << "Country country doesn't exis" << endl;
	}
}
void DUMP(map<string, string>& dr) {
	for (auto it = dr.begin(); it != dr.end(); ++it)
	{
		cout << (*it).first << "\t" << (*it).second << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	int Q;
	cin >> Q;
	map<string, string> directory = { {"Russia", "Moscow"}, {"Ukraine", "Kiev"}, {"Germany", "Berlin"} };
	for (int i = 0; i < Q; i++) {
		cout << "Выберите команду" << endl;
		string country;
		string capital;
		string comand;
		cin >> comand;
		if (comand == "CHANGE_CAPITAL") {
			cout << "Введите страну" << endl;
			cin >> country;
			cout << "Введите столицу" << endl;
			cin >> capital;
			directory[country] = capital;
		}
		else if (comand == "RENAME") {
			cout << "Введите страну" << endl;
			cin >> country;
			RENAME(directory, country);
		}
		else if (comand == "ABOUT") {
			cin >> country;
			ABOUT(directory, country);
		}
		else if (comand == "DUMP") {
			DUMP(directory);
		}
	}
}
