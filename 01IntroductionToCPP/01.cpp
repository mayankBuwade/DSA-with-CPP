//
#include<iostream>

using namespace std;

class Parent {
    protected:
        string fatherName;
        string motherName;
};

class Student: public Parent {
    private:
        int age;
    public:
        Student()
        {
            cout<<"Object is created"<<endl;
        }
        Student(int val)
        {
            age = val;   
        }
        int getAge()
        {
            return age;
        }
        void setAge(int userInput)
        {
            age = userInput;
        }
        string getFatherName()
        {
            return fatherName;
        }
        void setFatherName(string name)
        {
            fatherName = name;
        }
        
};

int main()
{
    system("cls");
    Student s1(5), s2, s3, s4;
    s2 = s1;
    cout<<s1.getAge()<<endl;
    cout<<s2.getAge()<<endl;

    return 0;
}