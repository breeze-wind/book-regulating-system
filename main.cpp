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
    cout<<"\t nuaa图书管理系统\t\n"<<"主菜单"<<endl<<"1.收银模块"<<endl<<"2.书库管理模块"<<endl<<"3.报表模块"<<endl<<"4.退出系统"<<endl;
    cout<<"请输入1-4内数字来选择"<<endl;
    int a=0;
    cin>>a;
	while(a<1||a>4)
	{
		cout<<"error:请输入1-4内数字"<<endl;
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
	cout<<"\t前台销售模块\t"<<endl;
	cout<<"输入想买的书ISBN"<<engl;
	cin<<a; 
	for()
	cout<<"日期：__DATE__"<<endl;
	cout<<"数量\tISBN号\t书名\t单价\t金额"<<endl;
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
        cout<<"读取书库失败"<<endl;
        return 0;
    }
    while (bookfile>>title>>isbn>>author>>qtyOnHand>>retail)
    {
        books[i].setTitle(title);
        books[i].setAuthor(author);
        books[i].setQty(qtyOnHand);
        books[i].setISBN(isbn);
        books[i].setRetail(retail);
    }//读取书库
    bookfile.close();
    void blockchoose();
    
}
