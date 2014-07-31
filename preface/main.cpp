/*
 ID: ShiehShieh
 PROG: preface
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>


using namespace std;


map<char, string> dictOne, dictTwo, dictThree, dictFour;
map<char, int> result;

string to_str(int number)
{
	stringstream s;
	s << number;
	string str = s.str();

	return str;
}


void createRomeChar(int input) {
	string str = to_str(input);
	string tem;
	int len = str.length();

	for (int i = len - 1; i >= 0; --i)
	{
		/* code */
		if (str[i] == '0')
		{
			/* code */
			cout << i << ' ' << "continue" << endl;
			continue;
		}
		if (i == len - 1)
		{
			/* code */
			tem = dictOne[str[i]];
			cout << tem << ' ' << i << ' ' << input << endl;
			for(char ch : tem) {
				++result[ch];
			}
		}else if (i == len - 2)
		{
			/* code */
			tem = dictTwo[str[i]];
			cout << tem << ' ' << i << ' ' << input << endl;
			for(char ch : tem) {
				++result[ch];
			}
		}else if (i == len - 3)
		{
			/* code */
			tem = dictThree[str[i]];
			cout << tem << ' ' << i << ' ' << input << endl;
			for(char ch : tem) {
				++result[ch];
			}
		}else if (i == len - 4)
		{
			/* code */
			tem = dictFour[str[i]];
			cout << tem << ' ' << i << ' ' << input << endl;
			for(char ch : tem) {
				++result[ch];
			}
		}
	}

	return;
}


int main(int argc, char const *argv[])
{
	ifstream inf("preface.in");
	ofstream ouf("preface.out");
	int N = 0;

	inf >> N;

	dictOne['1'] = "I";
	dictOne['2'] = "II";
	dictOne['3'] = "III";
	dictOne['4'] = "IV";
	dictOne['5'] = "V";
	dictOne['6'] = "VI";
	dictOne['7'] = "VII";
	dictOne['8'] = "VIII";
	dictOne['9'] = "IX";
	dictTwo['1'] = "X";
	dictTwo['2'] = "XX";
	dictTwo['3'] = "XXX";
	dictTwo['4'] = "XL";
	dictTwo['5'] = "L";
	dictTwo['6'] = "LX";
	dictTwo['7'] = "LXX";
	dictTwo['8'] = "LXXX";
	dictTwo['9'] = "XC";
	dictThree['1'] = "C";
	dictThree['2'] = "CC";
	dictThree['3'] = "CCC";
	dictThree['4'] = "CD";
	dictThree['5'] = "D";
	dictThree['6'] = "DC";
	dictThree['7'] = "DCC";
	dictThree['8'] = "DCCC";
	dictThree['9'] = "CM";
	dictFour['1'] = "M";
	dictFour['2'] = "MM";
	dictFour['3'] = "MMM";

	for (int i = 1; i <= N; ++i)
	{
		/* code */
		createRomeChar(i);
	}

	for(pair<char, int> p : result) {
		cout << p.first << ' ' << p.second << endl;
	}

	auto tem = result.find('I');
	if (tem != result.end())
	{
		/* code */
		ouf << 'I' << ' ' << tem->second << endl;
	}
	tem = result.find('V');
	if (tem != result.end())
	{
		/* code */
		ouf << 'V' << ' ' << tem->second << endl;
	}
	tem = result.find('X');
	if (tem != result.end())
	{
		/* code */
		ouf << 'X' << ' ' << tem->second << endl;
	}
	tem = result.find('L');
	if (tem != result.end())
	{
		/* code */
		ouf << 'L' << ' ' << tem->second << endl;
	}
	tem = result.find('C');
	if (tem != result.end())
	{
		/* code */
		ouf << 'C' << ' ' << tem->second << endl;
	}
	tem = result.find('D');
	if (tem != result.end())
	{
		/* code */
		ouf << 'D' << ' ' << tem->second << endl;
	}
	tem = result.find('M');
	if (tem != result.end())
	{
		/* code */
		ouf << 'M' << ' ' << tem->second << endl;
	}

	return 0;
}
