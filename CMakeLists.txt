cmake_minimum_required(VERSION 3.17)
project(PlatformerGame)


add_subdirectory(3rd_party/Box2D-cmake)
set(CMAKE_CXX_STANDARD 20)
set(SFML_STATIC_LIBRARIES TRUE)
set (EIGEN_DIR "C:/mingw-w64/x86_64-8.1.0-posix-seh-rt_v6-rev0/mingw64/SFML/lib/cmake/eigen-3.3.9")


include_directories(${EIGEN_DIR})
include_directories(headers F:/lib/SFML/include)

find_package(SFML 2.5 COMPONENTS system window graphics)
find_package(Eigen 3.3.9 QUIET)









add_executable(PlatformerGame main.cpp Engine/GameEngine.h Engine/GameEngine.cpp object/Hero.h object/Hero.cpp object/Enemy.h object/Enemy.cpp object/GameObject.h object/GameObject.cpp object/PhysicsObject.h object/PhysicsObject.cpp visual/Menu.h visual/Menu.cpp event/eventController.h event/eventController.cpp Engine/settings.h Engine/settings.cpp scene/scene.h scene/scene.cpp object/Animation.h object/Animation.cpp level/GameLevel.h level/GameLevel.cpp)
target_link_libraries(PlatformerGame sfml-system sfml-window sfml-graphics tobanteGaming::Box2D)