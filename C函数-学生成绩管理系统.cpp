#include<stdio.h>
#include<stdlib.h>
typedef struct student
{
    int id;
    char name[50];
    float chinese;
    float math;
    float english;
    float sum;
}student;
int ReadStuInfoFromFile(char *name, student **stu)
{
    int n, i = 0;
    student* st=(student*)malloc(100*sizeof(student));
    FILE* fp;
    fp=fopen(name, "r");
    if (fread(&n, sizeof(int), 1, fp) != 1) {
        fclose(fp);
        return 0;
    }
    if (n <= 0) {
        fclose(fp);
        return 0;
    }
    if(fread(st,sizeof(student),n,fp)<n)return 0;
    for(int i=0;i<n;++i){
        st[i].sum = st[i].chinese + st[i].english + st[i].math;
    }
    *stu=st;
    fclose(fp);
    return n;
}
int NoPass(student stu[], int n, student **noPassStudent, int *m)
{
    int num=0;
    student* nopt=(student*)malloc(100*sizeof(student));
    if(n<=0||m==NULL||stu==NULL||noPassStudent==NULL)
        return -1;
    for(int i=0;i<n;++i){
        if(stu[i].sum<180.0){
            nopt[num]=stu[i];
            num++;
        }
    }
    *m=num;
    *noPassStudent=nopt;
    return 0;
}
int Pass(student stu[], int n, student **PassStudent, int *m)
{
    int num=0;
    student* pt=(student*)malloc(100*sizeof(student));
    if(n<=0||m==NULL||stu==NULL||PassStudent==NULL)
        return -1;
    for(int i=0;i<n;++i){
        if(stu[i].sum>=180.0){
            pt[num]=stu[i];
            num++;
        }
    }
    *m=num;
    *PassStudent=pt;
    return 0;
}
int SortStudents(student stu[], int n)
{
    student t;
    int times;
    if(stu==NULL||n<=0)return-1;
    for(int i=1;i<n;++i){
        times=n-i;
        for(int j=0;j<times;++j){
            if(stu[j].sum<stu[j+1].sum){
                t=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=t;
            }
        }
    }
    return 0;
}
int PrintStudents(student stu[], int n)
{
    if(stu==NULL||n<=0)return -1;
    for(int i=0;i<n;++i){
    printf("%s %d %.2f %.2f ", stu[i].name, stu[i].id, stu[i].chinese, stu[i].math);
    printf("%.2f %.2f\n", stu[i].english, stu[i].sum);
    }
}
int SearchStudent(student stu[], int n, int id,int *rank, student *rstu)
{
    if(stu==NULL||n<=0||rank==NULL||rstu==NULL)return -1;
    if(SortStudents(stu,n)==-1)return -1;
    for(int i=0;i<n;++i){
        if(stu[i].id==id){
            *rank=i+1;
            *rstu=stu[i];
        }
    }
    return 0;
}
