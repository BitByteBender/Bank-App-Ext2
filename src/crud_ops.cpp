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

short FindClient(string AccNum, short Blocker=0)
{
  vector <stClients> vstClients = displayLib::LineToRec(LoadFromFile("0-Dupes_Clients.txt"));
  uint16_t i = 0;
  
  for (const stClients &rec:vstClients) {
    if (AccNum == rec.AccNum) {
      if (Blocker != -1) displayLib::DisplayClientRecord(rec, Blocker);
      return (i);
    }
    i++;
  }
  
  return (-1);
}

void UpdateClient()
{
  string AccNum = ReadInputs("Enter an account number you want to update: ");  
  
  vector <string> vClients = LoadFromFile("0-Dupes_Clients.txt");

  if (FindClient(AccNum, 0) != -1) {
    char CommitChecker = ReadInputs("Do you want to update this record (Y | N) ? ")[0];
    if (CommitChecker == 'Y' || CommitChecker == 'y') {
      stClients Client;
      Client = RecordClientData(false);
      Client.AccNum = AccNum;
      vClients[FindClient(AccNum, -1)] = RecToLine(Client, "#-#");
      cout<<"Account ["<<AccNum<<"] has been updated successfully!"<<endl;
    } else cout<<"Update has been Terminated!"<<endl;
  } else cout<<"[Warning]>> No Account with this number has been found!";

  SaveRecToFile(vClients, "0-Dupes_Clients.txt");
}

void DeleteClient()
{
  string AccNum = ReadInputs("Enter an account number you want to update: ");
  vector <string> vClients = LoadFromFile("0-Dupes_Clients.txt");

  if (FindClient(AccNum, 0) != -1) {
    char CommitDeletion = ReadInputs("Do you want to delete this record (Y | N) ? ")[0];
    if (CommitDeletion == 'y' || CommitDeletion == 'Y') {
      vClients[FindClient(AccNum, -1)] = "";
      cout<<"Account ["<<AccNum<<"] has been deleted successfully!"<<endl;
    } else cout<<"Deletion has been terminted!"<<endl;
  } else cout<<"[Warning]>> No Account with this Number has been found!";

  SaveRecToFile(vClients, "0-Dupes_Clients.txt");
}
