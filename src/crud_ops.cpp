#include "../headers/handlers.hpp"
#include "../headers/core.hpp"
#include <vector>

using std::vector;

void InsertClients()
{
  vector <string> vClients;
  stClients cl;
  char Choice = 'N';

  do {
    cl = RecordClientData();
    // problem here duplication of records (Fixed)
    /*
    vClients.push_back(RecToLine(cl, "#-#"));
    SaveRecToFile(vClients, "Clients.txt");
    vClients.clear();
    */
    // Saveing Single Record
    SaveSingleRecToFile(RecToLine(cl, "#-#"), "Clients.txt");
    Choice = ReadInputs("Do you want to enter a new client(Y/N)? ")[0];
  } while (Choice == 'Y' || Choice == 'y');
}
