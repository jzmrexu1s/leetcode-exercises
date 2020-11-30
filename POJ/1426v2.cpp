#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
int n,flag;
unsigned long long ans;
void dfs(unsigned long long x,int y)
{
    if(y>19) return ;
    if(x%n==0)
    {
        flag=1;
        ans=x;
        return;

    }
    else
    {for(int i=0;i<2;i++)
            dfs(10*x+i,y+1);
    }
    if(flag) return;


}
int main()
{
    unsigned long long x;
    while(cin>>n)
    {
        if(n==0) break;
        x=1;
        flag=0;
        dfs(x,0);
        cout<<ans<<endl;


    }
    return 0;

}