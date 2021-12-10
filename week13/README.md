UVA11321-Sort! Sort!! and Sort!!!  
給予N,M兩數，利用每個數字除以 M 的餘數由小到大排，  
若排序中相鄰的兩數為一奇一偶且兩數除以 M 的餘數相等，則奇數要在偶數前面。  
若兩奇數除以 M 餘數大小相等，則原本數值較大的奇數排在前面。  
同樣的，若兩偶數除以 M 餘數大小相等，則較小的偶數排在前面。  
```C
#include <stdio.h>
int a[10000];
void swap(int i, int j)
{
	int temp= a[i];
	a[i]= a[j];
	a[j]= temp;
}
int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m)==2){
		for(int i=0; i<n; i++){
			scanf("%d",&a[i]);
		}
		for(int i=0; i<n; i++){
			for(int j=i+1; j<n; j++){
				if(a[i]%m> a[j]%m) swap(i,j);
				if(a[i]%m== a[j]%m){
					if(a[i]%2==0 && a[j]%2!=0) swap(i,j);
					if(a[i]%2!=0 && a[j]%2!=0 && a[i]<a[j]) swap(i,j);
					if(a[i]%2==0 && a[j]%2==0 && a[i]>a[j]) swap(i,j);
				}
			}
		}
		printf("%d %d\n",n,m);
		for(int i=0; i<n; i++){
			printf("%d\n",a[i]);
		}
	}
}
```
UVA10107-What is the Median?  
僅一組，每行輸入一個數字，形成越來越長的數列  
每輸入一個數，就要輸出當前數列的中位數(排序後)  
EX:1 3 4 60 70 50 2 --> 1 2 3 3 4 27 4  
```C
#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b)
{
	return *(int *)a- *(int *)b;
}
int main()
{
	int a[10000]={0};
	int alen=0;
	
	while(scanf("%d",&a[alen])!=EOF){
		int median;
		if(alen==0){
			median =a[0];
		}
		else{
			qsort(a, alen+1, sizeof(int), cmp);
			int n=alen+1;
			if((n)%2==0){
				median= (a[n/2-1]+a[n/2-1+1])/2;
			}
			else{
				median= a[(n+1)/2-1];
			}
		}
		printf("%d\n",median);
		alen++;
	}
}
```
