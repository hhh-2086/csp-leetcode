#include<iostream>
using namespace std;
#include<vector>
int main(){
    int a[9] = {1,8,6,2,5,4,8,3,7};
    vector<int>height(a,a+9);
    int i,j;
    i = 0;
    j = height.size()-1; //获取数组长度
    int area = 0; //面积
    int t=0;
    while(i<j){
        if(height[i]<height[j]){
            t = height[i]*(j-i);
        }
        else{
            t = height[j]*(j-i);
        }
        if(t>area){area = t;}
        // 短边向内部移动
        if(height[i]<height[j]){
            i+=1;
        }
        else{
            j-=1;
        }
        if(i>=j)break;
    }
    cout<<area;
    return 0;
}