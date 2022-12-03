#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n = 4;
    vector<vector<string> >dp(n+1);
    vector<string>t1(1);
    vector<string>t2(1);
    t1[0] = {""};
    t2[0] = {"()"};
    dp[0] = (t1);
	dp[1] = (t2);
    
    for(int l=2;l<=n;l++){
        vector<string> t;
        for(int i=0;i<l;i++){
            int j = l-1-i;
            for(vector<string>::iterator k1=dp[i].begin(); k1!=dp[i].end(); k1++){
                for(vector<string>::iterator k2=dp[j].begin(); k2!=dp[j].end(); k2++){
                    t.push_back('('+*k1+')'+*k2);
                }
            }
        }
        dp[l] = t;
    }

    for(vector<string>::iterator k=dp[n].begin(); k!=dp[n].end(); k++){
        cout<<*k<<'\n';
    }

    system("pause");
    return 0;
}
