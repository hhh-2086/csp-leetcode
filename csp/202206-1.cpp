#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int data[n];
    float sum=0,sum2=0;
    for(int i=0;i<n;i++){
        cin>>data[i];
        sum+=data[i];
        sum2+=data[i]*data[i];
    }
    float avg = sum/n;
    float d = sum2/n-2*avg*sum/n+avg*avg;
    for(int i=0;i<n;i++){
        printf("%.16f\n",(data[i]-avg)/sqrt(d));
    }
    return 0;
}