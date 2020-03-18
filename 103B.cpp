#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define pb push_back
#define fr first
#define sc second
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0},dxx[8]={0,0,1,1,1,-1,-1,-1},dyy[8]={1,-1,0,1,-1,0,1,-1};
//914836017997511610
int cycles;
vector<int> v[105];
bool vis[105];int root[105];
void dfs(int u,int parent)
{
	vis[u]=true;
	//cout<<"uu"<<u<<endl;
	for(int i=0;i<v[u].size();++i)
	{	int child=v[u][i];
		//cout<<"rot"<<root[u]<<"root"<<root[child]<<endl;
		if(!vis[child])
		{
			dfs(child,u);
		}
		else if(vis[child] and child!=parent and root[child]!=root[u])
		{	//cout<<"c"<<child<<"u"<<u<<"p"<<parent<<endl;
			root[child]=root[u]=child;
			++cycles;
		}
	}
}
int main()
{ 	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  	int n,m,i,x,y;
  	cin>>n>>m;
  	for(i=1;i<=100;++i)
  		root[i]=i;
  	for(i=0;i<m;++i)
  	{
  		cin>>x>>y;
  		v[x].pb(y);v[y].pb(x);
  	}
  //	for(i=1;i<=10;++i)
  //		cout<<root[i]<<endl;
  	dfs(1,-1);
  	for(i=2;i<=n;++i)
  		{
  		if(!vis[i])
  			{cycles=2;break;}
  		}
  	string ans[2]={"NO","FHTAGN!"};
  	//cout<<"cycles"<<cycles<<"\n";
  	cout<<ans[cycles==1];
 	return 0;
}
	