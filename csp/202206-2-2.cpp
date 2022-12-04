// 利用c++数组，100%
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,L,S;
    cin>>n>>L>>S;
    int data[n][2] = {0};
    for(int i=0;i<n;i++){
        int j1,j2;
        cin>>j1>>j2;
        data[i][0]=j1;
        data[i][1]=j2;
    }
    int flag[S+1][S+1];
    int numB = 0;
    for(int i=S;i>=0;i--){
        for(int j=0;j<=S;j++){
            cin>>flag[i][j];
            if(flag[i][j]==1){
                numB++;//统计B中1的数量
            }
        }
    }
    int re=0;//最终的结果

// 计算次数为n*n
    int size = n;
    for(int i=0;i<size;i++){
        int r,c;
        r = data[i][0];
        c = data[i][1];
        if(r+S>L or c+S>L){
            continue;
        }
        int f=1;
        int s=0;
        for(int j=0;j<size;j++){
            int rowB = data[j][0]-r;
            int colB = data[j][1]-c;
            if(rowB>=0 and rowB<=S and colB>=0 and colB<=S){
                s++;//A中对应的B的大小部分，1的数量
                if(flag[rowB][colB]==0){
                    f=0;
                    break;
                }
            }
        }
        if(f==1 and s==numB){
            re+=1;
        }
    }
    cout<<re;

    return 0;
}