cmake_minimum_required(VERSION 3.24)
project(Labor5_DHG_official)

set(CMAKE_CXX_STANDARD 20)

add_executable(Labor5_DHG_official main.cpp Domain/Elektroscooter.cpp Domain/Elektroscooter.h Controller/Controller.cpp Controller/Controller.h Repository/AbstractRepository.h Repository/CSV_File_Repo.h Repository/CSV_File_Repo.cpp Repository/ElektroRepo.h Repository/ElektroRepo.cpp UI/ElektroUI.h UI/ElektroUI.cpp Tests/Test.h Tests/Test.cpp)
