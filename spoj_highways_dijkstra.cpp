#include<bits/stdc++.h>
#include <iostream>
using namespace std;
 
void init(int vis[],int dist[],int node)
{
    for(int i =0;i<=node;i++)
    {
        vis[i]=0;
        dist[i]=INT_MAX;
    }
}
void dijkstra(int vis[],int dist[],vector <pair <int,int>> v[],int source)
{
    dist[source]=0;
    set <pair <int,int>> s;
    s.insert({0,source});
    pair <int,int> p;
    int node,i;
    int wt;
    int child,dst;
    while(!s.empty())
    {
        p=*s.begin();
        s.erase(s.begin());
        node=p.second;
        wt=p.first;
        for(i=0;i<v[node].size();i++)
        {
            
            child=v[node][i].second;
            if(!vis[child])
            {
                dst=v[node][i].first;
                if(dist[node]+dst<dist[child])
                {
                    dist[child]=dist[node]+dst;
                    s.insert({dist[child],child});
                }
            }
        }
        vis[node]=1;
    }
}
int main(void) {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,i,j;
	int t;
	int edges,nodes,source,end;
	int a,b,c;
    cin>>t;
	while(t--)
	{
	    cin>>nodes>>edges>>source>>end;
	    vector <pair <int,int>> v[nodes+1];
	    int vis[nodes+1]={0};
	    int dist[nodes+1];
	    init(vis,dist,nodes);
	    pair<int,int >p1;
	    for(i=0;i<edges;i++)
	    {
	        cin>>a>>b>>c;
	        p1.first=c;
	        p1.second=b;
	        v[a].push_back(p1);
	        p1.second=a;
	        v[b].push_back(p1);
	    }
	    dijkstra(vis,dist,v,source);
	    if(dist[end]!=INT_MAX)
	    {
	        cout<<dist[end]<<endl;
	    }
	    else
	    {
	        cout<<"NONE"<<endl;
	    }
	}
	return 0;
}
