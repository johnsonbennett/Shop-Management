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
map <string, double>product_list;
struct retvalue reward_redeem(int point_rate, map <int , double>reward_map);
map <string,double> product_ready();
double shopping(map <string,double>product_list);
double read_files(string file_name,string key_word);

struct retvalue{
        int point;
        double rewards; 
    };


map <string, double> product_ready(){ //This function takes products from the file and put it to a map
    string product;
    string token;
    const char  delimiter = ' ';
    fstream product_file;
    product_file.open("Product.txt");
    while(!product_file.eof()){
        getline(product_file,product);
        cout << product<<"\n";
        stringstream ss;
        ss << product;        //Converted product into a string buffer since getline only works on buffers
        vector <string>list;
        while(getline(ss,token,delimiter)) {
            list.push_back(token);
        }
        if (list.empty() || list.size() < 3) continue;
        product_list.insert(pair<string, double> (list[0],stod(list[2])));
    }
    product_file.close();
    return product_list;
}

double read_files(string filename, string key_word){        //This function is used to read line by line looking for a key word
    fstream file;
    file.open(filename);
    string lines;
    double t =0;
    const char delimiter = ':';
    while(!file.eof()){
        getline(file,lines);
        if(lines.find(key_word) != std::string::npos){  //find returns -1 if not found, used it to avoid -1
            vector <string> line;
            string val;
            stringstream ss(lines);
            while(getline(ss,val,delimiter)){
                line.push_back(val);
            }
            t += stod(line[1]);
        }
        else{
            //Do nothing
        }   
    }
    return t;
}

double shopping(map<string,double>product_list,int trans_id){
    string end_prompt = "N";
    string product_id;
    vector <string>product;
    double total = 0;
    while(end_prompt == "N"){
        cout << "Enter product ID you want to purchase: ";
        cin >> product_id;
        if(product_list.find(product_id) == product_list.end()){
            cout << "ID not found!\n";
        }
        else{
            product.push_back(product_id);
            double value = product_list.at(product_id);
            total += value;
        }
        cout << "Total: $"<<total<<endl;
        cout << "Checkout (Y/N):";
        cin >> end_prompt;
    }
    if(total > 0){
        trans_id++;
        fstream transaction;
        transaction.open("transaction.txt",ios::app);
        transaction <<"Transaction ID: " << trans_id <<"\n";
        transaction << "Products: ";
        size_t size = product.size();
        for (int i =0; i < size; i++)
            transaction << product[i]<<" ";
        transaction << "\nTotal: " <<total;
        transaction <<"\n\n";
        transaction.close();
    }
    else{
        //Do nothing
    }
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

struct retvalue reward_redeem(int point_rate, map <int , double>reward_map) //Does the actual reward computation
{
    double reward = 0;
    double total = read_files("transaction.txt","Total");
    int points = total / point_rate; //This gives us the no of points accumilated from the given total
    for (auto elem : reward_map) {
        if (points >= elem.first) {
            reward = elem.second;
        }
    }
    
    return retvalue{points,reward};
}
   
        
        
