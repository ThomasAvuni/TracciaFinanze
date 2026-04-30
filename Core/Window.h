//
// Created by Thomas on 26/04/2026.
//

#ifndef TRACCIAFINANZE_WINDOW_H
#define TRACCIAFINANZE_WINDOW_H

struct SDL_Window;
typedef void *SDL_GLContext;


#include <string>

class Window {
public:

    /**
     *
     * @param WindowName
     * @param Width
     * @param Height
     */
    Window(const std::string& WindowName, int Width, int Height, bool EnableVSync = true);

    void SetVSyncEnabled(bool enabled) {m_EnableVSync = enabled;}

    [[nodiscard]] SDL_Window *GetWindowHandle() const {return m_pWindowHandle;}
    [[nodiscard]] SDL_GLContext GetGLContext() const {return m_GLContext;}
    [[nodiscard]] int GetWidth() const {return m_Width;}
    [[nodiscard]] int GetHeight() const {return m_Height;}

private:
//?---------------FUNCS--------------------
    void InitSDL();
    void InitImGui();
//?---------------VARS--------------------
    std::string m_WindowName;
    int m_Width;
    int m_Height;
    bool m_EnableVSync = true;

    SDL_Window *m_pWindowHandle;
    SDL_GLContext m_GLContext;
};


#endif //TRACCIAFINANZE_WINDOW_H
