#include<iostream>
#include<stack>
#include<cctype>
#include<cmath>
using namespace std;

bool isOperator(char c){
   return  c == '+' || c == '-' || c == '*' || c == '/' || c == '^';

   }

   int precendence(char op){
    if (op == '^') return 3;
    else if (op == '*' || op == '/') return 2;
    else if (op == '+' || op == '-') return 1;
    else return 0;
   }

 string infixToPostfix(const string& infix) {
    string postfix;
    stack<char> st;
    for(char c:infix){
        if (isalnum(c))
        {
           postfix += c;
        }else if( c == '('){
            st.push(c);
        }else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
           postfix += st.top();
           st.pop();
            }
             if (!st.empty()) st.pop();
            
        }else if(isOperator(c)) {
         while (!st.empty() && precendence(st.top()) >= precendence(c) && st.top() != '(' )
         {
            postfix += st.top();
            st.pop();
         }
         st.push(c);
         
        }  
    }
    while (!st.empty())
    {   
       postfix += st.top();
       st.pop();
    }

    return postfix;
    
 } 


 double EVALUATION (const string& expression){
    stack<double> st;
    for(char c: expression){
        if(isdigit(c)){
            st.push(c - '0');
        }
        else{
          double val2 = st.top(); st.pop();
          double val1 = st.top(); st.pop();
          switch (c)
          {
          case '+':
              st.push(val1 + val2);
              break;
          case '-':
              st.push(val1 - val2);
              break;
          case '*':
              st.push(val1 * val2);
              break;
          case '/':
              st.push(val1 / val2);
              break;
          case '^':
              st.push(pow(val1, val2));
              break;
          }
        }
    }
    return st.top();
 }
   

int main(){
string infix{"2+((3+4)*(7-5))"};

cout<<"Postfix: "<<infixToPostfix(infix)<<endl;

cout<<"Evaluation: "<<EVALUATION(infixToPostfix(infix))<<endl;

}
