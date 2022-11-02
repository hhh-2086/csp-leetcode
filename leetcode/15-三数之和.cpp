// 三数之和。
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int data[] = {-1,0,1,2,-1,-4,-2,-3,3,0,4};
    int len = sizeof(data) / sizeof(data[0]);//数组的长度
    
    // 首先将data进行排序
    // c++中自带的sort函数
    sort(data,data+len,less<int>());//升序排序

    int L1 = 0;
    int R1 = len;
    for(int i=0;i<len;i++){
        // 去除重复元素的循环
        if(i>0 and data[i]==data[i-1]){
            continue;
        }
        if(data[i]>0){
            break;//全都是正数，相加不可能等于0
        }
        int L = i+1;
        int R = len-1;
        while(L<R){
            int v = data[i]+data[L]+data[R]; 
            if(v<0){
                L++;//左边指针右移
            }
            else if(v>0){
                R--;//右边指针左移
            }
            else if(v==0 ){
            // 输出对应的数字
                // 去除该循环的重复元素
                if(L1>0 and data[L1]==data[L] and data[R1]==data[R]){
                    L++;
                    continue;
                }
                L1 = L;
                R1 = R;
                cout<<data[i]<<' '<<data[L]<<' '<<data[R]<<'\n';
                // 继续进行循环，L++或R--都可以
                L++;
            }
            
        }
    }

    return 0;
}