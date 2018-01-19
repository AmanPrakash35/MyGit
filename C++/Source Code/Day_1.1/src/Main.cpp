#include<stdio.h>
/*
namespace na
{
	int num1 = 10;
}
namespace nb
{
	int num1 = 20;
}
int main( void )
{
	printf("Num1	:	%d\n",na::num1);	//10

	printf("Num1	:	%d\n",nb::num1);	//20
	return 0;
}*/


/*int num1 = 10;
namespace na
{
	int num2 = 20;
	namespace nb	//Nested namespace
	{
		int num3 = 30;
	}
}

int main( void )
{
	printf("Num1	:	%d\n",::num1);	//10
	printf("Num2	:	%d\n",na::num2);	//20
	printf("Num3	:	%d\n",na::nb::num3);	//30
	return 0;
}*/

/*int num1 = 10;
namespace na
{
	int num1 = 20;
	namespace nb	//Nested namespace
	{
		int num1 = 30;
	}
}

int main( void )
{
	printf("Num1	:	%d\n",::num1);	//10
	printf("Num2	:	%d\n",na::num1);	//20
	printf("Num3	:	%d\n",na::nb::num1);	//30
	return 0;
}*/

/*namespace na
{
	int num1 = 10;
}
namespace na
{
	int num2 = 20;
}

int main( void )
{
	printf("Num1	:	%d\n",na::num1);
	printf("Num2	:	%d\n",na::num2);
	return 0;
}*/

/*namespace na
{
	int num1 = 10;
}
namespace na
{
	int num1 = 20;	//Not Allowed
}

int main( void )
{
	printf("Num1	:	%d\n",na::num1);
	printf("Num2	:	%d\n",na::num1);
	return 0;
}*/

/*int num1 = 10;
namespace na
{
	int num1 = 20;
	namespace na
	{
		int num1 = 30;
	}
}

int main( void )
{
	printf("Num1	:	%d\n",::num1);
	printf("Num1	:	%d\n",na::num1);
	printf("Num2	:	%d\n",na::na::num1);
	return 0;
}*/

/*namespace na
{
	int num1 = 10;
}
int main( void )
{
	using namespace na;
	printf("Num1	:	%d\n",num1);
	printf("Num1	:	%d\n",na::num1);
	return 0;
}*/

/*namespace na
{
	int num1 = 10;
}
int main( void )
{
	int num1 = 20;
	using namespace na;
	printf("Num1	:	%d\n",num1);	//20
	return 0;
}*/

/*int num1 = 10;
namespace na
{
	int num2 = 20;
	namespace nb
	{
		int num3 = 30;
	}
}
int main( void )
{
	printf("Num3	:	%d\n",na::nb::num3);

	using namespace na::nb;
	printf("Num3	:	%d\n",num3);

	using namespace na;
	using namespace nb;
	printf("Num3	:	%d\n",num3);


	//printf("Num2	:	%d\n",na::num2);

	using namespace na;
	printf("Num2	:	%d\n",num2);
	return 0;
}*/

/*namespace na
{
	int num1 = 10;
	namespace nb
	{
		int num1 = 20;
	}
}
int main( void )
{
	using namespace na;
	printf("Num1	:	%d\n",num1);	//10

	//using namespace na::nb;	//Ok
	using namespace nb;
	printf("Num1	:	%d\n",num1);	//Ambiguity error

	return 0;
}*/

/*namespace na
{
	int num1 = 10;
}
void show( void )
{
	using namespace na;
	printf("Num1	:	%d\n",num1);
}
void print( void )
{
	using namespace na;
	printf("Num1	:	%d\n",num1);
}
void display( void )
{
	using namespace na;
	printf("Num1	:	%d\n",num1);
}
int main( void )
{
	::show();

	::print();

	::display();
	return 0;
}*/

/*namespace na
{
	int num1 = 10;
}
using namespace na;
void show( void )
{
	//using namespace na;
	printf("Num1	:	%d\n",num1);
}
void print( void )
{
	//using namespace na;
	printf("Num1	:	%d\n",num1);
}
void display( void )
{
	//using namespace na;
	printf("Num1	:	%d\n",num1);
}
int main( void )
{
	::show();

	::print();

	::display();
	return 0;
}*/

/*
int num1 = 10;
namespace na
{
	int num1 = 20;
}
int main( void )
{
	printf("Num1	:	%d\n",num1);
	using namespace na;
	printf("Num1	:	%d\n",num1);
	return 0;
}
*/
