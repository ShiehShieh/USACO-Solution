/*
 ID: ShiehShieh
 PROG: friday
 LANG: C++11
 */
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main(int argc, char *argv[])
{
	ifstream inf("friday.in");
	ofstream ouf("friday.out");
    map<int, int> result;
    int week = 1;
    int N = 0;

    inf >> N;

    inf.close();

    for (int nowYear = 1900; nowYear < 1900 + N; ++nowYear) {
        if ((nowYear % 4 != 0) || (nowYear % 100 == 0 && nowYear % 400 != 0)) {
            for (int nowMonth = 1; nowMonth < 13; ++nowMonth) {
                if (nowMonth == 1 || nowMonth == 3 || nowMonth == 5 || nowMonth == 7 || nowMonth == 8 || nowMonth == 10 || nowMonth == 12) {
                    for (int nowDay = 1; nowDay < 32; ++nowDay) {
                        if (nowDay == 13){
                            ++result[week];
                        }
                        week %= 7;
                        ++week;
                    }
                }else if(nowMonth == 2) {
                    for (int nowDay = 1; nowDay < 29; ++nowDay) {
                        if (nowDay == 13){
                            ++result[week];
                        }
                        week %= 7;
                        ++week;
                    }
                }else {
                    for (int nowDay = 1; nowDay < 31; ++nowDay) {
                        if (nowDay == 13){
                            ++result[week];
                        }
                        week %= 7;
                        ++week;
                    }
                }
            }
        }else {
            for (int nowMonth = 1; nowMonth < 13; ++nowMonth) {
                if (nowMonth == 1 || nowMonth == 3 || nowMonth == 5 || nowMonth == 7 || nowMonth == 8 || nowMonth == 10 || nowMonth == 12) {
                    for (int nowDay = 1; nowDay < 32; ++nowDay) {
                        if (nowDay == 13){
                            ++result[week];
                        }
                        week %= 7;
                        ++week;
                    }
                }else if(nowMonth == 2) {
                    for (int nowDay = 1; nowDay < 30; ++nowDay) {
                        if (nowDay == 13){
                            ++result[week];
                        }
                        week %= 7;
                        ++week;
                    }
                }else {
                    for (int nowDay = 1; nowDay < 31; ++nowDay) {
                        if (nowDay == 13){
                            ++result[week];
                        }
                        week %= 7;
                        ++week;
                    }
                }
            }
        }
    }

    ouf << result[6] << ' ' << result[7] << ' ' << result[1] << ' ' << result[2] << ' ' << result[3] << ' ' << result[4] << ' ' << result[5] << endl;

    ouf.close();

	return 0;
}
