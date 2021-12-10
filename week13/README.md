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
