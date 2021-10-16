UVA10268-498bis:  
計算多項式微分之後的值 每組測資兩行  
第一行是 x 的值 第二行是 多項式各項係數  
EX: 2 (x=2) 1 1 1(x^2+x+1)  
微分後為2x+1 帶入x得答案為5  
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
