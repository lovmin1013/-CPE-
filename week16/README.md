UVA299-Train Swapping:   
```C
#include <stdio.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		int a[n];
		int count=0;
		for(int i=0; i<n; i++){
			scanf("%d",&a[i]);
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<n-i-1; j++){
				if(a[j]>a[j+1]){
					int temp= a[j];
					a[j]= a[j+1];
					a[j+1]=temp;
					count++;
				}
			}
		}
		printf("Optimal train swapping takes %d swaps.\n",count);
	}
}
```
UVA10101-Bangla Numbers:  
```C

```
UVA10038-Jolly Jumpers:
```C

```
UVA10189-Minesweeper:  
```C

```
