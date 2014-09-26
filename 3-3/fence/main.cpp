/*
 ID: ShiehShieh
 PROG: fence
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>


using namespace std;


int F, endPoint, minOne, maxOne;
vector<string> allResult;
ifstream inf("fence.in");
ofstream ouf("fence.out");


void findThePath(int counter, int startPoint, int index, vector<vector<int>> allFence, string result);


string to_str(int number)
{
	stringstream s;
	s << number;
	string str = s.str();

	return str;
}


void findThePath(int counter, int startPoint, int index, vector<vector<int>> allFence, string result) {
	int localCounter;
	string localString;
	vector<vector<int>> localAllFence;

	if (startPoint == 0 || startPoint > maxOne)
	{
		return;
	}

	for (auto i = allFence[startPoint].begin(); i != allFence[startPoint].end(); ++i)
	{
		index = *i;
		localCounter = counter;
		localString = result;
		localAllFence = allFence;
		cout << index << ' ' << maxOne << endl;

		if (index > maxOne)
		{
			return;
		}

		localString += '\n';
		localString += to_str(index);
		++localCounter;

		if (localCounter > F)
		{
			return;
		}

		if (localCounter == F && index == endPoint)
		{
			allResult.push_back(localString);
			ouf << localString << endl;

			exit(0);
		}else if (allResult.size() == 10)
		{
			string output("9999999999");

			for(string str : allResult) {
				if (str < output)
				{
					output = str;
				}
			}

			ouf << output << endl;

			exit(0);
		}

		for (auto i = localAllFence[startPoint].begin(); i != localAllFence[startPoint].end(); ++i)
		{
			if (*i == index)
			{
				localAllFence[startPoint].erase(i);

				break;
			}
		}

		for (auto i = localAllFence[index].begin(); i != localAllFence[index].end(); ++i)
		{
			if (*i == startPoint)
			{
				localAllFence[index].erase(i);

				break;
			}
		}

		startPoint = index;

		findThePath(localCounter, startPoint, index, localAllFence, localString);
	}

	return;
}


int main(int argc, char const *argv[])
{
	int k = 0, t = 0, counter = 0, index = 0, startPoint = 100000000;
	vector<vector<int>> allFence(600);
	string result, output;

	minOne = 100000000;
	maxOne = 0;
	endPoint = 0;

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
		sort(allFence[i].begin(), allFence[i].end());

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

	++F;

	result += to_str(startPoint);
	++counter;

	findThePath(counter, startPoint, index, allFence, result);

	return 0;
}
