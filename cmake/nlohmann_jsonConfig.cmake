CMAKE_MINIMUM_REQUIRED(VERSION 3.11.2)

if (NOT nlohmann_FOUND)
  INCLUDE(FetchContent)

  FetchContent_Declare(nlohmann URL https://github.com/nlohmann/json/releases/download/v3.11.2/json.tar.xz)
  FetchContent_GetProperties(nlohmann)
  if (NOT nlohmann_POPULATED)
    SET(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(nlohmann)
    SET(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    ADD_SUBDIRECTORY(${nlohmann_SOURCE_DIR} ${nlohmann_BINARY_DIR})
    SET(nlohmann_FOUND TRUE)
  endif()
endif()