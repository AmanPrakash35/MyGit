#pragma pack(1)
#include<iostream>
#include<string>
using namespace std;
/*int main( void )
{
	//string str("Pune");
	string str= "Pune";
	cout<<str<<endl;
	return 0;
}*/
/*int main( void )
{
	string str1= "SunBeam";
	string str2= "Pune";
	string str = str1 + str2;
	cout<<str<<endl;
	return 0;
}*/
/*int main( void )
{
	string name;
	cout<<"Name	:	";
	cin>>name;
	cout<<"Name	:	"<<name<<endl;
	return 0;
}*/

/*int main( void )
{
	char name[ 50 ];
	cout<<"Name	:	";
	cin.getline(name, 50, '\n');
	string text( name );
	cout<<"Name	:	"<<text<<endl;
	return 0;
}*/
int main( void )
{
	size_t size = sizeof( string );
	cout<<"Size	:	"<<size<<endl;
	return 0;
}
