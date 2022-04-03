#include <iostream>
#include <cmath>

using namespace std;
const int NUM_HOUSES = 8;

void print_houses(int houses[], int cur_pos, int night){
    // Task 3:
    //   print the state of each house in current night.
    //   '*': thief's position, '1, 2, 3, ...': stolen houses, '0': valid houses.
    // example:
    //   Night 1:
    //      | 0 | 0 | * | 0 | 0 | 0 | 0 | 0 |
    cout << "Night " << night << ":  " << endl;
    char tp = '*';
    cout << '|';
    int i = 0;
    while(i < 8)
    {
        if(i == cur_pos)
        {
            cout << "*|";
            ++i;
        }
        else  if (i != cur_pos)
        {
            cout << houses[i] << '|';
            ++i;
        }


    }
    cout << endl;

    
    houses[cur_pos] = night;
   
    

}

int steal_house(int houses[], int cur_pos, int alert_dis, int night){
    // Task 2:
    //   output the next target. When there is no valid house to steal, return -1.
    int target = -1;
    int a = cur_pos + alert_dis;
    if(a < 8)
    {
        if(houses[a] == 0)
        {
            target = a;
        }

        else if ((a+1 < 8) && (houses[a] != 0) && (houses[a+1] == 0))
        {
            target = a+1;
        }
        else
        {
            target = -1;
        }
    }
    else if (a >= 8)
    {
        int b = a - 8;
        if (b <= cur_pos-alert_dis)
        {
            if(houses[b] == 0)
            {
                target = b;
            }
            else if ((houses[b] != 0) && (b+1 <= cur_pos - alert_dis) && (houses[b+1] == 0))
            {
                target = b+1;
            }
            else
            {
                target = -1;
            }
        }
    }
    return target;
}

int main(){ 
    int houses[NUM_HOUSES] = {0};
    int first_target;
    int alert_dis;
    
    cout << endl << "The number of houses in this community is " << NUM_HOUSES << "." << endl;
    // input the first target house ID of the thief (current position) and 
    // the alert distance (min interval) of the security system.
    cout << "Please input the first target house ID of the thief: " << endl;
    cin >> first_target;
    while ((first_target >= NUM_HOUSES) || (first_target < 0)){
        cout << "The target of the thief should less than " << NUM_HOUSES << endl;
        cout << "Please re-input the first target ID: " << endl;
        cin >> first_target;
    }
    houses[first_target] = 1;  // Set first target to 1

    cout << "Please input the alert distance of the community's security system: " << endl;
    cin >> alert_dis;
    while ((alert_dis >= NUM_HOUSES) || (alert_dis < 0)){
        cout << "The alert distance of the community's security system should less than " << NUM_HOUSES << endl;
        cout << "Please re-input the alert distance: " << endl;
        cin >> alert_dis;
    }
    cout << endl;

    int cur_pos = first_target;
    int night = 1;
    print_houses(houses, cur_pos, night);
    while(true){
        // Task 1:
        //   - update 'night'
        night += 1;

        //   - call 'steal_house( )' function to get the thief's next target and update 'cur_pos'
        cur_pos = steal_house(houses,cur_pos,alert_dis,night);
        if(cur_pos == -1)
        //   - When the next target is invalid (steal_house( ) return '-1'), break out the while loop.
        {break;}
        //   - call 'print_houses( )' function to print the states of the houses
        print_houses(houses,cur_pos,night);


    }
    cout << endl << "No house can be stolen." << endl << "Finished." << endl;
}