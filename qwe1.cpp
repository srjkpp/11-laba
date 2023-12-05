#include <iostream>
#include "windows.h"
#include <iomanip>
#define _USE_MATH_DEFINES 
#include <math.h> 
#include <cmath>
#include <cstdlib>
#include "time.h"
#include <string>

using namespace std;

const int MAX_PRODUCTS = 100;

struct shop {
    int art;
    char name[50];
    double price;
    int kilk;
};

void display_Product(const shop product) {
    cout << "Артикул: " << product.art << "\tНазва: " << product.name << "\tЦіна: " << fixed << setprecision(2) << product.price
        << "\tКількість: " << product.kilk << endl;
}

double TotalPrice(const shop products[], int n) {
    double totalPrice = 0.0;
    for (int i = 0; i < n; ++i) {
        totalPrice += products[i].price;
    }
    return totalPrice;
}

void diap(const shop products[], int n, double minPrice, double maxPrice) {
    cout << "Перелік товарів, що потрапляє у заданий діапазон вартості товару:" << endl;
    for (int i = 0; i < n; ++i) {
        if (products[i].price >= minPrice && products[i].price <= maxPrice) {
            display_Product(products[i]);
        }
    }
}

    int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int a;
    cout << "Введіть кілткість товарів: ";
    cin >> a;
    if (a <= 0 || a > MAX_PRODUCTS) {
        cout << "Кількість продуктів повинна бути від 1 до " << MAX_PRODUCTS << endl;
        return 1;
    }

    shop products[MAX_PRODUCTS];

    for (int i = 0; i < a; ++i) {
        cout << "Введіть данні про товар " << i + 1 << ":" << endl;
        cout << "номер: ";
        cin >> products[i].art;

        cout << "Назва: ";
        cin.ignore();
        cin.getline(products[i].name, sizeof(products[i].name));

        cout << "Ціна: ";
        cin >> products[i].price;
        

        cout << "Кількість: ";
        cin >> products[i].kilk;
    }

    cout << "Товари:" << endl;
    for (int i = 0; i < a; ++i) {
        display_Product(products[i]);
    }
    double total = TotalPrice(products, a);
    cout << "Ціна усіх товарів: " << fixed << setprecision(2) << total << endl;

    double minPrice, maxPrice;
    cout << "Введіть мінімальну ціну: ";
    cin >> minPrice;

    cout << "Введіть максимальну ціну: ";
    cin >> maxPrice;

    diap(products, a, minPrice, maxPrice);



    return 0;
}