#include<stdio.h>
02
  
03
int main()
04
{
05
    int a[10],j[10]={0},o[10]={0},m=0,n=0,temp=0,i=0,jcount=0,ocount=0;
06
    while(scanf("%d %d %d %d %d %d %d %d %d %d",&a[0],&a[1],&a[2],&a[3],&a[4],&a[5],&a[6],&a[7],&a[8],&a[9])!=EOF)
07
    {
08
        for(i=0,ocount=0,jcount=0;i<10;i++)
09
        {
10
            if(a[i]%2==1)
11
            {
12
              j[jcount]=a[i];
13
              jcount++;
14
            }
15
            else
16
            {
17
                o[ocount]=a[i];
18
                ocount++;
19
            }
20
        }
21
        for(m=0;m<jcount;m++)//ц╟ещ
22
        {
23
           for(n=0;n<jcount-m-1;n++)
24
               if(j[n+1]>j[n])
25
               {
26
                   temp=j[n];
27
                   j[n]=j[n+1];
28
                   j[n+1]=temp;
29
               }
30
        }
31
  
32
        for(m=0;m<ocount;m++)
33
            for(n=ocount-1;n-m>0;n--)
34
            {
35
                if(o[n]<o[n-1])
36
                {
37
                    temp=o[n-1];
38
                    o[n-1]=o[n];
39
                    o[n]=temp;
40
                }
41
            }
42
        if(ocount>0)
43
        {
44
            for(i=0;i<jcount;i++)
45
            printf("%d ",j[i]);
46
            for(i=0;i<ocount-1;i++)
47
            printf("%d ",o[i]);
48
            printf("%d",o[ocount-1]);
49
        }
50
        else
51
        {
52
            for(i=0;i<jcount-1;i++)
53
            printf("%d ",j[i]);
54
            printf("%d",j[jcount-1]);
55
  
56
        }
57
  
58
        printf("\n");
59
  
60
    }
61
    return 0;
62
  
63
}

