#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int data[n+1] = {0};
    data[0] = 1;
    int x,y;
    int result = 0;
    for(int i=0;i<k;i++){
        cin>>x>>y;
        if(data[y]==0){
            result += 1;
        }
        data[x] = 1;
    }
    cout<<result;
    return 0;
}