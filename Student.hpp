#ifndef Student_hpp
#define Student_hpp

#include "Cls.hpp"
#include <string>

class Cls;

using namespace std;

class Student{
public:
    Student();
    Student(string name, string id, int limit);
    void Display();
    void Register(Cls* cls);
    bool fullsize();
    int get_end();
    int get_limit();
    Cls* get_list(int i);
    void Withdraw(Cls* cls);
    string get_name();
    string get_id();
    int check_already();

private:
    string name;
    string id;
    Cls** list;
    int end;
    int limit;
    int check;
};

#endif
