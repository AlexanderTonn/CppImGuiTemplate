#ifndef RENDER_HPP
#define RENDER_HPP

#include <string>
#include <string_view>
#include <array>

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

    struct guiLabels
    {
        std::array<std::string, 4> menu = {"File", "Edit", "Help", "Exit"};
        std::array<std::string, 3> file = {"New", "Open", "Save"};
    };
    guiLabels labels;

    auto drawMenu() -> void;

public:
    void Draw(std::string_view label);
};

auto render(WindowClass &window_obj) -> void;

#endif // RENDER_HPP
