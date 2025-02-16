#include "../headers/handlers.hpp"
#include "../headers/displayLib.hpp"
#include "../headers/core.hpp"
#include "../headers/user_handler.hpp"

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

// Transactions Menu [Funcs]

double CalcTrx(double NumA, double NumB)
{
  return (NumA += NumB);
}

string GetAmount(double oBalance, double nBalance, double Amount)
{
  return (oBalance < nBalance ? "+"+to_string(Amount) : "-"+to_string(Amount));
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
	const double RecordOldBalance = vClients[FindClient(AccNum, -1)].Balance;
	
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

	SaveSingleRecToFile(TrxLines(vClients[FindClient(AccNum, -1)], GetAmount(RecordOldBalance, vClients[FindClient(AccNum, -1)].Balance, DepositAmount), "#-#"), "0-Trx.txt");
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

// User Manager Menu [Funcs]
void AddNewUsr()
{
  vector <string> vUsrs;
  char Choice = 'n';
  stUsers Usr;
  
  do {
    Usr = RecUsrData(true);
    SaveSingleRecToFile(RecToLine(Usr, "#-#"), "Users.txt");
    Choice = ReadInputs("Do you want to add more users(Y/N)? ")[0];
    if (Choice != 'y' && Choice != 'Y') {
      cout<<"Breaking!\nChoice: "<<Choice<<'\n';
      break;
    }
  } while (Choice == 'y' || Choice == 'Y');
}

bool FindUser(string Usrname)
{ 
  if (FetchUser(Usrname).Username == Usrname) {
    stUsers Usr = FetchUser(Usrname);
    cout<<"Username: "<<Usr.Username<<'\n'
	<<"Password: "<<Usr.Passwd<<'\n'
	<<"Permissions: "<<Usr.Permissions<<endl;
    return (1);
  } else cout<<"\nNo user with Username: ["<<Usrname<<"] is found!\n"<<endl;
  
  return (0);
}

void DeleteUser(string Usrname)
{
  vector <string> vUsernames = AccNums("Users.txt"), vLoader;

  if (FetchUser(Usrname).Username == Usrname) {
    uint16_t i = 0;
    for (const string &rec:vUsernames) {
      if (rec != Usrname) vLoader.push_back(LoadFromFile("Users.txt")[i]);
      i++;
    }
    SaveRecToFile(vLoader, "Users.txt");
  }
}

void CommitDeletion()
{
  char Choice = 'n';
  string Usrname = ReadInputs("Enter the Username you want to delete: ");

  if (FindUser(Usrname)) {
     Choice = ReadInputs("Do you want to delete this user(Y | N)? ")[0];
     if (Choice == 'y' || Choice == 'Y') DeleteUser(Usrname);
  }
}

void UpdateUser(string Usrname)
{
  vector <string> vUsernames = AccNums("Users.txt"), vLoader = LoadFromFile("Users.txt");

  if (FetchUser(Usrname).Username == Usrname) {
    uint16_t i = 0;
    for (const string &rec:vUsernames) {
      if (rec == Usrname) {
	stUsers Usr = RecUsrData(false);
	Usr.Username = rec;
	vLoader[i] = RecToLine(Usr, "#-#");
      }
      i++;
    }
    SaveRecToFile(vLoader, "Users.txt");
  }
}

void CommitUpdate()
{
  char Choice = 'n';
  string Usrname = ReadInputs("Enter the Username you want to update: ");

  if (FindUser(Usrname)) {
     Choice = ReadInputs("Do you want to update this user(Y | N)? ")[0];
     if (Choice == 'y' || Choice == 'Y') UpdateUser(Usrname);
  }
}
