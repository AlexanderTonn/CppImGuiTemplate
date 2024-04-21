#ifndef RENDER_HPP
#define RENDER_HPP

#include <string>
#include <string_view>
#include <array>

#include "guiStrings.hpp"
#include "util.hpp"

#ifdef _WIN32
#include <Windows.h>
#endif

class WindowClass
{
private:
    constexpr static auto window_flags = ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoDecoration |
                                         ImGuiWindowFlags_AlwaysVerticalScrollbar | ImGuiWindowFlags_NoMove |
                                         ImGuiWindowFlags_MenuBar;
    constexpr static auto window_size = ImVec2(1280.0F, 720.0F);
    constexpr static auto window_pos = ImVec2(0.0F, 0.0F);

    size_t szLanguageSelection = 0; // 0 = ENG, 1 = GER

    auto drawMenu() -> void;
    auto init() -> void;

    util _GUIFunc;

public:
    void Draw(std::string_view label);
};

auto render(WindowClass &window_obj) -> void;

#endif // RENDER_HPP
