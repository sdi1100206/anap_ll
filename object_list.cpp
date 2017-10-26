#include"object_list.h"
#include<string>
#include<cstring>

using namespace std;

Curve :: Curve( string onoma , vector < vector<double> > coors,vector <vector <double> > coors_in_grid)//Defining a curve
	:Next_Curve(NULL),onoma_kampulhs(onoma),coordinates(coors),coordinates_in_grid(coors_in_grid){}

Curve :: Curve(void) // defining a curve by default
	:Next_Curve(NULL){}

void Curve::Print_Curve(){//Print the coordinates of this curve
        //cout << coordinates << endl ;
}

/*
int Edge :: Get_start(){//take the key of the account sending money
	return Start;
}

*/
