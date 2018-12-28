#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
void Remove(int day, vector<vector<string>>& tfd, string& task) {
	for (int i = 0; i < tfd[day - 1].size(); i++) {
		if (tfd[day - 1][i] == task) {
			tfd[day - 1].erase(tfd[day - 1].begin() + i);
		}
	}
}
void Next_month(int& index, const vector<int>& diy, vector<vector<string>>& tfd) {
	index++;
	if (index > 11)index = 0;
	vector<vector<string>> NewMonth = tfd;
	int a = tfd.size();
	int b = diy[index];
	tfd.resize(b);
	const int e = b - 1;//переменная для определения индекса последнего дня в новом месяце
	if (a > b) {//если старый больше нового, то
		for (b; a > b; b++) {//перебираем все дни, которые не влезли с прошлого месяца
			tfd[e].insert(end(tfd[e]), begin(NewMonth[b]), end(NewMonth[b]));//все задачи из дня старого месяца дописываем в конец последнего дня нового месяца
		}
	}
	NewMonth.clear();
}
void Task_display(int day, const vector<vector<string>>& tfd) {
	cout << tfd[day - 1].size();
	for (auto i : tfd[day - 1]) {//перебираем все задачи в конкретном дне
		cout << " " << i;
	}
}
int main()
{
	int Q;
	cin >> Q;
	vector<int> day_in_year = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	vector<vector<string>> task_for_day;
	int index_of_month = 0;
	task_for_day.resize(day_in_year[index_of_month], {});
	for (int i = 0; Q > i; i++) {
		string comand;
		int day;
		string task;
		cin >> comand;
		if (comand == "NEXT") {
			Next_month(index_of_month, day_in_year, task_for_day);
		}
		else if (comand == "DUMP") {
			cin >> day;
			Task_display(day, task_for_day);
		}
		else if (comand == "ADD") {
			cin >> day >> task;
			task_for_day[day - 1].push_back(task);
		}
		else if (comand == "REMOVE") {
			cin >> day >> task;
			Remove(day, task_for_day, task);
		}
	}
}
