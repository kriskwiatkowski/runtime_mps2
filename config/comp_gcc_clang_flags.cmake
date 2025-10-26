# Global configuration
string(APPEND C_CXX_FLAGS " ")
string(APPEND C_CXX_FLAGS "-Wignored-qualifiers ")
string(APPEND C_CXX_FLAGS "-Wall ")
string(APPEND C_CXX_FLAGS "-Werror ")
string(APPEND C_CXX_FLAGS "-Wextra ")
string(APPEND C_CXX_FLAGS "-Wpedantic ")
string(APPEND C_CXX_FLAGS "-Wshadow ")
string(APPEND C_CXX_FLAGS "-Wno-variadic-macros ")
string(APPEND C_CXX_FLAGS "-Wundef ")
string(APPEND C_CXX_FLAGS "-Wunused ")
string(APPEND C_CXX_FLAGS "-Wunused-result ")
string(APPEND C_CXX_FLAGS "-Wno-vla ")
string(APPEND C_CXX_FLAGS "-Wredundant-decls ")

set(DEBUG_FLAGS "-Wno-pedantic -Wno-unused -Wno-unused-result -Wno-undef -Wno-unused-parameter")

string(APPEND CMAKE_C_FLAGS " ${C_FLAGS} ${C_CXX_FLAGS} ${EXTRA_C_FLAGS}")
string(APPEND CMAKE_C_FLAGS_DEBUG " ${DEBUG_FLAGS}")

string(APPEND CMAKE_CXX_FLAGS " ${C_CXX_FLAGS}")
string(APPEND CMAKE_CXX_FLAGS_DEBUG " ${DEBUG_FLAGS}")

string(APPEND CMAKE_ASM_FLAGS " ${EXTRA_ASM_FLAGS} -Wa,--noexecstack")
string(APPEND CMAKE_ASM_FLAGS_DEBUG " ${DEBUG_FLAGS}")
