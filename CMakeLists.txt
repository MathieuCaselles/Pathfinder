# CMakeList.txt : projet CMake pour Pathfinder, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.8)

project ("Pathfinder")

# Ajoutez une source à l'exécutable de ce projet.
add_executable (Pathfinder "Src/Main.cpp"  "Tools/DesignPatterns/Singleton.h"    "Engine/Game/Game.h" "Engine/Game/Game.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Pathfinder PROPERTY CXX_STANDARD 20)
endif()

# TODO: Ajoutez des tests et installez des cibles si nécessaire.
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(Pathfinder PRIVATE sfml-system sfml-network sfml-graphics sfml-window)