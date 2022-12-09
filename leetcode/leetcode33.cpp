#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>nums = {1};
    int target = 0;
    int l = 0, r = nums.size()-1;
    int k;
    int flag = -1;
    while(l<=r){
        k = (l+r)/2;
        if(nums[k]==target){
            flag = k;
            break;
        }
        if(nums[l]<nums[k]){
            // 连续单增区间
            if(nums[l]<=target && target<nums[k]){
                r = k-1;
                continue;
            }
        }
        if(nums[k]<nums[r]){
            if(nums[k]<target && target<=nums[r]){
                l = k+1;
                continue;
            }
        }
        if(nums[l]>nums[k]){
            r = k-1;
            continue;
        }
        if(nums[k]>nums[r]){
            l = k+1;
            continue;
        }
        break;//上述几个条件都不满足，所以无解
    }
    cout<<flag;
    return 0;
}
