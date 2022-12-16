# CMakeList.txt : projet CMake pour Pathfinder, incluez la source et définissez
# la logique spécifique au projet ici.
#
cmake_minimum_required (VERSION 3.8)

project ("Pathfinder")

# Ajoutez une source à l'exécutable de ce projet.
add_executable (Pathfinder "Src/Main.cpp"  "Tools/DesignPatterns/Singleton.h" "Engine/Game/Game.h" "Engine/Game/Game.cpp" "Engine/Scene/Scene.h" "Engine/Scene/Scene.cpp" "Src/Scenes/DefaultScene.h" "Src/Scenes/DefaultScene.cpp" 
"Src/Scenes/SceneEnum.h" "Engine/Components/PhysicsComponent.h" "Engine/Components/InputComponent.h"  "Engine/Components/GraphicsComponent.h" "Tools/DesignPatterns/Composite.h" "Engine/GameObject/GameObject.h" "Src/GameObjects/UI/Button.h" 
"Src/Components/InputComponents/UI/ICButton.h" "Src/Components/PhysicsComponents/UI/PCButton.h" "Src/Components/PhysicsComponents/UI/PCButton.cpp" "Src/Components/InputComponents/UI/ICButton.h" 
"Src/Components/InputComponents/UI/ICButton.cpp" "Src/Components/GraphicsComponents/UI/GCButton.h" "Src/Components/GraphicsComponents/UI/GCButton.cpp" "Src/GameObjects/UI/Button.cpp" "Src/GameObjects/UI/PathButton.h" 
"Src/GameObjects/UI/PathButton.cpp" "Src/GameObjects/UI/Arrow.h" "Src/Components/GraphicsComponents/GCVoid.h" "Src/Components/GraphicsComponents/GCVoid.cpp" "Src/Components/InputComponents/ICVoid.h" "Src/Components/InputComponents/ICVoid.cpp"
"Src/Components/PhysicsComponents/PCVoid.h" "Src/Components/PhysicsComponents/PCVoid.cpp" "Src/Components/GraphicsComponents/UI/GCArrow.h" "Src/Components/GraphicsComponents/UI/GCArrow.cpp" "Src/GameObjects/UI/Arrow.cpp" "Tools/MathUtils.h" 
"Src/Pathfinder/Sources/Node.cpp" "Src/Pathfinder/Header/Node.h" "Src/Pathfinder/Header/Pathfinder.h"  "Src/Pathfinder/Header/DCS/DCSManhattan.h" "Src/Pathfinder/Header/DCS/DCSEuclidean.h" "Src/Pathfinder/Header/DCS/DCSChebyshev.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Pathfinder PROPERTY CXX_STANDARD 20)
endif()

# TODO: Ajoutez des tests et installez des cibles si nécessaire.
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(Pathfinder PRIVATE sfml-system sfml-network sfml-graphics sfml-window)