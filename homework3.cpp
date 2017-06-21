#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Maze
{
	char **p;
	int row, col, startr, startc, endr, endc;
public:
	
	Maze( ifstream &in )
	{
		in >> row >> col >> startr >> startc >> endr >> endc;
		
		p = new char * [row];
		for( int i = 0; i < row; i++ )
		{
			p[i] = new char[col];
			for( int r = 0; r < col; r++ )
				in >> p[i][r];
		}
		show();

		if( !find_path(startr, startc) )
		{
			cout << "Error!  No Path found!!!\n";
		}
		else
		{
			cout << endl << endl;
			show();
		}

		
	}

	void show()
	{
		for( int i = 0; i < row; i++ )
		{
			for( int c = 0; c < col; c++ )
			{
				if( p[i][c] == 'x' ) p[i][c] = '0';
				cout << p[i][c] << "  ";
			}
			cout << endl;
		}
	}



	bool find_path( int cr, int cc )
	{
		if( cr < 0 || cr > row - 1 || cc < 0 || cc > col - 1 || p[cr][cc] != '0' )
			return false;

		p[cr][cc] = 'm';

		if( cr == endr && cc == endc )			
			return true;

		if( !find_path( cr - 1, cc )  && !find_path( cr + 1, cc ) && !find_path( cr, cc - 1 )  && !find_path( cr, cc + 1 ) )
			return	!(p[cr][cc] = 'x');
			
		return true;
	}
};


void main()
{
	ifstream in("input.txt");            
	Maze maze( in );
	cout << endl;
	system("pause");
}