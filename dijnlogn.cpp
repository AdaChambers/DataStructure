#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;
const int oo=1e9+10;
const int NN=110;
const int MM=10010;
int n,m;
int vis[NN],dis[NN];
struct edge{
        int to,cost;
}e[MM*2];
vector <int> con[NN];//use vector to set up a graph
int a[NN][NN];
struct point{
        int id;
        long long d;
};
struct point_cmp{//define < of priority_queue,the key is distance
        bool operator() (const point &x,const point &y)const{
                if(x.d>y.d)return 1;
                if(x.d==y.d && x.id>y.id)return 1;
                return 0;
        }
};
priority_queue <point ,vector<point> , point_cmp > q;
void dij(int origin){
        for(int i=0;i<=n+1;i++)dis[i]=oo;
        dis[origin]=0;
        point st;
        st.id=origin;st.d=0;
        q.push(st);
        //does not need to use vis[],and one same node can appear in the queue many times
        //but only the one with the best distance may bring new node into the queue
        //so the ones whoes dis is not the best will just be kicked off the queue,so vis is not necessary.
        while(!q.empty()){
                point root=q.top();
                q.pop();
                if(dis[root.id]!=root.d)continue;
                for(int i=0;i<con[root.id].size();i++){//use vector 
                        edge ed=e[con[root.id][i]];
                        int nex=ed.to;
                        if(dis[nex]>dis[root.id]+ed.cost){
                                dis[nex]=dis[root.id]+ed.cost;
                                point neww;
                                neww.id=nex;neww.d=dis[nex];
                                q.push(neww);
                        }
                }
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
                        a[x][y]=min(a[x][y],z);//in case that seval edges have same start and end
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
/*
3 3
1 2 5
2 3 5
3 1 2
*/