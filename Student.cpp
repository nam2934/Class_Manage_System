#include "Student.hpp"

Student::Student() : id(0), name(""), end(0), limit(0), check(0)
{
}

Student::Student(string name, string id, int limit)
{
    this->name = name;
    this->id = id;
    this->limit = limit;
    this->end = 0;
    this->check = 0;
    list = new Cls *[limit];
}

void Student::Register(Cls *cls)
{
    bool flag = true;
    bool flag2 = true;
    for (int i = 0; i < cls->get_end(); i++)
    {
        if (cls->get_list(i) == this)
        {
            flag = false;
        }
    }
    for (int i = 0; i < this->end; i++)
    {
        if (this->list[i] == cls)
        {
            flag2 = false;
        }
    }
    if(this-> fullsize()){
        cout << "[Failed] " << this->name << " can't take more class" << endl;
        return;
    }
    
    if(!flag && !flag2){
        cout << "[Failed] " << this->name << " has already registered " << cls->get_name() << endl;
        return;
    }

    if(cls->fullsize()){
        if(flag == false){
            this->list[this->end] = cls;
            this->end++;
        }
        if(flag == true){
            cls->Register(this);
        }
        return;
    }

    if(flag == false){
        this->list[this->end] = cls;
        this->end++;
        return;
    }
    this->list[this->end] = cls;
    this->end++;
    cls->Register(this);
}
/* else
{
    for (int i = 0; i < this->end; i++)
    {
        if (this->list[i] == cls)
        {
            cout << "[Failed] " << this->get_name() << " has already registered " << cls->get_name() << endl;
            flag = false;
        }
    }
    if (flag == true)
    {
        this->list[this->end] = cls;
        this->end++;
    }
    for (int i = 0; i < cls->get_end(); i++)
    {
        if (cls->get_list(i)->get_name() == this->name)
        {
            flag2 = false;
        }
    }
    if (flag2 == false)
    {
    }
    else
        cls->Register(this);
} */

int Student::check_already(){
    return check;
}
int Student::get_end()
{
    return end;
}

Cls *Student::get_list(int i)
{
    return list[i];
}

void Student::Withdraw(Cls *cls)
{
    int index;
    int flag = true;
    int flag2 = true;
    int flag3 = true;
    for (int i = 0; i < this->end; i++)
    {
        if (list[i] == cls)
        {
            index = i;
            flag = true;
            break;
        }
        else
            flag = false;
    }
    for (int i = 0; i < cls->get_end(); i++)
    {
        if (cls->get_list(i)->get_name() == this->name)
        {
            flag2 = false;
        }
    }
    for(int i=0 ;i< this->end; i++){
        if(this->list[i] == cls){
            flag3 = false;
        }
    }
    if (flag2 && flag3)
    {
        cout << "[Failed] " << this->name << " didn't registered " << cls->get_name() << endl;
    }
    else if(flag2 || flag3){
        for (int i = index; i < end; i++)
        {
            this->list[i] = this->list[i + 1];
        }
        list[this->end - 1] = NULL;
        this->end--;
    }
    else if(flag2 == false && flag3 ==false)
    {
        for (int i = index; i < end; i++)
        {
            this->list[i] = this->list[i + 1];
        }
        list[this->end - 1] = NULL;
        this->end--;
        cls->Withdraw(this);
    }
}

bool Student::fullsize()
{
    return (this->end == this->limit);
}

int Student::get_limit()
{
    return limit;
}
string Student::get_name()
{
    return name;
}

string Student::get_id()
{
    return id;
}

void Student::Display()
{
    cout << "-----------------------------------------------" << endl;
    cout << "Name : " << this->name << "\t"
         << "Student# : " << this->id << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Total number of lectures : " << this->end << endl
         << endl;
    for (int i = 0; i < end; i++)
    {
        cout << list[i]->get_name()
             << "\t" << list[i]->get_instructor()
             << endl;
    }
    cout << endl
         << endl;
}
