#pragma once

#include <vector>
using namespace std;

const int List = 5;

//Class called PricingRules contains the prices and discounts and provides them to be worked out by the UnidaysDiscountChallenge class
class PricingRules
{
public:
	char GetItem(int i);
	int GetPrice(int p);

	//Functions that calculate discounts
	int ApplyDiscount(int a, int b, int c, int d, int e);
	//No discount for item a
	void TwoForTwenty(int b);
	void ThreeForTen(int c);
	void BuyOneGetOneFree(int d);
	void ThreeForTwo(int e);

private:
	//Lists of items and respective prices
	char ItemList[List] = { 'a','b','c','d','e' };
	int PriceList[List] = { 8,12,4,7,5 };

	int DiscountApplyed = 0;
};

//Class called UnidaysDiscountChallenge that contains the items the user wants to buy as well as calculating the total price
class UnidaysDiscountChallenge
{
public:
	//Adds the users value to the "Basket" vector
	void AddToBasket(char item);
	//function to calculate the total price of the users entered items
	void CalculateTotalPrice();

	//From Pricing Rules class
	PricingRules Discount;
private:

	char Item;
	int Price;
	//Vectors containing the items the user entered as well as the discounts used to calculate the users total
	vector <char> Basket;
	vector <int> DiscountBasket;

	int Total;
	int Delivery = 0;
};
