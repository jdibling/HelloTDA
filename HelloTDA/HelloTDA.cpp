// HelloTDA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int main()
{
	std::cout << "Hello, TDA" << std::endl;
	tda::Session tdaSession; // create the TDA session
	tda::Subscriber tdaSubscriber(tdaSession); // create first subscriber

	
   return 0;
}

