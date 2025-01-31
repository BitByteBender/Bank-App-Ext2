#include "../headers/handlers.hpp"
#include "../headers/displayLib.hpp"
#include "../headers/user_handler.hpp"
//#include "../headers/core.hpp"

stUsers LineToRec(vector <string> Line)
{
  stUsers Usr;

  Usr.Username = Line[0];
  Usr.Passwd = Line[1];
  Usr.Permissions = stoi(Line[2]);

  return (Usr);
}

/*
bool FetchUsername(string Username)
{
  stUsers Usr;
  vector <string> Users = AccNums("Users.txt");
  
  for (const string &usr:Users) {
    if (usr == Username) {
      return (true);
    }
  }
  
  return (false);
}*/

stUsers FetchUsername(string Username)
{
  stUsers Usr;
  vector <string> Users = AccNums("Users.txt"), Lines = LoadFromFile("Users.txt");
  uint16_t i = 0;
  
  for (const string &usr:Users) {
    if (usr == Username) {
      Usr = LineToRec(displayLib::SplitLine(Lines[i], "#-#"));
    }
    i++;
  }
  
  return (Usr);
}

bool AuthenticateUser()
{
  string str = ReadInputs("Username: ");
  stUsers Usr = FetchUsername(str);
  
  if (Usr.Username == str) {
    if (ReadInputs("Password: ") == Usr.Passwd) {
      cout<<"You are In!\n"<<endl;
      return (true);
    }
  }

  cout<<"You are out!\n"<<endl;
  return (false);
}
