UVA10268-498bis:  

```C
#include <stdio.h>
int main()
{
	int n, x, i, a[50000];
	while(scanf("%d",&x) !=EOF){
		//如果有讀取到第一行x 就繼續計算
		for(n=0;;n++){
			scanf("%d",&a[n]);
			if(getchar()=='\n') break;
			//如果係數後是換行符號，就結束該組的輸入，並計算此組資料
		}
		int sum=a[0]*n;
		for(i=1; i<n; i++){
			sum= sum*x+a[i]*(n-i);
		}//每次乘x 再加下一項
		printf("%d\n",sum);
	}
}
```
