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

vector <string> MultiFunc(string FuncChoice)
{
  string Msg = "Enter an account number you want to "+FuncChoice+": ";
  string AccNum = ReadInputs(Msg.c_str());
  
  vector <string> vClients = LoadFromFile("0-Dupes_Clients.txt");

  if (FindClient(AccNum, 0) != -1) {
    char CommitChecker = ReadInputs(("Do you want to "+FuncChoice+" this record (Y | N) ? ").c_str())[0];
    if (FuncChoice == "update" && (CommitChecker == 'Y' || CommitChecker == 'y')) {
      stClients Client;
      Client = RecordClientData(false);
      Client.AccNum = AccNum;
      vClients[FindClient(AccNum, -1)] = RecToLine(Client, "#-#");
      cout<<"Account ["<<AccNum<<"] has been updated successfully!"<<endl;
    } else if (FuncChoice == "delete" && (CommitChecker == 'Y' || CommitChecker == 'y')) {
      vClients[FindClient(AccNum, -1)] = "";
      cout<<"Account ["<<AccNum<<"] has been deleted successfully!"<<endl;
    } else cout<<FuncChoice+" has been Terminated!"<<endl;
  } else cout<<"[Warning]>> No Account with this number has been found!";

  SaveRecToFile(vClients, "0-Dupes_Clients.txt");
  return (vClients);
}

void UpdateClient()
{
  /*
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
  */
  MultiFunc("update");
}

void DeleteClient()
{
  /*
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
  */
  MultiFunc("delete");
}

double CalcTrx(double NumA, double NumB)
{
  return (NumA += NumB);
}

vector <stClients> WithdrawOrDeposit(string TrxChoice)
{
  string AccNum = ReadInputs("Please enter a valid AccountNumber: ");
  vector <stClients> vClients = displayLib::LineToRec(LoadFromFile("0-Dupes_Clients.txt"));
  
  do {
    if (FindClient(AccNum, 1) != -1) {
      double DepositAmount = stod(ReadInputs(("Please enter a "+TrxChoice+" amount? ").c_str()));
      char Commit = ReadInputs("Are you sure you want to perform this transactions? (y/n) ")[0];
      if (Commit == 'Y' || Commit == 'y') {
	if (TrxChoice == "deposit")
	  vClients[FindClient(AccNum, -1)].Balance = CalcTrx(vClients[FindClient(AccNum, -1)].Balance, DepositAmount);
	else {
	  if (TrxChoice == "withdraw" && CalcTrx(vClients[FindClient(AccNum, -1)].Balance, (DepositAmount * -1)) >= 0)
	    vClients[FindClient(AccNum, -1)].Balance = CalcTrx(vClients[FindClient(AccNum, -1)].Balance, (DepositAmount * -1));
	  else {
	    cout<<"\nYou don't have enough balance!\n"<<endl;
	    continue;
	  }
	}

	displayLib::DisplayEndResutl(vClients[FindClient(AccNum, -1)].AccNum, TrxChoice, vClients[FindClient(AccNum, -1)].Balance);
      }
      break;
    } else AccNum = ReadInputs("Please re-enter a valid AccountNumber: ");
  } while (true);

  return (vClients);
}

void DepositToAccount()
{
  /*
  string AccNum = ReadInputs("Please enter a valid AccountNumber: ");
  vector <string> vNewRecs;
  vector <stClients> vClients = displayLib::LineToRec(LoadFromFile("0-Dupes_Clients.txt"));
  
  do {
    if (FindClient(AccNum, 1) != -1) {
      double DepositAmount = stod(ReadInputs("Please enter a deposit amount? "));
      char Commit = ReadInputs("Are you sure you want to perform this transactions? (y/n) ")[0];
      if (Commit == 'Y' || Commit == 'y') {
	vClients[FindClient(AccNum, -1)].Balance = CalcTrx(vClients[FindClient(AccNum, -1)].Balance, DepositAmount);
	cout<<"\nAccount ["<<vClients[FindClient(AccNum, -1)].AccNum
	    <<"] has a new Deposit!"<<'\n'
	    <<">> New Balance of ["<<vClients[FindClient(AccNum, -1)].AccNum<<"] is: "
	    <<vClients[FindClient(AccNum, -1)].Balance<<endl;
      }
      break;
    } else AccNum = ReadInputs("Please re-enter a valid AccountNumber: ");
  } while (true);

  vNewRecs = RecsToLines(vClients);
  */
  vector <stClients> vClients = WithdrawOrDeposit("deposit");
  vector <string> vNewRecs;
  
  vNewRecs = RecsToLines(vClients);
  SaveRecToFile(vNewRecs, "0-Dupes_Clients.txt");
}

void WithdrawFromAccount()
{
  /*
  string AccNum = ReadInputs("Please enter a valid AccountNumber: ");
  vector <string> vNewRecs;
  vector <stClients> vClients = displayLib::LineToRec(LoadFromFile("0-Dupes_Clients.txt"));
  
  do {
    if (FindClient(AccNum, 1) != -1) {
      double WithdrawAmount = stod(ReadInputs("Please enter a withdraw amount? "));
      char Commit = ReadInputs("Are you sure you want to perform this transactions? (y/n) ")[0];
      if (Commit == 'Y' || Commit == 'y') {
	vClients[FindClient(AccNum, -1)].Balance = CalcTrx(vClients[FindClient(AccNum, -1)].Balance, (WithdrawAmount * -1));
	cout<<"\nAccount ["<<vClients[FindClient(AccNum, -1)].AccNum
	    <<"] has a new Withdraw!"<<'\n'
	    <<">> New Balance of ["<<vClients[FindClient(AccNum, -1)].AccNum<<"] is: "
	    <<vClients[FindClient(AccNum, -1)].Balance<<endl;
      }
      break;
    } else AccNum = ReadInputs("Please re-enter a valid AccountNumber: ");
  } while (true);
  */
  vector <stClients> vClients = WithdrawOrDeposit("withdraw");
  vector <string> vNewRecs;
  
  vNewRecs = RecsToLines(vClients);
  SaveRecToFile(vNewRecs, "0-Dupes_Clients.txt");
}
