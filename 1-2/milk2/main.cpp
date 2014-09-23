/*
 ID: ShiehShieh
 PROG: milk2
 LANG: C++11
 */
#include<iostream>
#include<fstream>
#include<algorithm>

using namespace std;

struct milkedtime{
	int begin,end;
};

milkedtime ar[5005];

struct savemilkedtime{
	int begin,end;
	savemilkedtime *next;
};
savemilkedtime *root;
int n,MaxMilking,MaxNoMilking;

int cmp(milkedtime p,milkedtime q){
if(p.begin==q.begin)
return p.end<q.end;
return p.begin<q.begin;
}

void save(int x){
savemilkedtime *h=root;
savemilkedtime *t=new savemilkedtime();
int flag=1;
while(h->next!=NULL){
h=h->next;
if(flag && h->end>=ar[x].begin){//将该时间段更新
h->end=h->end>ar[x].end?h->end:ar[x].end;
flag=0;
}
if(!flag){
while(h->next!=NULL){//更新或删除后面的节点
savemilkedtime *t;
t=h->next;
if(t->begin<=h->end){
h->end=h->end>t->end?h->end:t->end;
h->next=t->next;
delete t;
}
}
break;
}
}
if(flag && h->next==NULL){//没有出现合并的情况
savemilkedtime *t=new savemilkedtime();
t->begin=ar[x].begin;
t->end=ar[x].end;
h->next=t;
t->next=NULL;
return;
}
}

void make(){
int i;
root=new savemilkedtime();
root->next=NULL;
    for(i=0;i<n;i++)
save(i);
}

void output(){//统计
    savemilkedtime *h,*t=root;
MaxMilking=0;MaxNoMilking=0;
while(t->next!=NULL){
t=t->next;
if(MaxMilking<t->end-t->begin)
MaxMilking=t->end-t->begin;
if(t->next!=NULL){
h=t->next;
if(MaxNoMilking<h->begin-t->end)
MaxNoMilking=h->begin-t->end;
}
}
}

int main(){
int i;
ifstream fin("milk2.in");
ofstream fout("milk2.out");
fin>>n;
for(i=0;i<n;i++)
fin>>ar[i].begin>>ar[i].end;
sort(ar,ar+n,cmp);
make();
output();
fout<<MaxMilking<<" "<<MaxNoMilking<<endl;
return 0;
}
