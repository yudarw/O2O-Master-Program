#pragma once
#include "Fanuc.h"
#include "Yaskawa.h"
#include "OpenHaptic.h"
#include "HomogeneousTransform.h"
#include <windows.h>
#include <stdio.h>
#include <process.h>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include "Eigen\Dense"
#include <msclr\marshal_cppstd.h>
#include "Wacoh.h"
#include "coppeliasim.h"
//#include <dirent.h>

using namespace std;
using namespace msclr::interop;
using namespace Eigen;

// Command:
#define LINE_ADD						0
#define LINE_EDIT						1

#define CMD_ADD_EMPTY_LINE				0
#define CMD_ADD_MOVE_POINT				1
#define CMD_ADD_OFFLINE_TRAJECTORY		2

#define CMD_WAIT						2
#define CMD_SET_IO						3
#define CMD_JUMP						4
#define CMD_LABEL						5

#define ROBOGUIDE						0
#define YASKAWA							1

// Struct Variable:
typedef struct pos_t {
	double X, Y, Z, W, P, R;
};

typedef struct Sequence {
	int		dataInt;
	double	dataDouble;
	string	dataString;
	int command;
	int moveType;
	int wait;
	double speed;
	pos_t   pos;
	int		posRegNum;
	string  label;
};

typedef struct TableEditorParam {
	unsigned int index;
	unsigned int selected_index;
	unsigned int total_index;
	vector <Sequence> program_data;
	vector <pos_t>    pos_register;
	unsigned int selected_pos_reg;
	unsigned int pos_reg_index;
	unsigned int total_pos_register;
};

typedef struct TrajectoryEditorParam {
	unsigned int index;
	unsigned int selected_index;
	unsigned int total_index;
	vector<pos_t> data;
};

typedef struct origin_t {
	pos_t data;
	string comment;
	pos_t centerpos;
	pos_t xpos;
	pos_t ypos;
	pos_t centerpos_offset;
};

extern Yaskawa		yrc;
extern OpenHaptic	haptic;
extern Fanuc		roboguide;
extern int selected_robot;
extern CoppeliaSim		sim;
extern CoppeliaRobot	ur10;


// -- Robot Position Variable --
// =========================================
extern DataPos rg_global_pos;
extern dataPos yw_global_pos;
extern float   global_robot_force[6];
extern float   calibrated_robot_force[6];

extern double normal_speed;
extern double fast_speed;
extern double slow_speed;
extern double robot_speed;


// -- Global varible --
extern std::vector<Sequence> program_data;
extern unsigned int steps;
extern unsigned int editing_mode;
extern unsigned int line_number;
extern unsigned int total_line_number;
extern string str_move_type[2];
extern string str_wait[2];
extern TableEditorParam tab;
extern origin_t origin[10];
extern int org_index;
extern string trajectory_file_name;
extern string trajectory_file_path;
extern string program_file_name;
extern string program_file_path;
extern string yaskawa_ip;
extern string roboguide_ip;
extern string serialComPort;
extern bool program_isRunning;
extern bool trajectory_isRunning;

extern int teleoperation_method;
extern double stiffness_val;
extern double impedance_val;
extern int speed_ratio;

extern double standby_pos[6];
extern double home_pos[6];


// -- Main Function --
extern vector<pos_t> load_trajectory(string filepath);
extern vector<pos_t> dataPosTable;
extern TrajectoryEditorParam tab2;
extern void print_trajectory(vector<pos_t> pos);
extern pos_t ConvertToPost(dataPos ywpos);
extern pos_t rgConvertToPost(DataPos ywpos);
extern dataPos ConvertToDataPos(pos_t pos);
extern void load_config_file();
extern void save_config_file();
extern double calibrate_speed(int sp_ratio, double sp_in);

// -- Teleoperation --
extern bool haptic_jog_mode;
extern bool teleoperationIsActive;
extern vector<pos_t> trajectory_setToZero(vector<pos_t> pos);
extern vector<pos_t> calibrate_trajectory(vector<pos_t> pos);
extern void save_trajectory(string filepath, vector<pos_t> pos);
extern void save_origin_data();
extern void load_origin_data();
extern void thread_simTeleoperation(void *);
extern void thread_simTeleoperation_2(void *);
extern void thread_simTeleoperation_3(void *);
extern void thread_update_robot_data(void *);
extern void gravity_compensation(dataPos pos, float __Fe[6], float __Fm[6]);
extern void setHapticForces(Vector3d fh);
extern void setRobotPosition(Vector3d pos, Vector3d rot);
extern MatrixXd getDiagMatrix(Vector3d vec);


extern void thread_run_sequence_program(void *);
extern void run_trajectory(void *);
extern dataPos arrayToDatapos(double pos[6]);


// -- Sequence Programming --
extern string program_file_name;
extern string program_file_path;
extern void save_sequence_program(string filepath);
extern int load_sequence_program(string filepath);
extern void print_program_data();
extern void execute_program_line(int i);

extern bool trajectoryIsRunning;

// -- Roboguide Recording --
extern int rg_trigger_state;
extern vector<pos_t> recorded_pos;

// -- Show Graph --
extern void set_graph_data(double line1, double line2, double line3, string str1, string str2, string str3);

extern Vector3d haptic_feedback_force;

extern void run_trajectory_non_threated();