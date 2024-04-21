#ifndef UTIL_HPP
#define UTIL_HPP

#include <array>
#include <imgui.h>
#include <imgui_stdlib.h>
#include <string>

class util
{
public:
    template <size_t size>
    auto drawComboBox(std::string sCbLabel,
                            std::array<std::string, size> sItems,
                            size_t &szCurrentItem,
                            bool xLabelOn) -> int
    {

        if (!xLabelOn)
            sCbLabel = "###" + sCbLabel;

        if (ImGui::BeginCombo(sCbLabel.c_str(), sItems[szCurrentItem].c_str()))
        {
            for (size_t i = 0; i < sItems.size(); i++)
            {
                bool isSelected = (szCurrentItem == i);
                if (ImGui::Selectable(sItems[i].c_str(), isSelected))
                {
                    szCurrentItem = i;
                }
                if (isSelected)
                {
                    ImGui::SetItemDefaultFocus();
                }
            }
            ImGui::EndCombo();
        }
        return static_cast<int>(szCurrentItem);
    }
};

#endif // UTIL_HPP
