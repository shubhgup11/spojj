#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,i,j;
	int t,q;
	while(1)
	{
    cin>>t>>q;
    if(t==0 && q==0)
        break;
    vector< pair<int,int> > arr;
    arr.clear();
    arr.push_back(make_pair(0,0));
    int dp[q+1][t+1];
    int cost,fun;
    for(i=1;i<=q;i++)
    {
        cin>>cost>>fun;
        arr.push_back(make_pair(cost,fun));
    }
    sort(arr.begin()+1,arr.end());
    for(i=0;i<=t;i++)
        dp[0][i]=0;
    for(i=0;i<=q;i++)    
        dp[i][0]=0;
    for(i=1;i<=q;i++)
    {
        cost=arr[i].first;
        fun=arr[i].second;
        for(j=1;j<=t;j++)
        {
            
            if(j>=cost)
            {
                dp[i][j]=max(dp[i-1][j-cost]+fun,dp[i-1][j]);
            }
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    /*for(i=0;i<=q;i++)
    {
        for(j=0;j<=t;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
        }*/
    i=q;
    j=t;
    while((j-1)>=0 && dp[i][j-1]==dp[i][j])
    {
        j--;
    }
    cout<<j<<" ";
    cout<<dp[q][t]<<endl;
	}
	
	return 0;
}

