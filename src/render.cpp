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

    init();

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
    if (ImGui::BeginMenuBar())
    {
        // FILE MENU
        if (ImGui::BeginMenu(_UIStr.menuBtns[szLanguageSelection].menuBar.at(0).c_str()))
        {
            if (ImGui::MenuItem(_UIStr.menuBtns[szLanguageSelection].fileOptions.at(0).c_str(), "Ctrl+N"))
            {
                std::cout << "New" << std::endl;
            }
            if (ImGui::MenuItem(_UIStr.menuBtns[szLanguageSelection].fileOptions.at(1).c_str(), "Ctrl+O"))
            {
                std::cout << "Open" << std::endl;
            }
            if (ImGui::MenuItem(_UIStr.menuBtns[szLanguageSelection].fileOptions.at(2).c_str(), "Ctrl+S"))
            {
                std::cout << "Save" << std::endl;
            }
            if (ImGui::MenuItem(_UIStr.menuBtns[szLanguageSelection].fileOptions.at(3).c_str(), "Ctrl+Shift+S"))
            {
                std::cout << "Save As.." << std::endl;
            }
            ImGui::EndMenu();
        }
        // EDIT MENU
        if (ImGui::BeginMenu(_UIStr.menuBtns[szLanguageSelection].menuBar.at(1).c_str()))
        {
            ImGui::EndMenu();
        }
        // HELP MENU
        if (ImGui::BeginMenu(_UIStr.menuBtns[szLanguageSelection].menuBar.at(2).c_str()))
        {
            if (ImGui::MenuItem(_UIStr.menuBtns[szLanguageSelection].helpOptions.at(0).c_str()))
            {
                std::cout << "About" << std::endl;
            }
            ImGui::Text(_UIStr.menuBtns[szLanguageSelection].helpOptions.at(1).c_str());
            ImGui::SameLine();
            _GUIFunc.drawComboBox(_UIStr.menuBtns[szLanguageSelection].helpOptions.at(1),
                                  _UIStr.cbEntries[szLanguageSelection].languages,
                                  szLanguageSelection,
                                  false);
            ImGui::EndMenu();
        }

        ImGui::EndMenuBar();
    }
}

auto WindowClass::init() -> void
{
    _UIStr.init();
}
