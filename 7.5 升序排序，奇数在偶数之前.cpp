#include<iostream>
using namespace std;
int main(void)
{
    /*先把一组数s[]中的奇数a[]和偶数b[]取出来，分别排序，最后奇数在前面偶数在后面 */
    int i,j,count=0,a[10],b[10],tmp;
    for(i=0;i<10;i++)
    {
      cin>>a[i];
      for(j=i+1;j<=9;j++)
      {
      	if(a[j]<a[i])
      	{
      	  tmp=a[j];
		  a[j]=a[i];
		  a[i]=tmp;
		}
	  }
	}
	for(i=0;i<10;i++)
	{
		if(a[i]%2!=0)
		{
            b[count]=a[i];
            count++;
        }
	}
	for(i=0;i<10;i++)
	{
        if(a[i]%2==0)
		{
            b[count]=a[i];
            count++;
        }
    }
    for(i=0;i<10;i++)
    { 
	  cout<<b[i]<<" ";
	}
	return 0;
}
