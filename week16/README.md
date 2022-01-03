UVA299-Train Swapping:   
第一列有一個整數表示接下來有N組測試資料，每組測試資料兩列，  
第一列是一個整數L ，為車箱的長度，第二列為整數1~L的一種排列組合，  
表示車箱的起始位置，最後車箱要依照編號1到L的順序依序排好。  
(泡泡排序)
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
