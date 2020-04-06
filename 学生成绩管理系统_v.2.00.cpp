#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;
const int MAX_STUDENT_NUM=40;//����ʱ����ʹ��5
class Student
{
	public:
		Student(int I_id=0);//,char N_name,float R_regularGrade,float F_finalExam);
		void inputId();
		void inputName();
		void inputRegularGrade();
		void inputFinalExam();
		int getId(){return id;}
		static void heading(){cout<<"ѧ��\t����\tƽʱ\t��ĩ\n";}
		void output();
		float calTotalMark();
	private:
		int id;
		char name[20];
		float regularGrade;
		float finalExam;
};
void Menu(int &num);
void Input(Student stu[],int &num);//�������� 
void Output(Student stu[],int num);//������� 
void Statis(Student stu[],int num);//ͳ�Ƹ����������� 
void Order(Student stu[],int num);//�ɼ��ɴ�С���� 
void Search(Student stu[],int num);//���ҷ��� 
void Insert(Student stu[],int &num);//���� 
void Delete(Student stu[],int &num);//ɾ��  
int main()
{
	/*int n;
	cout<<"������ѧ������: ";
	cin>>n;*/
	Student stu[MAX_STUDENT_NUM];//={100,92,90,87,68};
	//int currentN=0;
	int n=0;//ȡ��currentN
	int num;
	while(1)
	{
		Menu(num);
		switch(num)
		{
			case 1:cout<<"��ѡ����1=¼��ѧ��\n";
				Input(stu,n);break;
			case 2:cout<<"��ѡ����2=��ʾ��Ϣ\n";
				Output(stu,n);break;
			case 3:cout<<"��ѡ����3=��������\n";
				Order(stu,n);break;
			case 4:cout<<"��ѡ����4=����ѧ��\n";
				Search(stu,n);break;
			case 5:cout<<"��ѡ����5=����ѧ��\n";
				Insert(stu,n);break;
			case 6:cout<<"��ѡ����6=ɾ��ѧ��\n";
				Delete(stu,n);break;
			case 7:cout<<"��ѡ����7=ͳ������\n";
				Statis(stu,n);break;
			case 0:return 0;
			default :cout<<"����Ƿ������������룡\n"; 
		}
	}
	return 0;
}
void Menu(int &num)
{
	cout<<"      ========================================\n";
	cout<<"      =         ��ӭʹ�óɼ�����ϵͳ         =\n";
	cout<<"      =      1=¼��ѧ��     2=��ʾ��Ϣ       =\n";
	cout<<"      =      3=��������     4=����ѧ��       =\n";
	cout<<"      =      5=����ѧ��     6=ɾ��ѧ��       =\n";
	cout<<"      =      7=ͳ������     0=�˳�           =\n";
	cout<<"      ========================================\n";
	cout<<"��ѡ��:";
	cin>>num;
}
Student::Student(int I_id)//,char N_name,float R_regularGrade,float F_finalExam)
{
	id=I_id;//regularGrade=0;finalExam=0;
}
void Student::inputId()
{
	int tid;
	while(1)
	{
		cout<<"������ѧ�ţ�1-40��֮�䣺";
		cin>>tid;
		if(tid>=1&&tid<=40)
		{
			id=tid;break;
		}
		else
			cout<<"ѧ��Ӧ��1~40֮�䣡\n";
	}
}
void Student::inputName()
{
	cout<<"������������";
	cin>>name; 
}
void Student::inputRegularGrade()
{
	while(1){
		cout<<"������ƽʱ�ɼ���0~100����";
		cin>>regularGrade;
		if(regularGrade>=0&&regularGrade<=100)break;
		else cout<<"������󣬳ɼ�Ӧ����0��100֮�䣡\n";
	}
}
void Student::inputFinalExam()
{
	while(1){
		cout<<"��������ĩ���Գɼ���0~100����";
		cin>>finalExam;
		if(finalExam>=0&&finalExam<=100)break;
		else cout<<"������󣬳ɼ�Ӧ����0��100֮�䣡\n";
	}
}
void Student::output()
{
	cout<<id<<"\t"<<name<<"\t"
	<<fixed<<setprecision(1)<<regularGrade<<"\t"
	<<fixed<<setprecision(1)<<finalExam<<endl;
}
float Student::calTotalMark()
{
	return regularGrade*0.5+finalExam*0.5;
}
void Input(Student stu[],int &num)
{
	if(num>=MAX_STUDENT_NUM)
		cout<<"�����Ѵﵽ"<<MAX_STUDENT_NUM<<"�����ޣ��޷������룡\n";
	else
	{
		int i=0;//��ʱ��i����num 
		for(i;i<MAX_STUDENT_NUM;i++)
		{
			stu[i].inputId();
			int j=0;
			for(j;j<i;j++)
				if(stu[i].getId()==stu[j].getId())break;
			if(j==i)
			{
				stu[i].inputName();
				stu[i].inputRegularGrade();
				stu[i].inputFinalExam();
				cout<<"��������ѧ�������밴y��Y: ";
				char ch='a';
				cin>>ch;
				if(ch=='y'||ch=='Y');
				else break; 
			}
			else{
			cout<<"ѧ�Ų������ظ�����ѧ���Ѿ����ڣ�\n";
			i--;	
			}
			if(i==MAX_STUDENT_NUM-1)
				cout<<"�����Ѵﵽ"<<MAX_STUDENT_NUM<<"�����ޣ��޷������룡\n";
		}
		num=0;
		for(int j=0;j<MAX_STUDENT_NUM;j++)
			if(stu[j].getId()!=0)num++; //���num 
	}
}
void Output(Student stu[],int num)
{
	Student::heading();
	for(int i=0;i<num;i++)
	if(stu[i].getId()!=0)stu[i].output();
	cout<<endl;
}
void Order(Student stu[],int num)
{
	for(int i=1;i<num;i++)
		for(int j=0;j<num-i;j++)
			if(stu[j].calTotalMark()<stu[j+1].calTotalMark())
				swap(stu[j],stu[j+1]);
	Output(stu,num);
}
void Search(Student stu[],int num)
{
	int cId;
 	char ch='y';
	while(ch=='y'||ch=='Y')
	{
		cout<<"��������Ҫ���ҵ�ѧ�ţ�";
		cin>>cId;
		int i=0;
		for(i;i<num;i++)
			if(cId==stu[i].getId())
			{
				Student::heading();
				stu[i].output();
				break;
			}
		if(i==num)
			cout<<"û�и�ѧ������Ϣ��\n";
		cout<<"���������밴y��Y:";
		cin>>ch;
	}
}
void Insert(Student stu[],int &num)
{
	int i=0;
	Student sin;
	char ch='y';
	while(ch=='y'||ch=='Y')
	{
		if(num>=MAX_STUDENT_NUM){
			cout<<"�����Ѵﵽ���ޣ�\n";break; 
		}
		sin.inputId();
		for(i=0;i<num;i++)
			if(sin.getId()==stu[i].getId())break;
		if(i==num)
		{
			sin.inputName();
			sin.inputRegularGrade();
			sin.inputFinalExam();
			stu[num++]=sin;
			cout<<"�ɹ����룡\n���������밴y��Y:";
		}
		else
			cout<<"ѧ�Ų������ظ�����ѧ���Ѿ����ڣ�\n���������밴y��Y:";
		cin>>ch;
	}
}
void Delete(Student stu[],int &num) 
{
	int del;
	char ch='y';
	while(ch=='y'||ch=='Y')
	{
		cout<<"��ǰ����:"<<num<<endl;
		int i=0;
		if(num==0)
		{
			cout<<"û��ѧ����ɾ��\n";break;
		}
		else
		{
			cout<<"������Ҫɾ����ѧ��ѧ�ţ�";
			cin>>del;
			int i=0;
			for(i;i<num;i++)
				if(stu[i].getId()==del)
				{
					for(int k=i;k<num;k++)
						stu[k]=stu[k+1];
					num--;
					cout<<del<<"��ѧ����Ϣɾ���ɹ���\n";
					break; 
				}
			if(i>=num)
			{
				cout<<"û�и�ѧ��ѧ����\n";
			}
			cout<<"����ɾ������ѧ���밴y��Y��";
			cin>>ch;
		}	
	}
}
void Statis(Student stu[],int num)
{
	cout<<"100~90\t89~80\t79~70\t69~60\t<60\n";
	int a=0,b=0,c=0,d=0,e=0;
	for(int j=0;j<num;j++)
	{
		if(stu[j].getId()!=0)
			if(stu[j].calTotalMark()>=90&&stu[j].calTotalMark()<=100)a++;
			else if(stu[j].calTotalMark()>=80&&stu[j].calTotalMark()<90)b++;
			else if(stu[j].calTotalMark()>=70&&stu[j].calTotalMark()<80)c++;
			else if(stu[j].calTotalMark()>=60&&stu[j].calTotalMark()<70)d++;
			else e++; 
	}
	cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\n";
}
