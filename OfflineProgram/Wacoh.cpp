#include <windows.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include "Wacoh.h"

using namespace std;

HANDLE COM;
bool wacoh_isConnected = false;
string serialPortList[10];

int  force_ori[6] = { 0 };
int  force_tmp[6] = { 8192, 8192, 8192, 8192, 8192, 8192 };
float  force_senstv[6] = { 32.800, 32.815, 32.835, 1653.801, 1634.816, 1636.136 };
//float  force_tmpp[6] = { 0 };

// Serial Communication:
// ///////////////////////////////////////////////////
int serial_connect(string com_num) {
	//char * comPort;
	//strcpy(comPort, com_num.c_str());
	BOOL   status;
	COM = CreateFile(com_num.c_str(), GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	if (COM == INVALID_HANDLE_VALUE)
		printf("> COM number is invalid! \n");

	COMMTIMEOUTS	timeouts;
	DCB				dcb;

	timeouts.ReadIntervalTimeout = 1;
	timeouts.ReadTotalTimeoutMultiplier = 1;
	timeouts.ReadTotalTimeoutConstant = 1;
	timeouts.WriteTotalTimeoutMultiplier = 1;
	timeouts.WriteTotalTimeoutConstant = 1;

	SetCommTimeouts(COM, &timeouts);
	EscapeCommFunction(COM, SETDTR);

	status = GetCommState(COM, &dcb);
	if (status == FALSE) {
		return -1;
	}

	dcb.BaudRate = 921600;
	dcb.ByteSize = (BYTE)8;
	dcb.Parity = (BYTE)NOPARITY;
	dcb.StopBits = (BYTE)ONESTOPBIT;
	dcb.fOutxCtsFlow = FALSE;
	dcb.fRtsControl = RTS_CONTROL_ENABLE;

	status = SetCommState(COM, &dcb);
	if (status == FALSE) {
		return -1;
	}

	wacoh_isConnected = true;
	printf("> Serial Comm success... \n");
	return 1;
}

// Read force sensor WACOH:
// ////////////////////////////////////////////
void WacohRead(float  force_tmpp[6]) {
	DWORD n = 0;
	char str[128];
	WriteFile(COM, "R", 1, &n, 0);
	Sleep(1);
	ReadFile(COM, str, 27, &n, 0);
	str[n] = 0;
	int tmp;

	if (n >= 27)
		sscanf(str, "%1d%4hx%4hx%4hx%4hx%4hx%4hx", &tmp, &force_ori[0], &force_ori[1], &force_ori[2], &force_ori[3], &force_ori[4], &force_ori[5]);
	else
	{
		DWORD nn;
		ReadFile(COM, str + n, 27, &nn, 0);
		n += nn;
		str[n] = 0;
		if (nn >= 27)
			sscanf(str, "%1d%4hx%4hx%4hx%4hx%4hx%4hx", &tmp, &force_ori[0], &force_ori[1], &force_ori[2], &force_ori[3], &force_ori[4], &force_ori[5]);
	}

	for (int i = 0; i < 6; i++) {
		force_tmpp[i] = float(force_ori[i] - force_tmp[i]) / force_senstv[i];
	}
	//printf("%d,%d,%d,%d,%d,%d,%d\n", tmp, force_ori[0], force_ori[1], force_ori[2], force_ori[3], force_ori[4], force_ori[5]);
	//printf("Force Read: %.3f  %.3f  %.3f  %.3f  %.3f  %.3f\n", force_tmpp[0], force_tmpp[1], force_tmpp[2], force_tmpp[3], force_tmpp[4], force_tmpp[5]);
}

void serial_close() {
	wacoh_isConnected = false;
	CloseHandle(COM);
}


void detect_serialPort() {
	char lpTargetPath[5000]; // buffer to store the path of the COMPORTS
	char temp[32];
	DWORD test;
	int num = 0;
	for (int i = 0; i < 255; i++) // checking ports from COM0 to COM255
	{
		//string str = "COM" + to_string(2); // converting to COM0, COM1, COM2
		sprintf(temp,"COM%d", i);
		test = QueryDosDevice(temp, lpTargetPath, 5000);
		// Test the return value and error if any
		if (test != 0) //QueryDosDevice returns zero if it didn't find an object
		{
			cout << temp << ": " << lpTargetPath << std::endl;
			serialPortList[num] = string(temp);
			num++;
		}

		if (::GetLastError() == ERROR_INSUFFICIENT_BUFFER)
		{
		}
	}
}