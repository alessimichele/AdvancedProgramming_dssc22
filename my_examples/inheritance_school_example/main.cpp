/*
Suppose you are developing a program to simulate a university's course enrollment system. You have 2 types of students: undergraduate, graduate. Each type of student has certain common characteristics, but also some unique characteristics.

Create a base class called Student that has the following member variables and functions:

name (string): The name of the student.
id (int): The student ID number.
major (string): The student's major.
getGPA() (virtual function): A function that returns the student's GPA (grade point average). This function will be implemented differently in each derived class.
The Student class should have a constructor that initializes these member variables.

Create three derived classes from the Student class: Undergraduate, Graduate, and PartTime. Each derived class should have additional member variables and functions specific to that type of student.

For example, the Undergraduate class might have a member variable called year (int) that indicates the student's year in school (e.g., freshman, sophomore, etc.). 
The Graduate class might have a member variable called researchArea (string) that indicates the student's research area. 


Create an array of Student objects that includes objects of each of the three derived classes. Write a program that loops through the array and calls the getGPA() function for each object. Use polymorphism to achieve this behavior.

For example, if the first object in the array is an Undergraduate, the program should call the getGPA() function for that object, which will calculate and return the student's GPA based on their specific undergraduate GPA calculation method. If the second object in the array is a Graduate, the program should call the getGPA() function for that object, which will calculate and return the student's GPA based on their specific graduate GPA calculation method.

*/

#include "include/Undergraduated.hpp"
#include "include/Graduated.hpp"
#include "include/Student.hpp"
#include "include/another_constructor.hpp"


int main(){
    Undergraduated u1("Alice", 1001, "Computer Science", 3);
    Graduated g1("Charlie", 2001, "Computer Science", "Machine Learning");
    std::cout<<u1.year<<std::endl;
    g1.getInfo();
    SomeOther s("Tizio", 343, "SiSi", "Ciao");
    s.getInfo();
}


