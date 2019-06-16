#include <cstdio>
#include <cstdlib>
void swap(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void quickSort(int arr[] ,int start, int end)
{
    int arrBase,arrMiddle;
    int tempStart=start,tempEnd = end;
    if(tempStart>=tempEnd) return;
    //拷贝一个基准值作为后面比较的参数
    arrBase=arr[start];
    while(start<end)
    {
        while(start<end&&arr[end]>arrBase)end--;
        if(start<end)
        {
            swap(&arr[start], &arr[end]);
            start++;
        }
        while(start<end&&arr[start]<arrBase)start++;
        if(start<end)
        {
            swap(&arr[start],&arr[end]);
            end--;
        }
    }
    arr[start]=arrBase;
    arrMiddle=start;
    quickSort(arr,tempStart,arrMiddle-1);
    quickSort(arr,arrMiddle+1,tempEnd);
}

int main()
{
    int n;scanf("%d",&n);
    int a[110];
    for(int i=0;i<n;i++)scanf("%d",a+i);
    quickSort(a,0,n-1);
    for(int i = 0; i<n; i++)printf("%d ",a[i]);
    printf("\n");
    return 0;
}