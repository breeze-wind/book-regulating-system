//
// Created by Lenovo on 24-12-17.
//

#include "BookData.h"
#include <string>
BookData::BookData()
{
    this->isexist=false;//初始化认为书不存在
};
//~BookData()=default;
void BookData::setTitle(std::string& title)
{
    this->booktitle =title;
}
void BookData::setAuthor(std::string& author)
{
    this->bookAuthor = author;
}
void BookData:: setQty(int qty)
{
    this->QtyOnHand = qty;
}
void BookData:: setISBN(std::string& isbn)
{
    this->isbn=isbn;//
}
void BookData:: setRetail(double retail)
{
    this->Retail = retail;
}

std::string BookData:: bookTitle(void)
{
    return booktitle;
}
char BookData:: bookTitle(int i)
{
    return booktitle[i];
}
std::string BookData:: ISBN(void)
{
    return isbn;
}
std::string BookData:: bookauthor(void)
{
    return bookAuthor;
}
int BookData:: qtyOnHand(void)
{
    return QtyOnHand;
}
double BookData:: retail(void)
{
    return this -> Retail;
}