/*
 ID: ShiehShieh
 PROG: transform
 LANG: C++11
 */

#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void rotate270(char **sour,int n,char **destin);
void rotate180(char **sour,int n,char **destin);
void rotate90(char **sour,int n,char **destin);
void reflection(char **sour,int n, char **destin);
int isequal(char **p1,char **p2,int n);
int main()
{
    FILE *fin = fopen("transform.in","r"), *fout = fopen("transform.out","w");

    int n;
    fscanf(fin,"%d",&n);

    char **tmp = new char*[n];
    char** des=new char*[n]; //用来计算的
    char** p1=new char*[n];  //存储读入的转换前矩阵
    char** p2=new char*[n];  //存储读入的转换后矩阵,
    char *line = new char[n+1];

    for(int i=0;i<n;i++)
    {  
        *(tmp+i)=new char[n];
        *(des+i)=new char[n];
        *(p1+i)=new char[n];
        *(p2+i)=new char[n];
    }

    for(int i = 0; i<n; i++)
    {  
        fscanf(fin,"%s",line);
        for(int j=0;j<n;j++)
        {
            p1[i][j]=line[j];
            des[i][j]=line[j];
        }
    }
    for(int i = 0; i<n; i++)
    {  
        fscanf(fin,"%s",line);
        for(int j=0;j<n;j++){
            p2[i][j]=line[j];
        }
    }
    //上面输入
    rotate90(p1,n,des);
    if(isequal(p2,des,n) == 1)
    {

        fprintf(fout,"%d\n",1);
        fclose(fin);fclose(fout);
        return 0;
    }

    rotate180(p1,n,des);
    if(isequal(p2,des,n) == 1)
    {

        fprintf(fout,"%d\n",2);fclose(fin);fclose(fout);
        return 0;
    }

    rotate270(p1,n,des);
    if(isequal(p2,des,n) == 1)
    {

        fprintf(fout,"%d\n",3);fclose(fin);fclose(fout);
        return 0;
    }

    reflection(p1,n,des);
    if(isequal(p2,des,n) == 1)
    {
        fprintf(fout,"%d\n",4);fclose(fin);fclose(fout);
        return 0;
    }

    reflection(p1,n,des);
    rotate90(des,n,tmp);
    if(isequal(p2,tmp,n) == 1)
    {

        fprintf(fout,"%d\n",5);fclose(fin);fclose(fout);
        return 0;
    }

    reflection(p1,n,des);
    rotate180(des,n,tmp);
    if(isequal(p2,tmp,n) == 1)
    {

        fprintf(fout,"%d\n",5);fclose(fin);fclose(fout);
        return 0;
    }

    reflection(p1,n,des);
    rotate270(des,n,tmp);
    if(isequal(p2,tmp,n) == 1)
    {

        fprintf(fout,"%d\n",5);fclose(fin);fclose(fout);
        return 0;
    }

    if(isequal(p1,p2,n) == 1)
    {

        fprintf(fout,"%d\n",6);fclose(fin);fclose(fout);
        return 0;
    }

    fprintf(fout,"%d\n",7);
    fclose(fin);fclose(fout);
    return 0;


}

void rotate90(char **sour,int n,char **destin)   //旋转90度
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            destin[j][n-1-i] = sour[i][j]; 
        }
    }
}

void rotate180(char **sour,int n,char **destin)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            destin[n-1-i][n-1-j] = sour[i][j]; 
        }
    }
}

void rotate270(char **sour,int n,char **destin)   //旋转270度
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            destin[n-1-j][i] = sour[i][j]; 
        }
    }
}


void reflection(char **sour,int n, char **destin)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            destin[i][n-1-j] = sour[i][j]; 
        }
    }
}

int isequal(char **p1,char **p2,int n)         //判断数组是否相等
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(p1[i][j] != p2[i][j])
            {
                return 0;
            }
        }
    }

    return 1;
}