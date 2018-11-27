#include <iostream>
#include <string>
#include "Student.hpp"
#include "Cls.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    // Classes
    Cls* OOP = new Cls("OOP", "Kim", 4);
    Cls* DS = new Cls("DS", "Yang", 2);
    Cls* AI = new Cls("AI", "Hwang", 5);
    
    // Students
    Student* A = new Student("A", "2018111111", 2);
    Student* B = new Student("B", "2018111112", 2);
    Student* C = new Student("C", "2018111113", 2);
    Student* D = new Student("D", "2018111114", 2);
    Student* E = new Student("E", "2018111115", 2);

  
    // OOP Registration
    OOP->Register(A); // A
    OOP->Register(B); // A B
    OOP->Register(C); // A B C
    OOP->Register(D); // A B C D
    OOP->Withdraw(C); // A B D
    OOP->Register(E); // A B D E
    // OOP -> A, B, D, E
 
    //DS Registration
    A->Register(DS); // A
    B->Register(DS); // A B
    DS->Register(E); // print error msg (class is full)
    E->Register(DS); // print error msg (class is full)
    B->Withdraw(DS); // A
    C->Register(DS); // A C
    // DS -> A, C
    
    
    // AI Registration
    A->Register(AI); // print error msg (can't take more class)
    AI->Register(A); // print error msg (can't take more class)
    AI->Register(C); // C
    C->Register(AI); // print error msg (can't take more class, by student side)
    AI->Register(C); // print error msg (already registered, by class side)
    AI->Register(D); // D
    E->Register(AI); // E
    A->Withdraw(AI); // print error msg (didn't registered)
    // AI -> C, D, E

    
    // Display Status of each
    A->Display();
    B->Display();
    C->Display();
    D->Display();
    E->Display();
    
    OOP->Display();
    DS->Display();
    AI->Display(); 
    //done
    return 0;
}

/*
 
######################   Sample I/O   ######################
 
 
 [Failed] DS has already been full!
 [Failed] DS has already been full!
 [Failed] A can't take more class
 [Failed] A can't take more class
 [Failed] C can't take more class
 [Failed] C has already registered AI
 [Failed] A didn't register AI!
 -----------------------------------------------
 Name : A    Student# : 2018111111
 -----------------------------------------------
 Total number of lectures : 2
 
 OOP    Kim
 DS    Yang
 
 
 -----------------------------------------------
 Name : B    Student# : 2018111112
 -----------------------------------------------
 Total number of lectures : 1
 
 OOP    Kim
 
 
 -----------------------------------------------
 Name : C    Student# : 2018111113
 -----------------------------------------------
 Total number of lectures : 2
 
 DS    Yang
 AI    Hwang
 
 
 -----------------------------------------------
 Name : D    Student# : 2018111114
 -----------------------------------------------
 Total number of lectures : 2
 
 OOP    Kim
 AI    Hwang
 
 
 -----------------------------------------------
 Name : E    Student# : 2018111115
 -----------------------------------------------
 Total number of lectures : 2
 
 OOP    Kim
 AI    Hwang
 
 
 -----------------------------------------------
 Porf. : Kim    Class Name : OOP
 -----------------------------------------------
 Total number of students : 4
 
 A    2018111111
 B    2018111112
 D    2018111114
 E    2018111115
 
 
 -----------------------------------------------
 Porf. : Yang    Class Name : DS
 -----------------------------------------------
 Total number of students : 2
 
 A    2018111111
 C    2018111113
 
 
 -----------------------------------------------
 Porf. : Hwang    Class Name : AI
 -----------------------------------------------
 Total number of students : 3
 
 C    2018111113
 D    2018111114
 E    2018111115
 
 
 
*/


/* error message example
 
 cout << "[Failed] " << this->name << " can't take more class" << endl;
 cout << "[Failed] " << this->name << " has already registered " << cls->getName() << endl;
 cout << "[Failed] " << this->name << " has already been full!" << endl;
 cout << "[Failed] " << student->getName() <<"didn't registered " << this->name << endl;
 
*/
