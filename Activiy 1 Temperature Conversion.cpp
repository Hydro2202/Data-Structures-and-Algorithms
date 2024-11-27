#include <iostream>

using namespace std;

int main() {
   float temp;
   char chs;



   cout << "Choose temperature: [F] [C] ";
   cin >> chs;
   cout << "Enter temperature: ";
   cin >> temp;



   switch(chs){

    case 'F':
    cout<< "Celsius to Fahrenheit: "<< (temp *  9/5)  + 32;
    break;

    case 'C':
    cout<<"Fahrenheit to Celsius: "<< (temp   - 32) * 5/9 ;
    break;
	
	

   }



   return 0;
   
   




}
