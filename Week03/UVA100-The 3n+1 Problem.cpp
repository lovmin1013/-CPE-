#include <stdio.h>
int cyclelength(int n){
    int length=1;
    while(n!=1){
        if(n%2==0){
            n=n/2;
            length++;
        }
        else{
            n=n*3+1;
            length++;
        }
    }
    return length;
}
int main(void)
{
    int i,j,max;
    while(scanf("%d %d",&i,&j)!= EOF){
        max=1;
        if(i<j){
	        for(int n=i; n<=j; n++){
	            int len= cyclelength(n);
	            if(len>max) max=len;
	        }
	    }
	    else{
	    	for(int n=j; n<=i; n++){
	            int len= cyclelength(n);
	            if(len>max) max=len;
	        }
	    }
        printf("%d %d %d\n",i,j,max);
    }
}
