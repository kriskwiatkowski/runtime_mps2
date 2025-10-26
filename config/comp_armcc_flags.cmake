# In ARM CC build the suffix of the static library is .lib
set(CMAKE_STATIC_LIBRARY_SUFFIX ".lib")

string(APPEND C_CXX_FLAGS " ")
string(APPEND C_CXX_FLAGS "--diag_warning=all ")
string(APPEND C_CXX_FLAGS "--diag_error=warning ")
string(APPEND C_CXX_FLAGS "--strict_warnings ")
string(APPEND C_CXX_FLAGS "--strict ")
string(APPEND C_CXX_FLAGS "--no_vla ")
string(APPEND C_CXX_FLAGS "--diag_warning=174 ")    # Expression has no effect
string(APPEND C_CXX_FLAGS "--diag_warning=111 ")    # Statement unreachable
string(APPEND C_CXX_FLAGS "--diag_warning=177 ")    # Never referenced
string(APPEND C_CXX_FLAGS "--diag_warning=1293 ")   # Assignment in condition

string(APPEND CMAKE_C_FLAGS " ${EXTRA_C_FLAGS}")
string(APPEND CMAKE_C_FLAGS_RELEASE " ${C_CXX_FLAGS}")
string(APPEND CMAKE_C_FLAGS_RELWITHDEBINFO " ${C_CXX_FLAGS}")
string(APPEND CMAKE_C_FLAGS_MINSIZEREL " ${C_CXX_FLAGS}")

string(APPEND CMAKE_ASM_FLAGS " ${EXTRA_ASM_FLAGS}")

string(APPEND CMAKE_CXX_FLAGS_RELEASE " ${C_CXX_FLAGS}")
string(APPEND CMAKE_CXX_FLAGS_RELWITHDEBINFO " ${C_CXX_FLAGS}")
string(APPEND CMAKE_CXX_FLAGS_MINSIZEREL " ${C_CXX_FLAGS}")
