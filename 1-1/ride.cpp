/*
ID: ShiehShieh
PROG: ride
LANG: C++
*/
#include <fstream>
#include <string>

int main(int argc, char *argv[])
{
	std::ifstream inf("ride.in");
	std::ofstream ouf("ride.out");
	std::string comet;
	std::string group;

	inf >> comet >> group;
    
    int numComet = 1;
    int numGroup = 1;
    
    for (char c : comet) {
        numComet *= c - 'A' + 1;
    }
    
    for (char c : group) {
        numGroup *= c - 'A' + 1;
    }
    
    std::cout << numComet << ',' << numGroup << std::endl;

	return 0;
}
