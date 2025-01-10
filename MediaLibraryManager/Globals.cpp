#include "Globals.h"
#include <iostream>
#include <fstream>
using namespace std;

void Resource::Show_Id() {
	cout << "编号：" << id << "\t";
}

void Resource::Show_Resource() {
	cout << "标题：" << title << "\t作者：" << author << "\t评级：" << rate << "\t";
}

void Resource::Save_Id(ofstream& out) {
	out << id << " ";
}

void Resource::Save_Resource(ofstream& out) {
	out << title << " " << author << " " << rate << " ";
}

// Show
void Book::Show() {
	Resource::Show_Id();
	cout << "类别：图书\t";
	Resource::Show_Resource();
	cout << "出版社：" << press << "\tISBN 号：" << ISBN << "\t页数：" << page << endl;
}
void VCD::Show() {
	Resource::Show_Id();
	cout << "类别：视频光盘\t";
	Resource::Show_Resource();
	cout << "出品者：" << name << "\t出品年份：" << year << "\t视频时长：" << period << endl;
}
void Picture::Show() {
	Resource::Show_Id();
	cout << "类别：图画\t";
	Resource::Show_Resource();
	cout << "出口国籍：" << nation << "\t长：" << length << "\t宽：" << width << endl;
}

// Save
void Book::Save(ofstream& out) {
	Resource::Save_Id(out);
	out << "Book ";
	Resource::Save_Resource(out);
	out << press << " " << ISBN << " " << page;
}
void VCD::Save(ofstream& out) {
	Resource::Save_Id(out);
	out << "VCD ";
	Resource::Save_Resource(out);
	out << name << " " << year << " " << period;
}
void Picture::Save(ofstream& out) {
	Resource::Save_Id(out);
	out << "Picture ";
	Resource::Save_Resource(out);
	out << nation << " " << length << " " << width;
}

// Clone
Resource* Book::Clone() {
	return new Book(*this);
}
Resource* VCD::Clone() {
	return new VCD(*this);
}
Resource* Picture::Clone() {
	return new Picture(*this);
}