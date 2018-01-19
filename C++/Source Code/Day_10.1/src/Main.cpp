#include<iostream>
#include<string>
#include<typeinfo>
using namespace std;

namespace nexception
{
	class ArgumentException
	{
	private:
		const string message;
	public:
		ArgumentException( const string message ) throw( ) : message( message )
		{	}
		const string getMessage( void )const
		{
			return this->message;
		}
	};
}
using namespace nexception;
namespace nshape
{
	class Shape
	{
	protected:
		float area;
	public:
		Shape( void ) throw( ) : area( 0.0f ){	}

		virtual void calculateArea( void ) throw( ) = 0 ;

		int getArea( void )const throw( )
		{
			return this->area;
		}
		virtual ~Shape( void ){	}
	};
	class Rectangle : public Shape
	{
	private:
		float length;
		float breadth;
	public:
		Rectangle( void ) throw( ): length( 0.0f ), breadth( 0.0f )
		{	}
		void setLength( const float length )throw( ArgumentException )
		{
			if( this->length >= 0.0 )
				this->length = length;
			else
				throw ArgumentException("Invalid length.");
		}
		void setBreadth( const float breadth )throw( ArgumentException )
		{
			if( this->breadth >= 0.0 )
				this->breadth = breadth;
			else
				throw ArgumentException("Invalid breadth.");
		}
		virtual void calculateArea( void )throw( )
		{
			this->area = this->length * this->breadth;
		}
	};
	class Math
	{
	public:
		static const float PI;
	public:
		static float power( float base, int index )throw( )
		{
			float result = 1;
			for( int count = 1; count <= index; ++ count )
			{
				result = result * base;
			}
			return result;
		}
	};
	const float Math::PI = 3.14f;
	class Circle : public Shape
	{
	private:
		float radius;
	public:
		Circle( void ) : radius( 0 )
		{	}
		void setRadius( const float radius )throw( ArgumentException )
		{
			if( this->radius >= 0.0 )
				this->radius = radius;
			else
				throw ArgumentException("Invalid radius");
		}
		virtual void calculateArea( void )throw( )
		{
			this->area = Math::PI * Math::power(this->radius, 2);
		}
	};
	enum ShapeType
	{
		EXIT, RECTANGLE, CIRCLE
	};
	class ShapeFactory
	{
	public:
		static Shape* getInstance( ShapeType choice )
		{

			switch( choice )
			{
			case RECTANGLE:	return new Rectangle();
			case CIRCLE: return new Circle();
			}
			return NULL;
		}
	};
}
using namespace nshape;
void accept_record( Shape* const ptrShape )throw( ArgumentException )
{
	if( dynamic_cast<Rectangle*>(ptrShape) != NULL )
	{
		Rectangle* ptr = dynamic_cast<Rectangle*>(ptrShape);

		float length;
		cout<<"Length	:	";
		cin>>length;
		ptr->setLength(length);

		float breadth;
		cout<<"Breadth	:	";
		cin>>breadth;
		ptr->setBreadth(breadth);
	}
	else
	{
		Circle* ptr = dynamic_cast<Circle*>(ptrShape);
		float radius;
		cout<<"Radius	:	";
		cin>>radius;
		ptr->setRadius(radius);
	}
}
void print_record( const Shape* const ptrShape )throw( )
{
	string name = typeid( *ptrShape ).name();
	cout<<"Area of object of "<<name<<" is "<<ptrShape->getArea()<<endl;
}
ShapeType menu_list( void )
{
	int choice;
	cout<<"0.Exit"<<endl;
	cout<<"1.Rectangle"<<endl;
	cout<<"2.Circle"<<endl;
	cout<<"Enter choice	:	";
	cin>>choice;
	return ShapeType( choice );
}
int main( void )
{
	try
	{
		ShapeType choice;
		while( ( choice = ::menu_list( ) ) != EXIT )
		{
			Shape* ptrShape = ShapeFactory::getInstance(choice);
			if( ptrShape != NULL )
			{
				::accept_record(ptrShape);
				ptrShape->calculateArea();
				::print_record(ptrShape);
				delete ptrShape;
			}
		}
	}
	catch (ArgumentException& e)
	{
		cout<<e.getMessage()<<endl;
	}
	catch(...)
	{
		cout<<"Internal error."<<endl;
	}
	return 0;
}
