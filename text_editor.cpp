#include"text_editor.h"
#include <assert.h>
#include<string>
#include <sstream>
using namespace std;
template <class T>
Node<T>::Node()
{
	value = 0;
	next = 0;
}

template <class T>
Node<T>::Node(T val)
{
	value = val;
	next = 0;
}
template <class T>
text_editor<T>::text_editor(void)
{
	head = tail = 0;
	count = 0;
}
template <class T>
void text_editor<T>::Add(T val)
{
	Node<T>* newNode = new Node<T>(val);
	if (head == 0)
		head = tail = newNode;
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
	count++;
}
template <class T>
T text_editor<T>::get_line(int pos)
{
	assert(pos >= 0 && pos<count);
	Node<T>* tmp = head;
	for (int i = 0; i<pos; i++)
		tmp = tmp->next;
	return tmp->value;
}

template <class T>
void text_editor<T>::Insertline(int pos, T val)
{
	assert(pos >= 0 && pos<count);
	Node<T>* tmp = head;
	Node<T>* newNode = new Node<T>(val);
	if (pos == 0)
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		for (int i = 0; i < pos-1 ; i++)
			tmp = tmp->next;

		newNode->next = tmp->next;
		tmp->next = newNode;
	}
	count++;
}

template <class T>
void text_editor<T>::Deleteline(int pos)
{
	assert(pos >= 0 && pos<count);
	Node<T>* tmp = head;
	if (pos == 0)
	{
		head = head->next;
		delete tmp;
	}
	else
	{
		for (int i = 0; i<pos - 1; i++)
			tmp = tmp->next;
		Node<T>* del = tmp->next;
		tmp->next = del->next;
		delete del;
		if (pos == count - 1)
			tail = tmp;
	}
	count--;
}
template <class T>
void text_editor<T>::update(int pos, T val) {
	assert(pos >= 0 && pos < count);
	Node<T>* tmp = head;
	Node<T>* newNode = new Node<T>(val);
	if (pos == 0)
	{
		head->value = val;
	}
	else
	{
		for (int i = 0; i < pos; i++)
			tmp = tmp->next;

		newNode = tmp->next;

		tmp->value = val;
	}

}
template <class T>
void text_editor<T>::find(T word) {
	Node<T>* tmp = head;
	bool enter = false;
	string str;
	int line = 1;
	while (tmp){
		stringstream ss(tmp->value);
		while (ss >> str){
			if (str.find(word) != std::string::npos){
				cout << " Found \"" << word << "\" at line: " << line << endl;
				enter = true;
			}
		}
		tmp = tmp->next;
		line++;
	}
	if (enter == false)
	{
		cout << " This text is not exist" << endl;
	}
}
template <class T>
void text_editor<T>::findandreplace(T word1, T word2) {
	Node<T>* tmp = head;
	string str;
	int line = 1;
	while (tmp){
		stringstream ss1;
		stringstream ss(tmp->value);
		while (ss >> str){
			if (str.find(word1) != std::string::npos){
				ss1 << word2 << " ";
			}
			else{
				ss1 << str << " ";
			}
		}
		tmp->value = ss1.str();
		tmp = tmp->next;
		line++;
	}
}
template <class T>
void text_editor<T>::display() {
	for (int i = 0; i<count; i++)
		cout << " "<<get_line(i) << endl;
}

template <class T>
text_editor<T>::~text_editor(void)
{

}

