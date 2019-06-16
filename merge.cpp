#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
//二路归并
void _Merge(int a[], int begin1, int end1, int begin2, int end2, int *tmp)
{
	int index=begin1;
	int i=begin1, j=begin2;
	while (i<=end1&&j<=end2){
		if (a[i]<=a[j]) tmp[index++]=a[i++];
		else tmp[index++]=a[j++];
	}
	while (i<=end1)
		tmp[index++]=a[i++];
	while (j <= end2)
		tmp[index++]=a[j++];
	//将tmp中的数据拷贝到原数组对应的序列区间
	memcpy(a+begin1, tmp+begin1, sizeof(int)*(end2-begin1+1));
}
void MergeSort(int *a, int left, int right, int *tmp)
{
	if (left>=right)return;
	//assert(a);
	int mid=left+((right-left)>>1);
	MergeSort(a,left,mid,tmp);
	MergeSort(a,mid+1,right,tmp);
	_Merge(a,left,mid,mid+1,right,tmp);
}
int main()
{
	int n;
	int a[110];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",a+i);
	}
	int *tmp = (int *)malloc(sizeof(int)*(sizeof(a)/sizeof(int)));
	memset(tmp,-1,sizeof(tmp)/sizeof(int));
	MergeSort(a,0,n-1,tmp);
	for(int i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	printf("\n");
	return 0;
}
