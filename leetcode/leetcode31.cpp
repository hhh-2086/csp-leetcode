#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>nums = {1,5,1};
    int nums_size = nums.size();
    if(nums_size==1){
        return 0;
    }
    int loc = nums_size-2;

    while(loc>=0){//定位到递减序列的位置
        if(nums[loc]>=nums[loc+1]){ loc--; }
        else{break;}
    }
    if(loc == -1){
        sort(nums.begin(),nums.end());
        return 0;
    }
    // loc指向的位置就是要开始更改的位置
    int j;
    int d = INT_MAX;
    for(int i=loc+1; i<nums_size; i++){
        if(nums[i] - nums[loc] < d && nums[i] - nums[loc] > 0){
            d = nums[i]-nums[loc];
            j = i;
        }
    }

    // 交换loc和j对应的数字，然后后面递增排列
    int  tmp = nums[loc];
    nums[loc] = nums[j];
    nums[j] = tmp;
    sort(nums.begin()+loc+1,nums.end());

    // 输出nums的值
    for(int &i:nums){
        cout<<i<<' ';
    }
    system("pause");
    return 0;
}
