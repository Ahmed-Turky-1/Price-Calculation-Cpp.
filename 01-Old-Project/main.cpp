#include <iostream>
using namespace std;

int main() {
    // Initializing the base price variable
    int price = 2000;

    // Displaying various arithmetic operations without changing the original variable
    cout << "Price After Adding 4000 Is: " << price + 4000 << endl;
    cout << "\nPrice After Tripling Is: " << price * 3 << endl;
    cout << "\nPrice After Increase 577 Is: " << price + 577 << endl;
    cout << "\nPrice After Decrease 577 Is: " << price - 577 << endl;

    // Updating the variable value
    price = 8000;
    cout << "\nThe new Price is: " << price << endl;

    return 0;
}
