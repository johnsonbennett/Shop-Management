#include <iostream>
#include <map>
using namespace std;
;
double point_setup();
auto reward_setup();
map <int, double> reward_map;
double reward_redeem(double total, int points,map <int , double>reward_map);
double point_rate = point_setup();
double point_setup()
{
    double point_amount;
    
    cout << "Set amount to earn 1 point($? for 1 point): ";
    cin >> point_amount;

    return point_amount;
}

auto reward_setup()
{

    int point_thresh;
    char thres_prompt = 'Y';
    double gift;
    
    while(thres_prompt == 'Y')
        cout << "Set no of points required for rewards: ";
        cin >> point_thresh;
        cout << "Set the rewards amount: $";
        cin >> gift;
        reward_map.insert(pair<int,double>(point_thresh,gift));
        cout << "Do you want to add another limit(Y/N):";
        cin >> thres_prompt;
    

}

//This function does the actual computation of the rewards

double reward_redeem(double total,int point_rate, map <int , double>reward_map)
{
    int points = total / point_rate; //This gives us the no of points accumilated from the given total
    for (auto i = reward_map.begin(); i != reward_map.end();i++)
    {
        if((*i).first > (*i++).first){
            
        }
    }
}





