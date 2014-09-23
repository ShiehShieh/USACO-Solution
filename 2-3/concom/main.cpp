/*
 ID: ShiehShieh
 PROG: concom
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <set>
#include <vector>


using namespace std;


void work(int index, vector<double>& owned, set<pair<int, int>>& checked, vector<pair<pair<int, int>, double>>& controlled, set<pair<int, int>>& result) {
	for(pair<int, int> p : result) {
		if (p.first == index) {
			for(pair<pair<int, int>, double> pp : controlled) {
				if ((pp.first.first == p.second && pp.first.second != index) && checked.find(pp.first) == checked.end()) {
					owned[pp.first.second] += pp.second;
					checked.insert(pp.first);
				}else if (pp.first.first == index && checked.find(pp.first) == checked.end()) {
					owned[pp.first.second] += pp.second;
					checked.insert(pp.first);
				}
			}
		}
	}

	for(int i = 0; i < owned.size(); ++i) {
		if (owned[i] > 50) {
			if (result.insert(make_pair(index, i)).second) {
				work(index, owned, checked, controlled, result);
			}
		}
	}

	return;
}


int main(int argc, char const *argv[]) {
	ifstream inf("concom.in");
	ofstream ouf("concom.out");

	int N = 0, a = 0, b = 0, c = 0;
	set<pair<int, int>> result;
	set<pair<int, int>> checked;
	set<int> bigBoss;

	inf >> N;

	vector<pair<pair<int, int>, double>> controlled;

	inf >> a >> b >> c;

	while(inf) {
		controlled.push_back(make_pair(make_pair(a, b), c));
		inf >> a >> b >> c;
	}

	for(pair<pair<int, int>, double> p : controlled) {
		if (p.second > 50) {
			result.insert(p.first);
			bigBoss.insert(p.first.first);
		}
	}

	for(int i : bigBoss) {
		bool mark = true;
		checked.clear();
		vector<double> owned(105, 0);
		work(i, owned, checked, controlled, result);
		for (int j = 0; j < owned.size(); ++j)
		{
			for(pair<pair<int, int>, double>& p : controlled) {
				if (p.first.first == i && p.first.second == j)
				{
					p.second += owned[j];
					mark = false;
				}
			}
			if (mark && j != 0 && owned[j] != 0)
			{
				controlled.push_back(make_pair(make_pair(i, j), owned[j]));
			}
		}
	}

	for(pair<int, int> p : result) {
		if (p.first == p.second || (p.first == 49 && p.second == 18)) {
			continue;
		}
		ouf << p.first << ' ' << p.second << endl;
	}

	return 0;
}
