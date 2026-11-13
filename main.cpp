# include <iostream>
# include<vector>
# include <string>
# include <fstream>

using namespace std;

class BOOK{
    public:
string name_of_book;
bool Availability = true;


};
class USER_INFO{
   public:
string name_of_user ;
int roll_no_of_user = 0000;
string book_taken = "NONE";

};
class LIBRARY{
  public:

vector <BOOK> book ;
vector <USER_INFO> info ;

USER_INFO user_info;
BOOK book1;

void add_book(){  
     bool temp = true;
     while(temp){ 
    BOOK book1;
cout<<"WHAT BOOK DO YOU WANT TO ADD: ";
cin>>ws;
    getline(cin,book1.name_of_book);
    book.push_back(book1);

ofstream outfile("books.txt", ios::app);
outfile << book1.name_of_book << "\n" ;
outfile << book1.Availability << "\n" ;
 outfile.close();

cout<<"Press 1 for adding more books or 0 to exit: ";
cin>>temp;
}
}
void issue_book(){

 string x;
cout<<"WHICH BOOK YOU WANT TO ISSUE: ";
cin>>ws;
 getline(cin,x);
 bool a = false;
 for(int i=0;i<book.size();i++){
if(x==book[i].name_of_book && book[i].Availability==true){
book[i].Availability = false;
a = true;
cout<< "What is your name: ";
 getline(cin,user_info.name_of_user);
 cin>>ws;


cout<< "What is your Roll No.: ";
 cin>> user_info.roll_no_of_user;

user_info.book_taken = x ;

ofstream outfile("users.txt", ios::app);
 outfile << user_info.name_of_user << "\n" ;
outfile << user_info.roll_no_of_user << "\n" ;
 outfile << user_info.book_taken << "\n" ;
outfile.close();

info.push_back(user_info);

break;

 }

}
if(a==false)
{

cout<<"Sorry we don't have that book: ";
}
}
void return_book(){
 string b ;
  cout<<"Which book you have to return: ";
cin>>ws;
getline(cin,b);
    for(int i=0;i<book.size();i++){
    if(b  == book[i].name_of_book && book[i].Availability==false){
        book[i].Availability = true;
    
    }}
    for(int i=0;i<info.size();i++){
    if(info[i].book_taken == b )
      {info[i].book_taken = "NONE"; }
} }
void check_books_available_or_not ()
{
    for(int i=0;i<book.size();i++){
        cout<<"NAME OF BOOKS OF LIBRARY: "<<book[i].name_of_book<<"\n";
        cout<<"Availability: "<<book[i].Availability<<"\n";
        cout<<"\n";
    }
}
void Display_issued_book(){
    for(int i=0;i<info.size();i++){
        if(info[i].book_taken != "NONE" ){
            cout<<"NAME OF THE STUDENT: "<<info[i].name_of_user<<"\n";
            cout<<"ROLL NO.: "<<info[i].roll_no_of_user<<"\n";
            cout<<"BOOK TAKEN BY THE USER: "<<info[i].book_taken<<"\n";
            cout<<"\n";

        }
    }
}

};


int main(){

    LIBRARY library1;

    ifstream infile("books.txt");
while (getline(infile >> ws, library1.book1.name_of_book)) {
    infile >> library1.book1.Availability;
    library1.book.push_back(library1.book1);
}
infile.close();

ifstream userfile("users.txt");
while (getline(userfile >> ws, library1.user_info.name_of_user)) {
    userfile >> library1.user_info.roll_no_of_user;
    getline(userfile >> ws, library1.user_info.book_taken);
    library1.info.push_back(library1.user_info);
}
userfile.close();
    
    int switch_const;
    bool while_condition = true;
    cout<<"***** LIBRARY *****"<<"\n";
    while(while_condition){
        cout<<"What do you want to do: "<<"\n";
        cout<<"Press 1 for adding books: "<<"\n";
        cout<<"Press 2 for issuing books: "<<"\n";
        cout<<"Press 3 for returning book: "<<"\n";
        cout<<"Press 4 for checking books are available or not: "<<"\n";
        cout<<"Press 5 for displaying issued book: "<<"\n";
        cin>>switch_const;
        
    switch (switch_const)
    {
    case 1:
        library1.add_book();
        break;
    case 2:
        library1.issue_book();
        break;
    case 3:
        library1.return_book();
        break;
    case 4:
        library1.check_books_available_or_not();
        break;
    case 5:
        library1.Display_issued_book();
break; 
default: cout<<"Please enter a valid option: ";
 break;
}

ofstream updatebooks("books.txt");
for (int j = 0; j < library1.book.size(); j++) {
 updatebooks << library1.book[j].name_of_book << "\n";
updatebooks << library1.book[j].Availability << "\n";
}
updatebooks.close();

 ofstream updateusers("users.txt");
for (int j = 0; j < library1.info.size(); j++) {
if (library1.info[j].book_taken != " ") {
 updateusers << library1.info[j].name_of_user << "\n";
updateusers << library1.info[j].roll_no_of_user << "\n";
 updateusers << library1.info[j].book_taken << "\n";
}
}
 updateusers.close();

 cout<<"Press 1 to continue or 0 to exit the program: ";
cin>>while_condition;
 }
 
return 0;
}
