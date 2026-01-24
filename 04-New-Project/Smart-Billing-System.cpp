#include <iostream>
#include <string>
#include <iomanip> // For output formatting

using namespace std;

/**
 * Utility function to print a decorative separator
 */
void printSeparator() {
    cout << setfill('-') << setw(55) << "-" << setfill(' ') << endl;
}

int main() {
    // Using double for financial precision (handling decimals)
    double waterPrice, juicePrice, milkPrice;
    const double DISCOUNT_AMOUNT = 10.0;

    cout << "====================================================" << endl;
    cout << "          RETAIL PRICE CALCULATOR SYSTEM           " << endl;
    cout << "====================================================" << endl;

    // Input section with clear prompts
    cout << "Enter the unit price for Water: ";
    cin >> waterPrice;
    cout << "Enter the unit price for Juice: ";
    cin >> juicePrice;
    cout << "Enter the unit price for Milk:  ";
    cin >> milkPrice;

    /**
     * Reusable Lambda function to display the receipt
     * This avoids code duplication (DRY Principle)
     */
    auto displayReceipt = [&](string title, double w, double j, double m) {
        cout << "\n>>> " << title << " <<<" << endl;
        printSeparator();
        cout << left << setw(40) << "Item Description" << " | " << "Total Price" << endl;
        printSeparator();
        
        cout << setw(40) << "1 Water + 1 Juice" << " | " << (w + j) << endl;
        cout << setw(40) << "2 Waters" << " | " << (2 * w) << endl;
        cout << setw(40) << "2 Waters + 1 Juice" << " | " << (2 * w + j) << endl;
        cout << setw(40) << "5 Juices" << " | " << (5 * j) << endl;
        cout << setw(40) << "4 Waters + 3 Juices" << " | " << (4 * w + 3 * j) << endl;
        cout << setw(40) << "60 Waters + 40 Juices" << " | " << (60 * w + 40 * j) << endl;
        cout << setw(40) << "1000 Waters + 200 Juices" << " | " << (1000 * w + 200 * j) << endl;
        cout << setw(40) << "50 Milks + 2 Waters + 10 Juices" << " | " << (50 * m + 2 * w + 10 * j) << endl;
        cout << setw(40) << "1 Water + 10 Juices + 7 Milks" << " | " << (w + 10 * j + 7 * m) << endl;
        printSeparator();
    };

    // Stage 1: Display prices based on original input
    displayReceipt("PRICES BEFORE DISCOUNT", waterPrice, juicePrice, milkPrice);

    // Stage 2: Apply the discount to each item
    double discountedWater = waterPrice - DISCOUNT_AMOUNT;
    double discountedJuice = juicePrice - DISCOUNT_AMOUNT;
    double discountedMilk = milkPrice - DISCOUNT_AMOUNT;

    // Stage 3: Display prices after applying the discount
    displayReceipt("PRICES AFTER DISCOUNT (-10 per unit)", discountedWater, discountedJuice, discountedMilk);

    return 0;
}
