#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <dir.h>//����ͷ�ļ�
using namespace std;
string key[4]={"000","111","222","333"};//���벻ͬ��ģʽ����һ��key����ѡ��guest��Ӧ111��manager��Ӧ222��admin��Ӧ333 
int n=0;
fstream fs;//���ڴ��ж�ȡ.txt�ļ� 
ofstream ofs;// ���ڴ浽Ӳ�� 
class score
{
public:

    float cpp;
    float chinese;//������ѧӢ��ɼ� 
    float math;
    float english;

};
class student//ѧ���Ļ�����Ϣ�ĵ���
{
public:
    long int id; //���������ѧ�� ���� �༶ �Ա� ���� ����
    string name;
    int clas;
    char sex;
    int age;
    score sc;
    //student operator=(student &stu) const;
};
template<typename T>//�ȽϺ��� ����ģ�滯
int comp(T q,T w)
{
    if(q>w)
        return 1;
    else return 0;
}
student a[100000];//ѧ������������ϴ󣬿��԰���������ȫУ��ѧ�����൱��n�� ����ʵ������軹�ܲ���ָ��Ӷ�̬Ӳ���ж�ȡ���� 
student temp;
class person//����Ȩ�޵����ã��Ǳ��ͻ��ǹ���Ա 
{
public:
    virtual int authority();//����̳е�д��
    virtual int menu();
    virtual string psk()
    {
        return key[0];
    }
};
class wkr:public person
{
public:
    void out()//�ļ������������Ļ ����
    {
        cout<<"outputing!"<<endl;cout<<" id   name class sex age  cpp eng math"<<endl;//��仰����˼�ǣ����ڴ��ļ��е������ݵ���Ļ��
        int i;
        fs.open("t.dat",ios::in|ios::out);
        for(i=0; i<n; i++)//���ļ���ֱ���������Ļ
        {
            fs>>temp.id>>temp.name>>temp.clas>>temp.sex>>temp.age>>temp.sc.cpp>>temp.sc.chinese>>temp.sc.math>>temp.sc.english;
            cout<<" "<<temp.id<<"  "<<temp.name<<"  "<<temp.clas<<"     "<<temp.sex<<"  "<<temp.age;
            cout<<"     "<<temp.sc.cpp<<' '<<temp.sc.chinese<<' '<<temp.sc.math<<' '<<temp.sc.english<<endl;//���ļ��ж�ȡ����Ӣ�ɼ� 
        }
        fs.close();//�ر��ļ� 
    };
    int find(long int tg,int op=0)//���Һ��� 0����ѧ�� 1����༶
    {
        int i,j, fg=0;
        if(op==0)
        {
            fg=0;
            for(i=0; i<n; i++)
            {
                if(a[i].id==tg)
                {
                    cout<<a[i].id<<' '<<a[i].name<<' '<<a[i].clas<<' '<<a[i].sex<<' '<<a[i].age<<endl;
                    cout<<a[i].sc.cpp<<' '<<' '<<a[i].sc.chinese<<' '<<a[i].sc.math<<a[i].sc.english<<endl;
                    fg=1;
                    j=i;
                }
            }
            if(fg==0)
                cout<<"Not Found!"<<endl;//�Ҳ��� 
        }
        else if(op==1)
        {
            fg=0;
            for(i=0; i<n; i++)
            {
                if(a[i].clas==tg)
                {
                    cout<<a[i].id<<' '<<a[i].name<<' '<<a[i].clas<<' '<<a[i].sex<<' '<<a[i].age<<endl;
                    cout<<a[i].sc.cpp<<' '<<a[i].sc.chinese<<' '<<a[i].sc.math<<' '<<a[i].sc.english<<endl;
                    fg=1;
                    j=i;
                }
            }
            if(fg==0)
                cout<<"Not Found!"<<endl;//�Ҳ��� 
        }
        return j;
    };
    int find(string name)//���Һ��������ڴ����ҵ���Ӧ��ѧ�� 
    {
        int i,j,fg=0;
        fg=0;
        for(i=0; i<n; i++)
        {
            if(a[i].name==name)
            {
                cout<<a[i].id<<' '<<a[i].name<<' '<<a[i].clas<<' '<<a[i].sex<<' '<<a[i].age<<endl;
                cout<<a[i].sc.cpp<<' '<<a[i].sc.chinese<<' '<<a[i].sc.math<<' '<<a[i].sc.english<<endl;
                fg=1;
                j=i;
            }
        }
        if(fg==0)
        {
            cout<<"Not Found!"<<endl;//�Ҳ��� 
            return -1;
        }
        return j;
    }
    void sortor()//������ 
    {
        int k,j,op;
        cout<<"how to sort?(0,1,2,3,4 for cpp,chin,math,eng and average): ";//�����򷽷�����ѡ�� 
        extern void reget();reget();
        cin>>op;
        if(op==0)
        {
            for(j=0; j<n-1; j++)
                for(k=j+1; k<n; k++)
                {
                    if(comp(a[j].sc.cpp,a[k].sc.cpp))
                        swap(a[j],a[k]);//������ð�������ԭ���Ƚ��ܳɼ��Ĵ�С���ٽ����������� 
                }
        }
        else if(op==1)
        {
            for(j=0; j<n-1; j++)

                for(k=j+1; k<n; k++)
                {
                    if(comp(a[j].sc.chinese,a[k].sc.chinese))
                        swap(a[j],a[k]);
                }
        }
        else if(op==2)
        {
            for(j=0; j<n-1; j++)

                for(k=j+1; k<n; k++)
                {
                    if(comp(a[j].sc.math,a[k].sc.math))
                        swap(a[j],a[k]);
                }
        }
        else if(op==3)
        {
            for(j=0; j<n-1; j++)

                for(k=j+1; k<n; k++)
                {
                    if(comp(a[j].sc.english,a[k].sc.english))
                        swap(a[j],a[k]);
                }
        }
        else if(op==4)//�ܷ���������
        {
            for(j=0; j<n-1; j++)

                for(k=j+1; k<n; k++)
                {
                    if(comp(a[j].sc.chinese+a[j].sc.math+a[j].sc.cpp+a[j].sc.english,a[k].sc.chinese+a[k].sc.math+a[k].sc.cpp+a[k].sc.english))
                        swap(a[j],a[k]);
                }
        }
        else
            cout<<"not support"<<endl;
        cout<<"sorted!"<<endl;//������ɵ�֪ͨ 
        extern void rewrite();rewrite();//ֱ�Ӹ����ļ�
    }
    virtual string psk()
    {
        return key[1];
    }
    void backup()//���˳��򣬽����µ�ѡ�� 
    {
        cout<<"backing up..."<<endl;
        extern void reget();reget();
        ifstream f;
        int i=0;
        string line;
        ofs.open("backup.dat");
        fs.open("t.dat",ios::in|ios::out);
        while(!fs.eof())
        {
            getline(fs,line);
            ofs<<line<<endl;
        }
        ofs.close();
        fs.close();
        cout<<"successfully backed up"<<endl;
    }
    void restore()//�洢���� 
    {
        extern void reget();reget();extern void rewrite();
        int i,j,id;string s1,s2;s1="backup";s2=".dat";char code[3];ifstream f;
        cout<<"input ID to choose a student to restore:"<<endl;
        cin>>id;
        f.open("backup.dat");
        if(f.fail())//�Ҳ���
        {
            f.close();
            cout<<"no back up found"<<endl;
            return;
        }
        else
        {
            string tp;
            int flag=0;
            f.open("backup.dat");
            while(!f.eof())
            {
                f>>temp.id>>temp.name>>temp.clas>>temp.sex>>temp.age>>temp.sc.cpp>>temp.sc.chinese>>temp.sc.math>>temp.sc.english;
                if(temp.id==id)
                {
                    flag=1;break;
                }
            }
            if(flag==0)
            {
                cout<<"no record in this file"<<endl;
                restore();
            }
            else
            {
                flag=0;
                for(j=0;j<n;j++)
                {
                    if(a[j].id==id)
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag)
                {
                    a[j]=temp;
                    rewrite();
                    cout<<"restored"<<endl;
                }
                else
                {
                    a[n]=temp;n++;
                    rewrite();
                    cout<<"refilled and restored"<<endl;
                }
            }
        }
        f.close();
    }
    virtual int menu()//guest�Ĳ˵� 
    {
        int op,m;
        cout<<" 1 find; 2 list ; 3 logout ; 0 help"<<endl;cin>>op;
        if(op==1)
        {
            extern int finder();
            m=finder();
        }
        else if(op==2)
        {
            out();
        }
        else if(op==3)
        return 0;
        else if(op==0)
        {
            extern void help();help();
        }
        menu();
    }
};
class mgr:public wkr
{
public:
    void add()//������� д���ݵ��ļ���ĩβ��app�� �����n�Զ���1
    {
        cout<<"adding an item"<<endl;
        cout<<"id name class sex age || cpp chin eng math:"<<endl;
        fs.open("t.dat",ios::app);
        cin>>temp.id>>temp.name>>temp.clas>>temp.sex>>temp.age>>temp.sc.cpp>>temp.sc.chinese>>temp.sc.math>>temp.sc.english;
        fs<<temp.id<<' '<<temp.name<<' '<<temp.clas<<' '<<temp.sex<<' '<<temp.age<<' '<<temp.sc.cpp<<' '<<temp.sc.chinese<<' '<<temp.sc.math<<' '<<temp.sc.english<<endl;
        fs.close();
        n++;
        extern void reget();reget();
    }
    void change(int num)//�ı亯��
    {
        extern void reget();reget();
        cout<<"change to : id name class sex age ||cpp chin eng math:"<<endl;
        cin>>temp.id>>temp.name>>temp.clas>>temp.sex>>temp.age>>temp.sc.cpp>>temp.sc.chinese>>temp.sc.math>>temp.sc.english;
        ifstream fin;
        ofstream fout;
        string ts;
        int i;
        fin.open("t.dat");fout.open("temp.tp");
        for(i=0;i<n;i++)
        {
            getline(fin,ts);
            if(i!=num)
            {
                fout<<ts<<endl;
            }
            else
            {
                fout<<temp.id<<' '<<temp.name<<' '<<temp.clas<<' '<<temp.sex<<' '<<temp.age<<' '<<temp.sc.cpp<<' '<<temp.sc.chinese<<' '<<temp.sc.math<<' '<<temp.sc.english<<endl;
            }
        }
        fin.close();fout.close();
        fin.open("temp.tp");fout.open("t.dat");
        for(i=0;i<n;i++)
        {
            getline(fin,ts);
            fout<<ts<<endl;
        }
        fin.close();fout.close();
        extern void reget();reget();
        cout<<"changed!"<<endl;
    }
    void dele(int num)//ɾ������
    {
        int i;
        ifstream fin;ofstream fout;string ts;
        fin.open("t.dat");fout.open("temp.tp");
        for(i=0;i<n;i++)
        {
            getline(fin,ts);
            if(i!=num)
            {
                fout<<ts<<endl;
            }
        }
        fin.close();fout.close();
        fin.open("temp.tp");fout.open("t.dat");n--;
        for(i=0;i<n;i++)
        {
            getline(fin,ts);
            fout<<ts<<endl;
        }
        fin.close();fout.close();
        cout<<"item deleted"<<endl;
        extern void reget();reget();
    }
    virtual string psk()
    {
        return key[2];
    }
    virtual int menu()//manager�Ĳ˵� 
    {
        int op,m;extern int finder();extern void del(int num);
        cout<<" 1 find; 2 list ; 3 sort ; 4 change ; 5 delete ; 6 add ; 7 logout ;0 help"<<endl;
        cout<<"11 back up; 22 restore"<<endl;
        cin>>op;
        if(op==1)
        {
            m=finder();
        }
        if(op==2)
        {
            out();
        }
        if(op==3)
        {
            sortor();
            out();
        }
        if(op==4)
        {
            change(finder());out();
        }
        if(op==5)
        {
            del(finder());
        }
        if(op==6)
            add();
        if(op==7)
        return 0;
        else if(op==0)
        {
            extern void help();help();
        }
        if(op==11)
        backup();
        if(op==22)
        restore();
        menu();
    }
};
class root: public mgr
{
    public:
    virtual string psk()
    {
        return key[3];
    }
    virtual int menu()
    {
        int op,m;extern int finder();extern void del(int num);
        string tmpsk;
        cout<<endl<<"1 find; 2 list ; 3 sort ; 4 change ; 5 delete ; 6 add ; 7 logout"<<endl<<"8 change psk ; 0 help"<<endl;
        cout<<"11 back up; 22 restore"<<endl;
        cin>>op;
        if(op==1)
        {
            finder();
        }
        if(op==2)
        {
            out();
        }
        if(op==3)
        {
            sortor();
            out();
        }
        if(op==4)
        {
            change(finder());out();
        }
        if(op==5)
        {
            del(finder());
        }
        if(op==6)
        add();
        if(op==7)
        return 0;
        if(op==8)
        {
            cout<<"account:1 guest; 2 mgr ; 3 admin :"; cin>>m;//�����ݿ��޸�����
            cout<<"new psk:";cin>>tmpsk; key[m]=tmpsk;cout<<"psk refreshed!"<<endl;
            ofs.open("key.dat");
            ofs<<key[0]<<' '<<key[1]<<' '<<key[2]<<' '<<key[3]<<endl;
            ofs.close();
        }
        else if(op==0)
        {
            extern void help();help();
        }
        if(op==11)
        backup();
        if(op==22)
        restore();
        menu();
    }
};
root rt;

int person:: authority()//ģ����Ȩ
{
    string pk;int un;
    person *p;
    cout<<"Login as   1,guest 2,manager 3,admin:";cin>>un;
    cout<<"password:";cin>>pk;
    if(un==1)
    {
        p=new wkr;
        if((*p).psk()==pk)
        {
            cout<<"welcome guest"<<endl;//��ӭ 
            return 1;
        }
        delete(p);
    }
    else if(un==2)
    {
        p=new mgr;
        if((*p).psk()==pk)
        {
            cout<<"welcome manager"<<endl;
            return 2;
        }
        delete(p);
    }
    else if(un==3)
    {
        p=new root;
        if((*p).psk()==pk)
        {
            cout<<"welcome superAdmin"<<endl;
            return 3;
        }
        delete(p);
    }
    cout<<"δ��֤��"<<endl;

    return authority();
}
int finder()//ģ�����
{
    int opr,dat;
    string name;
    long int ser;
    cout<<"how to search?(0,1,2,3,4 for id,classnumber,name,top,last):";
    cin>>opr;
    if(opr==0)
    {
        cout<<"input id to search:";//ѧ�� 
        cin>>ser;
        dat=rt.find(ser,0);
    }
    else if(opr==1)
    {
        cout<<"input class number to search:";//�༶�� 
        cin>>ser;
        dat=rt.find(ser,1);
    }
    else if(opr==2)
    {
        cout<<"input name to search:";//ѧ������ 
        cin>>name;
        dat=rt.find(name);
    }
    else if(opr==3)
    {
                int j,k;
                for(j=0; j<n-1; j++)
                for(k=j+1; k<n; k++)
                {
                    if(comp(a[j].sc.chinese+a[j].sc.math+a[j].sc.cpp+a[j].sc.english,a[k].sc.chinese+a[k].sc.math+a[k].sc.cpp+a[k].sc.english))
                        swap(a[j],a[k]);
                }
                cout<<a[n-1].id<<' '<<a[n-1].name<<' '<<(a[n-1].sc.math+a[n-1].sc.cpp+a[n-1].sc.english)/3<<endl;
                dat=n-1;
    }
    else if(opr==4)
    {
                int j,k;
                for(j=0; j<n-1; j++)
                for(k=j+1; k<n; k++)
                {
                    if(comp(a[j].sc.chinese+a[j].sc.math+a[j].sc.cpp+a[j].sc.english,a[k].sc.chinese+a[k].sc.math+a[k].sc.cpp+a[k].sc.english))
                        swap(a[j],a[k]);
                }
                cout<<a[0].id<<' '<<a[0].name<<' '<<(a[0].sc.chinese+a[0].sc.math+a[0].sc.cpp+a[0].sc.english)/3<<endl;
                dat=0;//����ƽ���� 
    }
    cout<<"again?(0 or 1)";//�Ƿ�Ҫ������������� 
    cin>>opr;
    if(opr)
        return finder();
    else
    {
        cout<<"operation locked"<<endl;
        return dat;
    }
}
void output()//ģ�����
{
    rt.out();
}
void del(int num)//ģ��ɾ��
{
    char op;
    cout<<"delete this?(y/n):";
    cin>>op;
    if(op=='y')
    {
        rt.dele(num);
        cout<<"this one deleted"<<endl;
    }
}
int person::menu()
{
    int op,m;
    cout<<"1  login"<<endl<<"2  exit"<<endl; cin>>op;
    if(op==1)
    {
        return authority();
    }
    else if(op==2)
    {
        exit(0);
    }
}
void control()//���̿���ģ��
{
    int athy=0;
    person pson;
    athy=pson.menu();
    if(athy==1)
    {
        wkr exe;
        exe.menu();
    }
    else if(athy==2)
    {
        mgr exe;
        exe.menu();
    }
    else if(athy==3)
    {
        root exe;
        exe.menu();
    }
    control();
}
void rewrite()
{
    int i;
    ofs.open("t.dat");
    for(i=0;i<n;i++)
    {
        ofs<<a[i].id<<' '<<a[i].name<<' '<<a[i].clas<<' '<<a[i].sex<<' '<<a[i].age<<' '<<a[i].sc.cpp<<' '<<a[i].sc.chinese<<' '<<a[i].sc.math<<' '<<a[i].sc.english<<endl;
    }
    ofs.close();
    ofs.open("key.dat");
    ofs<<key[0]<<' '<<key[1]<<' '<<key[2]<<' '<<key[3]<<endl;
    ofs.close();
}
void reget()
{
    int i;
    fs.open("t.dat",ios::in|ios::out);n=0;
    while(!fs.eof())//���ȡ
    {
        fs>>a[n].id>>a[n].name>>a[n].clas>>a[n].sex>>a[n].age>>a[n].sc.cpp>>a[n].sc.chinese>>a[n].sc.math>>a[n].sc.english;
        n++;
    }
    fs.close();
    fs.open("key.dat",ios::in|ios::out);
    fs>>key[0]>>key[1]>>key[2]>>key[3];
    fs.close();
}
void help()//�������� 
{
    ifstream f;
    fs.open("help.chm",ios::in);
    if(fs.fail())
    {
        fs.close();
        cout<<"cannot find the help file, please verify the files."<<endl;
    }
    else
    {
        string s;
        while(!fs.eof())
        {
            getline(fs,s);
            cout<<s<<endl;
        }
        fs.close();
    }
}
int main()
{
    int i,j,op;
    char ch;
    fs.open("key.dat",ios::in|ios::out);
    fs>>key[0]>>key[1]>>key[2]>>key[3];fs.close();//��ȡ����
    fs.open("t.dat",ios::in|ios::out);
    if(fs.fail()||fs.eof())//����Ϣ
    {
        fs.close();
        ofs.open("t.dat");
        //fs<<key[0]<<' '<<key[1]<<' '<<key[2]<<' '<<key[3]<<' '<<key[4]<<endl;
        cout<<"please import data"<<endl;
        cin>>n;//��������
        for(i=0; i<n; i++)
        {
            cin>>a[i].id>>a[i].name>>a[i].clas>>a[i].sex>>a[i].age>>a[i].sc.cpp>>a[i].sc.chinese>>a[i].sc.math>>a[i].sc.english;
            ofs<<a[i].id<<' '<<a[i].name<<' '<<a[i].clas<<' '<<a[i].sex<<' '<<a[i].age<<' '<<a[i].sc.cpp<<' '<<a[i].sc.chinese<<' '<<a[i].sc.math<<' '<<a[i].sc.english<<endl;
        }
        ofs.close();

    }
    else//����Ϣ
    {
       while(!fs.eof())//���ȡ
       {
            fs>>a[n].id>>a[n].name>>a[n].clas>>a[n].sex>>a[n].age>>a[n].sc.cpp>>a[n].sc.chinese>>a[n].sc.math>>a[n].sc.english;
            n++;
       }
    }
    cout<<"imported"<<endl;
    control();
    return 0;
}
