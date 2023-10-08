#include "inord_list.h"
void prepcmd(string str, string &str11, string &str2, int &counter){
	int itt=0;
	string array[20]={};
	counter=0;
    string word = "";
    for (auto x : str){
        if (x == ' '){
            array[itt]= word ;
            itt++;
            counter++;
            word = "";
        }else{
            word = word + x;
        }
    }
    array[itt]= word ;
    itt++;
    counter++;
    str11=array[0];
    str2=array[1];
}
void clean(string &x){
	 char sep[] = ",;:'`&.[]{}()?!";
	 char sep2[] = {'"'};
	 for (unsigned int i = 0; i < strlen(sep); ++i){
		 x.erase(remove(x.begin(), x.end(), sep[i]), x.end());
	 }
	 for (unsigned int i = 0; i < strlen(sep); ++i){
		 x.erase(remove(x.begin(), x.end(), sep[i]), x.end());
		 //replace(x.begin(), x.end(), sep2[i], ' ');
	 }
	 transform(x.begin(), x.end(), x.begin(), ::tolower);
}
void removeDupWord(string str)
{
    string word = "";
    for (auto x : str)
    {
        if (x == ' ')
        {
            cout << word << endl;
            word = "";
        }
        else {
            word = word + x;
        }
    }
    cout << word << endl;
}
int main(int argc, char** argv){
	ifstream file(argv[1]);
	inord_list list;
	if(!file){
		cout<<"File not found";
		return 0;
	}
	ifstream commandfile(argv[2]);
	if(!commandfile){
		cout<<"File not found";
		return 0;
	}
	//-----------------------------------
	string command_input,str1,str2,txtstr,newtxtsr;
	int loc;
	stringstream ss;
	stringstream ssc;
	while(getline(commandfile, command_input)){
		txtstr = "";
		prepcmd(command_input,str1,str2,loc);
		if(str1 != "wordCount" && str1 != "distWords" && str1 != "charCount" && str1 != "frequentWord" && str1 != "countWord" && str1 != "starting" && str1 != "containing" && str1 != "search"){
		  	cout << "Undefined command"<<endl;
		  	return 0;
		}
		if(argc !=3 ){
			cout<<"Incorrect number of arguments";
			return 0;
		}

		if(str1 == "wordCount"){
			if(loc == 1 || (str2 == "" && loc ==2)){
				while(file>>txtstr){
					clean(txtstr);
					if(txtstr =="")
						continue;
					list.insert(txtstr);
				}
				list.wordCount();
			}else
				cout<<"Incorrect number of arguments"<<endl;
		}
		else if(str1 == "distWords"){
			if(loc == 1 || (str2 == "" && loc ==2)){
				while(file>>txtstr){
					clean(txtstr);
					if(txtstr =="")
						continue;
					list.insert(txtstr);
				}
				list.distWords();
			}else
				cout<<"Incorrect number of arguments"<<endl;
		}
		else if(str1 == "frequentWord"){
			if(loc == 1 || (str2 == "" && loc ==2)){
				while(file>>txtstr){
					clean(txtstr);
					if(txtstr == "")
						continue;
					list.insert(txtstr);
				}
				list.frequentWord();
			}else
				cout<<"Incorrect number of arguments"<<endl;
		}
		else if(str1 == "charCount"){
			if(loc == 1 || (str2 == "" && loc ==2)){
				list.charCount(argv);
			}else
				cout<<"Incorrect number of arguments"<<endl;
		}
		else if(str1 == "countWord"){
			if(loc != 2){
				cout<<"Incorrect number of arguments"<<endl;
			}else{
				clean(str2);
				while(file>>txtstr){
					clean(txtstr);
					//if(txtstr =="")
						//continue;
					list.insert(txtstr);
				}
				list.countWord(str2);
			}
		}
		else if(str1 == "starting"){
			if(loc != 2){
				cout<<"Incorrect number of arguments"<<endl;
			}else{
				clean(str2);
				while(file>>txtstr){
					clean(txtstr);
					//if(txtstr =="")
						//continue;
					list.insert(txtstr);
				}
			list.starting(str2);
			}
		}
		else if(str1 == "containing"){
			if(loc != 2){
				cout<<"Incorrect number of arguments"<<endl;
			}else{
				clean(str2);
				while(file>>txtstr){
					clean(txtstr);
					//if(txtstr =="")
						//continue;
					list.insert(txtstr);
				}
				list.containing(str2);
			}
		}
		else if(str1 == "search"){
			if(loc != 2){
				cout<<"Incorrect number of arguments"<<endl;
			}else{
				ifstream file2(argv[1]);
				string txtstr2;
				inord_list list;
				if(!file2){
					cout<<"File not found";
					return 0;
				}
				clean(str2);
				while(getline(file2,txtstr2)){
					clean(txtstr2);
					list.add_node(txtstr2);
				}
				list.search(str2);
			}
		}
		str1 = "";
		str2 = "";
		txtstr = "";
	}
	file.close();
	commandfile.close();
	return 0;
}
