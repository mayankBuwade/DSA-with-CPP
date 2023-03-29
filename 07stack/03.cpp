//balancing of symbols
// "{}{}{}" --> true
// "{}{}{" --> false
// "{()}" --> true
// "{{()}}" --> true
//
#include<iostream>
#include<stack>

using namespace std;

bool isBalanced(string str)
{
    stack<char> s;
    for(int i = 0; i<str.size(); i++)
    {
        if( str[i] == '(' || str[i] == '{' || str[i] == '[' )
        {
            s.push(str[i]);
        }
        else
        {
            char top = s.top();
            if(top == '(')
            {
                if(str[i] != ')') return false;
            }
            else if(top == '{')
            {
                if(str[i] != '}') return false;
            }
            else if(top == '[')
            {
                if(str[i] != ']') return false;
            }
            s.pop();
        }
    }
    if(s.empty()) return true;
    return false;
}

int main()
{
    system("cls");
    cout<<isBalanced("{[][](){{}}");
    return 0;
}