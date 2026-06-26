//-------------------------SIGN-IN/SIGN-UP------------------------------

#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

// function for color
void color(int c){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

class User
{
private:
    string name, password, role;

public:

User(){
color(11);
cout<<"Default Constructor Activated!\n";
color(7);
}

User(string name,string password,string role){
this->name=name;
this->password=password;
this->role=role;

color(10);
cout<<" Account Registered Successfully!\n";
color(7);
}

User(const User& user){
name=user.name;
password=user.password;
role=user.role;

 color(14);
cout<<" Copy Constructor Triggered!\n";
 color(7);
}

~User(){
color(8);
cout<<" Destructor Called for User: "<<name<<endl;
color(7);
}

bool signin(string n,string p){
return (n==name && p==password);
}

void showrole(){
color(13);
cout<<"[Role Access] "<<role<<endl;
color(7);
}

void showdata(){

color(11);
cout<<"\n----------- USER PROFILE -----------\n";
color(7);

cout<<"Name : "<<name<<endl;
cout<<"Role : "<<role<<endl;

color(11);
cout<<"------------------------------------\n";
color(7);
}
};

int main(){

color(9);
cout<<"====================================\n";
cout<<"        DIGITAL USER PORTAL\n";
cout<<"====================================\n";
color(7);

User *user1=NULL;
int choice;

do{

color(11);
cout<<"\n--------------- MENU ----------------\n";
color(7);

cout<<" 1. Create Account (Sign Up)\n";
cout<<" 2. Login to Account (Sign In)\n";
cout<<" 3. Exit System\n";

color(11);
cout<<"-------------------------------------\n";
color(7);

cout<<"Select Option : ";
cin>>choice;

if(choice==1){

color(9);
cout<<"\n=========== ACCOUNT CREATION =========\n";
color(7);

string name,password,role;

cout<<"Enter User Name  : ";
cin>>name;

cout<<"Enter Password   : ";
cin>>password;

cout<<"Enter Role(Admin/User) : ";
cin>>role;

if(user1!=NULL)
delete user1;

user1=new User(name,password,role);

color(10);
cout<<"  Account Created!\n";
color(7);
}

else if(choice==2){

if(user1==NULL){
color(14);
cout<<" No account exists. Please Sign Up first.\n";
color(7);
continue;
}

color(9);
cout<<"\n============== LOGIN PANEL ==============\n";
color(7);

string n,p;

cout<<"Enter Username : ";
cin>>n;

cout<<"Enter Password : ";
cin>>p;

if(user1->signin(n,p)){

color(10);
cout<<"\n Welcome Back!\n";
color(7);

user1->showdata();

}

else{

color(12);
cout<<"\n Invalid Credentials!\n";
color(7);

cout<<" Creating Secure Backup Copy...\n";

User user2=*user1;

user2.showrole();
}

}

else if(choice!=3){

color(12);
cout<<" Invalid Option Selected!\n";
color(7);

}

}while(choice!=3);

delete user1;

color(8);
cout<<"\n====================================\n";
cout<<"        SYSTEM SHUTDOWN\n";
cout<<"====================================\n";
color(7);

return 0;
}