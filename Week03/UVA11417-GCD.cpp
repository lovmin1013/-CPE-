///�̤j���]��
#include <stdio.h>
int gcd(int a,int b)
{  ///���j�p��GCD
	if(a==0) return b;
	else return gcd(b%a,a);
}  ///ex:n=4 �֥[gcd(1,2)(1,3)(1,4)(2,3)(2,4)(3,4)���`��
int main()
{
	int i,j,n,G;
	scanf("%d",&n);
	while(n){
		G=0;
		for(i= 1; i< n; i++){
        	for(j= i+1; j <=n; j++){
            	G= G +gcd(i, j);
        	}
		}
		printf("%d\n",G);
		scanf("%d",&n);
	}
	return 0;
}
