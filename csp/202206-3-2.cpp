#include <bits/stdc++.h>
using namespace std;

struct role{
    string name;
    map<string,bool>opt;
    map<string,bool>res_kind;
    map<string,bool>res_name;
}roles[500];
map<string,int>role_all_id;//根据角色的名称，检索到角色的编号，方便再roles中查找
map<string,vector<int> >related;//组或角色（不区分），关联的角色的id

bool check(int role_id,string opt, string res_kind, string res_name){
    string s = "*";
    role &r = roles[role_id];
    if(!r.opt.count(opt) && !r.opt.count(s)){
        return 0;
    }
    if(!r.res_kind.count(res_kind) && !r.res_kind.count(s)){
        return 0;
    }
    if(!r.res_name.count(res_name) && r.res_name.size()!=0){
        return 0;
    }
    return 1;
}
// 相关变量
string rname;
int nv,no,nn;
string opt_name;
string res_kind_name;
string res_name_name;

string related_name;
int ns;
int role_id;
string s;

string check_name;
int ng;
string op1,res1,res_name1;//操作的名称，资源种类名称，资源名称
string gs[500];//存储每次输入所属的所有组的名称
string gname;
int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    // 输入n行角色的信息
    for(int i=0;i<n;i++){
        cin>>rname;//角色的名称
        role_all_id[rname] = i;//记录名称对应的id
        roles[i].name = rname;
        cin>>nv;
        for(int j=0;j<nv;j++){
            cin>>opt_name;
            roles[i].opt[opt_name] = true;
        }
        cin>>no;
        for(int j=0;j<no;j++){
            cin>>res_kind_name;
            roles[i].res_kind[res_kind_name] = true;
        }
        cin>>nn;
        for(int j=0;j<nn;j++){
            cin>>res_name_name;
            roles[i].res_name[res_name_name] = true;
        }
    }
    
    // 输入m个关联
    for(int i=0;i<m;i++){
        cin>>related_name;
        role_id = role_all_id[related_name];
        cin>>ns;//ns个关联
        for(int j=0;j<ns;j++){
            cin>>s;//不用区分group还是role，因此该字符不记录
            cin>>s;
            related[s].push_back(role_id);
        }
    }
    // 输入q个校验
    
    for(int i=0;i<q;i++){
        // 首先输入所有的信息
        cin>>check_name;
        cin>>ng;
        for(int j=0;j<ng;j++){
            cin>>gs[j];
        }
        cin>>op1>>res1>>res_name1;

        int flag=0;
        // 开始校验
        if(role_all_id.count(check_name)){
            if(check(role_all_id[check_name],op1,res1,res_name1)){
                flag = 1;
                break;;//检验下一行
            }
        }
        
        // 检验节点的关联节点
        for(int it=0; it<related[check_name].size(); it++){
            int related_id = related[check_name][it];
            if(check(related_id,op1,res1,res_name1)){
                flag = 1;
                break;
            }
        }

        // 由组开始检验
        for(int j=0;j<ng;j++){
            if(flag){
                break;
            }
            gname = gs[j];
            for(int it=0;it<related[gname].size();it++){
                int related_id = related[gname][it];
                if(check(related_id,op1,res1,res_name1)){
                    flag = 1;
                    break;
                }
            }
        }

        cout<<flag<<'\n';

    }
    //system("pause");
    return 0;
}

/*
1 2 3
op 1 open 1 door 0
op 1 g sre
op 1 u xiaop
xiaoc 2 sre ops open door room302
xiaop 1 ops open door room501
xiaoc 2 sre ops remove door room302

*/