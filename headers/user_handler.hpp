#ifndef USER_HANDLER
#define USER_HANDLER

#include "core.hpp"

stUsers LineToRec(vector <string> Line);
stUsers FetchUser(string Username);
int16_t GetPermission(string, string);
bool AuthenticateUser(string, string);
vector <uint16_t> RetrieveChoices(short Permissions);
string RetrieveChoicesV2(short Permissions);
#endif /* USER_HANDLER */
