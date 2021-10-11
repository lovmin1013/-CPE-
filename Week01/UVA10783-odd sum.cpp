#include <stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		int a,b,sum=0;
		scanf("%d %d",&a,&b);
		for(int k=a;k<=b;k++){
            if(k%2!=0) sum+=k;
		}
		printf("case %d:%d\n",i+1,sum);
	}
	return 1;
}
