#include "Globals.h"
#include <iostream>
#include <fstream>
using namespace std;

void Resource::Show_Id() {
	cout << "��ţ�" << id << "\t";
}

void Resource::Show_Resource() {
	cout << "���⣺" << title << "\t���ߣ�" << author << "\t������" << rate << "\t";
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
	cout << "���ͼ��\t";
	Resource::Show_Resource();
	cout << "�����磺" << press << "\tISBN �ţ�" << ISBN << "\tҳ����" << page << endl;
}
void VCD::Show() {
	Resource::Show_Id();
	cout << "�����Ƶ����\t";
	Resource::Show_Resource();
	cout << "��Ʒ�ߣ�" << name << "\t��Ʒ��ݣ�" << year << "\t��Ƶʱ����" << period << endl;
}
void Picture::Show() {
	Resource::Show_Id();
	cout << "���ͼ��\t";
	Resource::Show_Resource();
	cout << "���ڹ�����" << nation << "\t����" << length << "\t��" << width << endl;
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