#include "insertion.h"

void Insertion<T>::set(int num,int data)
{
	array[num] = data;
	return;
}


void Insertion<T>::sort()
{
	int i=1;
	while(i<max&&i>0)
	{
		while(array[i]>array[i+1])
		{
			T temp = array[i];
			array[i] = array[i+1];
			array[i+1] = temp;
			if(i-1>0)
			{
				i-=1;
			}
		}
		i++;
	}
	return;
}	