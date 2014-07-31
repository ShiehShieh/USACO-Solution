/*
ID:ShiehShieh
LANG:C++
TASK:subset
*/
 
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
long long a[40][40*(40+1)/2]; 
int main(){
	freopen("subset.in", "r", stdin);
	freopen("subset.out", "w", stdout);
	int i,j,n;
	a[1][1] = 1;
	scanf("%d",&n);
	if(n*(n+1)%4!=0) {printf("0\n"); return 0;}
	for(int i = 2; i <= 39; i++)
		for(int j = 1; j <= i*(i+1)/2; j++){
			if(i>n) goto out; 
			if(j < i)	a[i][j] = a[i-1][j];
			else if(j == i) a[i][j] = a[i-1][j]+1;
			else if(j > i) a[i][j] = a[i-1][j] + a[i-1][j-i]; 
 
		} 
	out:;
    if(n*(n+1)%4==0) printf("%lld\n",a[n][n*(n+1)/2/2]/2);  
    else printf("0\n"); 
}
