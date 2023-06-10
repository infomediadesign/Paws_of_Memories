cmake_minimum_required (VERSION 3.11)

project(raylibstarter)

add_subdirectory ("src")

cmake_policy(SET CMP0079 NEW)

target_link_libraries(${Paws_of_Memories} raylib nlohmann_json::nlohmann_json)

include(cmake/nlohmann_json.cmake)