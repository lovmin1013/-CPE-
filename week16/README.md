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
#include <stdio.h>
void bangla(long long num)
{
	if( num >= 10000000){
		bangla(num/10000000);//超過7位數先處理前段
		printf(" kuti");
		num %= 10000000;//取出後7位
	}
	if( num >= 100000){
		printf(" %lld lakh", num/100000);//印出第6.7位
		num %= 100000;//取出後5位
	}
	if( num >= 1000){
		printf(" %lld hajar", num/1000);//印出第4.5位
		num %= 1000;//取出後3位
	}
	if( num >= 100){
		printf(" %lld shata", num/100);//印出第3位
		num %= 100;//取出後2位
	}
	if(num) printf(" %lld", num);//印出後2位
}
int main()
{
	long long num;
	long long count =0;
	while(scanf("%lld",&num)==1){
		printf("%4lld.",++count);
		if(num) bangla(num);//若資料非0 呼叫函式
		else printf(" 0");
		printf("\n");
	}
}
```
UVA10038-Jolly Jumpers:
```C

```
UVA10189-Minesweeper:  
```C

```
