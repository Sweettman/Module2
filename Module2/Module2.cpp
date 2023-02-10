// Module2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <fstream>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <istream>

using namespace std;
void login();
void registration();

int main()
{
   int number;
   //MAINE MENUE, acci artcy
   cout << "\n ";
   cout << "\n ";
   cout << R"( __          ________ _  _____ ____  __  __ ______ _)""\n";
   cout << R"( \ \        / |  ____| |/ ____/ __ \|  \/  |  ____| |)""\n";
   cout << R"(  \ \  /\  / /| |__  | | |   | |  | | \  / | |__  | |)""\n";
   cout << R"(   \ \/  \/ / |  __| | | |   | |  | | |\/| |  __| | |)""\n";
   cout << R"(    \  /\  /  | |____| | |___| |__| | |  | | |____|_|)""\n";
   cout << R"(     \/  \/   |______|_|\_____\____/|_|  |_|______(_))""\n";
   cout << "\n ";
   cout << "____________________________MENUE____________________________\n ";
   cout << "\n\tPlease pick one one of the following opitons ";
   cout << "\n ";
   cout << "\t| Press 1 to Login                         |" << endl;
   cout << "\t| Press 2 to Create an account             |" << endl;
   cout << "\t| Press 3 to Exit                          |" << endl;
   cin >> number;
   cout << endl;

   //input from user
   switch (number)
   {
   case 1:
      login();
      break;
   case 2:
      registration();
      break;
   case 3:
      cout << "\t\t\t thank you! \n\n";
      break;
   default:
      system("cls");
      cout << "\t\t\t your selections is not valid, please select one of the abotiosn above.\n" << endl;
      main();
   }
}


//Here we will write to our .txt file.
//this will allow us to create a login, that can latter be used by pressing "1" on the maine menue
void registration()
{
   string RuserId, Rpassword, RID, Rpass;
   system("cls");
   cout << "\t\t\t Enter Username : ";
   cin >> RuserId;
   cout << "\t\t\t password ";
   cin >> Rpassword;

   ofstream f1("records.txt", ios::app);      //append credentials
   f1 << RuserId << '  ' << Rpassword << endl;
   system("cls");
   cout << "\t\t\t succesful registration";
   main();
}

void login()
{
   int count{};                                   //count
   string Username, Password, user, code;             //variables
   system("cls");                                 //clear
   cout << "\t\t\t Enter credentials : " << endl; //display
   cout << "\t\t\t Username ";
   cin >> Username;                                 //input
   cout << "\t\t\t Password ";
   cin >> Password;

   ifstream input("records.txt");
   while (input >> user >> code)
   {
      if (user == Username && code == Password) //if the correct credentials were entered

      {
         count = 1;
         system("cls");
      }
   }
   input.close();
   if (count == 1)
   {
      cout << Username << "\n successful login!";
      main();
   }
   else
   {
      cout << "\n wrong ID or password";
      main();
   }
}


