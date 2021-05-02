#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "linux_parser.h"
#include "process.h"

using std::string;
using std::to_string;
using std::vector;

// Constructor to initialize all the values
Process::Process(int pid) : processId_(pid){
	calculateCpuUsage();
  	determineCommand();
  	determineRam();
  	determineUptime();
  	determineUser();
}
// TODO: Return this process's ID
int Process::Pid() { return processId_; }

// TODO: Return this process's CPU utilization
float Process::CpuUtilization() { return cpuUsage_; }

// TODO: Return the command that generated this process
string Process::Command() { return command_; }

// TODO: Return this process's memory utilization
string Process::Ram() { return ram_; }

// TODO: Return the user (name) that generated this process
string Process::User() { return user_; }

// TODO: Return the age of this process (in seconds)
long int Process::UpTime() { return uptime_; }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
// bool Process::operator<(Process const& a[[maybe_unused]]) const { return true; }

// calculate the CPU utilization of this process and save in cpuUsage_
void Process::calculateCpuUsage(){
	// read values from the filesystem
  	long uptime = LinuxParser::UpTime();
  	vector<float> val = LinuxParser::CpuUtilization(Pid());
  // If value read successfuly
  if(val.size() == 5){
  	// add utime, stime, cutime, cstime (they are in seconds)
    float totaltime = val[kUtime_] + val[kStime_] + val[kCutime_] + val[kCstime_];
    float seconds = uptime - val[kStarttime_];
    // calculate the processes CPU usage
    cpuUsage_ = totaltime / seconds;
  }
  else cpuUsage_ = 0;
}

// determine the username that generated this process and save in user_
void Process::determineUser() { user_ = LinuxParser::User(Pid());}
// determine the command that generated this process and save in command_
void Process::determineCommand(){command_ = LinuxParser::Command(Pid());}
// determine the memory utilization of that process and save in ram_
void Process::determineRam(){
  	// Read kB value from file
	string val = LinuxParser::Ram(Pid());
  // Convert into MB
  try{
  	long conv = std::stol(val)/1000;
    ram_ = std::to_string(conv);
  } catch (const std::invalid_argument& arg){
  	ram_ = "0";
  }
}

// determine the age of the process and save in uptime_
void Process::determineUptime(){
	uptime_ = LinuxParser::UpTime(Pid());
}