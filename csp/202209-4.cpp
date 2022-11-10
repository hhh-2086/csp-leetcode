#include<bits/stdc++.h>
using namespace std;
// 超时！！！！
int main(){
    int n,m,q;
    cin>>n>>m>>q;//n个投票者，m个作品，q行
    int people[n+1] = {0};//每个人刚开始没有喜欢的作品、
    int arts[m+1] = {0};//刚开始每个作品的票数为0
    // 建立作品对应的人。
    map<int ,set<int> >who;
    set<int>tm;
    for(int i=0;i<q;i++){
        int a;
        cin>>a;//事件的编号

        switch (a)//总共有五种情况
        {
            int pos,t;
        case 1:
            int l,r,x;
            cin>>l>>r>>x;//号为x的作品开展了一场拉票活动，成功地吸引了编号为l-r的投票者的兴趣，使得他们的投票意愿全部改为x。
            // 查看是否有人的作品改投，随之改变arts对应
            for(int t=l;t<=r;t++){
                if(people[t]==0){
                    // 该人之前没有投票
                    people[t] = x;
                    arts[x]+=1;//作品票数加1
                    who[x].insert(t);//作品添加新的人
                }
                else{
                    a = people[t];
                    arts[a] -= 1;//原来的作品票数-1
                    who[a].erase(t);//原作品中去掉这个人
                    people[t] = x;
                    arts[x] += 1;//该作品票数+1
                    who[x].insert(t);
                }
            }
            break;
        case 2://需要定位到投某作品的人都有谁
            int w;
            cin>>x>>w;//x退出竞赛，x的票全都给了w，如果w=0，那么投票者暂时找不到新的作品
            
            if(w!=0){
                // n个人中，票为x的全都改成w
                for(int i=1;i<=n;i++){
                    if(people[i]==x){
                        people[i] = w;
                    }
                }
                who[w].insert(who[x].begin(),who[x].end());//将x的所有人添加到作品w中
                // 更新作品w的票
                arts[w] += arts[x];
            }
            arts[x] = 0;//将x作品的票数清零
            who.erase(x);//直接删除x作品相关信息
            break;
        case 3://需要定位到投某作品的人都有谁
            int y;
            cin>>x>>y;//x和y的作品投票交换
            t = arts[x];
            arts[x] = arts[y];
            arts[y] = t;

            tm = who[x];
            who[x] = who[y];
            who[y] = tm;

            for(set<int>::iterator it=who[x].begin();it!=who[x].end();it++){
                people[*it] = x;
            }
            for(set<int>::iterator it=who[y].begin();it!=who[y].end();it++){
                people[*it] = y;
            }
            break;

        case 4://含输出项
            w;
            cin>>w;//调查w的票数，w=0则没有票数
            cout<<arts[w]<<'\n';
            break;
        case 5://含输出项
            // 求出获胜作品，票数最多且编号小的那个获胜，票数至少为1
            // 找到数组中的最大值所在的位置
            // C++中函数
            pos = max_element(arts,arts+m+1) - arts;//第一个最大值所在的index
            cout<<pos<<'\n';
            break;
        }
    }

    return 0;
}