#ifndef CORE_H
#define CORE_H

#include <iostream>
#include <string>
#include <cstdint>
#include <vector>
#include <fstream>


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ws;
using std::to_string;
using std::vector;
using std::ios;
using std::fstream;

enum enOps { MainMenu = 0, ClMenu = 1 };

struct stClients
{
  string AccNum;
  uint16_t PinCode;
  string CName, Phone;
  double Balance;
};

void DisplayTable(const char *Style, uint16_t BorderCount, bool isActive);
void MenuOperations(uint16_t OperationChoice);
void ChoicePicker();
void SysTrigger();
#endif /*CORE_H*/
