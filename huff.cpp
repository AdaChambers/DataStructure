#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
char cha[100100];
int id[100100];
int n;
struct nodee
{
        int weight,lss=-1,rs=-1,fa=-1;
}node[100100];
struct cmp   
{
    bool operator()(int x,int y)//define > in the priority queue(greater)
    {
        if(node[x].weight>node[y].weight)return 1;
        else if(node[x].weight==node[y].weight)return x<y;
        else return 0;
    }
};
priority_queue <int,vector<int>, cmp> q;
char ss[100100];
void build(){
        int cnt=n;
        for(int i=1;i<n;i++){//build up the tree

                int lss=q.top();q.pop();
                int rs=q.top();q.pop();
                //printf("%d %d\n",node[lss].weight,node[rs].weight);
                cnt++;
                node[cnt].weight=node[lss].weight+node[rs].weight;
                node[cnt].lss=lss;node[cnt].rs=rs;
                node[lss].fa=cnt;node[rs].fa=cnt;
                q.push(cnt);
        }
}
vector <int> code[100100];
void get_code(int cur){
        for(int i=1;i<=n;i++){
                int nod=i;
                while(nod>0){//the code is up-side-down
                        int father=node[nod].fa;if(father==-1)break;
                        if(nod==node[father].lss)code[i].push_back(0);
                        else code[i].push_back(1);
                        nod=father;
                }
        }
}
void into_code(char *text,int l){//translate text into 01 code
        for(int i=0;i<l;i++){
                int iden=id[(int)text[i]];
                for(int j=code[iden].size()-1;j>=0;j--){//the code is up-side-down
                        printf("%d",code[iden][j]);
                }
        }
        printf("\n");
}
void into_text(char *cod,int l,int root){//trslate code into text
        int i=0;
        int goDown;
        while(i<l){

                goDown=root;
                while(goDown>0 && i<l){
                        //printf("%c %d\n",cod[i],goDown);
                        
                        if(cod[i]=='0')goDown=node[goDown].lss;
                        else goDown=node[goDown].rs;
                        if(1<=goDown&&goDown<=n){
                                printf("%c",cha[goDown]);
                                i++;
                                break;
                        }
                        i++;
                }
        }
        printf("\n");
        if(i==l+1 && goDown>n)printf("wrong!\n");
}
int main(){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){//get charactor list
                char s[4];
                scanf("%s",s);
                cha[i]=s[0];
                id[(int)s[0]]=i;
                int weight;
                scanf("%d",&weight);
                node[i].weight=weight;
                q.push(i);
        }
        build();
        int root=2*n-1;
        get_code(root);
        for(int i=1;i<=n;i++){//print code
                printf("%c ",cha[i]);
                for(int j=code[i].size()-1;j>=0;j--){
                        printf("%d",code[i][j]);
                }
                printf("\n");
        }
        scanf("%s",ss);//text
        into_code(ss,strlen(ss));
        scanf("%s",ss);
        into_text(ss,strlen(ss),root);
        // for(int i=1;i<=root;i++){
        //      printf("%d %d\n",node[i].fa,node[i].weight);
        // }
        return 0;
}