#include "../headers/handlers.hpp"
#include "../headers/core.hpp"


void InsertClients()
{
  vector <string> vClients;
  stClients cl;
  char Choice = 'N';

  do
  {
    cl = RecordClientData();
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
