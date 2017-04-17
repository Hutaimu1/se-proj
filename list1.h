#pragma once
#include <vector>
#include <iostream>
#include<string>
using namespace std;

struct Node
{
	string value;
	Node *next;
	Node(string v) :value(v), next(NULL) {};
};

class List
{
private:
	Node *head;
	int size;
public:
	List() :
		size(0), head(NULL) {}
	List(const vector<string>& v);
	List(string* array, int array_size);
	List(const List& rhs);
	~List();
	int length()const;
	bool insert(int pos, string value);
	int find(string value);
	int remove(string value);
	void printAll();
	bool split(int pos, List& new_list);
	void combine(List& append_list);
};
List::List(const List& rhs)
{
	Node *p = rhs.head;
	for (int i = 0; i < rhs.length(); i++) {
		insert(i, p->value);
		p = p->next;
	}
}
void List::combine(List& append_list)
{
	List *temp = new List(append_list);
	Node *p = head;
	for (int i = 0; i<size - 1; i++)
		p = p->next;
	p->next = temp->head;
}
bool List::split(int pos, List& new_list)
{
	if (pos < 0 || pos >= size)
		return false;
	else {
		new_list.size = size - pos;
		Node *p = head;
		for (int i = 0; i <pos; i++)
			p = p->next;
		//~new_list
		while (new_list.head != NULL) {
			string num = new_list.head->value;
			new_list.remove(num);
		}
		for (int i = 0; i < size - pos; i++) {
			new_list.insert(i, p->value);
			p = p->next;
		}
		return true;
	}
}
void List::printAll()
{
	Node *p = head;
	cout << "{";
	while (p != NULL) {
		cout << p->value << ",  ";
		p = p->next;
	}
	cout << "}" << endl;
}
List::~List()
{
	//Destroy List by call remove();
	while (head != NULL) {
		string num = head->value;
		remove(num);
	}

}
int List::remove(string value)
{
	Node *p = head;
	int count = 0;
	while (p->next != NULL) {
		if (p->next->value == value) {
			count++;
			Node *temp = p->next;
			p->next = p->next->next;
			delete temp;
			size--;
			continue;
		}
		p = p->next;
	}
	if (head->value == value) {
		count++;
		Node *temp2 = head;
		head = head->next;
		delete temp2;
		size--;

	}
	return count;
}
int List::find(string value)
{
	Node *p = head;
	for (int i = 0; i < size; i++) {
		if (p->value == value)
			return i;
		p = p->next;
	}
	return -1;
}
List::List(string* array, int array_size) :head(NULL)
{
	for (int i = 0; i <array_size; i++)
		insert(i, array[i]);
}
List::List(const vector<string>& v) :head(NULL)
{
	for (int i = 0; i < v.size(); i++)
		insert(i, v[i]);
}
bool List::insert(int pos, string value)
{
	if (pos > size || pos < 0)
		return false;
	else {
		size++;
		Node *newPtr = new Node(value); //Define a new Node
		if (pos == 0) {                 //pos=0:we need to insert head!
			newPtr->next = head;
			head = newPtr;
		}
		else {                          //pos>0:we need to insert in the middle!
			Node *p = head;
			for (int i = 0; i < pos - 1; i++)
				p = p->next;
			newPtr->next = p->next;
			p->next = newPtr;
		}
		return true;
	}
}
int List::length()const
{
	return size;
}
