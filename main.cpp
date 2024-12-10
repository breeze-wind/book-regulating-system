#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;
class BookData//�����鼮��Ϣ��
{
public:
    BookData()
    {
        isexist=false;//��ʼ����Ϊ�鲻����
    };
    ~BookData()=default;
    void setTitle(string& title)
    {
        this->bookTitle =title;
    }
    void setAuthor(string& author)
    {
       this->bookauthor = author;
    }
    void setQty(int qty)
    {
        this->qtyOnHand = qty;
    }
    void setISBN(string& isbn)
    {
            this->isbn=isbn;//
    }
    void setRetail(double retail)
    {
        this->retail = retail;
    }
    bool isexist;
    string bookTitle(void)
    {
    	return this->bookTitle;
	}
	   string isbn(void)
    {
    	return this->isbn;
	}
	string bookauthor(void)
    {
	    return this->bookauthor;
    }
	int qtyOnHand(void)
    {
	    return this->qtyOnHand;
    }
	double retail(void)
    {
	    return this -> retail;
    }

	
private:
    string bookTitle;
    string isbn;
    int qtyOnHand;
    double retail;
    string bookauthor;

};
BookData operator -(BookData& book,int a)
{
	book.setQty(book.qtyOnHand-a);
	if (book.qtyOnHand<=0)
	{
		book.isexist=false;
		book.bookTitle[0]='\0';
	}
	return book;
}
BookData books[200];//�������
void  lookUpBook(string);
void Bookinfo(BookData&);
void cash_managing(void);
bool isempty(int i)
{
return books[i].isexist;
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
	 		sheeting();
	 		break;
	 	case 4:
	 		system_exit();
	 		break;
	 }
	 
}//
void cash_managing(void)
{
	string a;//isbn
	int b=0;//����
	cout<<"\tǰ̨����ģ��\t"<<endl;
	cout<<"�����������ISBN"<<endl;
	cin<<a;
	int i=0;
	while(isempty(i))
	{
		if (books[i].isbn==a)
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
	cout<<books[i].qtyOnHand<<"\t"<<books[i].isbn<<"\t"<<books[i].bookTitle<<"\t"<<books[i].retail<<"Ԫ\t"<<endl;
	cout<<"����\tISBN��\t����\t����\t���"<<endl;
	cin>>b;
	if (b>=books[i].qtyOnHand)
	{
		cout<<"��治��T_T������ģ�"<<endl;
		cash_managing();
		return;
	}
	double b1 = b*(books[i].retail);
	cout<<"\t"<<books[i].isbn<<"\t"<<books[i].bookTitle<<"\t"<<books[i].retail<<"Ԫ\t"<<b1<<"Ԫ\t"<<endl;
	cout<<"----------------------------------------------"<<endl;
	cout<<"���ۺϼ�:RMB "<<b1<<endl;
	cout<<"����˰"<<fixed<<setprecision(2)<<b1*0.06<<endl;
	cout<<"Ӧ�����"<<fixed<<setprecision(2)<<b1*1.06<<endl;
	cout<<"\n\nлл���٣�";
	books[i]-b;
}
int main()
{
 BookData books[200];//�������
	string title;
    string author;
    int qtyOnHand;
    double retail;
    string isbn;
    ifstream basic_ifstream("bookfile");
    int i=0;
    if (basic_ifstream()==false)
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
    }//��ȡ���
    basic_ifstream.close();//�ر��ļ�������
    void blockchoose();//����ģ��ѡ��
    
}
