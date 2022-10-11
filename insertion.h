#ifndef "INSERTION_H"
#define "INSERTION_H"

#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class Insertion<T>
{
	public:
		Insertion()
		{
			cout<<"How big is hte areeay"<<endl;
			cin>>max;
			*array = new T[max+1];
		}
		Insertion(count)
		{
			max = count;
			*array = new T[max+1];
		}
		T *array;
		int max;
		void set(int num,int data);
		void sort();
		~Insertion()
		{
			delete[] array;
		}
};


#endif