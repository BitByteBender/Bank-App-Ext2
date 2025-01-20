#include "../headers/handlers.hpp"
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

void UpdateClient()
{
  vector <string> vClients = LoadFromFile("0-Dupes_Clients.txt");
  string AccNum = ReadInputs("Enter an account number you want to update: ");
  bool doesExist = false;
  
  for (const string &an:AccNums("0-Dupes_Clients.txt")) {
    if (an == AccNum) {
      cout<<"Found!\n";
      // 1- Enter new details
      // 2- Reload the file to a new vector till the found AccNum
      // 3- Delete record and Insert this updated record
      // 4- finish adding the rest records
      // 5- Renew the file
      doesExist = true;
      break;      
    }
  }

  if (doesExist == false) cout<<"[Warning]>> No Account with this number has been found!";
}
