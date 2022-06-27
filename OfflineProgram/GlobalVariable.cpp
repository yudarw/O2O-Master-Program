#include "GlobalVariable.h"

Yaskawa			yrc;
Fanuc			roboguide;
OpenHaptic		haptic;
CoppeliaSim		sim;
CoppeliaRobot	ur10;

int selected_robot = 0;


// -- Speed Variable --
// =======================================
double normal_speed = 100;
double fast_speed	= 200;
double slow_speed	= 30;
double robot_speed;


// -- Roboguide Recording --
int rg_trigger_state;

vector<Sequence> program_data;
vector<pos_t> pos_register;
unsigned int steps = 0;
unsigned int line_number = 0;
unsigned int editing_mode = 0;
unsigned int total_line_number = 0;
string str_move_type[2] = { "MOVE L", "MOVE J" };
string str_wait[2] = { "TRUE", "FALSE" };

TableEditorParam tab;
origin_t origin[10];
int org_index;

// -- Robot Position Variable --
// =========================================
DataPos rg_global_pos;
dataPos yw_global_pos;
float	global_robot_force[6];
float	calibrated_robot_force[6];
vector<pos_t> recorded_pos;


// ========================================= // 
//		Trajectory Editor Variable
// ========================================= //
TrajectoryEditorParam tab2;
vector<pos_t> dataPosTable;

// Haptic Teleoperation
bool hapticTeleoperationIsActive = false;
int load_sequence_program(string filepath);

Vector3d haptic_feedback_force;

bool program_isRunning = false;