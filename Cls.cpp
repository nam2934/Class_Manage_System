#include "Cls.hpp"

Cls::Cls() : name(""), instructor(""), end(0), limit(0), check(0)
{
}

Cls::Cls(string name, string instructor, int limit)
{
    this->name = name;
    this->instructor = instructor;
    this->limit = limit;
    this->end = 0;
    this->check = 0;
    list = new Student *[limit];
}

void Cls::Register(Student *student)
{
    bool flag = true;
    bool flag2 = true;
    for (int i = 0; i < student->get_end(); i++)
    {
        if (student->get_list(i) == this)
        {
            flag = false;
        }
    }
    for (int i = 0; i < this->end; i++)
    {
        if (this->list[i] == student)
        {
            flag2 = false;
        }
    }
    if(this-> fullsize()){
        cout << "[Failed] " << this->name << " has already been full!" << endl;
        return;
    }
    
    if(!flag && !flag2){
        cout << "[Failed] " << student->get_name() << " has already registered " << name << endl;
        return;
    }
    
    if(student->fullsize()){
        if(flag == false){
            this->list[this->end] = student;
            this->end++;
        }
        if(flag == true){
            student->Register(this);
        }
        return;
    }

    if(flag == false){
        this->list[this->end] = student;
        this->end++;
        return;
    }
    student->Register(this);
}
Student *Cls::get_list(int i)
{
    return list[i];
}
int Cls::check_already(){
    return check;
}
bool Cls::fullsize()
{
    return (this->end == this->limit);
}

void Cls::Withdraw(Student *student)
{
    int index;
    int flag = true;
    int flag2 = true;
    int flag3 = true;
    for (int i = 0; i < end; i++)
    {
        if (list[i] == student)
        {
            index = i;
            flag = true;
            break;
        }
        else
            flag = false;
    }
    for (int i = 0; i < student->get_end(); i++)
    {
        if (student->get_list(i)->get_name() == this->name)
        {
            flag2 = false;
            break;
        }
    }
    for (int i = 0; i < this->end; i++)
    {
        if (this->list[i] == student)
        {
            flag3 = false;
            break;
        }
    }
    if (flag2 && flag3)
    {
        cout << "[Failed] " << student->get_name() << " didn't registered " << this->name << endl;
    }
    else if (flag2 || flag3)
    {
        for (int i = index; i < end; i++)
        {
            this->list[i] = this->list[i + 1];
        }
        list[this->end - 1] = NULL;
        this->end--;
    }
    else
    {
        for (int i = index; i < end; i++)
        {
            list[i] = list[i + 1];
        }
        list[this->end - 1] = NULL;
        this->end--;
        student->Withdraw(this);
    }
}

int Cls::get_limit()
{
    return limit;
}

string Cls::get_name()
{
    return name;
}

string Cls::get_instructor()
{
    return instructor;
}

int Cls::get_end()
{
    return end;
}

void Cls::Display()
{
    cout << "-----------------------------------------------" << endl;
    cout << "Porf. : " << this->instructor << "\t"
         << "Class Name : " << this->name << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Total number of students : " << this->end << endl
         << endl;
    for (int i = 0; i < end; i++)
    {
        cout << list[i]->get_name()
             << "\t" << list[i]->get_id()
             << endl;
    }
    cout << endl
         << endl;
}