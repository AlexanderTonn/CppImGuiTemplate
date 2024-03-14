#include <iostream>

#include <fmt/format.h>
#include <imgui.h>
#include <imgui_stdlib.h>
#include <implot.h>
#include <string>

#include "render.hpp"

/**
 * @brief Main Drawfunction for ImGui
 *
 * @param label
 */
void WindowClass::Draw(std::string_view label)
{
    // ##########
    // Backend stuff
    // ##########

    // ##########
    // Frontend stuff
    // ##########
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::Begin(label.data(), nullptr, window_flags);
    ImGui::SetCursorPos(ImVec2(0.0F, 0.0F));

    drawMenu();

    ImGui::Text("Hello, world!");

    ImGui::End();
}

/**
 * @brief Render the ImGui Window
 *
 * @param window_obj
 */
auto render(WindowClass &window_obj) -> void
{
    window_obj.Draw("Template");
}

auto WindowClass::drawMenu() -> void
{
    if(ImGui::BeginMenuBar())
    {
        // FILE MENU
        if (ImGui::BeginMenu(labels.menu[0].c_str()))
        {
            if (ImGui::MenuItem(labels.file[0].c_str(), "Ctrl+N"))
            {
                std::cout << "New" << std::endl;
            }
            if (ImGui::MenuItem(labels.file[1].c_str(), "Ctrl+O"))
            {
                std::cout << "Open" << std::endl;
            }
            if (ImGui::MenuItem(labels.file[2].c_str(), "Ctrl+S"))
            {
                std::cout << "Save" << std::endl;
            }
            if (ImGui::MenuItem(labels.file[2].c_str(), "Ctrl+Shift+S"))
            {
                std::cout << "Save As.." << std::endl;
            }
            ImGui::Separator();
            if (ImGui::MenuItem(labels.menu[3].c_str(), "Alt+F4"))
            {
                std::cout << "Exit" << std::endl;
            }
            ImGui::EndMenu();
        }
        // EDIT MENU
        if (ImGui::BeginMenu(labels.menu[1].c_str()))
        {
            ImGui::EndMenu();
        }
        // HELP MENU
        if (ImGui::BeginMenu(labels.menu[2].c_str()))
        {
            ImGui::EndMenu();
        }

        ImGui::EndMenuBar();
    }


}
