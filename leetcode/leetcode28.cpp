#include <bits/stdc++.h>
using namespace std;

int main()
{
    string haystack = "sadbutsad";
    string needle = "aaabbcd";
    int n = haystack.size();
    int m = needle.size();
    if(m == 0){
        return 0;
    }
    int next[m];
    next[0] = -1;
    // 初始化next
    for(int i=1,j=-1;i<m;i++){
        while (j>=0 && needle[i]!=needle[j+1])
        {
            j = next[j];//向前回溯
        }
        if(needle[i]==needle[j+1]){//找到相同的前后缀
            j++;
        }
        next[i] = j;//将j（前缀的长度）赋给next[i]
    }

    // 匹配
    for(int i=0,j=-1;i<n;i++){
        while (j>=0 && haystack[i]!=needle[j+1])
        {
            j = next[j];//寻找之前匹配的位置
        }
        if(haystack[i] == needle[j+1]){
            j++;
        }
        if(j==m-1){//匹配到了模式串
            cout<< i-m+1;
            return 0;
        }
    }
    cout<<"无";
    system("pause");
    return 0;
}
