cmake_minimum_required(VERSION 3.22)

# Forza il toolchain PRIMA di project
set(VCPKG_MANIFEST_MODE OFF)
set(CMAKE_TOOLCHAIN_FILE "$ENV{HOME}/dev/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

# Aiutiamo CMake 4.2 a trovare i file di configurazione di vcpkg
list(APPEND CMAKE_PREFIX_PATH "$ENV{HOME}/dev/vcpkg/installed/x64-linux")

project(TracciaFinanze)

set(CMAKE_CXX_STANDARD 26)

# --- Ricerca Pacchetti ---
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

# Proviamo prima la modalità moderna CONFIG, se fallisce usiamo quella classica
find_package(Boost CONFIG QUIET COMPONENTS uuid)
if(NOT Boost_FOUND)
    find_package(Boost REQUIRED COMPONENTS uuid)
endif()



set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/imgui)

set(IMGUI_SOURCES
        ${IMGUI_DIR}/imgui.cpp
        ${IMGUI_DIR}/imgui_draw.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp
        ${IMGUI_DIR}/backends/imgui_impl_sdl2.cpp
        ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
        Core/Window.cpp
        Core/Window.h
        Core/Application.cpp
        Core/Application.h
        Core/Component.cpp
        Core/Component.h
        Core/ComponentStack.cpp
        Core/ComponentStack.h
        Core/base.h
        Core/Components/AddExpenseComponent.cpp
        Core/Components/AddExpenseComponent.h
        Core/ExpensesManager.cpp
        Core/ExpensesManager.h
        Core/ImGuiLayer.cpp
        Core/ImGuiLayer.h
        Core/Theme.h
        Core/Components/ExpensesView.cpp
        Core/Components/ExpensesView.h
        Core/Components/SingleExpenseView.cpp
        Core/Components/SingleExpenseView.h
)

add_executable(TracciaFinanze
        main.cpp
        ${IMGUI_SOURCES}
)

target_compile_definitions(${PROJECT_NAME} PRIVATE SDL_MAIN_HANDLED)

target_include_directories(${PROJECT_NAME} PRIVATE
        ${IMGUI_DIR}
        ${IMGUI_DIR}/backends
        # Non serve Boost_INCLUDE_DIRS se linki Boost::boost
)

# --- Link ---
target_link_libraries(${PROJECT_NAME} PRIVATE
        SDL2::SDL2
        OpenGL::GL
        nlohmann_json::nlohmann_json
        Boost::boost
        Boost::uuid
)