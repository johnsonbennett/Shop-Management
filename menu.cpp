#include <iostream>
#include "rewards.cpp"
#include "ProductProcessing.cpp"
#include "CustomeRegistrtion.cpp"
using namespace std;

struct node* head = NULL; //A global variable for the head of the linked list

int main()
{
    int i = 0;
    while (i >= 0 && i < 8)
    {
        cout << endl << "----------------MENU--------------" << endl;
        cout << "1. Customer Registration" << endl;
        cout << "2. Customer Removal" << endl;
        cout << "3. Product Addition" << endl;
        cout << "4. Product Removal" << endl;
        cout << "5. Shopping" << endl;
        cout << "6. View customer using customer ID" << endl;
        cout << "7. Redeem Rewards" << endl;
        cout << "8. Exit" << endl;
        cout << "----------------------------------" << endl;
        cout << "Enter your choice : ";
        cin >> i;

        switch (i)
        {
        case 1:
            RandomNumber();
            getName();
            dates();
            cards();
            
            break;

        case 2:
            // Customer Removal code
            break;

        case 3:
            addItem();
            break;

        case 4:
            deleteItem();
            break;

        case 5:
        {
          string customer_id;
          cout << "Enter user ID: ";
          cin >> customer_id;
          if(find_id(customer_id)){
            map <string,double>list = product_ready();
            double total = shopping(list,customer_id);
            cout << "Your total is $" << total  <<endl;
          }
          else{
            cout << "User ID not found\n";
          }
        }
        break;
        case 6:
        {
            string user_id;
            cout << "Enter User ID (CID**********): ";
            cin >> user_id;
            cout <<"\n";
            show_customer(user_id);
            break;
        }

        case 7:
        {
          string customer_id;
          cout << "Enter user ID: ";
          cin >> customer_id;
          if(find_id(customer_id)){
            double rate = point_setup();
            reward_setup();
            auto results =reward_redeem(rate,reward_map,customer_id);
            cout << "You have " << results.point <<" points\n";
            cout << "You redeemed $" << results.rewards<<"\n";
          }
          else{
            cout <<"User ID not found\n";
          break; 
          }
        }
        break;
        default:
            cout << "Exiting the application...." << endl;
            exit(0);
            break;
        }
    }

    return 0;
}
