#include<stdio.h>
void tiaozheng(int a[],int k,int n)
{
	int i=k,j=2*i,temp;
	while(j<=n)
	{
		if(j<n&&a[j]<a[j+1]){j++;}//������������Ĵ���Ǹ�
		if(a[i]<a[j]){
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
			i=j;
			j=2*i;//ÿ������Ѵ�Ľڵ����ϵ��ˣ���ô�Ǹ�С�Ľڵ���ܶ��ڸ�С��������˵���ܾ��Ǵ�ֵ�ˣ����Ի�Ҫ��������
		}//���ڵ����Ϊ��ģ�����������Ļ�������ҲҪ������
		else{break;}
	}	
}
void tuipx(int a[],int leng)
{
	int i,temp;
	for(i=leng/2;i>=1;i--){tiaozheng(a,i,leng);}// ��ÿ���ڵ�ĸ��ڵ����Ϊ����������ѭ��i��СֵΪ1�����Ե�һ���ͻ������ֵ
	for(i=leng;i>=2;i--)//���ΰ����ֵ�ŵ����
	{ 
		temp=a[1];//�ѵ�һ�����ķŵ����
		a[1]=a[i];
		a[i]=temp;
		tiaozheng(a,1,i-1);//ÿ�ε������һ����������
	}
}
void print(int a[],int leng)
{
	int i;
	for(i=1;i<=leng;i++)
	{
		printf("%d  ",a[i]);
	}

}

int main()
{
	int i,a[100],leng=0;
	printf("��������Ҫ����ĸ���");
	scanf("%d",&leng);
	for(i=1;i<=leng;i++)
	{
		printf("�������%d������",i);
		scanf("%d",&a[i]);
	}
	printf("ԭ����Ϊ:");
	print(a,leng);
	tuipx(a,leng);
	printf("\n�����õ�����Ϊ:");
	print(a,leng);
    return 0;

}