/*
 ID: ShiehShieh
 PROG: crypt1
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


string to_str(int number)
{
	stringstream s;
	s << number;
	string str = s.str();

	return str;
}

int to_num(string s)
{
	int num;
	stringstream ss(s);
	ss >> num;
	return num;
}


void createFirst(string name, vector<char>& N, int index, vector<string>& result) {
	string name1 = name;

	for (int i = 0; N[i] != '0'; ++i)
	{
		if (index < 3)
		{
			name1[index] = N[i];
			createFirst(name1, N, index + 1, result);
		}else if(index == 3)
		{
			result.push_back(name1);
			break;
		}
	}
}


void createSecond(string name, vector<char>& N, int index, vector<string>& result) {
	string name1 = name;

	for (int i = 0; N[i] != '0'; ++i)
	{
		if (index < 2)
		{
			name1[index] = N[i];
			createFirst(name1, N, index + 1, result);
		}else if(index == 2)
		{
			result.push_back(name1);
			break;
		}
	}
}


bool contains(vector<char> number, vector<char> without, int num) {
	string str = to_str(num);
	int mark = 0;

	for(char c : without) {
		if (str.find(c) == string::npos)
		{
			++mark;
		}
	}

	if (mark == without.size())
	{
		return true;
	}

	return false;
}


int main(int argc, char *argv[])
{
	ifstream inf("crypt1.in");
	ofstream ouf("crypt1.out"); 
	int N = 0, pud1 = 0, pud2 = 0, final = 0;
	char k = 0;
	string numOne("555"), numTwo("55");
	vector<char> number;
	vector<char> without;
	set<string> times;
	char total[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
	vector<string> resultOne, resultTwo;
	inf >> N;
	inf >> k;
	while(inf) {
		number.push_back(k);
		inf >> k;
	}

	number.push_back('0');

//	for(char c : number) {
//		cout << c << endl;
//	}

	createFirst(numOne, number, 0, resultOne);
	createSecond(numTwo, number, 0, resultTwo);

	int mark = 0;
	for(int i = 0; i < 9; ++i) {
		mark = 0;
		for (char c : number)
		{
			if (c != total[i])
			{
				++mark;
			}
			if (mark == number.size())
			{
				without.push_back(total[i]);
			}
		}
	}

	without.push_back('0');

//	sort(resultTwo.begin(), resultTwo.end());
//	resultTwo.erase(unique(resultTwo.begin(), resultTwo.end()), resultTwo.end());

	for(string str1 : resultOne) {
		for(string str2 : resultTwo) {
			pud1 = to_num(str1) * (str2[1] - '0');
			pud2 = to_num(str1) * (str2[0] - '0') * 10;
			final = pud1 + pud2;
			if (pud1 < 1000 && pud2 < 10000 && final < 10000 && contains(number, without, pud1) && contains(number, without, pud2 / 10) && contains(number, without, final))
			{
				times.insert(str1 + str2);
			}
		}
	}

	ouf << times.size() << endl;

	return 0;
}
