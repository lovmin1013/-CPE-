#include <stdio.h>
int main()
{
	int a,b;
	while(scanf("%d %d",&a,&b)==2){
		if(a==0 && b==0) break;
		int c=0, ans=0;
		while(a>0 || b>0){
			int a1=a%10;
			int b1=b%10;
			if(c+a1+b1>=10){
				ans++;
				c=1;
			}else c=0;
			a=a/10;
			b=b/10;
		}
		if(ans==0) printf("No carry operation.\n");
		else if(ans==1) printf("1 carry operation.\n");
		else printf("%d carry operations.\n",ans);
	}
}
