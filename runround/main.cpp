/*
 ID: ShiehShieh
 PROG: runround
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>


using namespace std;


string to_str(int number)
{
	stringstream s;
	s << number;
	string str = s.str();

	return str;
}


bool checkout(int input) {
	string str = to_str(input);
	int count = 0;
	vector<bool> mark(str.length(), false);

	for (int i = 0; i < str.length() - 1; ++i)
	{
		/* code */
		if (str[i] == '0')
		{
			/* code */
//			cout << input << ' ' << "false" << endl;
			return false;
		}
		for (int j = i + 1; j < str.length(); ++j)
		{
			/* code */
			if (str[j] == '0')
			{
				/* code */
//				cout << input << ' ' << "false" << endl;
				return false;
			}
			if (str[i] == str[j])
			{
				/* code */
//				cout << input << ' ' << "false" << endl;
				return false;
			}
		}
	}

//	cout << 'a' << endl;

	for (int i = 0; count < str.length(); ++count)
	{
		/* code */
		i = (i + (str[i] - '0')) % str.length();
//		cout << i << endl;
		if (mark[i])
		{
			/* code */
//			cout << input << ' ' << "false" << endl;
			return false;
		}
		mark[i] = true;
	}

	for(bool b : mark) {
		if (b == false)
		{
			/* code */
//			cout << input << ' ' << "false" << endl;
			return false;
		}
	}

//	cout << input << ' ' << "true" << endl;
	return true;
}


int main(int argc, char const *argv[])
{
	ifstream inf("runround.in");
	ofstream ouf("runround.out");
	int N = 0, i = 0;

	inf >> N;

	for (i = N + 1; !checkout(i); ++i)
	{
		/* code */
	}

	ouf << i << endl;

	return 0;
}
