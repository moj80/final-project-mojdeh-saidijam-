#ifndef ORDER_H
#define ORDER_H
#include <iostream>

void dedicate(Drug *dr, Drug *order[]);
int check(int id,Drug *order[]);

class Order
{
	public:
		void takeOrder(Drug *dr[], Drug *order[]);
		static int order;
};

#endif 
