#include <string>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long times) { 
  string time = "00:00:00";
  long cal = 0;
  if(times > 0){
  	// calculate hours
    cal = times / 3600;
    time = TimeValueToString(cal) + ":";
    // calculate minutes
    cal = (times / 60) % 60;
    time += TimeValueToString(cal) + ":";
    // calculate seconds
    cal = times % 60;
    time = TimeValueToString(cal) + ":";
    
  }
  return time;
}

string Format::TimeValueToString(long time){
	if(time < 10) {return "0" + std::to_string(time);}
  	else {return std::to_string(time);}
  	return " ";
}