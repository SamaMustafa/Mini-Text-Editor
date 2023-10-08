#ifndef INORDLIST_H_
#define INORDLIST_H_
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;
typedef string ListElemType;

class inord_list {
public:
	inord_list();
	~inord_list();
	void wordCount();
	void distWords();
	void charCount(char** argv);
	void frequentWord();
	void countWord(const ListElemType);
	void starting(const ListElemType);
	void containing(const ListElemType);
	void search(const ListElemType);
	void insert(const ListElemType );
	int count(const ListElemType);
	void add_node(const ListElemType n);
	void add_node2(const int n);
	void removeDuplicates();
	void print();
private:

	struct Node
	{
		ListElemType elem;
		Node* next;
		Node* pred;
		int num;
	};
	typedef Node* link;
	link head;
	link tail;
	link current;
	link pred;
	link next;

};

#endif /* INORDLIST_H_ */
