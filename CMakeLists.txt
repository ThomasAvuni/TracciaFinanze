cmake_minimum_required(VERSION 3.22)

# --- CONFIGURAZIONE CROSS-PLATFORM VCPKG ---
# Questo blocco rileva il sistema operativo e imposta i percorsi corretti
if(WIN32)
    # Percorso per Windows (Assicurati che sia questo il tuo percorso)
    set(VCPKG_ROOT "C:/VCPKG/vcpkg")
    set(VCPKG_TRIPLET "x64-windows")
else()
    # Percorso per Linux (Fedora)
    set(VCPKG_ROOT "$ENV{HOME}/dev/vcpkg")
    set(VCPKG_TRIPLET "x64-linux")
endif()

# Impostazione del Toolchain (Deve stare PRIMA del comando project)
set(VCPKG_MANIFEST_MODE OFF)
set(CMAKE_TOOLCHAIN_FILE "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")

# Aiutiamo CMake a trovare i pacchetti nel triplet corretto
list(APPEND CMAKE_PREFIX_PATH "${VCPKG_ROOT}/installed/${VCPKG_TRIPLET}")

project(TracciaFinanze)

# Standard C++ moderno
set(CMAKE_CXX_STANDARD 26)


# --- RICERCA PACCHETTI ---
find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

# Ricerca Boost (proviamo prima la modalità Config, poi quella classica)
find_package(Boost CONFIG QUIET COMPONENTS uuid)
if(NOT Boost_FOUND)
    find_package(Boost REQUIRED COMPONENTS uuid)
endif()

# --- CONFIGURAZIONE IMGUI ---
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/imgui)

set(IMGUI_SOURCES
        ${IMGUI_DIR}/imgui.cpp
        ${IMGUI_DIR}/imgui_draw.cpp
        ${IMGUI_DIR}/imgui_tables.cpp
        ${IMGUI_DIR}/imgui_widgets.cpp
        ${IMGUI_DIR}/backends/imgui_impl_sdl2.cpp
        ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

# --- SORGENTI DEL PROGETTO ---
set(CORE_SOURCES
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

# --- ESEGUIBILE ---
add_executable(${PROJECT_NAME}
        main.cpp
        ${IMGUI_SOURCES}
        ${CORE_SOURCES}
)

# Definizioni per SDL
target_compile_definitions(${PROJECT_NAME} PRIVATE SDL_MAIN_HANDLED)

# --- INCLUDE DIRECTORIES ---
target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}
        ${IMGUI_DIR}
        ${IMGUI_DIR}/backends
        Core
)

# --- LINK LIBRARIES ---
target_link_libraries(${PROJECT_NAME} PRIVATE
        SDL2::SDL2
        OpenGL::GL
        nlohmann_json::nlohmann_json
        Boost::boost
        Boost::uuid
)