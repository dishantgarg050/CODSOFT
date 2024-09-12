#include <iostream>
using namespace std;
int main()
{
         double a,b;
         cin>>a>>b;
         char op;
         cin>>op;
        
         
       if(op=='+')
       {
        cout<<a<<'+'<<b<<'='<<a+b<<endl;
         }

         else if(op=='*')
         {
         cout<<a<<'*'<<b<<'='<<a*b<<endl;
         }
         
        else if(op=='/')
        {
                if(b==0){
                        cout<<"cannot divided by zero"<<endl;
                        
                }
                else{
          cout<<a<<'/'<<b<<'='<<a/b<<endl;
          }
          
        }

        else if(op=='-')
        {
           cout<<a<<'-'<<b<<'='<<a-b<<endl;
           
        }

        else
        {
                cout<<"invalid operator"<<endl;
        }
        return 0;
}