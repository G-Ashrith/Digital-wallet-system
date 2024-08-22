#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool compareBalance(const pair<int, int > a,const pair<int,int> b){
    return a.second < b.second;
}
int main() {
    int n,m;
    cin>>n;
    vector<int> ids(n);
    vector<long int> balance(n);
    for(int i=0;i<n;++i){
        cin>>ids[i]>>balance[i];
    }
    cin>>m;
    
    for(int i=0;i<m;++i){
        int sender,reciever;
        long int amount;
        cin>>sender>>reciever>>amount;
        
        int senderIndex=-1,recieverIndex=-1;
        for(int j=0;j<n;++j){
            if(ids[j]==sender) senderIndex=j;
            if(ids[j]==reciever) recieverIndex=j;
        }
        if(senderIndex!= -1 && recieverIndex != -1 && balance[senderIndex] >= amount){
            balance[senderIndex]-=amount;
            balance[recieverIndex]+=amount;
            cout<<"Success"<<endl;
        }
        else cout<<"Failure"<<endl;
    }
    vector<pair<int,long int>> walletData(n);
    for(int i=0;i<n;++i){
        walletData[i]={ids[i],balance[i]};
    }
    cout<<endl;
    sort(walletData.begin(),walletData.end(),compareBalance);
    for(const auto data:walletData){
        cout<<data.first<<" "<<data.second<<endl;
    }
 
    return 0;
}