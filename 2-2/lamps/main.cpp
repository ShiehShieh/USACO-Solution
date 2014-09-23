/*
 ID: ShiehShieh
 PROG: lamps
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <sstream>


using namespace std;


vector<int> dict;
set<int> result;
int reference = 0;
string prototype(4, '5');


string to_str(int number)
{
	stringstream s;
	s << number;
	string str = s.str();

	return str;
}


string changeIt(int input) {
	string resultStirng(4, '0');
	int rest = input, index = 3;

	resultStirng[index--] = rest % 2 + '0';
	rest = rest / 2;
	while(rest) {
		resultStirng[index--] = rest % 2 + '0';
		rest = rest / 2;
	}

//	cout << resultStirng << endl;

	return resultStirng;
}


void create(int N, int input, int index, bool mark) {
	int flag = 0;
	string changed = changeIt(input);
	for (int i = 0; i < 4; ++i)
	{
		/* code */
		if (prototype[i] == '5')
		{
			/* code */
			++flag;
		}
		if (prototype[i] == changed[i])
		{
			/* code */
			++flag;
		}
	}
	if (flag == 4)
	{
		/* code */
		result.insert(input);
	}
	if (N == 0 || index == 5)
	{
		/* code */
		return;
	}
	if (mark)
	{
		/* code */
		input = input ^ dict[index];
		create(N - 1, input, index + 1, true);
		create(N - 1, input, index + 1, false);
	}else {
		create(N, input, index + 1, true);
		create(N, input, index + 1, false);
	}
}


int main(int argc, char const *argv[])
{
	ifstream inf("lamps.in");
	ofstream ouf("lamps.out");
	set<int> openOne, closeOne;
	int N = 0, C = 0, k = 0, original = 15;
	dict.push_back(15);
	dict.push_back(10);
	dict.push_back(5);
	dict.push_back(9);

	inf >> N >> C;

	inf >> k;

	while(k != -1) {
		openOne.insert(k);
		inf >> k;
	}

	inf >> k;

	while(k != -1) {
		closeOne.insert(k);
		inf >> k;
	}

	for(int i : openOne) {
		if (i % 2 && (i - 1) % 3 == 0)
		{
			/* code */
			prototype[0] = '1';
		}else if (i % 2 == 0 && !((i - 1) % 3 == 0))
		{
			/* code */
			prototype[1] = '1';
		}else if (i % 2 && !((i - 1) % 3 == 0))
		{
			/* code */
			prototype[2] = '1';
		}else if (i % 2 == 0 && (i - 1) % 3 == 0)
		{
			/* code */
			prototype[3] = '1';
		}
	}

	for(int i : closeOne) {
		if (i % 2 && (i - 1) % 3 == 0)
		{
			/* code */
			if (prototype[0] == '1')
			{
				/* code */
				ouf << "IMPOSSIBLE" << endl;

				exit(0);
			}
			prototype[0] = '0';
		}else if (i % 2 == 0 && !((i - 1) % 3 == 0))
		{
			/* code */
			if (prototype[1] == '1')
			{
				/* code */
				ouf << "IMPOSSIBLE" << endl;

				exit(0);
			}
			prototype[1] = '0';
		}else if (i % 2 && !((i - 1) % 3 == 0))
		{
			/* code */
			if (prototype[2] == '1')
			{
				/* code */
				ouf << "IMPOSSIBLE" << endl;

				exit(0);
			}
			prototype[2] = '0';
		}else if (i % 2 == 0 && (i - 1) % 3 == 0)
		{
			/* code */
			if (prototype[3] == '1')
			{
				/* code */
				ouf << "IMPOSSIBLE" << endl;

				exit(0);
			}
			prototype[3] = '0';
		}
	}

	int times = C;
	while(times > 4) {
		times -= 2;
	}

	create(times, original, 0, true);
	create(times, original, 0, false);

	if (result.empty())
	{
		/* code */
		ouf << "IMPOSSIBLE" << endl;
	}

	for(int i : result) {
		string str(N, '0');
		string tem = changeIt(i);
		for (int i = 1; i <= N; ++i)
		{
			/* code */
			if (tem[0] == '1' && i % 2 && (i - 1) % 3 == 0)
			{
				/* code */
				str[i - 1] = '1';
			}else if (tem[1] == '1' && i % 2 == 0 && !((i - 1) % 3 == 0))
			{
				/* code */
				str[i - 1] = '1';
			}else if (tem[2] == '1' && i % 2 && !((i - 1) % 3 == 0))
			{
				/* code */
				str[i - 1] = '1';
			}else if (tem[3] == '1' && i % 2 == 0 && (i - 1) % 3 == 0)
			{
				/* code */
				str[i - 1] = '1';
			}
		}
		ouf << str << endl;
	}

	return 0;
}
