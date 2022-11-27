#include<bits/stdc++.h>
using namespace std;
int main(){
    int target = -7;
    int data[]={-1,-5,-5,-3,2,5,0,4};
    int n = 8;
    vector<int>nums(data,data+n);
    // 非降序排序
    sort(nums.begin(),nums.end());
    // 双指针
    float p1=0.1,p2=0.1;
    for(vector<int>::iterator i=nums.begin();i!=nums.end();i++){
        for(vector<int>::iterator j=i+1;j!=nums.end();j++){
            if(p1==*i and p2==*j){
                continue;
            }
            p1=*i;
            p2=*j;
            vector<int>::iterator k1 = j+1;
            vector<int>::iterator k2 = nums.end()-1;
            float t1=0.1,t2=0.1;
            while (k1<k2)
            {
                int sum = *i+*j+*k1+*k2;
                if(sum==target){
                    if(*k1==t1 and *k2==t2){
                        k1++;
                        continue;
                    }
                    cout<<*i<<' '<<*j<<' '<<*k1<<' '<<*k2<<'\n';
                    t1=*k1;
                    t2=*k2;
                    k1++;
                }
                else if(sum<target){
                    k1++;
                }
                else{
                    k2--;
                }
            }
        }
    }
    return 0;
}