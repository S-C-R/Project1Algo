//Programmer: Ben Langston
#include insertion.h
#include <iostream>
#include <cstdlib>
#include <chrono>
using namespace std;


int main()
{
	int coont=0, size=0, selfvalue=0;
	double tyme=0.0;
	char mode='a', autonomy='y';
	cout<<"Enter what case you want (b for best; w for worst; a for average):"<<endl;
	cin>>mode;
	if((mode!='b'&&mode!='w')&&mode!='a')
	{
		cout<<"User entered an invalid case, using best case"<<endl;
		mode='b';
	}
	cout<<"Enter group size (1-500):"<<endl;
	cin>>size;
	if(size<1||size>500)
	{
		cout<<"User entered invalid size, group size is now 1"<<endl;
		size=1;
	}
	cout<<"Enter the amount of runs (1-100):"<<endl;
	cin>>coont;
	if(coont<1||coont>100)
	{
		cout<<"User entered invalid amount of runs, running 1 time"<<endl;
		coont=1;
	}
	for(int k=0;k<coont;k++)
	{
		Insertion<int> group(size);
		if(mode=='b')
		{
			for(int i=1;i<size+1;i++)
			{
				group.set(i,i);
			}
		}
		else if(mode=='w')
		{
			for(int i=1;i<size+1;i++)
			{
				group.set(i,size-i);
			}
		}
		else if(mode=='a')
		{
			cout<<"Do you want to put in your own inputs?(y/n):"<<endl;
			cin>>autonomy;
			if(autonomy=='y')
			{
				for(int i=1;i<size+1;i++)
				{
					cout<<"Put in the integer at location "<<i<<":"<<endl;
					cin>>selfvalue;
					if(!cin)
					{
						cout<<"not a valid int, the value will be 0"<<endl;
						selfvalue=0;
					}
					group.set(i,selfvalue);
				}
			}
			else
			{
				for(int i=1;i<size+1;i++)
				{
					group.set(i,rand()%500);
					//This loop creates a random int between 0 and 499 for every value in group
				}
			}
		}
		auto start = high_resolution_clock::now(); 					  //Start of timing
		group.sort();											     //The actual insertion sort
		auto stop = high_resolution_clock::now(); 					//End of timing
		auto duration = duration_cast<microseconds>(stop - start); //The timing translated into microseconds
		cout<<duration.count()<<" microseconds"<<endl;			  //Output of time into console
		tyme+=duration.count();									 //Add all time together to get average
	}
	
	cout<<"Average time: "<<tyme/coont<<endl;				 //Total time divided by the number of run-throughs
	return 0;
}
