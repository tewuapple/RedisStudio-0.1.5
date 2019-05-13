#ifndef Base_Util_INCLUDED
#define Base_Util_INCLUDED

#include <string>
#include <sstream>

namespace Base {

class Util {

public:
    static std::string ConvertHumanTimeDuration(long long seconds);

    static std::string GetUniqueMachineID(); 

	static char * scientificnotationtostr(char *in, char *out);
    };

} // namespace Base

#endif
