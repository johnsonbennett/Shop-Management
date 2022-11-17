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
struct retvalue reward_redeem(int point_rate, map <int , double>reward_map,string customer_id);
map <string,double> product_ready();
double shopping(map <string,double>product_list);
double read_files(string file_name,string key_word);
int id_generator(string filename,string key);

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

void item_delete(string filename, string id,string key)
{
    fstream file(filename);
    fstream outfile("temp.txt", ios::in | ios::out | ios::app);
    string lines;
    while(!file.eof()){
        getline(file,lines);
        if(lines.find(id) != std::string::npos){
            getline(file,lines);
            while(lines.find(key) == std::string::npos && !file.eof()){
                getline(file,lines);
            }
        }
        else{
            outfile<< lines <<endl;
        }
    }

    outfile.close();
    file.close();

    char new_name[] = "customer.txt";
    char old_name[] = "temp.txt";
    int result = rename(old_name,new_name);
}



double read_files(string filename, string key_word_1,string key_word_2,bool action,int points){
    fstream file;
    file.open(filename);
    string lines;
    double t =0;
    const char delimiter = ':';
    string line;
    string val;
    while(!file.eof()){
        getline(file,lines);
        if(lines.find(key_word_1) != std::string::npos){
            getline(file,lines);
            while(lines.find(key_word_2) == std::string::npos && !file.eof())
            {
                getline(file,lines);
                if(lines.find(key_word_2) != std::string::npos){
                    vector <string> line;
                    string val;
                    stringstream ss(lines);
                    if(!action) {
                        while(getline(ss,val,delimiter)){
                            line.push_back(val);
                        }
                        t += stod(line[1]);
                    }
                    else{
                        item_delete("customer.txt",key_word_1,key_word_2);
                        file << "total reward points: " << points <<"\n\n";
                    }                
                }
                else{}
            }
        }
        else{}
    }
        
    return t;
}

int id_generator(string filename,string key)
{
    fstream file(filename);
    string line;
    int counter = 0;
    while(!file.eof()){
        getline(file,line);
        if(line.find(key) != std::string::npos)
            counter++;
        else{}
    }
    return counter;
}

double shopping(map<string,double>product_list,string customer_id){
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
        int trans_id = id_generator("transaction.txt", "Transaction ID");
        trans_id++;
        fstream transaction;
        transaction.open("transaction.txt",ios::app);
        transaction <<"Transaction ID: " << trans_id <<"\n";
        transaction<< "User ID: " << customer_id <<"\n";
        transaction << "Products: ";
        size_t size = product.size();
        for (int i =0; i < size; i++)
            transaction << product[i]<<" ";
        transaction << "\nTotal: " <<total;
        transaction <<"\n\n";
        transaction.close();
    }
    else{}
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

struct retvalue reward_redeem(int point_rate, map <int , double>reward_map,string customer_id) //Does the actual reward computation
{
    double reward = 0;
    double total = read_files("transaction.txt",customer_id, "Total",false,0);
    cout << total<<endl;

    int points = (total / point_rate); //This gives us the no of points accumilated from the given total
    cout << "POINTS = " << points << endl;
    read_files("customer.txt",customer_id,"total reward points", true,points);
    for (auto elem : reward_map) {
        if (points >= elem.first) {
            reward = elem.second;
        }
    }
    
    return retvalue{points,reward};
}



