//
#include<iostream>

using namespace std;

class Student {
    private:
     int age;
     static int totalObject;
    public:
        Student()
        {
            ++totalObject;
        };
        Student(int);
        int getAge();
        void setAge(int);
        static int getTotalObject();
};

int Student::totalObject = 0;

Student::Student(int age)
{
    ++totalObject;
    this->age = age;
}
int Student::getAge()
{
    return age;
}

void Student::setAge(int age)
{
    this->age = age;
}

int Student::getTotalObject()
{
    return totalObject;
}


int main()
{
    system("cls");
    Student s1, s2, s3, s4;
    cout<<Student::getTotalObject();
    return 0;
}


