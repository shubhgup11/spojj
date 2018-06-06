// TRIE implementation....
// just take a variable to mark the end of the number...
// now while adding a number ...if you encounter an end...then "NO"
// and while adding a number if there are more nodes even ehen the node's end is reached then also answer is "NO"


#include<bits/stdc++.h>
#include <iostream>
using namespace std;
struct maka
{
    maka* arr[10];
    int end;
};
maka* create()
{
    maka *temp;
    temp=new maka();
    for(int i=0;i<10;i++)
    {
        temp->arr[i]=NULL;
    }
    temp->end=0;
    return temp;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,i,j;
	int t,q;
	int flag;
    cin>>n;
    while(n--)
    {
        flag=0;
        string str;
        int ln;
        cin>>t;
        vector< maka *> v;
        maka *head;
	    head=create();
	    v.push_back(head);
        while(t--)
        {
            
    	    maka *tempp;
            cin>>str;
            tempp=head;
            ln=str.length();
            if(flag==0)
            {
                for(i=0;i<ln-1;i++)
                {
                    if(tempp->arr[str[i]-'0']==NULL)
                    {
                        tempp->arr[str[i]-'0']=create();
                        v.push_back(tempp->arr[str[i]-'0']);
                        
                    }
                    if(tempp->end==1)
                    {
                        //cout<<"yo1\n";
                           flag=1;
                    }
                    tempp=tempp->arr[str[i]-'0'];
                }
                if(tempp->arr[str[i]-'0']!=NULL  )
                {
                    if(tempp->arr[str[i]-'0']->end!=1)
                    {
                        flag=1;
                        //cout<<"yo2\n";
                    }
                }
                else
                {
                    if(tempp->end==1)
                    {
                        //cout<<"yo3\n";
                        flag=1;
                    }
                        tempp->arr[str[i]-'0']=create();
                        v.push_back(tempp->arr[str[i]-'0']);
                        tempp=tempp->arr[str[i]-'0'];
                        tempp->end=1;
                }
            }
        }
        //cout<<v.size();
        for(i=0;i<v.size();i++)
        {
            delete v[i];
        }
        if(flag==0)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
	return 0;
}

