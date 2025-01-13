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
	int id; // ���
	string title; // ����
	string author; // ����
	string rate; // ������δ������һ�㣬���ˣ���ͯ)
};

class Book :public Resource { // ͼ��
public:
	Book(int id, string title, string author, string rate, string press, int ISBN, int page)
		: Resource(id, title, author, rate), press(press), ISBN(ISBN), page(page) {
	}
	void Show() override;
	void Save(ofstream&) override;
	string GetClassName() override { return "Book"; }
private:
	string press; // ������
	int ISBN; // ISBN ��
	int page; // ҳ��
};

class VCD :public Resource { // ��Ƶ����
public:
	VCD(int id, string title, string author, string rate, string name, int year, int period)
		: Resource(id, title, author, rate), name(name), year(year), period(period) {
	}
	void Show() override;
	void Save(ofstream&) override;
	string GetClassName() override { return "VCD"; }
private:
	string name; // ��Ʒ��
	int year; // ��Ʒ���
	int period; // ��Ƶʱ��
};

class Picture :public Resource { // ͼ��
public:
	Picture(int id, string title, string author, string rate, string nation, int length, int width)
		: Resource(id, title, author, rate), nation(nation), length(length), width(width) {
	}
	void Show() override;
	void Save(ofstream&) override;
	string GetClassName() override { return "Picture"; }
private:
	string nation; // ���ڹ���
	int length; // ���������׼ƣ�������
	int width; // �������׼ƣ�������
};

extern Resource* res[100];

#endif // GLOBALS_H
