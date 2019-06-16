#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
const int oo=1e9+10;
const int NN=110;
const int MM=10010;
int n,m;
int vis[NN],dis[NN];
struct edge{
        int to,cost;
}e[MM*2];
vector <int> con[NN];
int a[NN][NN];
void dij(int origin){
        int cnt=0;
        for(int i=1;i<=n;i++)dis[i]=oo;
        memset(vis,0,sizeof(vis));
        //vis[origin]=1;
        dis[origin]=0;
        while(1){
                int minn=oo;
                int exp;
                for(int i=1;i<=n;i++){//find the minn dis
                        if( (!vis[i]) && dis[i]<minn){
                                minn=dis[i];
                                exp=i;
                        }
                }
                vis[exp]=1;//put it in set
                for(int i=0;i<con[exp].size();i++){//update distance
                        edge ed=e[con[exp][i]];
                        int nex=ed.to;
                        if(dis[nex]>dis[exp]+ed.cost){
                                dis[nex]=dis[exp]+ed.cost;
                        }
                }
                cnt++;
                if(cnt==n-1)break;
        }
}
int main(){
        while(1){
                scanf("%d%d",&n,&m);
                if(n==0)break;
                for(int i=1;i<=n;i++)con[i].clear();
                for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
                        a[i][j]=oo;
                }
                for(int i=1;i<=m;i++){
                        int x,y,z;
                        scanf("%d%d%d",&x,&y,&z);
                        a[x][y]=min(a[x][y],z);
                        a[y][x]=a[x][y];
                }
                int nume=0;
                for(int i=1;i<=n;i++)for(int j=1;j<=n;j++){
                        if(a[i][j]<oo){
                                e[++nume].to=j;
                                e[nume].cost=a[i][j];
                                con[i].push_back(nume);
                        }
                }
                dij(1);
                printf("%d\n",dis[n]);
        }
        return 0;
}