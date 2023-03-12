#include "sorting_algo.h"
#include <iostream>
#include <chrono>
#include <string>
#include <fstream>
#include <sstream>

#define MAXN 1000000

int time_report(void (sort_func(int *arr, long size)), int *a, long s){
    auto start = std::chrono::high_resolution_clock::now(); 
    sort_func(a, s); 
    auto end = std::chrono::high_resolution_clock::now();
    // Duration in microseconds
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start); 
    return duration.count();
}

int **arr = new int*[10];
int main(){
    FILE *time_rp_file;
    time_rp_file = fopen("time_report.txt", "w");

    std::string line;
    //create a pointer to an array of pointers to int
    std::ifstream myfile("input-data.txt");
    if (myfile.is_open()) {
        int i = 0;
        while (getline(myfile, line)) {
            std::istringstream iss(line);
            int j = 0;
            arr[i] = new int[MAXN]; //allocate memory for the i-th row
            while (iss >> arr[i][j]) {
                j++;
            }
            i++;
        }
        myfile.close();
    }
    fprintf(time_rp_file,"|%s|%s|%s|%s|\n", "------------", "------------", "------------", "------------");
    fprintf(time_rp_file,"| %10s | %10s | %10s | %10s |\n", "Quick", "Heap", "Merge", "C++ lib");
    fprintf(time_rp_file,"|%s|%s|%s|%s|\n", "------------", "------------", "------------", "------------");
    printf("|%s|%s|%s|%s|\n", "------------", "------------", "------------", "------------");
    printf("| %10s | %10s | %10s | %10s |\n", "Quick", "Heap", "Merge", "C++ lib");
    printf("|%s|%s|%s|%s|\n", "------------", "------------", "------------", "------------");
    for (int i = 0; i < 10; i++){
        int quick = time_report((main_quick_sort), arr[i], MAXN);
        int heap = time_report((main_heap_sort), arr[i], MAXN);
        int merge = time_report((main_merge_sort), arr[i], MAXN);
        int cpp_lib = time_report((main_cpp_lib_sort), arr[i], MAXN);
        fprintf(time_rp_file, "| %10d | %10d | %10d | %10d |\n", quick, heap, merge, cpp_lib);
        printf("| %10d | %10d | %10d | %10d |\n", quick, heap, merge, cpp_lib);
    }
    fprintf(time_rp_file,"|%s|%s|%s|%s|\n", "------------", "------------", "------------", "------------");
    printf("|%s|%s|%s|%s|\n", "------------", "------------", "------------", "------------");
    // free the memory
    for (int i = 0; i < 10; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    fclose(time_rp_file);
    return 0;
}

