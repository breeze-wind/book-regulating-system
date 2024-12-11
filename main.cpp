#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;
class BookData
{
public:
    BookData()
    {
        isexist=false;//��ʼ����Ϊ�鲻����
    };
    //~BookData()=default;
    void setTitle(string& title)
    {
        this->booktitle =title;
    }
    void setAuthor(string& author)
    {
       this->bookAuthor = author;
    }
    void setQty(int qty)
    {
        this->QtyOnHand = qty;
    }
    void setISBN(string& isbn)
    {
            this->isbn=isbn;//
    }
    void setRetail(double retail)
    {
        this->Retail = retail;
    }
    bool isexist;//�����治���ڣ���ϵ�����Ҫ��Ҫд��ȥ�� 
    string bookTitle(void)
    {
    	return booktitle;
	}
	char bookTitle(int i)
    {
    	return booktitle[i];
    }
	   string ISBN(void)
    {
    	return isbn;
	}
	string bookauthor(void)
    {
	    return bookAuthor;
    }
	int qtyOnHand(void)
    {
	    return QtyOnHand;
    }
	double retail(void)
    {
	    return this -> Retail;
    }

	
private:
    string booktitle;
    string isbn;
    int QtyOnHand;
    double Retail;
    string bookAuthor;

};//�����鼮��Ϣ��
BookData operator -(BookData& book,int a)
{
	book.setQty(book.qtyOnHand()-a);
	if (book.qtyOnHand()<=0)
	{
		book.isexist=false;
		//book.bookTitle[0]='\0';
	}
	return book;
}

void bookfile_managing(void);
 BookData books[50];//�������
void  lookUpBook(string);
void Bookinfo(BookData&);
void cash_managing(void);
void sheeting(void);
void system_exit(void);
bool isempty(int i)
{
 if (books[i].bookTitle(0)=='\0')
 {return true;}
	return false;
}
void blockchoose()
{
    cout<<"\t nuaaͼ�����ϵͳ\t\n"<<"���˵�"<<endl<<"1.����ģ��"<<endl<<"2.������ģ��"<<endl<<"3.����ģ��"<<endl<<"4.�˳�ϵͳ"<<endl;
    cout<<"������1-4��������ѡ��"<<endl;
    int a=0;
    cin>>a;
	while(a<1||a>4)
	{
		cout<<"error:������1-4������"<<endl;
		cin>>a;
		 
	 } 
	 switch(a)
	 {
	 	case 1:
	 		cash_managing();
	 		break;
	 	case 2:
	 		bookfile_managing();
	 		break;
	 	case 3:
	 		//sheeting();
	 		break;
	 	case 4:
	 		//system_exit();
	 		break;
	 }
	 
}//
void cash_managing(void)
{
	string a;//isbn
	int b=0;//����
	cout<<"\tǰ̨����ģ��\t"<<endl;
	cout<<"�����������ISBN"<<endl;
	cin>>a;
	int i;
	i = 0;
	while(isempty(i))
	{
		if (books[i].ISBN()==a)
			break;
		i++;
	}
	if (!books[i].isexist)
	{
		cout<<"������T_T  ������İ�"<<endl;
		 cash_managing();
		return;
	}
	cout<<"���ڣ�"<<__DATE__<<endl;
	cout<<"�������\tISBN��\t����\t����"<<endl;
	cout<<books[i].qtyOnHand()<<"\t"<<books[i].ISBN()<<"\t"<<books[i].bookTitle()<<"\t"<<books[i].retail()<<"Ԫ\t"<<endl;
	cout<<"����\tISBN��\t����\t����\t���"<<endl;
	cin>>b;
	if (b>=books[i].qtyOnHand())
	{
		cout<<"��治��T_T������ģ�"<<endl;
		cash_managing();
		return;
	}
	double b1 = b*(books[i].retail());
	cout<<"\t"<<books[i].ISBN()<<"\t"<<books[i].bookTitle()<<"\t"<<books[i].retail()<<"Ԫ\t"<<b1<<"Ԫ\t"<<endl;
	cout<<"----------------------------------------------"<<endl;
	cout<<"���ۺϼ�:RMB "<<b1<<endl;
	cout<<"����˰"<<fixed<<setprecision(2)<<b1*0.06<<endl;
	cout<<"Ӧ�����"<<fixed<<setprecision(2)<<b1*1.06<<endl;
	cout<<"\n\nлл���٣�";
	books[i]-b;
	 blockchoose();
}
void Bookinfo(BookData& book)
{
	cout<<"--------------------------------------------------------------------";
	cout<<"\n\tnuaaͼ�����ϵͳ\t\n\t\t�������\t\nISBN�ţ�"<<book.ISBN()<<"\n�� ����"<<book.bookTitle()<<"\n�������"<<book.qtyOnHand()<<"\n���ۼۣ�"<<book.retail()<<"\n���ߣ�"<<book.bookauthor()<<endl;
	cout<<"--------------------------------------------------------------------";
}
void lookUpBook(string a)
{
//	Bookinfo(books[0]);
	int i=0;
	while(!isempty(i))
	{
		if (books[i].bookTitle() == a)
		{
			break;
         	}
		i++;
	}
//	cout<<i<<endl;
	if (!books[i].isexist)
	{
		cout<<"û�Ȿ��0.0�������"<<endl;
		return;
	}//ʣ�µĶ����ڹݵģ�������

	Bookinfo(books[i]);
}
void sheeting(void)//����ģ�� 
{
	 cout<<"\t\t\tnuaaͼ�����ϵͳ\t\t\n\t\t\t����ģ��\t\t\n\n1.����б�\n2.���ۼ��б�\n3.���ص����˵�"<<endl;
	 cout<<"����ѡ��";
	 int a=0;
	 cin>>a;
	 switch(a)
	 {
	 	case 1: 
	 }
	  
}

void bookfile_managing(void)
{
     cout<<"\t\t\tnuaaͼ�����ϵͳ\t\t\n\t\t\t ������ģ��\t\t\n\n1.����б�\n2.���ۼ��б�\n3.���ص����˵�"<<endl;
	 cout<<"����ѡ��";
	 int a=0;
	 cin>>a;
	 switch(a)
	 {
	 	case 1: 
	 }
	  

}//������ϵͳ 

int main()
{
 //BookData books[200];//�������
	string title;
    string author;
    int qtyOnHand;
    double retail;
    string isbn;
    ifstream basic_ifstream("D://code//clion//book regulating system//bookfile.txt");
    int i=0;
    if (!basic_ifstream)
    {
        cout<<"��ȡ���ʧ��"<<endl;
        return 0;
    }
    while (basic_ifstream>>title>>isbn>>author>>qtyOnHand>>retail)
    {
        books[i].setTitle(title);
        books[i].setAuthor(author);
        books[i].setQty(qtyOnHand);
        books[i].setISBN(isbn);
        books[i].setRetail(retail);
    	books[i].isexist=true;
    	i++;
    }//��ȡ���
    basic_ifstream.close();//�ر��ļ�������
    blockchoose();//����ģ��ѡ��
    
}
