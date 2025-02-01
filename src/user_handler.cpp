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

stUsers FetchUser(string Username)
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

int16_t GetPermission(string Username, string Passwd)
{
  stUsers Usr = FetchUser(Username);
  
  if (Usr.Username == Username) {
    if (Passwd ==  Usr.Passwd) return (Usr.Permissions);
  }

  return (-2);
}

bool AuthenticateUser(string Username, string Passwd)
{
  //string Usrname = ReadInputs("Username: "), Passwd = ReadInputs("Password: ");
  return (GetPermission(Username, Passwd) < -1 ? false : true);
}

/*
vector <uint16_t> RetrieveChoices(short Permissions)
{
  vector <uint16_t> vSpots;
  short i = 0, Checker = Permissions;

  for (i = 1; i <= 6; ++i) {
    Checker = Permissions - pow(2, abs(7 - i));
    if (Checker > -1) {
      Permissions -= pow(2, abs(7 - i));
      vSpots.push_back(abs(7 - i) + 1);
    } else continue;
  }
  
  return (vSpots);
}
*/

string RetrieveChoicesV2(short Permissions)
{
  string strBinary;
  short i = 0, Checker = Permissions;

  for (i = 7; i >= 0; --i) {
    Checker = Permissions - pow(2, abs(i));
    if (Checker < 0) strBinary += '0';
    else {
      strBinary += '1';
      Permissions -= pow(2, abs(i));
    }
  }
  
  return (strBinary);
}
