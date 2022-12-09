#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 滑动窗口解决问题
    string s = "barfoothefoobarman";
    // cin>>s;
    vector<string> words = {"foo","bar"};
    // 最终结果储存
    vector<int>res;
    // slength为s长度，word_size为单词长度，最后为单词个数
    int slength = s.size(),word_size = words[0].size(),words_num = words.size();
    
    for(int i = 0; i < word_size && i + words_num*word_size <= slength; i++){
        // 开始初始化differ
        unordered_map<string,int>differ;
        for(int j=0; j<words_num;j++){
            // i开始切割出来words_num个单词
            differ[s.substr(i+j*word_size,word_size)]++;
        }// 初始化differ结束
        for(string &word:words){
            differ[word]--;
            if(differ[word]==0){
                differ.erase(word);
            }
        }//如果differ中元素个数为0，那么就是匹配
        if(differ.empty()){
            res.push_back(i);
        }

        // 开始滑动窗口
        for(int k = i+word_size; k<slength+1-word_size*words_num; k+=word_size){
            // 滑动窗口划走的单词--，新进入的单词++
            string word;
            word = s.substr(k + (words_num-1)*word_size, word_size);
            differ[word]++;
            if(differ[word]==0){
                differ.erase(word);
            }
            word = s.substr(k-word_size, word_size);
            differ[word]--;
            if(differ[word]==0){
                differ.erase(word);
            }

            // 判断该窗口的串是否符合条件
            if(differ.empty()){
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
