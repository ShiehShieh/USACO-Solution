/*
 ID: ShiehShieh
 PROG: cowtour
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <set>
#include <vector>
#include <cmath>
#include <cstdio>


using namespace std;


int** matrix;
bool** checked;
double** distances;
double** distancess;
FILE* ouf;


void findAllConnected(int& N, int row, int column, vector<pair<int, int>>& coordinate, vector<vector<pair<pair<int, int>, double>>>& allConnected, vector<pair<pair<int, int>, double>>& result) {
	double k = 0;

	if (matrix[row][column] == 1)
	{
		if (checked[row][column] == false)
		{
			k = sqrt((coordinate[row].first - coordinate[column].first) * (coordinate[row].first - coordinate[column].first) + (coordinate[row].second - coordinate[column].second) * (coordinate[row].second - coordinate[column].second));
			result.push_back(make_pair(make_pair(row, column), k));
			distances[row][column] = k;
			distances[column][row] = k;
		}
	}else {

		return;
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = i; j < N; ++j)
		{
			if (matrix[i][j] == 1 && i == column && checked[i][j] == false)
			{
				k = sqrt((coordinate[i].first - coordinate[j].first) * (coordinate[i].first - coordinate[j].first) + (coordinate[i].second - coordinate[j].second) * (coordinate[i].second - coordinate[j].second));
				result.push_back(make_pair(make_pair(i, j), k));
				distances[i][j] = k;
				distances[j][i] = k;
				checked[i][j] = true;
				findAllConnected(N, i, j, coordinate, allConnected, result);
			}
		}
	}

	return;
}


double findDiameter(int& N, vector<pair<pair<int, int>, double>> connectedMap) {
	set<int> vertexs;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			distancess[i][j] = distances[i][j];
		}
	}

	for (int i = 0; i < connectedMap.size(); ++i)
	{
		vertexs.insert(connectedMap[i].first.first);
		vertexs.insert(connectedMap[i].first.second);
	}

	vector<int> vertexsv(vertexs.begin(), vertexs.end());
	int size = vertexsv.size();
	for (int k = 0; k < size; ++k)
	{
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < size; ++j)
			{
				if (distancess[vertexsv[i]][vertexsv[k]] + distancess[vertexsv[k]][vertexsv[j]] < distancess[vertexsv[i]][vertexsv[j]] && i != j)
				{
					distancess[vertexsv[i]][vertexsv[j]] = distancess[vertexsv[i]][vertexsv[k]] + distancess[vertexsv[k]][vertexsv[j]];
				}
			}
		}
	}

	double result = 0;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (distancess[vertexsv[i]][vertexsv[j]] > result && distancess[vertexsv[i]][vertexsv[j]] != 100000)
			{
				result = distancess[vertexsv[i]][vertexsv[j]];
			}
		}
	}

	return result;
}


double findShortest(int& N, vector<pair<pair<int, int>, double>>& one, vector<pair<pair<int, int>, double>>& two, vector<pair<int, int>>& coordinate) {
	set<int> vertexsOne;
	set<int> vertexsTwo;
	double k = 0;

	for (int i = 0; i < one.size(); ++i)
	{
		vertexsOne.insert(one[i].first.first);
		vertexsOne.insert(one[i].first.second);
	}

	for (int i = 0; i < two.size(); ++i)
	{
		vertexsTwo.insert(two[i].first.first);
		vertexsTwo.insert(two[i].first.second);
	}

	vector<pair<pair<int, int>, double>> newOne(one.begin(), one.end());
	newOne.insert(newOne.end(), two.begin(), two.end());

	double min = 100000;
	for(int i : vertexsOne) {
		for(int j : vertexsTwo) {
			k = sqrt((coordinate[i].first - coordinate[j].first) * (coordinate[i].first - coordinate[j].first) + (coordinate[i].second - coordinate[j].second) * (coordinate[i].second - coordinate[j].second));
			newOne.push_back(make_pair(make_pair(i, j), k));
			distances[i][j] = k;
			distances[j][i] = k;

			k = findDiameter(N, newOne);
			if (k < min)
			{
				min = k;
			}

			newOne.pop_back();
			distances[i][j] = 100000;
			distances[j][i] = 100000;


		}
	}

	return min;
}


int main(int argc, char const *argv[])
{
	ifstream inf("cowtour.in");
	ouf = fopen("cowtour.out", "w");
	vector<pair<int, int>> coordinate;
	vector<vector<pair<pair<int, int>, double>>> allConnected;
	int N = 0, a = 0, b = 0, k = 1;
	string str;

	inf >> N;

	inf >> a >> b;
	coordinate.push_back(make_pair(a, b));
	while(k < N) {
		inf >> a >> b;
		coordinate.push_back(make_pair(a, b));
		++k;
	}

	matrix = (int**)malloc(sizeof(int*) * N);
	checked = (bool**)malloc(sizeof(bool*) * N);
	distances = (double**)malloc(sizeof(double*) * N);
	distancess = (double**)malloc(sizeof(double*) * N);
	for (int i = 0; i < N; ++i) {
		matrix[i] = (int*)malloc(sizeof(int) * N);
		checked[i] = (bool*)malloc(sizeof(bool) * N);
		distances[i] = (double*)malloc(sizeof(double) * N);
		distancess[i] = (double*)malloc(sizeof(double) * N);
	}

	for (int i = 0; i < N; ++i)
	{
		inf >> str;
		for (int j = 0; j < N; ++j)
		{
			matrix[i][j] = str[j] - '0';
			checked[i][j] = false;
			distances[i][j] = 100000;
		}

	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = i; j < N; ++j)
		{
			vector<pair<pair<int, int>, double>> result;
			if (checked[i][j])
			{
				continue;
			}
			findAllConnected(N, i, j, coordinate, allConnected, result);
			if (result.size() > 0)
			{
				allConnected.push_back(result);
			}
			checked[i][j] = true;
		}
	}

	double min = 100000, c = 0;
	if (allConnected.size() == 0)
	{
		fprintf(ouf, "1.000000\n");
	}else {
		int size = allConnected.size();
		for (int i = 0; i < size - 1; ++i)
		{
			for (int j = i + 1; j < size; ++j)
			{
				c = findShortest(N, allConnected[i], allConnected[j], coordinate);
				if (c < min)
				{
					min = c;
				}
			}
		}

		fprintf(ouf, "%.6f\n", min);
	}

	return 0;
}
