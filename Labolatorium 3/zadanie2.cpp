#include <iostream>
#include <string>
#include <vector>

using std::pair;    //pair <>
using std::string;
using std::stoi;    //string to int
using std::vector;

//podział string na pare int(godziny):int(minuty)
pair<int,int> get_time_from_string(string time_string){
    int partition = time_string.find(":");
    pair<int,int> time_pair {stoi(time_string.substr(0,partition)),stoi(time_string.substr(partition+1,time_string.length()))};
    return time_pair;
}

unsigned int ToMinutes(string time_string) {
    pair<int, int> time_pair = get_time_from_string(time_string);
    unsigned int time_minutes = time_pair.first*60+time_pair.second;
    return time_minutes;
}

unsigned int MinimalTimeDifference(vector<string> times){
    unsigned int minimal_time_differ = 1440; //minimalna wartosc poczatkujaca jest rowna maksymalnej mozliwej roznicy (24h*60min)
    for(string elem1 : times){
        for(string elem2 : times){
            unsigned int time_in_minutes1 = ToMinutes(elem1);
            unsigned int time_in_minutes2 = ToMinutes(elem2);
            if(time_in_minutes1 <= time_in_minutes2){
                continue;
            }
            unsigned int time_differ = time_in_minutes1 - time_in_minutes2;
            if(time_differ < minimal_time_differ){
            minimal_time_differ = time_differ;
            }
        }
    }
    return minimal_time_differ;
}

int main(){
    vector<string> times_vector {"12:30", "13:00", "16:00", "12:55"};
    std::cout << "List of times: " << std::endl;
    for(string elem : times_vector){
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::cout << "List of times in minutes: " << std::endl;
    for(string elem : times_vector){
        std::cout << ToMinutes(elem) << " ";
    }
    std::cout << std::endl;

    std::cout << "Minial time difference: " << MinimalTimeDifference(times_vector) <<" minutes" << std::endl;

    return 0;
}