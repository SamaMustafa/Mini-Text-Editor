#include"text_editor.cpp"
#include<iostream>
#include<string>
using namespace std;
int main() {
	text_editor <string> L;
	int n;
	bool flag = true;
	
	cout << "\t\t\t\t\t Welcome to Mini Text Editor \n";
	cout << "\t\t\t\t\t ---------------------------\n\n";
	while (flag == true){
		cout << " Press 1 to Add a new line in your text. \n";
		cout << " Press 2 to Insert a new line at a specific position. \n";
		cout << " Press 3 to Get a specific line from the text. \n";
		cout << " Press 4 to Delete a specific line from the text. \n";
		cout << " Press 5 to Update a line (Replace line with a new one). \n";
		cout << " Press 6 to Find the position(s) of a specific word. \n";
		cout << " Press 7 to Find a word and Replace it with another in every line.  \n";
		cout << " Press 8 to Display the whole text. \n";
		cout << " Press 9 to Exit \n";
		cout << "  ";
		cin >> n;
		switch (n) {
		 case 1: {
					cout << " Enter your text: ";
					string s;
					cin.ignore();
					getline(cin, s);
					L.Add(s);	
		}
			break;
		case 2: {
					cout << " Enter position to insert at: ";
					int w;
					cin >> w;
					cout << " Enter your text: ";
					string s;
					cin.ignore();
					getline(cin, s);
					L.Insertline(w-1, s);
					
		}
			break;
		case 3: {
					cout << " Enter position of the text: ";
					int s;
					cin >>s;
					cout<<" "<<L.get_line(s-1)<<endl;
					
		}
			break;
		case 4: {
					cout << " Enter position of the text: ";
					int s;
					cin >> s;
					L.Deleteline(s-1);
					
		}
			break;
		case 5: {
					cout << " Enter position to update: ";
					int w;
					string s;
					cin >> w;
					cout << " Enter your new text: ";
					cin.ignore();
					getline(cin, s);
					L.update(w-1, s);
					
		}
			break;
		case 6: {
					cout << " Enter the text you want to find: ";
					string w;
					cin.ignore();
					getline(cin, w);
					L.find(w);
					
		}
			break;
		case 7: {
					cout << " Enter the text you want to remove: ";
					string s1, s2;
					cin >> s1;
					cout << " Enter the text you want to replace with: ";
					cin >> s2;
					L.findandreplace(s1, s2);
					
		}
			break;
		case 8: {
					L.display();
					break;
		}
		case 9: {
					flag = false;
					cout << "\t\t\t\tThank you for using Mini Text Editor system."<<endl;
					break;
		}
		default:
			cout << "Invalid Choice,Please try again."<<endl;
			break;
		}
		cout << "\t\t\t------------------------------------------------------------" << endl;
	} 
	system("pause");
	return 0;
}