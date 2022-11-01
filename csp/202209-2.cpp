#include<iostream>
using namespace std;

int f[300001] = {0};
int len = 300000;
int main(){
    f[0] = 1;
    int n,m;
    cin>>n>>m;//一共n本书，m是包邮价格
    for(int i=0;i<n;i++){
        int a;//书的价格
        cin>>a;
        for(int j = len;j>=a;j--){
            if(f[j-a]==1){
                f[j] = 1;
            }
        }
    }
    int k = m;
    for(k;f[k]!=1;k++);
    cout<<k;
    return 0;
}