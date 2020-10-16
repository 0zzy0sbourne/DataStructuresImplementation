#include <iostream> 
#include <stdbool.h> 
#include <cmath> 
#define LENGTH  10 
using namespace std; 

struct array{
	int length = LENGTH ;
	bool  search(int*); 
	void printArray(int*); 
	void sortArray(int*);
       	void createArray( int* ) ;
	int* arrayptr =(int*)malloc(sizeof(int) * length);  	
	array() // send the pointer to your array. 
	{
	 
		 createArray(arrayptr);
	       	 sortArray(arrayptr);
	   	 printArray(arrayptr);
		 search(arrayptr); 	 
	}
	
	

}; 
void array::createArray( int* ptr)
{
	int choice ;
	cout<<"Enter your array:"<<endl; 	
	for(int i = 0;i<length;i++) 
	{
		cin>>choice;
	       	*(ptr+i) = choice ; 	
	}

}
bool array::search( int* ptr)
{	
	int  m ; 
	int iter = 0 ; 
	int lastindex  = length-1 ;  
	bool found  = false ; 
	int desiredVal;  
	cout<<"Enter the value that you want to search:"<<endl;  
	cin>>desiredVal; 
	while(iter<= lastindex)
	{
		m = floor((iter+lastindex) / 2) ; 
		if(*(ptr+m) < desiredVal) 
		{
			iter = m + 1 ; 
		}
		else if(*(ptr+m)  > desiredVal)
		{
			lastindex = m-1 ; 
		}
		else {
			found = true ;
		       	break; 	
		}
	}	
	if(found == true)
	{
		cout<<"Found!!!"<<endl; 
	}
	return found ; 
		
}
void array::printArray(int* ptr)
{
	for(int i =0;i<length;i++)
	{
		cout<<*(ptr+i)<<" "; 
	}
}
void  array::sortArray(int* ptr)
{
	int a;  
	for(int i = 0;i<length;i++) 
	{
	
		for(int j = i;j< length;j++) 
		{
			if(*(ptr+i) > *(ptr+j)) 
			{
				a = *(ptr+i); 
				*(ptr+i) = *(ptr+j); 
				*(ptr+j) = a ; 
			}	
				
		}

	}
	
 	
}


int main()
{
		
	
	struct array newarray;  
	



	return 0 ;  
}
