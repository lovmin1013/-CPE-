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
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	while(scanf("%d", &n)!= EOF){
		int a[n];
		for(int i=0; i<n; i++){
			scanf("%d",&a[i]);
		}
		int check[n-1];//按順序排
		for(int i=0; i<n-1; i++){
			check[i]= i+1;
		}
		int diff[n-1];//計算相鄰數差
		for(int i=0; i<n-1; i++){
			diff[i] = abs(a[i+1]-a[i]);
		}
		for(int i=0; i<n-1; i++){
			for(int j=i+1; j<n-1; j++){
				if(diff[i]> diff[j]){
					int temp= diff[i];
					diff[i]= diff[j];
					diff[j]= temp;
				}
			}
		}
		int is_j= 1;
		for(int i=0; i<n-1; i++){
			if(diff[i]!= check[i]){
				is_j=0;
				break;
			}
			else{
				is_j=1;
			}
		}
		if(is_j == 1) printf("Jolly\n");
		else printf("Not jolly\n");
	}
}
```
UVA10189-Minesweeper:  
```C
#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a, b, m=1;
	while(cin>>a>>b){
		char n[a][b];
		if(a==0 && b==0) break;
		if(m!=1) cout<<endl;
		printf("Field #%d:\n", m);
		for(int i=0; i<a; i++){
			for(int j=0; j<b; j++){
				cin>>n[i][j];
			}
		}
		for(int i=0; i<a; i++){
			for(int j=0; j<b; j++){
				int c=0;
				if(n[i][j]=='*'){
					printf("%c",n[i][j]);
				}
				else{
					for(int k=j-1; k<=j+1; k++){
						if(k>=0 && k<b){
							if(i!=0 && n[i-1][k]=='*') c++;
							if(n[i][k]=='*') c++;
							if(i!=a-1 && n[i+1][k]=='*') c++;
						}
					}
					printf("%d",c);
				}
			}
			cout<<endl;
		}
		m++;
	}
}
```
