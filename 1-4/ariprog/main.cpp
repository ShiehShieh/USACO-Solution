/*
 ID: ShiehShieh
 PROG: ariprog
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <sstream>
#include <algorithm>


using namespace std;


void create(int N, int start, int input, vector<int>& allPossibleV, set<int>& allPossibleS, vector<int>& diffV, vector<pair<int, int>>& result) {
    int now = allPossibleV[start];

    for (int i = 0; i < N - 1; ++i)
    {
        /* code */
        if (allPossibleS.find(now + input) != allPossibleS.end())
        {
            /* code */
            now = *(allPossibleS.find(now + input));
        }else {
            return;
        }
    }

    result.push_back(make_pair(allPossibleV[start], input));

    return;
}


bool compareSecond(pair<int, int> p1, pair<int, int> p2) {
    if (p1.second < p2.second)
    {
        /* code */
        return true;
    }else if(p1.second == p2.second) {
        if (p1.first < p2.first)
        {
            /* code */
            return true;
        }else {
            return false;
        }
    }else {
        return false;
    }
}


int main(int argc, char *argv[])
{
	ifstream inf("ariprog.in");
	ofstream ouf("ariprog.out");
    set<int> allPossibleS;
    int N = 0, M = 0;
    inf >> N >> M;

    for (int i = 0; i <= M; ++i)
    {
        for (int j = 0; j <= M; ++j)
        {
            allPossibleS.insert(i * i + j * j);
        }
    }

    vector<int> allPossibleV(allPossibleS.begin(), allPossibleS.end());
    vector<int> diffV;
    vector<pair<int, int>> result;

    for (int i = 0; i < allPossibleV.size() - 1; ++i)
    {
        /* code */
        diffV.push_back(allPossibleV[i + 1] - allPossibleV[i]);
    }

    set<int> diffS(diffV.begin(), diffV.end());

    for (int i = 0; i < allPossibleV.size() - N + 1; ++i)
    {
        /* code */
        int k = i;
        for (int j = diffV[i]; j < allPossibleV.back() / (N - 1) + 1; )
        {
            /* code */
            create(N, i, j, allPossibleV, allPossibleS, diffV, result);
            if (diffV[k + 1] == 0)
            {
                /* code */
                break;
            }
            j += diffV[++k];
        }
    }

    sort(result.begin(), result.end(), compareSecond);

    if (result.size() == 0)
    {
        /* code */
        ouf << "NONE" << endl;
    }else {
        for(pair<int, int> p : result) {
            ouf << p.first << ' ' << p.second << endl;
        }
    }

//    for(int i : diffV) {
//        cout << i << endl;
//    }

	return 0;
}
