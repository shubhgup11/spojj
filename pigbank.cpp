//   normal dp
// just  initialise the dp to int max..and fill the spots with the minimum values..
// if the value is int max..then it cant be reached..
// else dp[q][n]

#include<bits/stdc++.h>
#include <iostream>
using namespace std;
void func(int n,int q)
{
    int i,j;
    int wt,val;
    pair<int,int> arr[q];
    int dp[q+1][n+1];
    for(i=0;i<=q;i++)
    {
        dp[i][0]=0;
    }
    for(i=0;i<=n;i++)
    {
        dp[0][i]=INT_MAX;
    }
    for(i=0;i<q;i++)
    {
        cin>>val>>wt;
        arr[i]=make_pair(val,wt);
    }
    for(i=1;i<=q;i++)
    {
        val=arr[i-1].first;
        wt=arr[i-1].second;
        for(j=1;j<=n;j++)
        {
            if(wt>j)
                dp[i][j]=dp[i-1][j];
            else
            {
                if(dp[i][j-wt]==INT_MAX)
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=min(dp[i][j-wt]+val,dp[i-1][j]);
            }
        }
    }
    if(dp[q][n]==INT_MAX)
    {
        cout<<"This is impossible.\n";
    }
    else
        cout<<"The minimum amount of money in the piggy-bank is "<<dp[q][n]<<".\n";
        
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,i,j;
	int t,q;
    cin>>t;
	while(t--)
	{
	    cin>>i>>j;
	    cin>>q;
	        func(j-i,q);
	}
	return 0;
}

