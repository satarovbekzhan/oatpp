# --- Import tools ----

include(../cmake/CPM.cmake)

# ---- Dependencies ----

# ---- Create standalone executable ----

add_executable(hallo main.cpp)
target_link_libraries(hallo PRIVATE project_options project_warnings fmt::fmt spdlog::spdlog)
