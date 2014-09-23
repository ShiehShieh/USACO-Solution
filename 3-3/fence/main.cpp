/*
 ID: ShiehShieh
 PROG: fence
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <sstream>


using namespace std;


int F;


string to_str(int number)
{
	stringstream s;
	s << number;
	string str = s.str();

	return str;
}


void findThePath(int& counter, int& startPoint, int& index, vector<vector<int>>& allFence, string& result, string& output) {
	int minOne = 550;

	for (auto i = allFence[startPoint].begin(); i != allFence[startPoint].end(); ++i)
	{
		if (*i < minOne)
		{
			minOne = *i;
		}
	}

	index = minOne;

	for (auto i = allFence[startPoint].begin(); i != allFence[startPoint].end(); ++i)
	{
		if (*i == index)
		{
			allFence[startPoint].erase(i);

			break;
		}
	}

	for (auto i = allFence[index].begin(); i != allFence[index].end(); ++i)
	{
		if (*i == startPoint)
		{
			allFence[index].erase(i);

			break;
		}
	}

	if (allFence[index].size() == 0)
	{
		output += '\n';
		output += to_str(index);
		++counter;

		return;
	}

	startPoint = index;
	result += '\n';
	result += to_str(startPoint);
	++counter;

	return;
}


int main(int argc, char const *argv[])
{
	ifstream inf("fence.in");
	ofstream ouf("fence.out");
	int k = 0, t = 0, counter = 0, index = 0, startPoint = 100000000, endPoint = 0, minOne = 100000000, maxOne = 0;
	vector<vector<int>> allFence(600);
	string result, output;

	inf >> F;

	for (int i = 0; i < F; ++i)
	{
		inf >> k >> t;
		allFence[k].push_back(t);
		allFence[t].push_back(k);

		if (k < minOne)
		{
			minOne = k;
		}
		if (k > maxOne)
		{
			maxOne = k;
		}
		if (t < minOne)
		{
			minOne = t;
		}
		if (t > maxOne)
		{
			maxOne = t;
		}
	}

	for (int i = 0; i < 600; ++i)
	{
		if (allFence[i].size() % 2 != 0)
		{
			if (i < startPoint)
			{
				startPoint = i;
			}
			if (i > endPoint)
			{
				endPoint = i;
			}
		}
	}

	if (startPoint == 100000000 && endPoint == 0)
	{
		startPoint = minOne;
		endPoint = minOne;
	}

	counter = allFence[endPoint].size();
	result += to_str(startPoint);
	++counter;

	while(counter < F + 1) {
		findThePath(counter, startPoint, index, allFence, result, output);
		cout << counter << endl;
	}

	ouf << result << endl;
	cout << output << endl;

	return 0;
}
