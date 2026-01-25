#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

/**
 * Structure to represent a Product
 */
struct Product {
    string name;
    double price;
};

/**
 * RetailSystem Class to handle business logic and UI
 */
class RetailSystem {
private:
    vector<Product> products;
    const double DISCOUNT_VAL = 10.0;

    // Internal helper for formatting currency
    void formatCurrency(double value) const {
        cout << fixed << setprecision(2) << "$" << value;
    }

    // UI Helper for lines
    void drawLine(char c, int width) const {
        cout << setfill(c) << setw(width) << "" << setfill(' ') << endl;
    }

public:
    /**
     * Captures validated price input from user
     */
    void inputPrices() {
        vector<string> names = {"Water", "Juice", "Milk"};
        cout << " [Retail System - Input Phase] " << endl;
        
        for (const string& name : names) {
            double p;
            while (true) {
                cout << " > Enter price for " << left << setw(6) << name << ": ";
                if (cin >> p && p >= 0) {
                    products.push_back({name, p});
                    break;
                } else {
                    cout << "   Error: Please enter a valid positive number." << endl;
                    cin.clear();
                    cin.ignore(1000, '\n');
                }
            }
        }
    }

    /**
     * Calculates and displays the receipt based on current prices
     */
    void generateReceipt(string header, bool applyDiscount = false) const {
        double w = products[0].price;
        double j = products[1].price;
        double m = products[2].price;

        if (applyDiscount) {
            w = max(0.0, w - DISCOUNT_VAL);
            j = max(0.0, j - DISCOUNT_VAL);
            m = max(0.0, m - DISCOUNT_VAL);
        }

        cout << "\n\n" << header << endl;
        drawLine('=', 65);
        cout << left << setw(45) << "  Item Bundle Description" << " | " << "Total Cost" << endl;
        drawLine('-', 65);

        // Lambda for cleaner row rendering
        auto printRow = [&](string desc, double total) {
            cout << "  " << left << setw(43) << desc << " | ";
            formatCurrency(total);
            cout << endl;
        };

        printRow("1 Water + 1 Juice", (w + j));
        printRow("2 Waters", (2 * w));
        printRow("2 Waters + 1 Juice", (2 * w + j));
        printRow("5 Juices", (5 * j));
        printRow("4 Waters + 3 Juices", (4 * w + 3 * j));
        printRow("60 Waters + 40 Juices", (60 * w + 40 * j));
        printRow("1000 Waters + 200 Juices", (1000 * w + 200 * j));
        printRow("50 Milks + 2 Waters + 10 Juices", (50 * m + 2 * w + 10 * j));
        printRow("1 Water + 10 Juices + 7 Milks", (w + 10 * j + 7 * m));

        drawLine('=', 65);
    }
};

int main() {
    RetailSystem system;

    cout << "===============================================================" << endl;
    cout << "                MODERN RETAIL CALCULATOR v2.0                  " << endl;
    cout << "===============================================================" << endl;

    system.inputPrices();
    
    // Phase 1: Standard Pricing
    system.generateReceipt("REPORT: STANDARD RETAIL PRICES", false);

    // Phase 2: Discounted Pricing
    system.generateReceipt("REPORT: DISCOUNTED PRICES (-$10.00 Promo)", true);

    cout << "\n[System] Report generated successfully. Press Enter to exit." << endl;
    
    return 0;
}
