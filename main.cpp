#include <conio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Order {
  public:
    string restaurantName;
    int itemNum;
};

class UserInfo {
  public: 
    string name;
    string address;
};

string getName();
string getAddress();
int getUserChoice(int num_of_choices);
void orderFoodPage(UserInfo &userInfo, vector<Order> &orderVectors);
void orderConfirmationPage(UserInfo &userInfo, vector<Order> &ordersVector, Order &order);
void orderAddedPage(UserInfo &userInfo, vector<Order> &ordersVector);
void viewAddressPage(UserInfo &userInfo, vector<Order> &ordersVector);
void editAddressPage(UserInfo &userInfo, vector<Order> &ordersVector);
void mainMenuPage(UserInfo &userInfo, vector<Order> &orderVectors);

int main() {
  vector<Order> ordersVector;
  
  string name = getName();
  string address = getAddress();

  UserInfo userInfo = {name, address};

  mainMenuPage(userInfo, ordersVector);
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
  } else if(num_of_choices == 2) {
    bool isChoiceValid = choice == "1" || choice == "2";

    while(!isChoiceValid) {
    cout << "\nInvalid choice! Your choice: ";

    cin >> choice;
    isChoiceValid = choice == "1" || choice == "2";
    }
  }
  
  return stoi(choice);
}

void orderFoodPage(UserInfo &userInfo, vector<Order> &ordersVector){
  Order order;
  
  cout << "\n=====Order food=====";
  cout << "\nWhere would you like to order from?";
  cout << "\n1. Restaurant A" << "";
  cout << "\n2. Restaurant B" << "";
  cout << "\n3. Restaurant C" << "";
  cout << "\n4. Return to main menu" << "";
  cout << "\nYour choice: ";
  

  int restaurantChoice = getUserChoice(4);
  
  if(restaurantChoice == 4) {
    mainMenuPage(userInfo, ordersVector);
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

  cout << "\nWhat would you like to order?";
  cout << "\n1. Food Item 1" << "";
  cout << "\n2. Food Item 2" << "";
  cout << "\n3. Food Item 3" << "";
  cout << "\nYour choice: ";

  int itemChoice = getUserChoice(3);
  order.itemNum = itemChoice;

  orderConfirmationPage(userInfo, ordersVector, order);
}

void orderConfirmationPage(UserInfo &userInfo, vector<Order> &ordersVector, Order &order){
  cout << "\n=====Order confirmation=====";
  cout << "\nYour order: ";
  cout << "\nRestaurant " << order.restaurantName << ". Item " << order.itemNum << ".";
  cout << "\nPress 1 to confirm, 2 to restart, 3 to return to main menu";
  cout << "\nYour choice: ";

  int choice = getUserChoice(3);

  switch(choice) {
    case 1:
      ordersVector.push_back(order);
      orderAddedPage(userInfo, ordersVector);
      break;
    case 2:
      orderFoodPage(userInfo, ordersVector);
      break;
    case 3:
      mainMenuPage(userInfo, ordersVector);
      break;
  }
}

void orderAddedPage(UserInfo &userInfo, vector<Order> &ordersVector) {
  cout << "\nOrder added! Press 1 to order again, 2 to view orders, 3 to return to main menu";
  cout << "\nYour choice: ";

  int choice = getUserChoice(3);

  switch(choice) {
    case 1:
      orderFoodPage(userInfo, ordersVector);
      break;
    case 2:
      //TODO: add view orders page
      break;
    case 3:
      mainMenuPage(userInfo, ordersVector);
      break;
  }
} 

void viewAddressPage(UserInfo &userInfo, vector<Order> &ordersVector) {
  cout << "\n=====Address=====";
  cout << "\nYour address is " << userInfo.address;
  cout << "\n1. Edit address" << "";
  cout << "\n2. Return to main menu" << "";
  cout << "\nYour choice: ";

  int choice = getUserChoice(2);

  switch(choice) {
    case 1:
      editAddressPage(userInfo, ordersVector);
      break;
    case 2:
      mainMenuPage(userInfo, ordersVector);
      break;
  }
}

void editAddressPage(UserInfo &userInfo, vector<Order> &ordersVector) {
  string new_address;
  cout << "\n=====Edit address=====";
  cout << "\nEnter your new address: ";
  cin >> new_address;
  userInfo.address = new_address;
  cout << "Address updated";
  viewAddressPage(userInfo, ordersVector);
}

void mainMenuPage(UserInfo &userInfo, vector<Order> &ordersVector) {
  cout << "\n=====Main menu=====";
  cout << "\nHi, " << userInfo.name << "! What would you like to do today?";
  cout << "\n1. Order food";
  cout << "\n2. Check order history";
  cout << "\n3. Change delivery address";
  cout << "\n4. Exit";
  cout << "\nYour choice: ";

  int choice = getUserChoice(4);
  
  switch(choice) {
    case 1:
      orderFoodPage(userInfo, ordersVector);
      break;
    case 2:
      break;
    case 3:
      viewAddressPage(userInfo, ordersVector);
      break;
    case 4:
      cout << "\nThanks for using our app!";
      break;
  }
}




