// the cache was to find in what way to implement bfs...
// the adjacent nodes would be those prime numbers which have only a single digit difference with the parent number...
// and change the count if the numbers with all the 1 digits changed get over ..
// i used t dummmy variable -1 .
// i inserted it in the queue and scanned it to change count...
#include<bits/stdc++.h>
#include <iostream>
using namespace std;
int sieve[1000000+1];
void init()
{
    for(int i=0;i<=1000000;i++)
        sieve[i]=0;
}
void calcprime()
{
    int i,j;
    for(i=2;i<=1000;i++)
    {
        if(!sieve[i])
        {
            for(j=i*i;j<=1000000;j=j+i)
            {
                sieve[j]=1;
            }
        }
    }
}

bool checkprime(int i)
{
    if(!sieve[i])
        {
            sieve[i]=1;
            return 2>1;
        }
        return 2<1;
}
int func(int from,int to)
{
    queue <int> q;
    int i,j,ch,num,count;
    sieve[to]=1;
    if(from==to)
        {//cout<<"0\n";
        return 0;}
    else
    {
        for(i=1;i<=9;i++)
        {
            if(i!=to/1000)
            {
                num=i*1000+to%1000;
                if(checkprime(num))
                {
                    if(num==from)
                    {count=1;return 1;}
                    else
                    {
                        q.push(num);
                        // cout<<num<<" ";
                    }
                }
            }
        }
        ch=to/1000;
        for(i=0;i<=9;i++)
        {
            if(i!=(to/100)%10)
            {
                num=ch*1000+i*100+to%100;
                if(checkprime(num))
                {
                    if(num==from)
                    {count=1;return 1;}
                    else
                    {
                        q.push(num);
                        // cout<<num<<" ";
                    }
                }
            }
        
        }
        ch=to/100;
        for(i=0;i<=9;i++)
        {
            if(i!=(to/10)%10)
            {
                num=ch*100+i*10+to%10;
                if(checkprime(num))
                {
                    if(num==from)
                    {
                        count=1;
                        return 1;
                    }
                    else
                    {
                        q.push(num);
                        // cout<<num<<" ";
                    }
                }
            }
        }
        ch=to/10;
        for(i=0;i<=9;i++)
        {
            if(i!=to%10)
            {
                num=ch*10+i;
                if(checkprime(num))
                {
                    if(num==from)
                    {
                        count=1;
                        return 1;
                    }
                    else
                    {
                        q.push(num);
                        // cout<<num<<" ";
                    }
                }
            }
        }
        q.push(-1);
        count=2;
        //cout<<"2"<<endl;
        while(!q.empty())
        {
            to=q.front();
            q.pop();
            if(to==-1)
            {
                count++;
                if(!q.empty())
                {
                    q.push(-1);
                    //cout<<count<<endl;
                    
                }
                continue;
            }
            for(i=1;i<=9;i++)
            {
                if(i!=to/1000)
                {
                    num=i*1000+to%1000;
                    if(checkprime(num))
                    {
                        if(num==from)
                        {return count;}
                        else
                        {
                        q.push(num);
                        // cout<<num<<" ";
                    }
                    }
                }
            
            }
            
            for(i=0;i<=9;i++)
            {
                ch=to/1000;
                if(i!=(to/100)%10)
                {
                    num=ch*1000+i*100+to%100;
                    if(checkprime(num))
                    {
                        if(num==from)
                        {return count;}
                        else
                        {
                        q.push(num);
                        // cout<<num<<" ";
                    }
                    }
                }
                
                 if(i!=(to/10)%10)
                {
                    ch=to/100;
                    num=ch*100+i*10+to%10;
                    if(checkprime(num))
                    {
                        if(num==from)
                        {
                            return count;
                        }
                        else
                        {
                        q.push(num);
                        // cout<<num<<" ";
                    }
                    }
                }
                
                 if(i!=to%10)
                {
                    ch=to/10;
                    num=ch*10+i;
                    if(checkprime(num))
                    {
                        if(num==from)
                        {
                            return count;
                        }
                        else
                        {
                        q.push(num);
                        // cout<<num<<" ";
                    }
                    }
                }
            }
        }
        return -1;
    }
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,i,j;
	int t,q;
    cin>>t;
    
	while(t--)
	{
	    init();
	    calcprime();
	    cin>>i>>j;
	    i=func(i,j);
	    if(i==-1)
	        cout<<"Impossible.\n";
	    else
	        cout<<i<<endl;
	}
	return 0;
}

