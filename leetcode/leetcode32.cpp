#include <bits/stdc++.h>
using namespace std;
int bracket(string &s,int loc){
    int flag = 1;
    loc++;
    while(flag != 0 && loc<s.size()){
        if(s[loc]=='(')flag++;
        else flag--;

        loc++;
    }
    if(flag!=0)return -1;
    return loc;//返回对应的）所在的位置
}
int main()
{
    string s = "((())((()())";
    int i=0;
    int slength = s.size();
    for(i;s[i]==')' && i<slength;i++);

    int count = 0;
    int result = 0;

    int loc = -1;
    while(i<slength){
        if(s[i]=='('){
            loc = bracket(s,i);
            if(loc!=-1){
                count += loc-i;
                result = count>result?count:result;
                i = loc;//开始新的位置
            }
            else{
                i++;
                count = 0;
            }
        }
        else{
            i++;
            count = 0;
        }
    }
    cout<<result;
    system("pause");
    return 0;
}
