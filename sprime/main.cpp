/*
 ID: ShiehShieh
 PROG: sprime
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;


int to_num(string s)
{
	int num;
	stringstream ss(s);
	ss >> num;
	return num;
}


bool isPrime(int x)
{
	int e = (int)sqrt(x);
	if (x == 1)
	{
		/* code */
		return false;
	}
	for(int i = 2; i <= e; ++i)
	{
		if((x % i) == 0) {
			return false;
		}
	}

	return true;
}


void create(string name, int N, vector<char>& number, vector<int>& result) {
	string name1;

	if (N == 1)
	{
		/* code */
		result.push_back(to_num(name));

		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		/* code */
		name1 = name;
		name1 += number[i];
		if (isPrime(to_num(name1)))
		{
			/* code */
			create(name1, N - 1, number, result);
		}else {
			continue;
		}
	}
}


bool checkout(int input) {
	for ( ; input > 0; )
	{
		/* code */
		input = input / 10;

		if (!isPrime(input))
		{
			/* code */
			return false;
		}
	}

	return true;
}


int main(int argc, char const *argv[])
{
	ifstream inf("sprime.in");
	ofstream ouf("sprime.out");
	vector<int> allPossible;
	vector<int> result;
	vector<char> number;
	int max = 1;
	int N = 0;
	inf >> N;

	for (int i = 0; i < N; ++i)
	{
		/* code */
		max = max * 10;
	}

	number.push_back('1');
	number.push_back('3');
	number.push_back('7');
	number.push_back('9');

	create("2", N, number, result);
	create("3", N, number, result);
	create("5", N, number, result);
	create("7", N, number, result);

/*	int mark = 0;
	int first = 0;
	int min = max / 10;
	for (int i = (max / 10) + 1; i < max; )
	{
		first = i / min;
		if (first == 1 || first == 4 || first == 6 || first == 8 || first == 9)
		{
			i = (first * min) + (1 * min) + 1;
			mark = 0;
		}
		if (isPrime(i))
		{
			allPossible.push_back(i);
		}
		++mark;
		mark = mark % 4;
		if (mark == 2)
		{
			i = i + 4;
		}else {
			i = i + 2;
		}
	}

	for(int i : allPossible) {
		if (checkout(i))
		{
			result.push_back(i);
		}
	}
*/
	for(int i : result) {
		ouf << i << endl;
	}

	return 0;
}
