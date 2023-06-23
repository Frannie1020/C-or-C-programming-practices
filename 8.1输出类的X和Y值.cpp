#include<iostream> 
class Location
{
    private :
	int X,Y;
	public:
	void init(int initX,int initY)
	{
	     X = initX;
		 Y = initY;
	}
	int GetX()
	{
	    return X;
	}
	int GetY()
	{
	    return Y;
	}
};
int main()
{
     Location A1;
	 A1.init(20,90);
	 Location *rA1;     
	 rA1=&A1;
	 std::cout<<rA1->GetX()<<rA1->GetY();    ;
     return 0;	 
}
