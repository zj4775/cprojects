#include<stdio.h>
#include <string.h>

void exchange(int _array[],int pre,int post){
	int t=_array[pre];
	_array[pre]=_array[post];
	_array[post]=t;
}




/************************************************************************/
/* ��������  O nlogn     �ȶ�                                                              */
/************************************************************************/
void quick_sort(int _array[],int start,int end){
	int i=start;
	int j=end;
	int _value=_array[start];
	while(i<j){
		while(i<j&&_value<_array[j]){
			j--;
		}
		if(i<j){
			_array[i]=_array[j];
			i++;
		}
		while(i<j&&_array[i]<_value){
			i++;
		}
		if(i<j){
			_array[j]=_array[i];
			j--;
		}
	}
		
	_array[i]=_value;
	if(start<i){
		quick_sort(_array,start,i-1);
	}
	if(j<end){
		quick_sort(_array,j+1,end);
	}


}
/************************************************************************/
/* �������� ��ȡ�ڴ����  O nlogn     �ȶ�                                                              */
/************************************************************************/
int quick_sort_k(int _array[],int start,int end,int k){
	int i=start;
	int j=end;
	int _value=_array[start];
	while(i<j){
		while(i<j&&_value>_array[j]){
			j--;
		}
		if(i<j){
			_array[i]=_array[j];
			i++;
		}
		while(i<j&&_array[i]>_value){
			i++;
		}
		if(i<j){
			_array[j]=_array[i];
			j--;
		}
	}
	_array[i]=_value;//�Ȱѿ��ŵ�Ԫ�طź�
	if(i-start+1==k){
		return _array[i];
	}
	else if (i-start+1>k)
	{
		return quick_sort_k(_array,start,i-1,k);
	}else{
		return quick_sort_k(_array,i+1,end,k-(i-start+1));
	}

	
}

/************************************************************************/
/* ð������   O n2    �ȶ�                                                              */
/************************************************************************/
void bubble_sort(int _array[],int length){
	for (int i=1;i<=length-1;i++)
	{
		for (int j=1;j<=length-i;j++)
		{
			if (_array[j]>_array[j+1])
			{
				exchange(_array,j,j+1);
			}
		}
	}
}

/************************************************************************/
/* ˫��ð������ O n2      �ȶ�                                                              */
/************************************************************************/


void bi_bubble_sort(int _array[],int length){
	int low=0;
	int high=length;
	bool need_work=true;
	while (low<high)
	{
		for (int i=low;i<high;i++)
		{
			if (_array[i]>_array[i+1])
			{
				exchange(_array,i,i+1);
				need_work=true;
			}
		}
		high--;
		if (need_work=false)
		{
			break;
		}
		for (int j=high;j>low;j--)
		{
			if (_array[j]<_array[j-1])
			{
				exchange(_array,j,j-1);
			}
		}
		low++;
	}

}


/************************************************************************/
/* ��������    O n2     �ȶ�                                                            */
/************************************************************************/
void insert_sort(int _array[],int length){
	for (int i=2;i<=length;i++)
	{
		int _value=_array[i];	
		int j=i-1;
		while (_array[j]>_value&&j>0)
		{
			_array[j+1]=_array[j];
			j--;
		}
		_array[j+1]=_value;
	}
}
/************************************************************************/
/* ϣ������   O nlogn-> O n2     ���ȶ�                                                             */
/************************************************************************/
void shell_sort(int _array[],int length){
	int d=length/2;
	while (d>=1)
	{
		/**
		*�����Ч�ڲ�������ֻ��������ֵ����1
		**/
		for (int i=d+1;i<=length;i++)
		{
			int j=i-d;
			int _value=_array[i];
			while (_array[j]>_value&&j>0)
			{
				_array[j+d]=_array[j];
				j-=d;
			}
			_array[j+d]=_value;
		}
		d=d/2;
	}
}

/************************************************************************/
/* ѡ������    O n2     ���ȶ�                                                            */
/************************************************************************/
void select_sort(int _array[],int length){
	for (int i=1;i<length;i++)
	{
		int min_idx=i;
		for (int j=i+1;j<=length;j++)
		{
			if (_array[j]<_array[min_idx])
			{
				min_idx=j;
				
			}
		}
		exchange(_array,i,min_idx);
	}
}
/************************************************************************/
/* �鲢����  map-reduce  O nlogn   �ȶ�                                                            */
/************************************************************************/

void merge(int _array[],int l,int m,int r){
	int _leftarray[20];
	int _rightarray[20];
	int i;
	int j;
	int k=l;
	//�Ȱ����鿽����ȥ���������һֱ�Ǻ����С�Ļ������ǰ���ǰ�������ݸǵ�
	for (i=l;i<m;i++)
	{
		_leftarray[i-l+1]=_array[i];//�±��1��ʼ
	}
	for (j=m;j<=r;j++)
	{
		_rightarray[j-m+1]=_array[j];//�±��1��ʼ
	}
	i=j=1; 
	//�����ǽ��������ֵ�Ԫ��ֵ�ϲ�����
	while (i<=m-l&&j<=r-m+1)//�����1����Ϊm�Ǵ��м�ֵ+1��ʼ�����
	{
		if (_leftarray[i]<=_rightarray[j])
		{
			_array[k]=_leftarray[i];
			k++;
			i++;
		}else{
			_array[k]=_rightarray[j];
			k++;
			j++;
		}
	}
	while (i<=m-l)
	{
		_array[k]=_leftarray[i];
		k++;
		i++;
	}
	while (j<=r-m+1)
	{
		_array[k]=_rightarray[j];
		k++;
		j++;
	}
	
	
}
void merge_sort(int _array[],int l,int r){

	if (l==r)
	{
		return ;
	}
	else{
		int mid=(l+r)/2;
		merge_sort(_array,l,mid);
		merge_sort(_array,mid+1,r);
		merge(_array,l,mid+1,r);
	}


}

/************************************************************************/
/* ��������              �ȶ�                                                       */
/************************************************************************/

int ilen(int num){
	int divide=10;
	int len=1;
	while (num/divide!=0)
	{
		len++;
		num=num/divide;
	}
	return len;
}

int get_divide(int l){
	int res=1;
	for (int i=1;i<=l;i++)
	{
		res*=10;
	}
	return res;
}

int max_len(int _array[],int length){
	int max=0;
	for (int i=1;i<=length;i++)
	{
		int l=ilen(_array[i]);
		if (l>max)
		{
			max=l;
		}
	}
	return max;
}


void print(int _array[],int length){
	printf("\n����Ԫ������:\n");
	for(int i=1;i<=length;i++){
		printf("%d  ",_array[i]); 
	}
}


void radix_sort(int _array[],int length){
	int max_length=max_len(_array,length);
	int count[10]={0};
	int data[10][20]={0};

	for (int i=1;i<=max_length;i++)//����Ļ����Ǵ�С����
	{
		int divide=get_divide(i);
		memset(count,0,sizeof(count));
		for (int j=1;j<=length;j++)
		{
			int m=_array[j]%divide;
			m=m*10/divide;
			count[m]+=1;
			data[m][count[m]]=_array[j];//��ά���飬�д�����Ǳ���Ļ���������ͬ�׻����ĵڼ���
		}
		//��������_array
		int k=1;
		
		for (int i=0;i<10;i++)
		{
			for (int j=1;j<=count[i];j++)
			{
				_array[k++]=data[i][j];//������װlist
			}
		}
	}
}

/************************************************************************/
/* ������       O nlogn                                                              */
/************************************************************************/

void adjust(int _array[],int s,int e){
	int i=s;
	int j=2*s;
	while(j<=e)
	{
		if (j<e&&_array[j]<_array[j+1])//����������j<e ����������
		{
			j++;
		}
		if (_array[i]<_array[j])
		{
			exchange(_array,i,j);//�����
			i=j;
			j=2*i;
		}else{
			break;
		}
	}
}

void heap_sort(int _array[],int length){
	for (int i=length/2;i>=1;i--)//���ѭ�������ÿ���ڵ��ֵ�������ĺ��Ӵ󣬲������ķ��ڵ�һ��
	{
		adjust(_array,i,length);
	}
	for (int s=length;s>=2;s--)
	{
		exchange(_array,1,s);//�������Ǹ�������һ�����������������
		adjust(_array,1,s-1);//�����Ժ���Ҫ���µ����ѣ��ٰѴδ���Ǹ��ŵ���һ��
	}
}


int main(){
	int _array[100];
	int n;
	printf("������Ԫ�ظ���:\n");
	scanf("%d",&n);
	printf("������%d��Ԫ��:\n",n);
	for(int i=1;i<=n;i++){
		scanf("%d",&_array[i]);
	}
	int m=0;

	int _newtarray[20];

	while (m!=-1)
	{
		for (int t=1;t<=n;t++)
		{
			_newtarray[t]=_array[t];
		}
		printf("�������ѯ�ڼ���Ԫ��:\n");
		scanf("%d",&m);
		int res=quick_sort_k(_newtarray,1,n,m);
		printf("��%d���������%d\n  ",m,res); 
	}


	


	//print(_array,n);
	/*for (int h=3;h<=6;h++)
	{
		int res=quick_sort_k(_array,1,n,h);
		printf("��%dС��������%d  ",h,res); 
	}*/
	
	
	//bubble_sort(_array,n);
	//insert_sort(_array,n);
	//shell_sort(_array,n);
	//select_sort(_array,n);
	//merge_sort(_array,1,n);
	//radix_sort(_array,n);
	//bi_bubble_sort(_array,n);
	//heap_sort(_array,n);
	//print(_array,n);
    return 0;

}