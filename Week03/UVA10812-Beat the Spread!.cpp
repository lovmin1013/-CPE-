#include <stdio.h>
int main()
{
	int n,a,b;//a����ƩM b����Ʈt(�����)
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d %d",&a,&b);
		if(a<b||a<0||b<0||(a+b)%2==1) printf("impossible\n");
		//�Y�M<�t �� �M/�t�p��0 �� �M�[�t�l���_��
		else printf("%d %d\n",(a+b)/2,(a-b)/2);
	}
}
