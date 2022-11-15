#include <iostream>
using namespace std;

int main()
{
  int i = 0;
  while (i >= 0 && i < 8)
  {
    cout << "----------------MENU--------------" << endl;
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
      // Customer Registration code
      break;

    case 2:
      // Customer Removal code
      break;

    case 3:
      // product managemetn
      break;

    case 4:
      // Product Removal code
      break;

    case 5:
      // Shopping code
      break;

    case 6:
      // view customer using customer ID code
      break;

    case 7:
      // Redeem Rewards code
      break;
    default:
      cout << "Exiting the application...." << endl;
      exit(0);
      break;
    }
  }

  return 0;
}
