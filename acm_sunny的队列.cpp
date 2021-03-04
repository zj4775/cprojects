//维护滑动窗口的最大值和最小值,单调队列实现，因为每个数只出和进一次，所以时间复杂度是O(n)
/*
单调递减队列是这么一个队列，它的头元素一直是队列当中的最大值，
而且队列中的值是按照递减的顺序排列的。我们可以从队列的末尾插入一个元素，
可以从队列的两端删除元素。
1.首先看插入元素：为了保证队列的递减性，我们在插入元素v的时候，
要将队尾的元素和v比较，如果队尾的元素不大于v,则删除队尾的元素，
然后继续将新的队尾的元素与v比较，直到队尾的元素大于v,这个时候我们才将v插入到队尾。
2.队尾的删除刚刚已经说了，那么队首的元素什么时候删除呢？
由于我们只需要保存i的前k-1个元素中的最大值，
所以当队首的元素的索引或下标小于i-k+1的时候，
就说明队首的元素对于求f(i)已经没有意义了，因为它已经不在窗里面了。
所以当index[队首元素]<i-k+1时，将队首元素删除。
*/
//g++超时，c++过了
#include<cstdio>
#include<iostream>
using namespace std;
const int mn=1e6+10;
int a[mn],q[mn],n,k;
void workmin()
{
    int l=1,r=0,i=0;
    for(; i<k-1; i++)
    {
        while(l<=r&&a[q[r]]>a[i]) r--;
        q[++r]=i;
    }
    for(; i<n; i++)
    {
        if(q[l]<=i-k) l++;
        while(l<=r&&a[q[r]]>a[i]) r--;
        q[++r]=i;
        printf("%d ",a[q[l]]);
    }
    puts("");
}
void workmax()
{
    int l=1,r=0,i=0;
    for(; i<k-1; i++)
    {
        while(l<=r&&a[q[r]]<a[i]) r--;
        q[++r]=i;
    }
    for(; i<n; i++)
    {
        if(q[l]<=i-k) l++;
        while(l<=r&&a[q[r]]<a[i]) r--;
        q[++r]=i;
        printf("%d ",a[q[l]]);
    }
    puts("");
}
int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        for(int i=0; i<n; i++)
            scanf("%d",a+i);
        //workmin();
        workmax();
    }
    return 0;
}