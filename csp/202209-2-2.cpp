#include<iostream>
#include<math.h>
using namespace std;
int N = 0;
int M = 0;
int re = 3e5;//所有书和的最大值
void dfs(int k,int sum,int *price,int *sum_price){
    if(sum>=M){
        re = min(sum,re);
    }
    if(k>=N){
        return;//遍历到了最后一本书
    }
    // 剪枝操作
    if(sum+sum_price[N-1]-sum_price[k]+price[k]<M){
        return;
    }

    dfs(k+1,sum+price[k],price,sum_price);//选择这本书
    dfs(k+1,sum,price,sum_price);//不选这本书
}

int main(){
    int n,m;
    cin>>n>>m;//一共n本书，m是包邮价格
    N = n;//全局变量
    M = m;
    int price[n] = {0};
    int sum_price[n] = {0};//价格的前缀和
    int s = 0;
    for(int i=0;i<n;i++){
        cin>>price[i];
        s += price[i];
        sum_price[i] = s;
    }
    dfs(0,0,price,sum_price);
    cout<<re;//输出最终的结果
    return 0;
}