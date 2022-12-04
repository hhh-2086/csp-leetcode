// 利用vector 70%
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,L,S;
    cin>>n>>L>>S;
    int dataA[L+1][L+1] = {0};
    vector<pair<int,int> >data;
    for(int i=0;i<n;i++){
        int j1,j2;
        cin>>j1>>j2;
        dataA[j1][j2] = 1;
        // if(j1+S>L || j2+S>L){//确保所有的点作为B的原点之后都不越界
        //     continue;
        // }
        data.push_back(make_pair(j1,j2));
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
/*计算次数大概为n*s*s
    // 遍历A中每一个1的位置对B进行匹配
    int size = data.size();
    for(int i=0;i<size;i++){
        int r,c;
        r = data[i].first;
        c = data[i].second;
        int f=1;
        for(int j1=0;j1<=S;j1++){
            for(int j2=0;j2<=S;j2++){
                if(flag[j1][j2]!=dataA[r+j1][c+j2]){
                    f=0;
                }
            }
        }
        if(f==1){
            re+=1;
        }
    }
*/

// 计算次数为n*n
    int size = data.size();
    for(int i=0;i<size;i++){
        int r,c;
        r = data[i].first;
        c = data[i].second;
        if(r+S>L or c+S>L){
            continue;
        }
        int f=1;
        int s=0;
        for(int j=0;j<size;j++){
            int rowB = data[j].first-r;
            int colB = data[j].second-c;
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