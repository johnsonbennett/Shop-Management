//This file introduces functions for rewards and shopping

#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

double point_setup();
void reward_setup();
map <int, double> reward_map;
double reward_redeem(double total, int point_rate, map <int , double>reward_map);
double shopping();

double shopping(){
    string product_id;
    string end_prompt = "N";
    string product;
    string token;
    double total = 0;
    const char  delimiter = ' ';
    map <string,double>product_list;
    
    fstream product_file;
    product_file.open("Product.txt");
    fstream transaction;
    transaction.open("transaction.txt",ios::app);
    while(!product_file.eof()){
        getline(product_file,product);
        cout << product<<endl;
        stringstream ss;
        ss << product;
        vector <string>list;
        while(getline(ss,token,delimiter)) {
            list.push_back(token);
        }
        if (list.empty() || list.size() < 3) continue;
        product_list.insert(pair<string, double> (list[0],stod(list[2])));
    }
    product_file.close();
    while(end_prompt == "N"){
        cout << "Enter product ID you want to purchase: ";
        cin >> product_id;
        if(product_list.find(product_id) == product_list.end()){
            cout << "ID not found!\n";
        }
        else{
            transaction << "Product: "<<product_id <<"\n";
            double value = product_list.at(product_id);
            total += value;
        }
        cout << "Total: $"<<total<<endl;
        cout << "Checkout (Y/N):";
        cin >> end_prompt;
    }
    transaction <<"Total: $" <<to_string(total)<<"\n\n";
    transaction.close();
    return total;
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
    double reward = 0;
    int points = total / point_rate; //This gives us the no of points accumilated from the given total
    for (auto elem : reward_map) {
        // cout << elem.first << ", " << elem.second << std::endl;
        if (points >= elem.first) {
            reward = elem.second;
        }
    }

    return reward;
}
int main(){
    double total = shopping();
    double rate = point_setup();
    reward_setup();
    double reward = reward_redeem(total,rate,reward_map);
    cout << "Your total: $"<<total <<endl;
    cout << "Total reward gift: $"<<reward << '\n';

    return 0;
}
