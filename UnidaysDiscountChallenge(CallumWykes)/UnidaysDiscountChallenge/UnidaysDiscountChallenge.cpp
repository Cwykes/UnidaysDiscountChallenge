
#include "UnidaysDiscountChallenge.h"
#include <iostream>
#include <vector>
using namespace std;
//function to compare the list of items to the users list by returning each value
char PricingRules::GetItem(int i)
{
	return ItemList[i];
}

//function to compare the users list to the prices by returning each value
int PricingRules::GetPrice(int p)
{
	return PriceList[p];
}

//This function works out the price of all the a values (since a doesnt have any discounts) as well as calling the necessary functions to work out the other discounts the user has
int PricingRules::ApplyDiscount(int a, int b, int c, int d, int e) {

	DiscountApplyed = DiscountApplyed + a * PriceList[0];

	TwoForTwenty(b);
	ThreeForTen(c);
	BuyOneGetOneFree(d);
	ThreeForTwo(e);

	return DiscountApplyed;
}

//Works out the two for twenty discount on item b
void PricingRules::TwoForTwenty(int b) {
	while (b != 0) {
		//if b is divisable by 2 (even number), works out whether the basket is due for this discount and then adds the relevent amount to the total while making sure the number of "b" doesnt get added 
		if (b % 2 == 0)
		{
			for (int i = b; i > 0; i = i - 2) {
				DiscountApplyed = DiscountApplyed + 20;
				b = b - 2;
			}
		} else {
			DiscountApplyed = DiscountApplyed + PriceList[1];
			b--;
		}
	}
}


void PricingRules::ThreeForTen(int c) {
	while (c != 0) {
		//if c is divisable by 3 then calculates the discount needed in this case it is 3 lots of "c" for 10
		if (c % 3 == 0) {
			for (int i = c; i > 0; i = i - 3) {
				DiscountApplyed = DiscountApplyed + 10;
				c = c - 3;
			}
		} else {
			DiscountApplyed = DiscountApplyed + PriceList[2];
			c--;
		}
	}
}


void PricingRules::BuyOneGetOneFree(int d) {
	while (d != 0) {
		//If there are pairs of d than one of them is free as per the discount, this function works this out
		if (d % 2 == 0) {
			for (int i = d; i > 0; i = i - 2) {
				DiscountApplyed = DiscountApplyed + 7;
				d = d - 2;
			}
		} else {
			DiscountApplyed = DiscountApplyed + PriceList[3];
			d--;
		}
	}
}


void PricingRules::ThreeForTwo(int e) {
	while (e != 0) {
		//This function works out the discount forn the users e items, if the number of e items the user has chosen is a multiple of 3 it will only add on the values of two of the e items
		if (e % 3 == 0) {
			for (int i = e; i > 0; i = i - 3) {
				DiscountApplyed = DiscountApplyed + 10;
				e = e - 3;
			}
		} else {
			DiscountApplyed = DiscountApplyed + PriceList[4];
			e--;
		}
	}
}

//Adds items to the basket vector
void UnidaysDiscountChallenge::AddToBasket(char x)
{
	Basket.push_back(x);
}
//This function calculates the total price of all the items the user has selected which includes the discounts and delivery charge if necessary
void UnidaysDiscountChallenge::CalculateTotalPrice() {
	for (int i = 0; i < 5; i++) {
		DiscountBasket.push_back(0);
	}
	//for loop and switch/case to search through the entered items and determine the number of each items so the discounts can be calculated
	for (int i = 0; i < Basket.size(); i++) {
		switch (Basket[i])
		{
		case 'a':
			DiscountBasket.at(0) = DiscountBasket.at(0) + 1;
			break;
		case 'b':
			DiscountBasket.at(1) = DiscountBasket.at(1) + 1;
			break;
		case 'c':
			DiscountBasket.at(2) = DiscountBasket.at(2) + 1;
			break;
		case 'd':
			DiscountBasket.at(3) = DiscountBasket.at(3) + 1;
			break;
		case 'e':
			DiscountBasket.at(4) = DiscountBasket.at(4) + 1;
			break;
		default:
			break;
		}
	}
	//works out the total price of all the items as well as the discounts
	Total = Total + Discount.ApplyDiscount(DiscountBasket[0], DiscountBasket[1], DiscountBasket[2], DiscountBasket[3], DiscountBasket[4]);

	if (Total < 50) {
		Delivery = Delivery + 7;
		Total = Total + Delivery;
	}

	cout << "The total price of your order is : " << Total << " which includes a delivery charge of: " << Delivery << endl;
}