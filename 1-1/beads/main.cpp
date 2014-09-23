/*
 ID: ShiehShieh
 PROG: beads
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int checkout(string& neck, int index) {
    int i = index;
    int result = 0;
    char next;
    char standard = neck[i];

    do {
        if (i == neck.length() - 1) {
            next = neck[0];
            i = -1;
        }else {
            next = neck[i + 1];
        }
        ++i;
        ++result;
        if (result == neck.length()) {
            return result;
        }
    }while(next == standard || next == 'w');

    i = index;
    do {
        if (i == 0) {
            standard = neck[neck.length() - 1];
            i = neck.length();
        }else {
            standard = neck[i - 1];
        }
        --i;
        if (result == neck.length()) {
            return result;
        }
        ++result;
    }while(standard == 'w');

    do {
        if (i == 0) {
            next = neck[neck.length() - 1];
            i = neck.length();
        }else {
            next = neck[i - 1];
        }
        --i;
        if (!(next == standard || next == 'w') || result == neck.length()) {
            return result;
        }
        ++result;
    }while(true);

    return result;
}

int main(int argc, char *argv[])
{
	ifstream inf("beads.in");
	ofstream ouf("beads.out");
    int N = 0;
    vector<int> v;
    string necklace;

    inf >> N >> necklace;

    string doubleNecklace = necklace;

    for (int i = 0; i < N; ++i) {
        v.push_back(checkout(necklace, i));
    }

    int maxNumber = v[0];

    for (vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
        if (*i > maxNumber) {
            maxNumber = *i;
        }
    }

    ouf << maxNumber << endl;

	return 0;
}
