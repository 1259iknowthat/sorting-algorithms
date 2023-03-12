#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <random>
#include <chrono>

using namespace std;

//sorted ascending
void gen_sorted_array(FILE *f){
    vector<int> sorted_elements;
    //add 1m elements to vector then shuffle using unique seed
    for(int i = 0; i < 10e5; i++)       
        sorted_elements.push_back(i);
    //generate unique seed every time call the function
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    //shuffle the vector to get random elements
    std::shuffle(sorted_elements.begin(), sorted_elements.end(), std::default_random_engine(seed));
    sort(sorted_elements.begin(), sorted_elements.end());
    for (int i: sorted_elements){
        fprintf(f, "%d ", i);
    }
    fputc('\n',f);
}
//sorted descending
void gen_des_sorted_array(FILE *f){
    vector<int> sorted_elements;
    for(int i = 0; i < 10e5; i++)       
        sorted_elements.push_back(i);
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(sorted_elements.begin(), sorted_elements.end(), std::default_random_engine(seed));
    sort(sorted_elements.begin(), sorted_elements.end(), greater<int>());
    for (int i: sorted_elements){
        fprintf(f, "%d ", i);
    }
    fputc('\n',f);
}
//random elements
void gen_random_array(FILE *f){
    vector<int> random_elements;
    for(int i = 0; i < 10e5; i++)       
        random_elements.push_back(i);
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(random_elements.begin(), random_elements.end(), std::default_random_engine(seed));
    for (int i: random_elements){
        fprintf(f, "%d ", i);
    }
    fputc('\n',f);
}

int main(){
    FILE *f;
    f = fopen("input-data.txt", "w");
    gen_sorted_array(f);
    gen_des_sorted_array(f);
    for (int i = 0; i < 8; i++)
        gen_random_array(f);
    fclose(f);
}