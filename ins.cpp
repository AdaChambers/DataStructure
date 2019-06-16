#include<cstdio>
#include<cstring>
#include<cstdlib>
void insert_sort(int a[],int l)
{
    int i,temp,p;
    for(i=1;i<l;i++)
    {
        temp=a[i];
        p=i-1;
        while(p>=0 && temp<a[p]){
            a[p+1]=a[p];
            p--;
        }
        a[p+1]=temp;
    }
}

int main()
{
    int a[7]={2,4,1,5,3,9,7},l=sizeof(a)/sizeof(int);
    insert_sort(a,l);
    for (int i=0;i<l;i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}