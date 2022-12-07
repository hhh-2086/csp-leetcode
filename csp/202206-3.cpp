// 得分40
#include <bits/stdc++.h>

using namespace std;
class role;
class group;


//role数据结构为角色
class role{
public:
	string name;//角色的名称
	int nv;//操作清单中包含的操作数量
	set<string>op_nv;//操作清单
	int no;//资源种类数量
	set<string>res;//资源种类
	int nn;//资源名称的数量
	set<string>res_name;//资源名称
	//关联的角色名称和组的名称
	vector<role>rname;
	vector<group>gname;

};
class group{
public:
	string name;//group的名称
	vector<role>roles;//和改组相关的所有角色

};
map<string,role>RS;//role与其数据结构的对应
map<string,group>GS;//group与其数据结构的对应
// 校验该节点是否有该操作
bool check(role r,string op1,string res1,string res_name1){
    string s = "*";
    if(!r.op_nv.count(op1) and !r.op_nv.count(s)){
        return 0;
    }
    if(!r.res.count(res1) and !r.res.count(s)){
        return 0;
    }
    if(!r.res_name.count(res_name1) and r.nn!=0){
        return 0;
    }
    return 1;
}
int find(){
	//输入一行信息
	string sname;
	int gnum;
	string op1,res1,res_name1;//操作的名称，资源种类名称，资源名称
	
	cin>>sname;
    cin>>gnum;
    string gs[gnum];//存储所属的所有组的名称
    for(int j=0;j<gnum;j++){
        cin>>gs[j];
    }
	cin>>op1>>res1>>res_name1;
	
	// 假设关联不具有传递性，只需要找该节点直接关联的节点，而不用找关联节点的关联节点
	if(RS.count(sname)){
		if(check(RS[sname],op1,res1,res_name1)){
			return 1;
		}
	}
	// 查看他的关联节点
	role &r = RS[sname];
	for(vector<role>::iterator it = (r.rname).begin();it!=(r.rname).end();it++){
		if(check(*it,op1,res1,res_name1)){
			return 1;
		}
	}
	// 查看他关联的组，组关联的其他节点是否可以check
	for(int i=0;i<gnum;i++){
		if(GS.count(gs[i])){
			group &gr = GS[gs[i]];
			for(vector<role>::iterator it=gr.roles.begin();it!=gr.roles.end();it++){
				if(check(*it,op1,res1,res_name1)){
					return 1;
				}
			}
		}
    }

	// 下方假设关联具有传递性：
	/*
	//开始校验
	queue<role>q1;//存储将要访问的角色
    set<string>q2;//存储已经访问过的角色，为了方便，只记录其name
    queue<group>p1;//存储将要访问的组
    set<string>p2;//存储已经访问的组，为了方便，只记录其name
	// 因为set中要排序，但是本次的两个类，不好排序

// 初始化两个栈
    if(RS.count(sname)){
        q1.push(RS[sname]);//将本节点抛入
    }
    else{
        // 将所有有记录的组，抛入
        for(int i=0;i<gnum;i++){
            if(GS.count(gs[i])){
                p1.push(GS[gs[i]]);
            }
        }
    }
    while (true)
    {
        // 抛出q1中的一个节点校验是否可以进行操作
        if(q1.size()!=0){
            role r = q1.front();
            q1.pop();
            q2.insert(r.name);
            if(check(r,op1,res1,res_name1)){
                return 1;
            }
            // 并且将该节点关联的所有节点和组抛入到p1，q1中
            vector<role>::iterator it = (r.rname).begin();
            while(it!=(r.rname).end()){
                if(!q2.count((*it).name)){
                    q1.push(*it);
                }
                it++;
            }
            vector<group>::iterator itt = r.gname.begin();
            while(itt!=r.gname.end()){
                if(!p2.count((*itt).name)){
                    p1.push(*itt);
                }
                itt++;
            }
        }
        // 抛出group，将组关联的所有节点都抛入到p1中
        if(p1.size()!=0){
            group g = p1.front();
            p1.pop();
            p2.insert(g.name);
            // group关联的所有节点
            vector<role>::iterator it = g.roles.begin();
            while(it!=g.roles.end()){
                if(!q2.count((*it).name)){
                    q1.push(*it);
                }
				it++;
            }
        }
        // 遍历到最后都发现，根本没有这个操作
        if(p1.size()==0 and q1.size()==0){
            return 0;
        }
        
    }
	*/
	return 0;
}
int main() {
	//首先完成输入
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=0;i<n;i++){
		role r;
		string name;
		cin>>name;
		r.name = name;
		int nv;
		cin>>nv;
		r.nv=nv;
		for(int j=0;j<nv;j++){
			string s;
			cin>>s;
			r.op_nv.insert(s);
		}
		int no;
		cin>>no;
		r.no=no;
		for(int j=0;j<no;j++){
			string s;
			cin>>s;
			r.res.insert(s);
		}
		int nn;
		cin>>nn;
		r.nn=nn;
		for(int j=0;j<nn;j++){
			string s;
			cin>>s;
			r.res_name.insert(s);
		}
		RS[name] = r;
	}
	for(int i=0;i<m;i++){
		string sr;
		cin>>sr;
		role &r=RS[sr];//假设角色关联操作中的角色在前面n个中
		int ns;
		cin>>ns;
		for(int j=1;j<=ns;j++){
			//关联操作中，后面的角色名称和组的名称可能均未提到
			char c;
			cin>>c;
			if(c=='u'){
				//关联的是用户
				string rn;
				cin>>rn;//输入的角色的名称
				if(!RS.count(rn)){
					//创建一个新的用户
					role newr;
					newr.name=rn;
					
					newr.rname.push_back(r);
					r.rname.push_back(newr);
					RS[rn] = newr;//注意，将所有信息都存入之后才可以存储信息。C++中应该是所有信息的备份而不是地址的备份
				}
				else{
					RS[rn].rname.push_back(r);
					r.rname.push_back(RS[rn]);
				}
			}
			else{
				string gn;
				cin>>gn;
				if(!GS.count(gn)){
					group newg;
					newg.name = gn;
					newg.roles.push_back(r);
					r.gname.push_back(newg);
					GS[gn] = newg;//存储group信息
				}
				else{
					GS[gn].roles.push_back(r);
					r.gname.push_back(GS[gn]);
				}
			}
		}
	
	}
	
	for(int i=0;i<q;i++){
		if(find()){
			cout<<1<<'\n';
		}
		else{
			cout<<0<<'\n';
		}
	}
	return 0;
}


/*
样例输入
1 2 3
op 1 open 1 door 0
op 1 g sre
op 1 u xiaop
xiaoc 2 sre ops open door room302
xiaop 1 ops open door room501
xiaoc 2 sre ops remove door room302

输出
1
1
0
*/