// #include<iostream>
using namespace std;
#include<bits/stdc++.h>

struct MES
{
    int d,u,r;//日期，用户，风险区。
};

map<int,pair<int,int> >mp;//维护所有的风险区信息，风险区编号，开始风险时间和结束时间

vector<MES>ans;

int main(){
    int n;//一共有n天
    cin>>n;
    for(int day=0;day<n;day++){
        int r,m;//r个风险地区，m个风险信息
        cin>>r>>m;
        // 更新风险地区的信息
        for(int i=0;i<r;i++){
            int p;
            cin>>p;//风险地区的编号
            // 增加或者更新风险地区的信息
            if(!mp.count(p)){
                // 如果没有该地区的风险信息，那么在列表中更新
                mp[p] = make_pair(day,day+6);
            }
            else{
                // 有该地区的风险信息，并且风险连续
                if(mp[p].first<=day && mp[p].second+1>=day){
                    mp[p] = make_pair(mp[p].first,day+6);
                }
                else{
                    // 风险信息被间断，直接用新的时间替换
                    mp[p] = make_pair(day,day+6);  
                }
            }
        }

        // 维护上一次风险人群的信息
        vector<MES>tmp;
        for(vector<MES>::iterator it=ans.begin();it!=ans.end();it++){
            // 如果风险用户的信息超过七天，不再维护其信息
            if(day-it->d>=7){
                continue;
            }
            if(it->d>=mp[it->r].first and day<=mp[it->r].second){
                tmp.push_back(*it);//仍旧是风险用户，指针形式！！！！！
            }           
        }
        ans.clear();
        ans = tmp;//更新旧的风险用户的信息

        // 更新新来的用户的信息
        for(int i=0;i<m;i++){
            int d,u,r;
            cin>>d>>u>>r;
            if(day-d>=7)continue;//如果风险地区仍然在持续，但是用户被延后的信息中天数大于7，仍然不是危险用户！！
            // 地区是风险地区，且风险时间有效
            if(mp.count(r)){
                if(d>=mp[r].first and day<=mp[r].second){
                    MES q = {d,u,r};
                    ans.push_back(q);//新的疫情信息
                }
            }
        }

        // 输出当天疫情用户
        set<int>fout;
        for(vector<MES>::iterator it=ans.begin();it!=ans.end();it++){
            fout.insert(it->u);
        }
        cout<<day<<' ';
        for(set<int>::iterator it = fout.begin();it!=fout.end();it++){
            cout<<*it<<' ';//指针的形式输出！！！！
        }
        cout<<'\n';

    }
    return 0;
}