#include<bits/stdc++.h>
using namespace std;

int main(){
    string digits = "23";
    vector<string>re;//存储最终的结果
    // 初始化所有的按键
    map<char,string >button;
    button['2'] = "abc";
    button['3'] = "def";
    button['4'] = "ghi";
    button['5'] = "jkl";
    button['6'] = "mno";
    button['7'] = "pqrs";
    button['8'] = "tuv";
    button['9'] = "wxyz";
    if(digits.size()==0){
        cout<<"空";
        return 0;
    }
    char c = digits[0];
    // 初始化最初的re
    for(int i=0;i<button[c].length();i++){
        char t[2] = {button[c][i]};//string只能将char*类型转化，而不是char
        re.push_back(t);//该处应该有问题
    }

    for(int i=1;i<digits.length();i++){//遍历re，形成新的组合
        char key = digits[i];
        string words = button[key];
        vector<string>tmp;
        for(int j=0;j<re.size();j++){
            string s = re[j];
            for(int k=0;k<words.length();k++){
                tmp.push_back(s+words[k]);//拼接形成新的串
            }
        }
        re.clear();
        re = tmp;//更新
    }
    for(vector<string>::iterator it=re.begin();it!=re.end();it++){
        cout<<*it<<'\n';
    }
    return 0;
}