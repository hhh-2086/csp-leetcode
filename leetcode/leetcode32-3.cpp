#include <bits/stdc++.h>
using namespace std;

// 动态规划！
int main()
{
    string s = "()(())";

    int slength = s.length();
    if(slength<=1){
        return 0;
    }
    int dp[slength+1] = {0};
    int result = 0;
    // s从0开始，dp从1开始
    for(int i=1;i<slength;i++){
        if(s[i]==')'){
            if(s[i-1]=='('){
                dp[i+1] = dp[i-1]+2;
                result = max(result,dp[i+1]);
            }
            else{
                if(i-dp[i]-1>=0 && s[i-dp[i]-1]=='('){//可以匹配
                    dp[i+1] += dp[i-dp[i]-1]+dp[i]+2;
                    result = max(dp[i+1],result);
                }
            }
        }
    }
    cout<<result;
    system("pause");
    return 0;
}
