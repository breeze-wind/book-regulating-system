#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;
class BookData//定义书籍信息类
{
public:
    BookData()
    {
        isexist=false;//初始化认为书不存在
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
BookData books[200];//书库容器
void  lookUpBook(string);
void Bookinfo(BookData&);
void cash_managing(void);
bool isempty(int i)
{
return books[i].isexist;
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
	 
}//
void cash_managing(void)
{
	string a;//isbn
	int b=0;//数量
	cout<<"\t前台销售模块\t"<<endl;
	cout<<"输入想买的书ISBN"<<endl;
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
		cout<<"卖光了T_T  看看别的吧"<<endl;
		 cash_managing();
		return;
	}
	cout<<"日期："<<__DATE__<<endl;
	cout<<"库存数量\tISBN号\t书名\t单价"<<endl;
	cout<<books[i].qtyOnHand<<"\t"<<books[i].isbn<<"\t"<<books[i].bookTitle<<"\t"<<books[i].retail<<"元\t"<<endl;
	cout<<"数量\tISBN号\t书名\t单价\t金额"<<endl;
	cin>>b;
	if (b>=books[i].qtyOnHand)
	{
		cout<<"库存不足T_T看看别的？"<<endl;
		cash_managing();
		return;
	}
	double b1 = b*(books[i].retail);
	cout<<"\t"<<books[i].isbn<<"\t"<<books[i].bookTitle<<"\t"<<books[i].retail<<"元\t"<<b1<<"元\t"<<endl;
	cout<<"----------------------------------------------"<<endl;
	cout<<"销售合计:RMB "<<b1<<endl;
	cout<<"零售税"<<fixed<<setprecision(2)<<b1*0.06<<endl;
	cout<<"应付金额"<<fixed<<setprecision(2)<<b1*1.06<<endl;
	cout<<"\n\n谢谢光临！";
	books[i]-b;
}
int main()
{
 BookData books[200];//书库容器
	string title;
    string author;
    int qtyOnHand;
    double retail;
    string isbn;
    ifstream basic_ifstream("bookfile");
    int i=0;
    if (basic_ifstream()==false)
    {
        cout<<"读取书库失败"<<endl;
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
    }//读取书库
    basic_ifstream.close();//关闭文件输入流
    void blockchoose();//进入模块选择
    
}
