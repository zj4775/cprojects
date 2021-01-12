#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

struct list{
	int* ele;
	int length;
};

void init_list(list** l){
	*l=(list*)malloc(sizeof(list));
	(*l)->ele=(int*)malloc(sizeof(int)*MAX);
	printf("�������ַ�������:\n");
	scanf("%d",&((*l)->length));
	srand((unsigned)time(NULL));
	for (int i=0;i<(*l)->length;i++)
	{
		printf("�������:%d��Ԫ��\n",i+1);
		scanf("%d",&((*l)->ele[i]));
		//(*l)->ele[i]=rand()%10+1;
	}
}



void print_list(list* l){
	printf("����ַ���:\n");
	for (int i=0;i<l->length;i++)
	{
		printf("%d  ",l->ele[i]);
	}
	printf("\n");
}

void exchange(int *x,int *y){
	int z=*x;
	*x=*y;
	*y=z;
}

void sort_list(list* l){
	for (int i=l->length-1;i>=0;i--)
	{
		for (int j=0;j<i;j++)
		{
			if (l->ele[j]>l->ele[j+1])
			{
				exchange(&l->ele[j],&l->ele[j+1]);
			}
		}
	}
}

void del_duplicate(list* l){
	int pre=-1;
	int k=0;
	for (int i=0;i<l->length;i++)
	{
		if (l->ele[i]!=pre)
		{
			pre=l->ele[i];
			l->ele[k++]=l->ele[i];
		}
	}
	l->length=k;
}

void reverse(char* l,int s,int e){
	
	for (int i=s;i<(s+e)/2;i++)
	{
		char tmp=l[i];
		l[i]=l[e-1+s-i];
		l[e-1+s-i]=tmp;
	}

}

/************************************************************************/
/* ab ���ba                                                                     */
/************************************************************************/
void revert(char* l,int m,int n){
	reverse(l,0,m+n);
	reverse(l,0,n);
	reverse(l,n,m+n);
}

/************************************************************************/
/* ��ѯx��������򽻻������Ǹ��������                                                                     */
/************************************************************************/
void insert_x(list* l,int x){
	int idx=0;
	int low=0;
	int high=l->length-1;
	int mid=0;
	while (low<=high)
	{
		mid=(low+high)/2;
		if (l->ele[mid]==x)
		{
			break;
		}else if (l->ele[mid]<x)
		{
			low=mid+1; //������ж��ַ�����ʱ����Ҫ��+1 ��-1 ����mid����
		}else{
			high=mid-1;
		}
	}
	if (l->ele[mid]==x&&mid!=l->length-1)
	{
		printf("�ҵ���x");
		exchange(&l->ele[mid],&l->ele[mid+1]);
	}else{
		printf("δ�ҵ�x");
		for (int i=l->length-1;i>=mid;i--)
		{
			l->ele[i+1]=l->ele[i];
		}
		l->ele[i+1]=x;
		l->length++;
	}
}

/************************************************************************/
/* ѭ�� ����Ԫ��p��λ��   �����Ͼ���ab ba����                                                                   */
/************************************************************************/

void move_p(list* l,int p){
	//revert(l,p,l->length);
}

/************************************************************************/
/* �ȳ����������ϵ���λ��                                                                     */
/************************************************************************/

int mid_num(list* l1,list* l2){
	int s1=0;
	int e1=l1->length-1;
	int s2=0;
	int e2=l2->length-1;
	int mid1=0;
	int mid2=0;
	while(s1!=e1||s2!=e2){
		mid1=(s1+e1)/2;
		mid2=(s2+e2)/2;
		if (l1->ele[mid1]==l2->ele[mid2])
		{
			return l1->ele[mid1];
		}else if (l1->ele[mid1]<l2->ele[mid2])
		{
			if ((s1+e1)%2==0) //������ �����м��
			{
				s1=mid1;
				e2=mid2;
			}else{
				s1=mid1+1;  //ż���� ��Ҫ�м�㣨��ΪҪһ��һ�룩
				e2=mid2;
			}
		}else{
			if ((s2+e2)%2==0) //������ �����м��
			{
				e1=mid1;
				s2=mid2;
				
			}else{
				e1=mid1;
				s2=mid2+1;  //ż���� ��Ҫ�м�㣨��ΪҪһ��һ�룩
			}
		}
	}
	return l1->ele[s1]<l2->ele[s2]?l1->ele[s1]:l2->ele[s2]; //��ʣ����Ԫ���ˣ���λ����С���Ǹ�
}

/************************************************************************/
/* ��Ԫ��                                                                     */
/************************************************************************/
void main_ele(list* l){
	int k=1;
	int i=0;
	int pre=l->ele[0];
	for (i=1;i<l->length;i++)
	{
		if (l->ele[i]==pre)
		{
			k++;
		}else{
			k--;
			if (k==0)
			{
				pre=l->ele[i];
				k=1;
			}
		}
	}
	int count=0;
	for (i=0;i<l->length;i++)
	{
		if (pre==l->ele[i])
		{
			count++;
		}
	}
	if (count>l->length/2)
	{
		printf("������Ԫ��:%d",pre);
	}else{
		printf("��������Ԫ��");
	}

}

int main(){
	list* l;
	init_list(&l);
	print_list(l);
	sort_list(l);
	print_list(l);
	//del_duplicate(l);
	//print_list(l);


	/*char* l=(char*)malloc(MAX);
	gets(l);
	puts(l);
	revert(l,9,5);
	puts(l);*/

	/*printf("������x��ֵ:\n");
	int x;
	scanf("%d",&x);
	insert_x(l,x);
	print_list(l);*/


	/*list* l2;
	init_list(&l2);
	print_list(l2);
	sort_list(l2);
	print_list(l2);

	int mid=mid_num(l,l2);
	printf("��λ��:%d",mid);*/


	main_ele(l);

    return 0;

	

}