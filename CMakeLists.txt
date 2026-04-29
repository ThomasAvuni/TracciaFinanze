cmake_minimum_required(VERSION 4.2)
set(VCPKG_MANIFEST_MODE ON)
project(TracciaFinanze)

set(CMAKE_CXX_STANDARD 26)

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)

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
)

add_executable(TracciaFinanze
        main.cpp
        ${IMGUI_SOURCES}
)

target_compile_definitions(${PROJECT_NAME} PRIVATE SDL_MAIN_HANDLED)

target_include_directories(${PROJECT_NAME} PRIVATE
        ${IMGUI_DIR}              # ← imgui.h, imgui_internal.h ecc.
        ${IMGUI_DIR}/backends     # ← imgui_impl_sdl2.h, imgui_impl_opengl3.h
        ${SDL2_INCLUDE_DIRS}      # ← SDL.h ecc.
)

# --- Link ---
target_link_libraries(${PROJECT_NAME} PRIVATE
        ${SDL2_LIBRARIES}
        OpenGL::GL
        nlohmann_json::nlohmann_json
)