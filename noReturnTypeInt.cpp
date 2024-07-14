#include<bits/stdc++.h>
using namespace std;

func(){return 100;}
fun(){
    return 'a';
}
int fun2(){
    cout << "hello world" << endl;
} //some garbage has been returned but it is not giving any error.

int main(){
    cout << func() << endl;
    cout << fun() << endl;
    cout << fun2() << endl;
    return 1;
}