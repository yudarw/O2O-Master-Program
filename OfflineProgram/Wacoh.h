#include <iostream>
#include <stdio.h>
using namespace std;

extern bool wacoh_isConnected;
extern int serial_connect(string com_num);
extern void WacohRead(float  force_tmpp[6]);
extern void serial_close();
extern void detect_serialPort();
extern string serialPortList[10];