#include<iostream>
using namespace std;
int main(void)
{
    /*�Ȱ�һ����s[]�е�����a[]��ż��b[]ȡ�������ֱ��������������ǰ��ż���ں��� */
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
