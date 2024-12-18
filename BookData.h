//
// Created by Lenovo on 24-12-17.
//

#ifndef BOOKDATA_H
#define BOOKDATA_H
#include <string>



class BookData
{
public:
    bool isexist;//标记书存不存在（关系到最后要不要写回去）
    BookData();
    void setTitle(std::string& title);
    void setAuthor(std::string& author);
    void setQty(int qty);
    void setISBN(std::string& isbn);
    void setRetail(double retail);
    std::string bookTitle(void);
    char bookTitle(int i);
    std::string ISBN(void);
    std::string bookauthor(void);
    int qtyOnHand(void);
    double retail(void);

private:
    std::string booktitle;
    std::string isbn;
    int QtyOnHand;
    double Retail;
    std::string bookAuthor;

};//定义书籍信息类
bool doubleused_title(std::string&);
bool doubleused_isbn(std::string&);
std::string operator+(const std::string& a,int b);
bool doubleused_title(std::string& a);
bool doubleused_isbn(std::string& a);

#endif //BOOKDATA_H
