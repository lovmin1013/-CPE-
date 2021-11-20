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
