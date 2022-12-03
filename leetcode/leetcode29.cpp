#include <bits/stdc++.h>
using namespace std;

int main()
{
    int dividend = 10;
    int divisor = 3;

// 几类特殊情况
    if(dividend==0){//被除数为0
        return 0;
    }
    if(divisor == 1){
        return dividend;
    }
    if(divisor == -1){
        return -dividend;
    }
    if(divisor == INT_MIN){//除数为最小值
        return dividend == INT_MIN?1:0;
    }

// 只考虑一种情况
    bool flag = 1;//决定结果的正负
    if(dividend>0){
        dividend = -dividend;
        flag = !flag;
    }
    if(divisor>0){
        divisor = -divisor;
        flag = !flag;
    }

    vector<int>candidates;
    candidates.push_back(divisor);
    int sum = divisor;
    // 注意溢出
    while (candidates.back() >= dividend - candidates.back()) {
        candidates.push_back(candidates.back() + candidates.back());
        cout<<candidates.back();
    }
    int ans = 0;
    for(int i = candidates.size()-1;i>=0;i--){
        if(candidates[i]>=dividend){
            ans += (1<<i);
        }
        dividend -= candidates[i];
    }

    ans = flag==1?ans:-ans;
    cout<<ans;
    system("pause");
    return 0;
}
