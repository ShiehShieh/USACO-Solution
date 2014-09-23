/*
 ID: ShiehShieh
 PROG: fracdec
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <set>


using namespace std;


string to_str(int number)
{
	stringstream s;
	s << number;
	string str = s.str();

	return str;
}


int main(int argc, char const *argv[])
{
	ifstream inf("fracdec.in");
	ofstream ouf("fracdec.out");
	bool mark = true;
	int N = 0, D = 0, carry = 0, quotient = 0, k = 0, sl = 0;
	string resultString, repeated, ch;
	set<pair<int, int>> present;

	inf >> N >> D;

	if (present.insert(make_pair(0, N)).second == false)
	{
		repeated += to_str(0);
		if (mark)
		{
			k = N;
			mark = false;
		}
	}

	if (N < D)
	{
		resultString += "0.";
		N *= 10;
		while(N < D) {
			if (present.insert(make_pair(0, N)).second == false)
			{
				repeated += to_str(0);
				if (mark)
				{
					k = N;
					mark = false;
				}
			}
			resultString += '0';
			N *= 10;
		}

		carry = N;
		do{
			quotient = carry / D;
			carry = carry % D;
			carry *= 10;
			if (carry == k && carry != 0)
			{
				string output;
				if (repeated.length() == 1)
				{
					if (resultString.substr(resultString.length() - 2, 1) == repeated)
					{
						sl = 0;
						output = resultString.substr(0, resultString.length() - repeated.length() - 1) + '(' + repeated + ')';
						while(sl < output.length()) {
							ouf << output.substr(sl, 76) << endl;
							sl += 76;
						}
					}else {
						sl = 0;
						output = resultString.substr(0, resultString.length() - repeated.length()) + '(' + repeated + ')';
						while(sl < output.length()) {
							ouf << output.substr(sl, 76) << endl;
							sl += 76;
						}
					}
				}else {
					sl = 0;
					output = resultString.substr(0, resultString.length() - 2 * repeated.length()) + '(' + repeated + ')';
					while(sl < output.length()) {
						ouf << output.substr(sl, 76) << endl;
						sl += 76;
					}
				}
				exit(0);
			}
			if (present.insert(make_pair(quotient, carry)).second == false)
			{
				repeated += to_str(quotient);
				if (mark)
				{
					k = carry;
					mark = false;
				}
			}
			ch = to_str(quotient);
			resultString += ch;
			while(carry < D && carry != 0) {
				if (present.insert(make_pair(0, carry)).second == false)
				{
					repeated += to_str(0);
				}
				resultString += '0';
				carry *= 10;
			}
		}while(carry);

	}else if (N >= D)
	{
		carry = N;
		do{
			quotient = carry / D;
			carry = carry % D;
			if (present.insert(make_pair(quotient, carry)).second == false)
			{
				repeated += to_str(quotient);
				if (mark)
				{
					k = carry;
					mark = false;
				}
			}
			ch = to_str(quotient);
			resultString += ch;
		}while(carry && carry > D);
		if (carry < D && carry != 0)
		{
			resultString += ".";
			carry *= 10;
			while(carry < D) {
				if (present.insert(make_pair(0, carry)).second == false)
				{
					repeated += to_str(0);
					if (mark)
					{
						k = carry;
						mark = false;
					}
				}
				resultString += '0';
				carry *= 10;
			}

			do{
				quotient = carry / D;
				carry = carry % D;
				carry *= 10;
				if (carry == k && carry != 0)
				{
					string output;
					if (repeated.length() == 1)
					{
						if (resultString.substr(resultString.length() - 2, 1) == repeated)
						{
							sl = 0;
							output = resultString.substr(0, resultString.length() - repeated.length() - 1) + '(' + repeated + ')';
							while(sl < output.length()) {
								ouf << output.substr(sl, 76) << endl;
								sl += 76;
							}
						}else {
							sl = 0;
							output = resultString.substr(0, resultString.length() - repeated.length()) + '(' + repeated + ')';
							while(sl < output.length()) {
								ouf << output.substr(sl, 76) << endl;
								sl += 76;
							}
						}
					}else {
						sl = 0;
						output = resultString.substr(0, resultString.length() - 2 * repeated.length()) + '(' + repeated + ')';
						while(sl < output.length()) {
							ouf << output.substr(sl, 76) << endl;
							sl += 76;
						}
					}
					exit(0);
				}
				if (present.insert(make_pair(quotient, carry)).second == false)
				{
					repeated += to_str(quotient);
					if (mark)
					{
						k = carry;
						mark = false;
					}
				}
				ch = to_str(quotient);
				resultString += ch;
				while(carry < D && carry != 0) {
					if (present.insert(make_pair(0, carry)).second == false)
					{
						repeated += to_str(0);
					}
					resultString += '0';
					carry *= 10;
				}
			}while(carry);
		}else {
			resultString += ".0";
		}
	}

	ouf << resultString << endl;

	return 0;
}
