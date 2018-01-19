#include<cstring>
#include<iostream>
using namespace std;
namespace nstring
{
	class String
	{
	private:
		size_t length;
		char* buffer;
	public:
		String( void )
		{
			this->length = 0;
			this->buffer = NULL;
		}
		String( const char* str )
		{
			this->length = strlen(str);
			this->buffer = new char[ this->length + 1 ];
			strcpy(this->buffer, str);
		}
		void operator()( const char* str )
		{
			this->~String();
			this->length = strlen(str);
			this->buffer = new char[ this->length + 1 ];
			strcpy(this->buffer, str);
		}
		~String( void )
		{
			if( this->buffer != NULL )
			{
				delete[] this->buffer;
				this->buffer = NULL;
			}
		}
		friend ostream& operator<<( ostream& cout, const String& other )
		{
			cout<<other.buffer<<endl;
			return cout;
		}
	};
}
int main( void )
{
	using namespace nstring;
	String s1("Pune");
	s1("SunBeam");	//s1.operator()("SunBeam");
	cout<<s1<<endl;
	return 0;
}
