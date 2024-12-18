//
// Created by Lenovo on 24-12-18.
//

#ifndef BOOKFILE_MANAGING_H
#define BOOKFILE_MANAGING_H
#include <string>
#include"BookData.h"

void bookfile_managing(void);//书库信息管理
void deleteBook(void);//书记删除
void addBook(void);//添加书籍
void Edit_Book(void);//书籍信息编辑
void Edit_Book(BookData&);
void Bookinfo(BookData&);//书籍信息展示
void bookfile_managing(void);
#endif //BOOKFILE_MANAGING_H
