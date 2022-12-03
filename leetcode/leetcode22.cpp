#include<bits/stdc++.h>
using namespace std;
void brackets(int left,int right,char *data,int step,vector<string> &re){
    /*递归函数，生成n对括号
    输入为剩余的左括号数量和右括号数量
    当左右括号剩余都为0时，输出对应的字符串,字符串用data存储
    */
    if(left>0){
            data[step] = '(';
            brackets(left-1,right,data,step+1,re);
    }
    if(right>0 and left<=right){
            data[step] = ')';
            brackets(left,right-1,data,step+1,re);
    }
    if(left==0 and right==0){
            //括号匹配一次，
            string s(data,data+step+1);
            re.push_back(s);
    }
}
int main(){
    int n=3;
    vector<string>re;
    char data[2*n];
    data[0] = '(';
    data[2*n-1] = ')';
    brackets(n-1,n-1,data,1,re);
    for(vector<string>::iterator it = re.begin();it!=re.end();it++){
        cout<<*it<<'\n';
    }
    return 0;
}