// The following program computes the probability of
// obtaining a number when you throw two dice given
// the number of trials. 

// Following are the standard librarires that are used
#include <iostream> 	//
#include <cstdlib>
#include <ctime>

using namespace std;
const int sides = 6;
inline int r_sides(){return(rand()%sides + 1);}

int main(void)
{

const int n_dice = 2;
int d1, d2;					// header definition
srand(clock());

// This part of the algorithm checks the probability of dice
// and show that computer algo recreates reality. 
cout << "\nWe are going to initially throw the dice and see the probability of obtaining a particular sum" << endl;
cout << "\n----------------------------------------------------------------------------------------------" << endl;
cout << "\nEnter the number of trial throws: ";
	int trials;					// interleased definition
	cin >> trials;
	if(trials>1e6) cerr << "WARNING: Better enter something less." << endl;
  	int* outcomes = new int[n_dice*sides + 1];

  	for (int j=0; j<trials; j++) outcomes[(d1=r_sides())+(d2=r_sides())]++;
  	cout << "probability of obtaining a sum\n";
  	for (int j=2; j<n_dice*sides + 1; j++) 
    	cout << "j = " << j << "\t p = " << static_cast<double>(outcomes[j])/trials << endl ;
	cout << "--------------------------"<< endl;
  	// Create a computer dice
 	bool run = true;
  	cout << "Press 'Enter' to roll or 'Ctrl+z' to stop rolling the dice" << endl;
	cout << "Dice 1" << "\t" << "Dice 2" << endl;
  	while(run){
  		if(cin.get() == '\n')
			cout << r_sides() << "\t" << r_sides()  << endl;
		else{ 
			if(cin.get() == '^Z') run=false;
			else cout << "Error: Invalid input. Press 'Enter' to run or 'Ctrl+Z' to stop" << endl;   
		}
  	}
}
