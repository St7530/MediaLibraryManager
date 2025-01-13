#ifndef GLOBALS_H
#define GLOBALS_H

extern bool isChanged;

#include <iostream>
#include "FindItem.h"
using namespace std;

class Resource {
public:
	Resource(int id, string title, string author, string rate)
		: id(id), title(title), author(author), rate(rate) {
	}
	virtual void Show_Id();
	virtual void Show_Resource();
	virtual void Show() = 0;
	virtual void Save_Id(ofstream&);
	virtual void Save_Resource(ofstream&);
	virtual void Save(ofstream&) = 0;
	virtual string GetClassName() = 0;
	friend void FindBy(int);
	friend bool HasId(int);
	friend int GetIndexById(int);
private:
	int id; // 编号
	string title; // 标题
	string author; // 作者
	string rate; // 评级（未评级，一般，成人，儿童)
};

class Book :public Resource { // 图书
public:
	Book(int id, string title, string author, string rate, string press, int ISBN, int page)
		: Resource(id, title, author, rate), press(press), ISBN(ISBN), page(page) {
	}
	void Show() override;
	void Save(ofstream&) override;
	string GetClassName() override { return "Book"; }
private:
	string press; // 出版社
	int ISBN; // ISBN 号
	int page; // 页数
};

class VCD :public Resource { // 视频光盘
public:
	VCD(int id, string title, string author, string rate, string name, int year, int period)
		: Resource(id, title, author, rate), name(name), year(year), period(period) {
	}
	void Show() override;
	void Save(ofstream&) override;
	string GetClassName() override { return "VCD"; }
private:
	string name; // 出品者
	int year; // 出品年份
	int period; // 视频时长
};

class Picture :public Resource { // 图画
public:
	Picture(int id, string title, string author, string rate, string nation, int length, int width)
		: Resource(id, title, author, rate), nation(nation), length(length), width(width) {
	}
	void Show() override;
	void Save(ofstream&) override;
	string GetClassName() override { return "Picture"; }
private:
	string nation; // 出口国籍
	int length; // 长（以厘米计，整数）
	int width; // 宽（以厘米计，整数）
};

extern Resource* res[100];

#endif // GLOBALS_H
