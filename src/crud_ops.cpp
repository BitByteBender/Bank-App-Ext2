#include "../headers/handlers.hpp"
#include "../headers/displayLib.hpp"
#include "../headers/core.hpp"


void InsertClients()
{
  vector <string> vClients;
  stClients cl;
  char Choice = 'N';

  do
  {
    cl = RecordClientData(true);
    // problem here duplication of records (Fixed)
    /*
    vClients.push_back(RecToLine(cl, "#-#"));
    SaveRecToFile(vClients, "Clients.txt");
    vClients.clear();
    */
    // Saving Single Record
    SaveSingleRecToFile(RecToLine(cl, "#-#"), "Clients.txt");
    Choice = ReadInputs("Do you want to enter a new client(Y/N)? ")[0];
  } while (Choice == 'Y' || Choice == 'y');
  
  vClients = VerifyAccNums("Clients.txt");
  SaveRecToFile(vClients, "0-Dupes_Clients.txt");
}

bool FindClient(string AccNum)
{
  vector <stClients> vstClients = displayLib::LineToRec(LoadFromFile("0-Dupes_Clients.txt"));
  for (const stClients &rec:vstClients) {
    if (AccNum == rec.AccNum) {
      displayLib::DisplayClientRecord(rec);
      return (true);
    }
  }
  
  return (false);
}

void UpdateClient()
{
  string AccNum = ReadInputs("Enter an account number you want to update: ");  
  
  vector <string> vClients = LoadFromFile("0-Dupes_Clients.txt");
  uint16_t i = 0;

  if (FindClient(AccNum)) {
    for (const string &ln:AccNums("0-Dupes_Clients.txt")) {
      if (ln == AccNum) {	
	char CommitChecher = ReadInputs("Do you want to update this record (Y | N) ?")[0];
	if (CommitChecher == 'Y' || CommitChecher == 'y') {
	  stClients Client;
	  Client = RecordClientData(false);
	  Client.AccNum = ln;
	  vClients[i] = RecToLine(Client, "#-#");
	}
      }
      i++;
    }
  } else  cout<<"[Warning]>> No Account with this number has been found!";

  SaveRecToFile(vClients, "0-Dupes_Clients.txt");
}
