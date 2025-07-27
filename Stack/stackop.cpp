#include<bits/stdc++.h>
using namespace std;

bool isoperator(string x){
    return x == "+" || x == "-" || x == "*" || x == "/" || x == "^";
}

int precedence(string x){
    if (x == "+" || x == "-") return 1;
    if(  x == "*" || x == "/") return 2;
    if( x == "^") return 3;
    else return 0;
}


string infixToPostfix(string infix){
    stringstream ss(infix);
    string postfix,c;
    stack<string> st;

    while(ss>>c){
        if(isalnum(c[0])){
            postfix += c + " ";
        }else if(c == "("){
            st.push(c);
        }else if(c==")"){
            while (!st.empty() && st.top()!= "(")
            {
                postfix += st.top()+ " ";
                st.pop();
            }
            if(!st.empty()) st.pop();   
        }
        else if(isoperator(c)){
            while(!st.empty() && precedence(st.top()) >= precedence(c) && c!="(" ){
                postfix += st.top()+ " ";
                st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        postfix += st.top()+ " ";
        st.pop();
    }
    return postfix;
}

int evaluation(string postfix){
    stack<int> st;
    istringstream ss(postfix);
    string c;
    
    while (ss>>c)
    {
        if(isdigit(c[0])){
            st.push(stoi(c));
        }
        else {
            int val2 = st.top(); st.pop();
            int val1 = st.top(); st.pop();
            if (c == "+") st.push(val1 + val2);
            else if (c == "-") st.push(val1 - val2);
            else if (c == "*") st.push(val1 * val2);
            else if (c == "/") st.push(val1 / val2);
            else if (c == "^") st.push(pow(val1, val2));
        }
    }
    return st.top();
    
}


int main(){
string infix{"2 + ( ( 3 + 4 ) * ( 7 - 5 ) )"};

cout<<"Postfix: "<<infixToPostfix(infix)<<endl;

cout<<"evaluation: "<<evaluation(infixToPostfix(infix))<<endl;
}