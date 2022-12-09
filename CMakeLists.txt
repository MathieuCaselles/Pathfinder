# CMakeList.txt : projet CMake pour Pathfinder, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.8)

project ("Pathfinder")

# Ajoutez une source à l'exécutable de ce projet.
add_executable (Pathfinder "Src/Main.cpp"  "Tools/DesignPatterns/Singleton.h" "Engine/Game/Game.h" "Engine/Game/Game.cpp" "Engine/Scene/Scene.h" "Engine/Scene/Scene.cpp" "Src/Scenes/DefaultScene.h" "Src/Scenes/DefaultScene.cpp"  "Src/Scenes/SceneEnum.h" "Engine/Components/PhysicsComponent.h" "Engine/Components/InputComponent.h"  "Engine/Components/GraphicsComponent.h" "Tools/DesignPatterns/Composite.h" "Engine/GameObject/GameObject.h" "Src/GameObjects/ExampleButton.h"  "Src/Components/InputComponents/ICExampleButton.h" "Src/Components/PhysicsComponents/PCExampleButton.h" "Src/Components/PhysicsComponents/PCExampleButton.cpp" "Src/Components/InputComponents/ICExampleButton.h" "Src/Components/InputComponents/ICExampleButton.cpp" "Src/Components/GraphicsComponents/GCExampleButton.h" "Src/Components/GraphicsComponents/GCExampleButton.cpp" "Src/GameObjects/ExampleButton.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Pathfinder PROPERTY CXX_STANDARD 20)
endif()

# TODO: Ajoutez des tests et installez des cibles si nécessaire.
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(Pathfinder PRIVATE sfml-system sfml-network sfml-graphics sfml-window)