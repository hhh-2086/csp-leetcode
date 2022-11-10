// 最接近的三数之和
// 三数之和。
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int data[] = {1,1,1,1};
    int target = 0;
    int len = sizeof(data) / sizeof(data[0]);//数组的长度
    
    // 首先将data进行排序
    // c++中自带的sort函数
    sort(data,data+len,less<int>());//升序排序
    int x = 10e7;
    for(int i=0;i<len;i++){
        // 去除重复元素的循环
        if(i>0 and data[i]==data[i-1]){
            continue;
        }

        int L = i+1;
        int R = len-1;
        while(L<R){
            int v = data[i]+data[L]+data[R];
            if(abs(target-x) > abs(target-v)){
                x = v;//更新本轮循环中最接近的值
            }
            if(v<target){
                L++;//左边指针右移
            }
            else if(v>target){
                R--;//右边指针左移
            }
            else if(v==target){
                cout<<target;
                return 0;//直接结束
            }
            
        }
    }
    cout<<x;//输出最后的结果

    return 0;
}