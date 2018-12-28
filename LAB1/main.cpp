#include <iostream>
#include <string>
#include <vector>
#include <clocale>

using namespace std;

// ЯВЛЯЕТСЯ ЛИ СТРОКА ПАЛИНДРОМОМ (ЦИКЛ)
bool isPalindrom(string word)
{
	int len = word.length();
	for (int i = 0; i < len / 2; ++i)
	{
		if (word[i] != word[len - i - 1])
		{
			return false;
		}
	}
	return true;
}

// ЯВЛЯЕТСЯ ЛИ СТРОКА ПАЛИНДРОМОМ
bool isPalindrome(string w) {

	string word = w;

	reverse(w.begin(), w.end());

	return (w == word);
}

// ПАЛИНДРОМ ФИЛЬТЕР 
vector<string> PalindromFilter(vector<string> words, int minLength)
{
	vector<string> output;
	vector<string>::iterator it;

	for (it = words.begin(); it != words.end(); it++) {
		if (((*it).size() >= (unsigned)minLength) && isPalindrom(*it))
			output.push_back(*it);
	}

	return output;
}

int main()
{
	setlocale(LC_CTYPE, "rus");

	
	string str;
	cout << "Введите слово: ";
	cin >> str;

	if (isPalindrom(str))
		cout << "Слово является палиндромом.\n";
	else
		cout << "Слово не является палиндромом.\n";
	

	/*
	string str;
	cout << "Введите слово: ";
	cin >> str;

	if(isPalindrome(str))
		cout << "Слово является палиндромом.\n";
	else
		cout << "Слово не является палиндромом.\n";
	*/

	/*
	vector<string> words = { "abacaba", "aba", "weew", "bro", "code" };
	int minLength = 3;

	for (string i : PalindromFilter(words, minLength)) {
		cout << i << "\n";
	}
	*/
	
	system("pause");
	return 0;
}
