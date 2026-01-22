#include <iostream>
 using namespace std;

int main()
{
    // Set the price of one water bottle
    int water_price = 25;

    // Calculate the price of one juice (water price + 10)
    int juice_price = water_price + 10;

    // Calculate the price of milk (juice price + 20)
    int milk_price = juice_price + 20;

    // Store prices in variables
    int x = water_price;
    int y = juice_price;
    int z = milk_price;

    /* Output the total cost before discount */
    cout << "The price of one water and one juice is " << x + y;
    
    cout << "\nThe price of two water is " << 2 * x;
    
    cout << "\nThe price of two water and one juice is " << 2 * x + y;
    
    cout << "\nThe price of five juice is " << 5 * y;
    
    cout << "\nThe price of four water and three juice is " << 4 * x + 3 * y;
    
    cout << "\nThe price of sixty water and forty juice is " << 60 * x + 40 * y;
    
    cout << "\nThe price of one thousand water and two hundred juice is " << 1000 * x + 200 * y;
  
    cout << "\nThe price of fifty milk, two water, and ten juice is "<< 50 * z + 2 * x + 10 * y;
    
    cout << "\nThe price of one water, ten juice, and seven milk is " << x + 10 * y + 7 * z << endl;

    // Discount value
    int discount = 10;

    // Apply discount
    x = x - discount;
    y = y - discount;
    z = z - discount;

    /* Output the total cost after discount */
    cout << "\nAfter discounts" << endl;

    cout << "\nThe price of one water and one juice is " << x + y;
   
     cout << "\nThe price of two water is " << 2 * x;
    
    cout << "\nThe price of two water and one juice is " << 2 * x + y;
    
    cout << "\nThe price of five juice is " << 5 * y;
    
    cout << "\nThe price of four water and three juice is " << 4 * x + 3 * y;
    
    cout << "\nThe price of sixty water and forty juice is " << 60 * x + 40 * y;
    
    cout << "\nThe price of one thousand water and two hundred juice is " << 1000 * x + 200 * y;
    
    cout << "\nThe price of fifty milk, two water, and ten juice is" << 50 * z + 2 * x + 10 * y;
   
     cout << "\nThe price of one water, ten juice, and seven milk is "<< x + 10 * y + 7 * z;

    return 0;
}