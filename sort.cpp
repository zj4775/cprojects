#include<stdio.h>
#include <string.h>

void exchange(int _array[],int pre,int post){
	int t=_array[pre];
	_array[pre]=_array[post];
	_array[post]=t;
}




/************************************************************************/
/* 快速排序  O nlogn     稳定                                                              */
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
/* 快速排序 获取第大的数  O nlogn     稳定                                                              */
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
	_array[i]=_value;//先把快排的元素放好
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
/* 冒泡排序   O n2    稳定                                                              */
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
/* 双向冒泡排序 O n2      稳定                                                              */
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
/* 插入排序    O n2     稳定                                                            */
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
/* 希尔排序   O nlogn-> O n2     不稳定                                                             */
/************************************************************************/
void shell_sort(int _array[],int length){
	int d=length/2;
	while (d>=1)
	{
		/**
		*这个等效于插入排序，只不过步伐值不是1
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
/* 选择排序    O n2     不稳定                                                            */
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
/* 归并排序  map-reduce  O nlogn   稳定                                                            */
/************************************************************************/

void merge(int _array[],int l,int m,int r){
	int _leftarray[20];
	int _rightarray[20];
	int i;
	int j;
	int k=l;
	//先把数组拷贝出去，否则如果一直是后面的小的话，会把前面那半个的数据盖掉
	for (i=l;i<m;i++)
	{
		_leftarray[i-l+1]=_array[i];//下标从1开始
	}
	for (j=m;j<=r;j++)
	{
		_rightarray[j-m+1]=_array[j];//下标从1开始
	}
	i=j=1; 
	//以下是将两个部分的元素值合并起来
	while (i<=m-l&&j<=r-m+1)//这里加1是因为m是从中间值+1开始计算的
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
/* 基数排序              稳定                                                       */
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
	printf("\n数组元素如下:\n");
	for(int i=1;i<=length;i++){
		printf("%d  ",_array[i]); 
	}
}


void radix_sort(int _array[],int length){
	int max_length=max_len(_array,length);
	int count[10]={0};
	int data[10][20]={0};

	for (int i=1;i<=max_length;i++)//排序的基底是从小到大
	{
		int divide=get_divide(i);
		memset(count,0,sizeof(count));
		for (int j=1;j<=length;j++)
		{
			int m=_array[j]%divide;
			m=m*10/divide;
			count[m]+=1;
			data[m][count[m]]=_array[j];//二维数组，行代表的是被求的基数，列是同底基数的第几个
		}
		//重新排序_array
		int k=1;
		
		for (int i=0;i<10;i++)
		{
			for (int j=1;j<=count[i];j++)
			{
				_array[k++]=data[i][j];//重新组装list
			}
		}
	}
}

/************************************************************************/
/* 堆排序       O nlogn                                                              */
/************************************************************************/

void adjust(int _array[],int s,int e){
	int i=s;
	int j=2*s;
	while(j<=e)
	{
		if (j<e&&_array[j]<_array[j+1])//这里必须加上j<e 否则结果会错的
		{
			j++;
		}
		if (_array[i]<_array[j])
		{
			exchange(_array,i,j);//大根堆
			i=j;
			j=2*i;
		}else{
			break;
		}
	}
}

void heap_sort(int _array[],int length){
	for (int i=length/2;i>=1;i--)//这个循环跑完后每个节点的值都比他的孩子大，并且最大的放在第一个
	{
		adjust(_array,i,length);
	}
	for (int s=length;s>=2;s--)
	{
		exchange(_array,1,s);//把最大的那个数（第一个）跟后面的数交换
		adjust(_array,1,s-1);//交换以后需要重新调整堆，再把次大的那个放到第一个
	}
}


int main(){
	int _array[100];
	int n;
	printf("请输入元素个数:\n");
	scanf("%d",&n);
	printf("请输入%d个元素:\n",n);
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
		printf("请输入查询第几个元素:\n");
		scanf("%d",&m);
		int res=quick_sort_k(_newtarray,1,n,m);
		printf("第%d大的数字是%d\n  ",m,res); 
	}


	


	//print(_array,n);
	/*for (int h=3;h<=6;h++)
	{
		int res=quick_sort_k(_array,1,n,h);
		printf("第%d小的数字是%d  ",h,res); 
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