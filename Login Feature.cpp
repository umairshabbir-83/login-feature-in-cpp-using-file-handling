#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//Structs
struct User
{
	char userName[60];
	char Password[8];
};

//Functions
void loadUser(User arr[], int size)
{
	ifstream user;
	user.open("Users.csv");
	for(int i=0;i<size;i++)
	{
		user>>arr[i].userName>>arr[i].Password;
	}
	user.close();
}

bool findUser(User arr[], int size, User toFind)
{
	loadUser(arr,size);
	for(int i=0;i<size;i++)
	{
		if(strcmp(arr[i].userName,toFind.userName)== 0 && strcmp(arr[i].Password,toFind.Password)== 0)
		{
			return true;
			break;			
		}
	 }
  return false;;
}

//Main Block
int main()
{
	int size = 5;
	User regUser[size];
	User user;
	
	Label1:cout<<"\n** Kindly enter the credentials to access the system features **"<<endl;
	cout<<"Username: ";cin>>user.userName;
	cout<<"Password: ";cin>>user.Password;
	
	int find=findUser(regUser,size,user);
	if(find==true)
	{
		cout<<"** You have been successfully logged in to the system **"<<endl;
	}
	else
	{
		cout<<"\n** UserName OR Password is Incorrect **\n";
		goto Label1;
	}
}