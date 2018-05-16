#include<bits/stdc++.h>
#include <iostream>
using namespace std;
 
int flag=0;
void dfs(int source,int num,int parent,int vis[],vector <int> v[])
{
    int i;
    int child;
    vis[source]=num%2;
    for(i=0;i<v[source].size();i++)
    {
        child=v[source][i];
        if(child!=parent)
        {
            if(vis[child]==-1)
            {
                dfs(child,num+1,source,vis,v);
                if(flag==1)
                {
                    return;
                }
            }
            else 
            {
                if(vis[child]!=(num+1)%2)
                {
                    flag=1;
                    return;
                }
            }
        }
    }
}
void init(int vis[],int node)
{
    for(int i =0;i<=node;i++)
    {
        vis[i]=-1;
    }
}
int main(void) {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,i,j;
	int a,b;
	int t;
	int node,edge;
    cin>>t;
	for(j=1;j<=t;j++)
	{
	    flag=0;
	    cin>>node>>edge;
	    vector <int> v[node+1];
	    int vis[node+1];
	    for(i=0;i<edge;i++)
	    {
	        cin>>a>>b;
	        v[a].push_back(b);
	        v[b].push_back(a);
	    }
	    init(vis,node);
	    for(i=1;i<=node;i++)
	    {
	        if(vis[i]==-1)
	        {
	            dfs(i,0,i,vis,v);
	        }
	        if(flag==1)
	        {
	            cout<<"Scenario #"<<j<<":"<<endl<<"Suspicious bugs found!"<<endl;
	            break;
	        }
	   }
	   if(flag==0)
	   {
	       cout<<"Scenario #"<<j<<":"<<endl<<"No suspicious bugs found!"<<endl;
	   }
	}
	return 0;
}
