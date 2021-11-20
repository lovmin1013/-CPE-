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
UVA10812-Beat the Spread!:  
給予兩隊最後的分數和，及兩隊最後分數差的絕對值  
計算出兩隊最終得分為何?  
```C
#include <stdio.h>
int main()
{
	int n,a,b;//a為兩數和 b為兩數差(絕對值)
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d %d",&a,&b);
		if(a<b||a<0||b<0||(a+b)%2==1) printf("impossible\n");
		//若和<差 或 和/差小於0 或 和加差餘為奇數
		else printf("%d %d\n",(a+b)/2,(a-b)/2);
	}
}
```
