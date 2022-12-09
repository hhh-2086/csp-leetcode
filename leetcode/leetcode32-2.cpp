#include <bits/stdc++.h>
using namespace std;
// 用栈解决问题
int main()
{
    string s = "((())((()())";
    stack<int>data;
    data.push(-1);
    int result = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            data.push(i);//入栈
        }
        else{
            data.pop();//出栈
            if(data.empty()){//说明没有匹配，重新入栈作最后一个不被匹配的元素
                data.push(i);
            }
            else{//成功匹配，计算本次连续的括号数量
                result = max(result,i-data.top());
            }
        }
    }
    cout<<result;
    system("pause");
    return 0;
}
