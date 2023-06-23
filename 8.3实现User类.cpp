#include <string.h>
#include <iostream>
using namespace std;
class User
{
	char a[100][100],b[100][100];
	public:
		User(char *ak,char *bk)
		{
			if(ak!=NULL&&bk!=NULL)
			{
				strcpy(a[0],ak);
				strcpy(b[0],bk);
			}
		}
		void AddUser(char *c,char *d)
		{
			int i=0;
			while(a[i][0]!='\0')
			i++;
			strcpy(a[i],c);
            strcpy(b[i],d);
		}
		int login(char *name,char * pass)
		{
			int i=0;
			while(a[i][0]!='\0')
			{
				if((strcmp(a[i],name)==0)&&(strcmp(b[i],pass)==0))
				return i;
				i++;
			}
			if(a[i][0]=='\0')
			return -1;
			
		}
		
};
int main(){
	char name[10],name1[10],pass[10],pass1[10];
	cin>>name>>pass>>name1>>pass1;
	User user("LiWei","liwei101");
	user.AddUser(name,pass);
	if (user.login(name1,pass1) >=0)
	{
		cout<<"Success Login!"<<endl;
	}
	else{
		cout<<"Login failed!"<<endl;
	}
	  return 0;
}

