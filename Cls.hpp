#ifndef Class_hpp
#define Class_hpp

#include "Student.hpp"
#include <iostream>
#include <string>

using namespace std;

class Student;

class Cls{
public:
    Cls();
    Cls(string name, string instructor, int limit);
    void Register(Student* student);
    bool fullsize();
    void Withdraw(Student* student);
    void Display();
    Student* get_list(int i);
    int get_end();
    int get_limit();
    string get_name();
    string get_instructor();
    int check_already();
    
private:
    string name;
    string instructor;
    Student** list;
    int end;
    int limit;
    int check;
};

#endif
