#ifndef PROCESS_H
#define PROCESS_H

#include <string>
/*
Basic class for Process representation
It contains relevant attributes as shown below
*/
class Process {
 public:
  // constructor to initialize Process with the read process-ID from filesystem
  Process(int pid);
  int Pid();                               // TODO: See src/process.cpp
  std::string User();                      // TODO: See src/process.cpp
  std::string Command();                   // TODO: See src/process.cpp
  float CpuUtilization();                  // TODO: See src/process.cpp
  std::string Ram();                       // TODO: See src/process.cpp
  long int UpTime();                       // TODO: See src/process.cpp
  bool operator<(Process const& a) const;  // TODO: See src/process.cpp

  // TODO: Declare any necessary private members
 private:
  // process-ID
  int processId_;
  // username that generated this process
  std::string user_;
  // command that generated this process
  std::string command_;
  // CPU usage of the process
  float cpuUsage_;
  // processes memory utilization
  std::string ram_;
  // age of this process
  long uptime_;
  // CPU values of a process
  enum ProcessCPUStates {
  	kUtime_ = 0,
    kStime_,
    kCutime_,
    kCstime_,
    kStarttime_,
  };
  
  // calculate the CPU utilization of this process and save in cpuUsage_
  void calculateCpuUsage();
  // determine the user name that generated this process and save in user_
  void determineUser();
  // determine the memory utilization of that process and save in command_
  void determineCommand();
  // determine the memory utlization of that process and save in ram_
  void determineRam();
  // determine the age of this process and save in uptime_
  void determineUptime();
};

#endif