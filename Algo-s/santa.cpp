#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <random>
#include <chrono>
using namespace std;

/*void shuffle(vector<string> names){
    string temp = "";
    int randomIndex = 0;
    
    for(int i = 0; i < names.size(); i++)
    {
        randomIndex = rand() % names.size();
        temp = names[i];
        names[i] = names[randomIndex];
        names[randomIndex] = temp;
    }
    
}*/


int main(){
 
    ifstream file("names.txt");
    string name;
    printf("%s \n", "Please enter your name:");

    string player;

    vector<string> v;
    
    while (getline(file, name))
    {
        v.push_back(name);
    }

    for(int i = 0; i < 15; ++i)
    {
        cin >> player;
        if(player != v[i])
        {
            /*random_device random_device;
            mt19937 engine {random_device()};
            uniform_int_distribution<int> dist(0, v.size() - 1);
            string random_element = v[dist(engine)];
            //shuffle(v); 
            cout << random_element << endl;
            v.erase(v[random_element], v[random_element] + 1);*/
            srand ( time(NULL) ); 
            int RandIndex = rand() % v.size(); 
            cout << "Here's your name for *Secret Santa* " << v[RandIndex] << endl;
            v.erase(v.begin() + RandIndex, v.begin() + RandIndex + 1);
            cout << endl << endl << endl << endl<< endl << endl; 
            printf("%s \n", "Please enter your name:");
            
        }
    }



    return 0;
}