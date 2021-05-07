#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class Processor {
 public:
  float Utilization();  // TODO: See src/processor.cpp
  
  // Constructor
  Processor();

  // TODO: Declare any necessary private members
 private:
  // previous total cpu time since boot = 
  // user + nice + system + idle + iowait + irq + softirq + steal
  float prevTotalCpuTime;
  // previous idle time since boot = idle + iowait
  float prevIdleCpuTime;
  
  // Convert the given string vector into a long vector
  vector<long> convertToLong(vector<string> values);
};

#endif