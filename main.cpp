#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
class BookData
{
public:
    BookData()
    {
        isexist=true;
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
	
private:
    string bookTitle;
    string isbn;
    int qtyOnHand;
    double retail;
    string bookauthor;



};
void  lookUpBook(string);
void Bookinfo(BookData&);
bool isempty(int i)
{

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
	 
}
void cash_managing(void)
{
	string a;
	cout<<"\tǰ̨����ģ��\t"<<endl;
	cout<<"�����������ISBN"<<engl;
	cin<<a; 
	for()
	cout<<"���ڣ�__DATE__"<<endl;
	cout<<"����\tISBN��\t����\t����\t���"<<endl;
	cout<< 
}
int main()
{
    BookData books[200];
    string title;
    string author;
    int qtyOnHand;
    double retail;
    string isbn;
    ifstream bookfile("bookfile");
    int i=0;
    if (ifstream bookfile()==false)
    {
        cout<<"��ȡ���ʧ��"<<endl;
        return 0;
    }
    while (bookfile>>title>>isbn>>author>>qtyOnHand>>retail)
    {
        books[i].setTitle(title);
        books[i].setAuthor(author);
        books[i].setQty(qtyOnHand);
        books[i].setISBN(isbn);
        books[i].setRetail(retail);
    }//��ȡ���
    bookfile.close();
    void blockchoose();
    
}
