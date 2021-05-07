#ifndef FORMAT_H
#define FORMAT_H

#include <string>

namespace Format {
std::string ElapsedTime(long times);   // TODO: See src/format.cp };                                    // namespace Format
// Check to see if calculated number is smaller than 10
// and return 0x for number smaller than 10 otherwise return the number
std::string TimeValueToString(long time);
}
#endif