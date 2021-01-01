/**
 * @file chapter_09_q2.cpp
 * @author Mehrdad Tamiji (mehrdad.tamiji@gmail.com)
 * @brief Write the following program: Create a struct that holds a student’s first name and grade (on a scale of 0-100). Ask the user how many students they want to enter. Create a std::vector to hold all of the students. Then prompt the user for each name and grade. Once the user has entered all the names and grade pairs, sort the list by grade (highest first). Then print all the names and grades in sorted order.
 * @version 0.1
 * @date 2020-12-26
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#include <iostream>
#include <iterator>
#include <algorithm>
#include <limits>
#include <random>
#include <ctime>
#include <cstdlib>
#include <string>
#include <typeinfo>
#include <array>
#include <vector>
#include <string_view>
#include <numeric> 
#include <sstream>

struct Student_info
{
    std::string name{};
    int grade{0};
};

std::string get_string_from_user(const std::string &msg)
{
    std::string str{};
    std::getline(std::cin, str);
    return str;
}

int get_int_from_user(const std::string &msg)
{
    int num{0};
    while (true)
    {
        std::cin >> num;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
            std::cout << "you should enter a number. " << msg;
        }
        else
        {
            std::cin.ignore(32767, '\n');
            break;
        }
    }
    return num;
}

using std_vec_type = std::vector<Student_info>;

int get_number_std(const std::string &msg)
{
    std::cout << msg;
    int num_std{get_int_from_user(msg)};
    while (true)
    {
        if (num_std > 0)
        {
            break;
        }
        else
        {
            std::cout << "you should insert positive number" << '\n';
            num_std = get_int_from_user(msg);
        }
    }

    return num_std;
}

std::string get_std_name(const std::string &msg)
{
    std::cout << msg;
    return (get_string_from_user(msg));
}

int get_std_grade(const std::string &msg)
{
    std::cout << msg;
    return (get_int_from_user(msg));
}

std_vec_type get_student_info()
{
    const std::string msg_1{"pls insert number of students: "};
    const std::string msg_2{"pls insert name of student "};
    const std::string msg_3{"pls insert grade of student "};
    std::string msg_4{};
    int num_std{get_number_std(msg_1)};
    std_vec_type student_info{};
    student_info.resize(num_std);
    for (int i{0}; auto &element : student_info)
    {
        msg_4 = msg_2 + "#" + std::to_string(i + 1) + ":";
        element.name = get_std_name(msg_4);
        msg_4 = msg_3 + "#" + std::to_string(i + 1) + ":";
        element.grade = get_std_grade(msg_4);
        ++i;
    }

    return student_info;
}

bool is_greater(const Student_info &student_info1, const Student_info &student_info2)
{
    return (student_info1.grade > student_info2.grade);
}

void sort_based_on_grade(std_vec_type &student_info_vec)
{

    std::sort(student_info_vec.begin(), student_info_vec.end(), is_greater);
}

void print_info(const std_vec_type std_info)
{
    for (auto &element : std_info)
    {
        std::cout << element.name << " got a grade of " << element.grade << '\n';
    }
}

int main()
{
    std_vec_type student_info_vec{get_student_info()};
    sort_based_on_grade(student_info_vec);
    print_info(student_info_vec);
    return 0;
}