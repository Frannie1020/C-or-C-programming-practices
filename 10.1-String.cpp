#include <iostream>
#include <string.h>
using namespace std;
class String{
private:
	char *mystr;    //×Ö·û´®
	int len;    //×Ö·û´®³¤¶È
public:
	String(){
		len =0;
		mystr =NULL;
	}
	String(const char* p){
		len = strlen(p);
		mystr = new char[len+1];
		strcpy(mystr,p);
	}
	String(String &s){
		len = s.len;
		if (len !=0)
		{
			mystr = new char[len+1];
			strcpy(mystr,s.mystr);
		}
	}
	~String(){
         if (mystr != NULL)
         {
			 delete []mystr;
			 mystr =NULL;
			 len = 0;
         }
	}

	char *GetStr(){return mystr;}
	void ShowStr(){cout<<mystr;}

    bool IsSubstring(const char *str);
	bool IsSubstring(const String &str);
	int str2num();
	void toUppercase();
};

bool String::IsSubstring(const char *str)
{
	int l = strlen(str);
	if(l>len) 
	return false;
	for(int i=0;i<len-l;i++){
		for(int j=0;j<l;j++){
			if(str[j]!=mystr[i+j]){
				break ;
			}
			if(j==l-1){
				return true;
			} 
		}
	}
	return false ;
 } 
 bool String::IsSubstring(const String &str)
{
	if(str.len>len) return false;
	for(int i=0;i<len-str.len;i++){
		for(int j=0;j<str.len;j++){
			if(str.mystr[j]!=mystr[i+j]){
				break ;
			}
			if(j==str.len-1){
				return true;
			} 
		}
	}
	return false ;
}
 int String::str2num(){
	int a[10000];
	int pc=0;
	for(int i=0;i<len;i++){
		if(mystr[i]<='9'&&mystr[i]>='0'){
			a[pc++]=mystr[i]-'0';
		}
	}
	long long sum=0;
	for(int i=0;i<pc;i++){
		long long temp = 1;
		for(int j = 0;j<pc-i-1;j++){
			temp*=10;
		}	
		temp*=a[i];
		sum+=temp;
	}
	return sum;
}

void String::toUppercase(){
	for(int i=0;i<len;i++){
		if(mystr[i]>='a'&&mystr[i]<='z'){
			mystr[i]-='a'-'A';
		}
	}
}

int main(){
	String a("hiCprogramming");
	a.ShowStr();

	return 0;
}
 
