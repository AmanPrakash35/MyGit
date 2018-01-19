#include<iostream>
using namespace std;

class Point
{
private:
	int xPos;
	int yPos;
public:
	Point( void )
	{
		this->xPos = 0;
		this->yPos = 0;
	}
	Point( int xPos, int yPos )
	{
		this->xPos = xPos;
		this->yPos = yPos;
	}
	void printRecord( void )
	{
		cout<<"X Position	:	"<<this->xPos<<endl;
		cout<<"Y Position	:	"<<this->yPos<<endl;
	}
	friend Point operator+( Point& pt1, Point& pt2 )
	{
		Point temp;
		temp.xPos = pt1.xPos + pt2.xPos;
		temp.yPos = pt1.yPos + pt2.yPos;
		return temp;
	}
	friend Point operator+( Point& pt1, int value )
	{
		Point temp;
		temp.xPos = pt1.xPos + value;
		temp.yPos = pt1.yPos + value;
		return temp;
	}
	friend Point operator+( int value, Point& pt1)
	{
		Point temp;
		temp.xPos = value + pt1.xPos;
		temp.yPos = value + pt1.yPos;
		return temp;
	}
	friend bool operator==( Point& pt1, Point& pt2 )
	{
		return pt1.xPos == pt2.xPos && pt1.yPos == pt2.yPos;
	}
	friend Point operator+=( Point& pt1, Point& pt2 )
	{
		pt1.xPos += pt2.xPos;
		pt1.yPos += pt2.yPos;
		return pt1;
	}
	friend Point operator++( Point& pt1)
	{
		Point temp;
		temp.xPos = ++ pt1.xPos;
		temp.yPos = ++ pt1.yPos;
		return temp;
	}
	friend Point operator++( Point& pt1, int)
	{
		Point temp;
		temp.xPos = pt1.xPos ++;
		temp.yPos = pt1.yPos ++;
		return temp;
	}
	friend istream& operator>>( istream& cin, Point& other )
	{
		cout<<"Enter x position	:	";
		cin>>other.xPos;
		cout<<"Enter y position	:	";
		cin>>other.yPos;
		return cin;
	}
	friend ostream& operator<<( ostream& cout, Point& other )
	{
		cout<<"X Position	:	"<<other.xPos<<endl;
		cout<<"Y Position	:	"<<other.yPos<<endl;
		return cout;
	}
};

/*int main( void )
{
	Point pt1(10,20);
	Point pt2(30,40);
	Point pt3;
	//pt3 = pt1 + pt2;	//pt3 = operator+( pt1, pt2 );
	pt3.printRecord();
	return 0;
}*/
/*int main( void )
{
	Point pt1(10,20);
	Point pt2;
	pt2 = pt1 + 5;	//pt2 = operator+( pt1, 5 );
	pt2.printRecord();
	return 0;
}*/
/*int main( void )
{
	Point pt1(10,20);
	Point pt2;
	pt2 = 5 + pt1;	//pt2 = operator+( 5, pt1 );
	pt2.printRecord();
	return 0;
}*/
/*int main( void )
{
	Point pt1(10,20);
	Point pt2(10,20);
	bool status = pt1 == pt2;	//bool status = operator==( pt1, pt2 )
	if( status )
		cout<<"Equal"<<endl;
	else
		cout<<"Not Equal"<<endl;
	return 0;
}*/
/*int main( void )
{
	Point pt1(10,20);
	Point pt2(10,20);
	pt1 += pt2;	//operator+=( pt1, pt2 );
	pt1.printRecord();
	return 0;
}*/
/*int main( void )
{
	Point pt1(10,20);

	Point pt2 = ++ pt1;	//Point pt2 = operator++( pt1 )

	pt2.printRecord();

	return 0;
}*/
/*int main( void )
{
	Point pt1(10,20);

	Point pt2 = pt1 ++;	//Point pt2 = operator++( pt1, 0 )

	pt2.printRecord();

	return 0;
}*/
int main( void )
{
	Point pt1;
	Point pt2;
	//cin>>pt1;	//operator>>( cin, pt1 );
	//cout<<pt1;	//operator<<( cout, pt1 );

	cin>>pt1>>pt2;
	cout<<pt1<<pt2;
	return 0;
}
