#ifndef USER_HANDLER
#define USER_HANDLER

#include "core.hpp"

stUsers LineToRec(vector <string> Line);
stUsers FetchUser(string Username);
int16_t GetPermission(string, string);
bool AuthenticateUser(string, string);
vector <uint16_t> RetrieveChoices(short Permissions);
string RetrieveChoicesV2(short Permissions);

//crud_ops
void AddNewUsr();
bool FindUser(string);
void DeleteUser(string);
void CommitDeletion();
void UpdateUser(string);
void CommitUpdate();

//core
void UserManagerMenu(uint16_t OperationChoice);
void UserManagerTrigger();
#endif /* USER_HANDLER */
