#include "inord_list.h"
inord_list::inord_list() {
	head = NULL;
	tail = NULL;
	current = NULL;
	pred = NULL;
	next = NULL;
}
void inord_list::insert(const ListElemType e){
	link addedNode;
	link pred;
	addedNode = new Node;
	if (addedNode == NULL){
		cout<<"Wrong MEMORY ALLOCATION"<<endl;
		return;
	}
	else{
		addedNode-> elem = e;

		if (head == NULL || e <= head -> elem ){
			addedNode -> next = head;
			head = addedNode;

		}else{
			pred = head;
			while (pred-> next != NULL && pred-> next-> elem < e){
				pred = pred -> next;
			}
			addedNode -> next = pred -> next;
			pred -> next = addedNode;
		}
	}
}
void inord_list::wordCount(){
	int sum = 0;
	link node = new Node;
	if(head == NULL){
		cout<<"Word not found"<<endl;
		return;
	}
	node = head;
	while(node){
		sum+=1;
		node = node->next;
	}
	cout<<sum<<" "<<"words"<<endl;
}
void inord_list::distWords(){
	link node = new Node;
	int sum = 0;
	bool flag = true;
	const link head2 = head;
	if(head == NULL){
		cout<<"Word not found"<<endl;
		return;
	}
	node = head;
	while(node){
		flag = true;
		head = head2;
		while(head != node){
			if(head->elem == node->elem){
				flag = false;
				break;
			}else{
				head = head->next;
			continue;
			}
		}
		node = node->next;
		if(flag)
			sum+=1;
	}
	cout<<sum<<" distinct "<<"words"<<endl;
	head = head2;
}
void inord_list::charCount(char** argv){
	ifstream file(argv[1]);
	string txtstr;
	inord_list list;
	if(!file){
		cout<<"File not found";
		return;
	}
	while(getline(file,txtstr)){
		list.add_node(txtstr);
	}
	link node = new Node;
	int sum = 0; // sum may be = 0
	if(head == NULL){
		cout<<"Word not found"<<endl;
	}
	node = list.head;
	while(node){
		for(unsigned int i = 0;i <= node->elem.length(); i++){//unsigned int i = 0; node->elem.size[i] != "\0"; i++
			sum+=1;
		}
		node = node->next;
	}
	cout<<sum<<" "<<"characters"<<endl;
}
void inord_list::frequentWord(){//needs a fix and remove the general words
	link node = new Node;
	if(head == NULL){
		cout<<"Word not found"<<endl;
	}
	int total_count = 0, max_count = -1;
	ListElemType res;
	node = head;
	inord_list x;
	while (node){
		int count = 0;
		if(node->elem == "a" ||node->elem == "an" ||node->elem == "the" ||node->elem == "in" ||node->elem == "on" ||node->elem == "of" ||node->elem == "and" ||node->elem == "is" ||node->elem == "are"){
			node = node->next;
		}
		link compared = head;
		while (compared){
			/*if(current->elem == "a" || "an" || "the" || "in" || "on" || "of" || "and" || "is" || "are"){
				compared = compared->next;
				}*/
			if (node->elem == compared->elem){
				count++;
			}
			compared = compared->next;
		}
		if (count >= max_count){
			max_count = count;
			res = node->elem;
			x.insert(res);
		}
		node = node->next;
		total_count++;
	}
	node = x.head;
	stringstream ss;
	ListElemType str2 ="";
	while(node!= NULL){
		if(x.count(node->elem) == max_count){
			if(node->elem != str2){
				ss<<node->elem<<" ";
				str2 = node->elem;
			}
		}
		node = node->next;
	}
	string temp = ss.str();
    if (!temp.empty()){
    	temp.pop_back();
    }
	cout<<"Most frequent word is: "<<temp<<endl;
}
void inord_list::countWord(const ListElemType elem){
	link node = new Node;
	int sum = 0;
	ListElemType x;
	x = elem;
	if(head == NULL){
		cout<<"Word not found"<<endl;
		return;
	}
	node = head;
	while(node){
		if(node->elem == x)//current->elem.find(x) != std::string::npos
			sum+=1;
		node = node->next;
	}
	/*if(sum ==0){
		cout<<"Word not found"<<endl;
		return;
	}*/
	cout<<x<<" is repeated "<<sum<<" times"<<endl;
}
void inord_list::starting(const ListElemType elem){// the space and tabs
	link node = new Node;
	ListElemType str = elem;
	ListElemType x;
	stringstream ss;
	inord_list list;
	if(head == NULL){
		cout<<"Word not found"<<endl;
		return;
	}
	node = head;
	while(node){
		if(node->elem.rfind(str,0) == 0){
				x = node->elem;
				ss << x;
				//cout<<x<<endl;
				list.insert(x);
		}
		node = node->next;
	}
	node = list.head;
	ListElemType empty = "";
	int summation = 0;
	stringstream ss2;
	while(node){
		if(node->elem != empty){
			empty = node->elem;
			summation = count(node->elem);
			ss2<<empty<<": "<<summation<<"\t";
		}
		node = node->next;
	}
	if(summation == 0){
		cout<<"Word not found"<<endl;
		return;
	}
	ListElemType temp = ss2.str();
    if (!temp.empty()) {
	   	temp.pop_back();
    }
    cout<<temp<<endl;
}
void inord_list::containing(const ListElemType elem){// the space and tabs
	link node = new Node;
	ListElemType str = elem;
	ListElemType x;
	stringstream ss;
	inord_list list1;
	if(head == NULL){
		cout<<"Word not found"<<endl;
		return;
	}
	node = head;
	while(node){
		if(node->elem.find(str) != std::string::npos){
				x = node->elem;
				ss << x <<endl;
				list1.insert(x);
		}
		node = node->next;
	}
	ListElemType empty = "";
	int summation;
	stringstream ss2;
	node = list1.head;
	while(node){
		if(node->elem != empty){
			empty = node->elem;
			summation = count(node->elem);
			ss2<<empty<<": "<<summation<<"\t";
		}
		node = node->next;
	}
	if(summation == 0){
		cout<<"Word not found"<<endl;
		return;
	}
	ListElemType temp = ss2.str();
    if (!temp.empty()){
    	temp.pop_back();
    }
	cout<<temp<<endl;
}
void inord_list::search(const ListElemType elem){
	link node = new Node;
	ListElemType str = elem;
	stringstream ss,ssn;
	ListElemType word;
	inord_list list2;
	int sum=0;
	if(head == NULL){
		cout<<"Word not found"<<endl;
		return;
	}
	node = head;
	int line = 1;
	while(node){
		stringstream ss2(node->elem);
		while(ss2 >> word){
			if(word.find(str) != std::string::npos){
				ss<<word<<" ";
				ssn<<line<<" ";
				node->num = line;
				list2.insert(word + " "  + to_string(node->num));
				sum++;
			}
		}
		node = node->next;
		line++;
	}
	stringstream sss;
	stringstream ss4;
	string word2;
	list2.removeDuplicates();
	//list2.print();
	node = list2.head;
	string value;
	string value2;
	int num;
	int num2;
	int p = 0;
	while(node){
		ss4<<node->elem<<" ";
		ss4>>value>>num;
		//cout<<value<<"\t"<<num<<endl;
		if(node->next != NULL){
			ss4<<node->next->elem<<" ";
			ss4>>value2>>num2;
			//cout<<value2<<"\t"<<num2<<endl;
			if(value == value2){
				if(num > num2){
					link newnode = new Node;
					newnode->elem = node->elem;
					node->elem = node->next->elem;
					node->next->elem = newnode->elem;
				}
			}
		}
		//cout<<p<<endl;
		p++;
		node = node->next;
	}

	//cout<<value<<" "<<num<<endl;
	node = list2.head;
	while(node){
		sss<<node->elem<<" ";
		node = node->next;
	}
	std::map<std::string, std::vector<int>> output;
	int i = 0;
    std::string input_string;
    int input_line = 0;

    while(sss >> input_string >> input_line){
        output[input_string].push_back(input_line);
    }

    for(auto [s, l] : output){
        std::cout << s <<":"<<"\t"<< "lines ";
        for(auto n : l){
            std::cout << n << ' ';
        }
        std::cout << '\n';
    }
    if(sum == 0)
    	cout<<"Word not found"<<endl;
}
void inord_list::print(){
	if(head == NULL)
	{
		cout<<"Word not found"<<endl;
		return;
	}
	current = head;
	while(current)
	{
		cout<<current->elem<<endl;
		current = current->next;
	}
}
void inord_list::add_node(const ListElemType n)
    {
        link tmp = new Node;
        tmp->elem = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
    }
int inord_list::count(const ListElemType elem){
	int sum = 0;
	ListElemType x;
	x = elem;
	if(head == NULL)
	{
		cout<<"Word not found"<<endl;
		return 0;
	}
	current = head;
	while(current)
	{
		if(current->elem == x)
			sum+=1;
		current = current->next;
	}
	if(sum ==0)
	{
		cout<<x<<" not found"<<endl;
		return 0;
	}
	return sum;

}
void inord_list::removeDuplicates(){
    link current = head;
    link next_next;
    if (current == NULL)
    	return;
    while (current->next != NULL){
    	if (current->elem == current->next->elem){
        next_next = current->next->next;
        free(current->next);
        current->next = next_next;
    	}
    	else{
    		current = current->next;
    	}
    }
}
inord_list::~inord_list() {//List traversal
	link node = new Node;
	node = head;
	while(node){
		link next = node->next;
		delete node;
		node = next;
	}
	head = NULL;
	tail = NULL;
	current = NULL;
	pred = NULL;
	next = NULL;
}
