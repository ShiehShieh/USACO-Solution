/*
 ID: ShiehShieh
 PROG: castle
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>


using namespace std;


void floodFill(int& newComponent, int& index, vector<vector<pair<int, int>>>& castle, vector<int>& component) {
	component[index] = newComponent;

	for(pair<int, int> p : castle[index]) {
		if (component[p.second] == newComponent)
		{
			/* code */
			continue;
		}
		component[p.second] = newComponent;
		floodFill(newComponent, p.second, castle, component);
	}

	return;
}


int findMax(vector<int>& component, map<int, int>& maxMap) {
	int result = 0;
	for(int i : component) {
		++maxMap[i];
	}

	for(pair<int, int> p : maxMap) {
		if (p.second >= result)
		{
			/* code */
			result = p.second;
		}
	}

	return result ;
}


int main(int argc, char const *argv[])
{
	ifstream inf("castle.in");
	ofstream ouf("castle.out");
	map<int, vector<int>> wall;
	map<int, int> maxMap;
	vector<int> tem;
	int M = 0, N = 0, k = 0;
	inf >> M >> N;
	vector<vector<pair<int, int>>>	castle(M * N);

	tem.push_back(-1);
	tem.push_back(1);
	tem.push_back(0 - M);
	tem.push_back(M);
	wall[0] = tem;
	tem.clear();
	tem.push_back(M);
	tem.push_back(1);
	tem.push_back(0 - M);
	wall[1] = tem;
	tem.pop_back();
	tem.push_back(-1);
	wall[2] = tem;
	tem.clear();
	tem.push_back(M);
	tem.push_back(0 - M);
	tem.push_back(-1);
	wall[4] = tem;
	tem.clear();
	tem.push_back(0 - M);
	tem.push_back(1);
	tem.push_back(-1);
	wall[8] = tem;
	tem.clear();
	tem.push_back(M);
	tem.push_back(1);
	wall[3] = tem;
	tem.clear();
	tem.push_back(M);
	tem.push_back(0 - M);
	wall[5] = tem;
	tem.clear();
	tem.push_back(0 - M);
	tem.push_back(1);
	wall[9] = tem;
	tem.clear();
	tem.push_back(M);
	tem.push_back(-1);
	wall[6] = tem;
	tem.clear();
	tem.push_back(-1);
	tem.push_back(1);
	wall[10] = tem;
	tem.clear();
	tem.push_back(0 - M);
	tem.push_back(-1);
	wall[12] = tem;
	tem.clear();
	tem.push_back(M);
	wall[7] = tem;
	tem.clear();
	tem.push_back(1);
	wall[11] = tem;
	tem.clear();
	tem.push_back(0 - M);
	wall[13] = tem;
	tem.clear();
	tem.push_back(-1);
	wall[14] = tem;
	tem.clear();
	wall[15] = tem;

	inf >> k;

	int index = 0;

	while(inf) {
		for(int i : wall[k]) {
			castle[index].push_back(make_pair(index, index + i));
		}
		inf >> k;
		++index;
	}

	vector<int> component(N * M, 0);

	int newComponent = 1;
	index = castle.size();
	for (int i = 0; i < index; ++i)
	{
		/* code */
		if (component[i] == 0)
		{
			/* code */
			floodFill(newComponent, i, castle, component);
			++newComponent;
		}
	}

	int max = 0;

	ouf << newComponent - 1 << endl;

	max = findMax(component, maxMap);

	ouf << max << endl;
/*
	for(pair<int, int> p : maxMap) {
		cout << p.first << ' ' << p.second << endl;
	}
*/
	int suchWallIR = 0;
	int suchWallIC = 0;
	char suchWallC = ' ';
	for (int i = 0; i < M; ++i)
	{
		/* code */
		for (int j = 0; j < N; ++j)
		{
			/* code */
			if (j != N - 1 && component[j * M + i] == component[j * M + i + M])
			{
				/* code */
				continue;
			}else if (j != N - 1 && component[j * M + i] != component[j * M + i + M]){
				if (maxMap[component[j * M + i]] + maxMap[component[j * M + i + M]] > max)
				{
					/* code */
					max = maxMap[component[j * M + i]] + maxMap[component[j * M + i + M]];
					suchWallIR = j + 1;
					suchWallIC = i + 1;
					suchWallC = 'N';
				}
			}
			if (i != M - 1 && component[j * M + i] == component[j * M + i + 1])
			{
				/* code */
				continue;
			}else if (i != M - 1 && component[j * M + i] != component[j * M + i + 1])
			{
				/* code */
				if (maxMap[component[j * M + i]] + maxMap[component[j * M + i + 1]] > max)
				{
					/* code */
					max = maxMap[component[j * M + i]] + maxMap[component[j * M + i + 1]];
					suchWallIR = j + 1;
					suchWallIC = i + 1;
					suchWallC = 'E';
				}
			}
		}
	}

	ouf << max << endl;

	ouf << suchWallIR << ' ' << suchWallIC << ' ' << suchWallC << endl;

/*
	for (int i = 0; i < M * N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cout << component[i * M + j] << ' ' << flush;
		}
		cout << endl;
	}
*/
/*
	for(vector<pair<int, int>> i : castle) {
		for(pair<int, int> p : i) {
			cout << index << ' ' << p.first << ' ' << p.second << endl;
		}
		++index;
	}
*/

//	for(pair<int, vector<int>> p : wall) {
//		for(int i : p.second) {
//			cout << p.first << ' ' << i << endl;
//		}
//	}

	return 0;
}
