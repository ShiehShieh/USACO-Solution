/*
 ID: ShiehShieh
 PROG: ttwo
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <vector>


using namespace std;


char theMap[10][10];


void walk(pair<pair<int, int>, char>& object) {
	switch (object.second) {
		case 'E': {
			if (object.first.second == 9)
			{
				object.second = 'S';
			}else if (theMap[object.first.first][object.first.second + 1] == '*')
			{
				object.second = 'S';
			}else if (theMap[object.first.first][object.first.second + 1] == '.')
			{
				object.first.second += 1;
			}
			break;
		}
		case 'W': {
			if (object.first.second == 0)
			{
				object.second = 'N';
			}else if (theMap[object.first.first][object.first.second - 1] == '*')
			{
				object.second = 'N';
			}else if (theMap[object.first.first][object.first.second - 1] == '.')
			{
				object.first.second -= 1;
			}
			break;
		}
		case 'S': {
			if (object.first.first == 9)
			{
				object.second = 'W';
			}else if (theMap[object.first.first + 1][object.first.second] == '*')
			{
				object.second = 'W';
			}else if (theMap[object.first.first + 1][object.first.second] == '.')
			{
				object.first.first += 1;
			}
			break;
		}
		case 'N': {
			if (object.first.first == 0)
			{
				object.second = 'E';
			}else if (theMap[object.first.first - 1][object.first.second] == '*')
			{
				object.second = 'E';
			}else if (theMap[object.first.first - 1][object.first.second] == '.')
			{
				object.first.first -= 1;
			}
			break;
		}
	}
}


int main(int argc, char const *argv[])
{
	ifstream inf("ttwo.in");
	ofstream ouf("ttwo.out");

	int minute = 0;
	pair<pair<int, int>, char> C;
	pair<pair<int, int>, char> F;

	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 10; ++j) {
			inf >> theMap[i][j];

			if (theMap[i][j] == 'F') {
				F.first.first = i;
				F.first.second = j;
				F.second = 'N';
				theMap[i][j] = '.';
			}else if (theMap[i][j] == 'C') {
				C.first.first = i;
				C.first.second = j;
				theMap[i][j] = '.';
				C.second = 'N';
			}
		}
	}

	while(minute < 160000) {
		walk(F);
		walk(C);
		++minute;
		if (F.first.first == C.first.first && F.first.second == C.first.second) {
			ouf << minute << endl;

			break;
		}
	}

	if (minute >= 160000) {
		ouf << 0 << endl;
	}

	return 0;
}