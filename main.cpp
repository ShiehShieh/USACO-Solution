/*
ID:ShiehShieh
PROG:dualpal
LANG:C++
*/
#include <fstream>


using namespace std;
 
 
int thehui(int i,int j){
    int s[20];
    int h=0;
    while ( i!=0 ){
        s[h]=i%j;
        i/=j;
        h++;
    }
    int lt;
    for ( lt=0; lt<h ; lt ++ ) {
        if ( s[lt]!=s[h-lt-1] ) return 1;
    }
    return 0;
} 


int hui(int i){
    int j,num=0;
    for (j=2;j<=10;j++){
        if ( thehui(i,j)==0 ) {
            num++;
            if ( num==2 ) return 0;}
        }
    return 1;
}
 
int main () {
    ifstream fin("dualpal.in");
    ofstream fout("dualpal.out");
    int n,s;
    fin >> n >> s;
    int num=0,i=s;
    while ( num < n ) {
        i++;
        if ( hui(i)==0 ) {
            num++;
            fout << i << endl;
        }
    }
    return 0;
}
