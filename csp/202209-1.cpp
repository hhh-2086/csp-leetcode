#include<iostream>
using namespace std;
int main(){
	unsigned int n,m;
	cin>>n>>m;
	int b[n] = {0};
	int a[n] = {0}; //a0=1 
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
//	主要代码部分 
	int c = 1;
	int x = 0;
	int c1 = 0;
	for(int i=0;i<n;i++){
		c1 = c*a[i];//下一个c的值 
		b[i] = (m%c1-x)/c;
		x = x+c*b[i];//更新已知的被减数 
		c = c1;//更新c的值 
	}
//	主要代码部分结束 
	for(int i=0;i<n;i++){
		cout<<b[i]<<' ';
	} 
	return 0; 
} 
//样例输入：
/* 
15 32767
2 2 2 2 2 2 2 2 2 2 2 2 2 2 2
*/ 
