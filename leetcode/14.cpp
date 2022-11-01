#include<iostream>
using namespace std;
#include<vector>

int main(){

    vector<string>strs;// = {"flower","flow","flight"};
    strs.push_back("cir");
    strs.push_back("car");
    // strs.push_back("flight");

    string f = strs[0]; //取出第一个字符
    // 创建对应的数字
    int len = f.length();
    // cout<<len;
    char all[len] = {0};
    for(int i=0;i<len;i++){
        all[i] = f[i];
    }
    // 开始逐个对比
    for(int j=1;j<strs.size();j++){//遍历所有的字符串
        if(len>strs[j].length()){
            len = int(strs[j].length());//取小的长度
        }
        int d  = 0;
        for(int k = len-1;k>=0;k--){
            string t = strs[j];
            d++;
            if(all[k] != t[k]){
                len-=d;//缩小串的长度
                d = 0;
            }
        }
        if(len==0)break;
    }
    for(int i=0;i<len;i++){
        cout<<all[i];
    }

    return 0;
}
