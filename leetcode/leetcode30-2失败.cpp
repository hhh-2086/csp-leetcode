#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 滑动窗口解决问题
    string s = "thethethethe";
    // cin>>s;
    vector<string> words = {"foo","foo","the","man"};
    // 最终结果储存
    vector<int>res;
    // slength为s长度，word_size为单词长度，最后为单词个数
    int slength = s.size(),word_size = words[0].size(),words_num = words.size();
    // 创建对应的值
    map<string,int>word_code;
    for(int i=0; i<words_num; i++){
        word_code[words[i]] = i;
    }
    int true_code = 0;
    // 因为不能保证，words中单词不重复，所以要遍历计算真正的code值。
    for(string &word:words){
        true_code += pow(2,word_code[word]);
    }
    int code = 0;
    for(int i = 0; i < word_size && i + words_num*word_size <= slength; i++){
        // 开始计算code
        code = 0;
        for(int j=0; j<words_num;j++){
            // i开始切割出来words_num个单词
            string word = s.substr(i+j*word_size,word_size);
            if(word_code.count(word)){
                code += pow(2,word_code[word]);
            }
        }
        if(code == true_code){
            res.push_back(i);
        }
        
        // 开始滑动窗口
        for(int k = i+word_size; k<slength+1-word_size*words_num; k+=word_size){
            // 滑动窗口划走的单词--，新进入的单词++
            string word;
            word = s.substr(k + (words_num-1)*word_size, word_size);
            if(word_code.count(word)){
                code += pow(2,word_code[word]);
            }
            word = s.substr(k-word_size, word_size);
            if(word_code.count(word)){
                code -= pow(2,word_code[word]);
            }
            if(code == true_code){
                res.push_back(k);
            }
        }
    }

    for(int &i:res){
        cout<<i<<' ';
    }
    system("pause");
    return 0;
}
