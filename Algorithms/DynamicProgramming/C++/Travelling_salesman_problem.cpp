
/*

Write a program to solve the travelling salesman problem and to print the path and the cost using
Dynamic Programming.
*/

#include<iostream>
using namespace std;


class travelling_salesman
{
    public:
 
    int distance[20][20], visited_city[20], n, cost = 0;
 
    void get_input();
    int least(int city);
    void Minimum_cost(int city);
    
};


void travelling_salesman::get_input()
{

	    cout << "Enter number of cities : ";
	    cin >> n;
 
	    cout << "\n\nEnter the distance matrix : \n";
 
	    for(int i=0; i<n; i++)
	    {
 
		    for(int j=0; j<n; j++)
            {
                cin >> distance[i][j];
            }
 
		    visited_city[i] = 0;
	    }
 

	    cout<<"\n\nThe distance matrix is :\n";
 
	    for(int i=0; i<n; i++)
	    {
            cout << "\n";

		    for(int j=0; j<n; j++)
            {
                cout << distance[i][j] << "  ";
            }
		    
	    }
}


int travelling_salesman::least(int city)
{
	    
        int i, next_city = 999, min=999, min1;
 
	    for(int i=0; i<n; i++)
        {
           if(distance[city][i] != 0 && visited_city[i] == 0)
           {
               if(distance[city][i] + distance[i][city] < min)
	           {
		          min = distance[i][0] + distance[city][i];
		          min1 = distance[city][i];
		          next_city = i;
	           }
           }
	        
        }
 

	    if(min != 999)
	    cost = cost + min1;
 
	    return next_city;
}


void travelling_salesman::Minimum_cost(int city)
{
	    
        int next_city;
 
	    visited_city[city] = 1;
 
	    cout << city+1 << "-->";

	    next_city = least(city);

        if(next_city == 999)
	    {
		    next_city = 0;

		    cout << next_city + 1;

		    cost = cost + distance[city][next_city];
 
		    return;
	    }
 
	    Minimum_cost(next_city);
}


int main()
{
    travelling_salesman ts;
    int s;
	
    ts.get_input();
     
    cout << "\n\nEnter start city : ";
    cin >> s;

    cout << "\n\nThe shortest path is : ";

	ts.Minimum_cost(s-1);

	cout << "\n\nMinimum cost of the Travelling Salesman Problem is " << ts.cost;

 
	return 0;
}


/*

Enter number of cities : 4


Enter the distance matrix : 
0 5 8 6
2 0 7 5
4 7 0 9
3 1 2 0


The distance matrix is :

0  5  8  6  
2  0  7  5  
4  7  0  9  
3  1  2  0  

Enter start city : 1    


The shortest path is : 1-->2-->4-->3-->1

Minimum cost of the Travelling Salesman Problem is 16

*/