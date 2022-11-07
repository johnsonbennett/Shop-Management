#include <iostream>
#include <vector>
using namespace std;
;
double point_setup();
auto reward_setup();
double reward_redeem(double total,vector <int> point, vector <double> gift ,int point_rate);

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
    vector <int> limit_thresh; //Created a vector so that if by any chance the manager wants to enter more than 1 reward limit
    //it is stored in a a vector. Primarily used vector because we don't need to worry about the size
    vector <double> gift_limit;
    while(thres_prompt == 'Y')
        cout << "Set no of points required for rewards: ";
        cin >> point_thresh;
        limit_thresh.push_back(point_thresh);
        cout << "Set the rewards amount: $";
        cin >> gift;
        gift_limit.push_back(gift);
        cout << "Do you want to add another limit(Y/N):";
        cin >> thres_prompt;
    
    struct retValue{
        vector <int> lt;
        vector <double> gt;

    };
    return retValue {limit_thresh, gift_limit};

}

//This function does the actual computation of the rewards

double reward_redeem(double total , vector <int> point , vector <double> gift,int point_rate)
{
    int points = total / point_rate; //This gives us the no of points accumilated from the given total
    for (auto i = point.begin(); i != point.end();i++ )
    {
        if(point.at(0) <= points <= point.at(*(i+1)) )
        {
            auto reward = gift.at(0); 
        }
    }
}





