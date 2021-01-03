#ifndef CPP_TOOLS_H
#define CPP_TOOLS_H

#include <string> 
#include <chrono>


int_fast64_t powint(int_fast64_t base, int exp);
bool approximatelyEqualAbsRel(double a, double b);
int get_random_number(int min, int max );
std::string get_string_from_user();
int get_int_from_user();
char get_char_from_user();
std::chrono::high_resolution_clock get_sys_time();
void get_duration_function();

#endif