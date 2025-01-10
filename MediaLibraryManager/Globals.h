#ifndef GLOBALS_H
#define GLOBALS_H

extern bool isChanged;

#include <iostream>
using namespace std;

class Resource {
public:
	Resource(int id, string title, string author, string rate)
		: id(id), title(title), author(author), rate(rate) {
	}
	// �������캯��
	Resource(const Resource& other)
		: id(other.id), title(other.title), author(other.author), rate(other.rate) {
	}
	virtual Resource* Clone() = 0;
	virtual void Show_Id();
	virtual void Show_Resource();
	virtual void Show() = 0;
	virtual void Save_Id(ofstream&);
	virtual void Save_Resource(ofstream&);
	virtual void Save(ofstream&) = 0;
	int GetId() { return id; }
	string GetTitle() { return title; }
	virtual string GetClassName() = 0;
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
	// �������캯��
	Book(const Book& other)
		: Resource(other), press(other.press), ISBN(other.ISBN), page(other.page) {
	}
	Resource* Clone() override;
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
	// �������캯��
	VCD(const VCD& other)
		: Resource(other), name(other.name), year(other.year), period(other.period) {
	}
	Resource* Clone() override;
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
	// �������캯��
	Picture(const Picture& other)
		: Resource(other), nation(other.nation), length(other.length), width(other.width) {
	}
	Resource* Clone() override;
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
