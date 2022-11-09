//Written by Bennett Johnson. This file introduces functions for rewards and shopping

#include <iostream>
#include <map>
//#include "LinkedList.cpp"
#include <fstream>
using namespace std;

double point_setup();
void reward_setup();
map <int, double> reward_map;
double reward_redeem(double total, int point_rate, map <int , double>reward_map);
void shopping();

void shopping(){
    string product_id;
    string end_prompt = "N";
    string product;
    double total;
    map <string,string>product_list;
    fstream product_file;
    product_file.open("Product.txt");
    while(!product_file.eof()){
        getline(product_file,product);
        cout << product << endl;
        list = product.split(" ");
        product_list.insert(pair <string,string> (list[0],list[2]));

    }
    while(end_prompt == "N"){
        cout << "Enter product ID you want to purchase: ";
        cin >> product_id;
        if()
        cout << "Checkout (Y/N):";
        cin >> end_prompt;
    }
}

double point_setup() //This function asks the manager to set amount for a point
{
    double point_amount;
    cout << "Set amount to earn 1 point($? for 1 point): ";
    cin >> point_amount;
    
    while(point_amount < 0)
    {
        cout << "Amount cannot be less than $0\nTry again: ";
        cin >> point_amount;
    }

    return point_amount;
}

void reward_setup()  //Sets up how the reward should be done
{
    int point_thresh;
    char thres_prompt = 'Y';
    double gift;
    bool duplicate = false;
    
    while(thres_prompt == 'Y' || duplicate == true) 
    {
        cout << "Set no of points required for rewards: ";
        cin >> point_thresh;
        
        while(point_thresh < 0)
        {
            cout << "Amount cannot be less than $0\nTry again: ";
            cin >> point_thresh;
        }
        
        cout << "Set the rewards amount: $";
        cin >> gift;
        
        while(gift < 0.00)
        {
            cout << "Gift cannot be less than $0\nTry again: ";
            cin >> gift;
        }
        if(reward_map.find(point_thresh) == reward_map.end()){
            reward_map.insert(pair<int,double>(point_thresh,gift));
        }
        else{
            cout << "Duplicate entry found\nTry again:";
            duplicate = true;
        }
        cout << "Do you want to add another limit(Y/N):";
        cin >> thres_prompt;
    }
}

//This function does the actual computation of the rewards

double reward_redeem(double total,int point_rate, map <int , double>reward_map) //Does the actual reward computation
{
    double reward;
    int points = total / point_rate; //This gives us the no of points accumilated from the given total
    cout << points << '\n';
    for (auto i = reward_map.begin(); i != reward_map.end();i++)
    {
        if(points < (*i).first){
            if(i == reward_map.begin()){
                reward = 0;
            }
            else
                reward = (*i--).second; 
        }
        else{
            //Does nothing
        }
    }
    return reward;
}
int main(){
    double total = 500.00;
    double rate = point_setup();
    reward_setup();
    shopping();
    double reward = reward_redeem(total,rate,reward_map);
    cout << "Total reward gift: $"<<reward << '\n';

    return 0;
}





