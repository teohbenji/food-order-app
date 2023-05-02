#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Order {
  public:
    string restaurantName;
    int itemNum;
};

string getName();
string getAddress();
int getUserChoice(int num_of_choices);
void orderFoodPage(string &name, vector<Order> &orderVectors);
void mainMenuPage(string &name, vector<Order> &orderVectors);
void orderConfirmationPage(string &name, vector<Order> &ordersVector, Order order);

int main() {
  vector<Order> ordersVector;

  string name = getName();
  string address = getAddress();
  
  mainMenuPage(name, ordersVector);
}

string getName(){
  string name;
  cout << "Hi! Please enter your name: ";
  cin >> name;
  return name;
}

string getAddress(){
  string address;
  cout << "Please enter your address: ";
  cin >> address;
  return address;
}

int getUserChoice(int num_of_choices) {
  string choice;
  cin >> choice;
  
  if(num_of_choices == 4) {
    bool isChoiceValid = choice == "1" || choice == "2" || choice == "3" || choice == "4";

    while(!isChoiceValid) {
    cout << "\nInvalid choice! Your choice: ";

    cin >> choice;
    isChoiceValid = choice == "1" || choice == "2" || choice == "3" || choice == "4";
    }
  } else if(num_of_choices == 3) {
    bool isChoiceValid = choice == "1" || choice == "2" || choice == "3";

    while(!isChoiceValid) {
    cout << "\nInvalid choice! Your choice: ";

    cin >> choice;
    isChoiceValid = choice == "1" || choice == "2" || choice == "3";
    }
  }
  
  return stoi(choice);
}

void orderFoodPage(string &name, vector<Order> &ordersVector){
  cout << "\n=====Order food=====";
  Order order;
  cout << "\nWhere would you like to order from?";
  cout << "\n1. Restaurant A" << "";
  cout << "\n2. Restaurant B" << "";
  cout << "\n3. Restaurant C" << "";
  cout << "\n4. Return to main menu" << "";
  cout << "\nYour choice: ";
  

  int restaurantChoice = getUserChoice(4);
  
  if(restaurantChoice == 4) {
    mainMenuPage(name, ordersVector);
  } else {
    switch(restaurantChoice) {
    case 1:
      order.restaurantName = "A";
      break;
    case 2:
      order.restaurantName = "B";
      break;
    case 3:
      order.restaurantName = "C";
      break;
    }
  }

  cout << "\nWhere would you like to order from?";
  cout << "\n1. Food Item 1" << "";
  cout << "\n2. Food Item 2" << "";
  cout << "\n3. Food Item 3" << "";

  int itemChoice = getUserChoice(3);
  order.itemNum = itemChoice;

  orderConfirmationPage(name, ordersVector, order);

}

void orderConfirmationPage(string &name, vector<Order> &ordersVector, Order order){
  cout << "\n=====Order confirmation=====";
  cout << "\nYour order: ";
  cout << "\nRestaurant " << order.restaurantName;
  cout << "\nItem " << order.itemNum;
  cout << "\nPress 1 to confirm, 2 to restart, 3 to return to main menu";
  cout << "\nYour choice: ";

  int choice = getUserChoice(3);

  switch(choice) {
    case 1:
      ordersVector.push_back(order);
      //TODO: make bottom into afterorderConfirmation page
      cout << "\nPress 1 to confirm, 2 to restart, 3 to return to main menu";
      cout << "\nYour choice: ";
      break;
    case 2:
      orderFoodPage(name, ordersVector);
      break;
    case 3:
      mainMenuPage(name, ordersVector);
      break;
  }
}

void mainMenuPage(string &name, vector<Order> &ordersVector){
  cout << "\n=====Main menu=====";
  cout << "Hi, " << name << "! What would you like to do today?";
  cout << "\n1. Order food";
  cout << "\n2. Check order history";
  cout << "\n3. Change delivery address";
  cout << "\n4. Exit";
  cout << "\nYour choice: ";

  int choice = getUserChoice(4);
  
  switch(choice) {
    case 1:
      orderFoodPage(name, ordersVector);
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
  }
}




