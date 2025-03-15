/*Implement a restaurant ordering system that holds information about the restaurant’s menus, menu
items, orders, and payments. Identify the relationship between the five entities mentioned. Keep in
mind the following information as well:
a) Menu Items hold two things: food name and food price.
b) Menu is a class that holds an array of menu items. You can have different functions to add and
remove items, or display the entire menu.
c) Restaurant ordering system has one menu.
d) Any staff member can place an order to the system on behalf of a customer. Theorder class
consists of one or more menu items and a payment.
e) Payment is a class that holds the amount of money that a customer needs to pay.This is
generated when the order is placed.*/
#include <iostream>
#include <string>
using namespace std;
class MenuItem {
public:
    string foodName;
    double foodPrice;
    MenuItem(string name, double price) {
        foodName = name;
        foodPrice = price;
    }
    void displayItem() {
        cout << foodName << " - $" << foodPrice << endl;
    }
};
class Menu {
public:
    MenuItem* item1; 
    MenuItem* item2;
    MenuItem* item3;
    Menu(MenuItem* i1, MenuItem* i2, MenuItem* i3) {
        item1 = i1;
        item2 = i2;
        item3 = i3;
    }

    void displayMenu() {
        cout << "Menu:" << endl;
        item1->displayItem();
        item2->displayItem();
        item3->displayItem();
    }
};
class Payment {
public:
    double totalAmount;
    Payment(double amount) {
        totalAmount = amount;
    }

    void displayPayment() {
        cout << "Total Amount to Pay: $" << totalAmount << endl;
    }
};
class Order {
public:
    MenuItem* orderItem1;
    MenuItem* orderItem2;
    Payment* payment;      
    Order(MenuItem* item1, MenuItem* item2, Payment* pay) {
        orderItem1 = item1;
        orderItem2 = item2;
        payment = pay;
    }
    void displayOrder() {
        cout << "Order Details:" << endl;
        orderItem1->displayItem();
        orderItem2->displayItem();
        payment->displayPayment(); 
    }
};

class RestaurantOrderingSystem {
public:
    Menu menu;
    RestaurantOrderingSystem(Menu m) : menu(m) {}
    Order placeOrder(MenuItem* item1, MenuItem* item2, Payment* payment) {
        return Order(item1, item2, payment);
    }
};
int main() {
    MenuItem burger("Burger", 5.99);
    MenuItem pizza("Pizza", 8.99);
    MenuItem salad("Salad", 3.49);
    Menu restaurantMenu(&burger, &pizza, &salad);
    restaurantMenu.displayMenu();
    Payment payment(14.98);
    RestaurantOrderingSystem restaurant(restaurantMenu);
    Order order = restaurant.placeOrder(&burger, &pizza, &payment);
    order.displayOrder();

    return 0;
}
