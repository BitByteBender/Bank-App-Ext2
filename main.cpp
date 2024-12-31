#include "headers/displayLib.hpp"
#include "headers/handlers.hpp"
#include "headers/core.hpp"

using displayLib::DisplayMenuWrapper;

int main(void)
{
  DisplayMenuWrapper("x", 35, "Main Menu", 5, "1: Display Client List, 2: Insert New Client", true);
  DisplayTable("-", 90, false);

  cout<<'\n'<<"Testing File"<<'\n';
  //vector <string> Loader = LoadFromFile("Clients.txt");
  for (const string &c:LoadFromFile("Clients.txt")) {
    cout<<c<<'\n';
  }

  cout<<"\nvector of strings: "<<'\n';
  for (const string &s:AccNums()) {
    cout<<s<<'\n';
  }
  cout<<endl;

  //InsertClients();

  cout<<"\nVerifying duplication: \n";
  vector <string> vrf = VerifyAccNums("Clients.txt");
  for (const string &d:vrf) {
    cout<<d<<'\n';
  }

  cout<<'\n'<<"Testing File<0 Dupes>"<<'\n';
  SaveRecToFile(vrf, "0-Dupes_Clients.txt");

  for (const string &c:LoadFromFile("0-Dupes_Clients.txt")) {
    cout<<c<<'\n';
  }
  return (0);
}
