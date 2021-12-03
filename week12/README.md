UVA10062-Tell me the frequencies:  
給予字串，轉換為ASCII碼 並計算出現之次數。  
(每行最多2000個字母，由小到大排序)  
```C
#include <stdio.h>
char line[2000];
int main()
{
	for(int t=0; gets(line); t++){
		int ans[256]={};
		char  c[256]={};
		for(int i=0; i<256; i++) c[i]=i;

		for(int i=0; line[i]!=0; i++){
			char c= line[i];
			ans[c]++;
		}

		for(int i=0; i<256; i++){
			for(int j=i+1; j<256; j++){
				if(ans[i]>ans[j]){
					int temp=ans[i];
					ans[i]=ans[j];
					ans[j]=temp;
					char t=c[i];
					c[i]=c[j];
					c[j]=t;
				}
				if(ans[i]==ans[j] && c[i]<c[j]){
					int temp=ans[i];
					ans[i]=ans[j];
					ans[j]=temp;
					char t=c[i];
					c[i]=c[j];
					c[j]=t;
				}
			}
		}
		if(t>0) printf("\n");
		for(int i=0; i<256; i++){
			if(ans[i]>0) printf("%d %d\n",c[i],ans[i]);
		}
	}
}
```
UVA10420-List of Conquests(計算國名):  
輸入有幾筆資料(<2000)，讀入之字串最多75個字元  
輸出要照(A-Z)進行排序  
```C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char line[2000][75];
char other[100];
int compare(const void *p1, const void *p2)
{
	char *s1= (char*)p1;
	char *s2= (char*)p2;
	return strcmp(s1, s2);
}
int main()
{
	int n;
	scanf("%d",&n);
	
	for(int i=0; i<n; i++){
		scanf("%s",line[i]);
		gets(other);
	}
	qsort(line, n, 75, compare);
	
	int ans=1;
	printf("%s ",line[0]);
	for(int i=0; i<n-1; i++){
		if(strcmp(line[i],line[i+1])!=0){
			printf("%d\n",ans);
			printf("%s ",line[i+1]);
			ans=1;
		}
		else ans++;
	}
	printf("%d\n",ans);
}
```
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
