cmake_minimum_required(VERSION 3.20)

project(CppDiplomProject)



# TODO: Define by your own needs:
#set(OPENSSL_ROOT_DIR "C:\\Program Files\\OpenSSL-Win64")

#set(BOOST_ROOT "C:\\Boost")

set(libpqxx_DIR "libpqxx")
set(Share_DIR "../share")
set(Parser_source_ini ${Share_DIR}/parser.cpp)
set(Parser_header_ini ${Share_DIR}/parser.h)
set(HTML_source ${Share_DIR}/htmlhelper.cpp)
set(HTML_header ${Share_DIR}/htmlhelper.h)
set(DataBase_source ${Share_DIR}/database.cpp)
set(DataBase_header ${Share_DIR}/database.h)


# TODO: If you are running on Windows below 10, change this:

#add_compile_definitions(_WIN32_WINNT=0x0A01)



# Boost:
find_package(Boost 1.80.0 REQUIRED COMPONENTS url filesystem system regex locale program_options chrono atomic thread)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find Boost")
endif()


# PQXX
set(PostgreSQL_ADDITIONAL_VERSIONS "16")

add_subdirectory(${libpqxx_DIR} libpqxx-build) 


# OpenSSL
find_package(OpenSSL REQUIRED)

add_subdirectory(spider)

add_subdirectory(http_server)
