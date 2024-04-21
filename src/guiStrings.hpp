#ifndef GUISTRINGS_HPP
#define GUISTRINGS_HPP

#include <string>
#include <array>

enum languages
{
    ENG,
    GER
};

class guiStrings
{
    public:
    struct menuButtons
    {
        std::array<std::string, 3> menuBar;
        std::array<std::string, 4> fileOptions;
        std::array<std::string, 3> editOptions;
        std::array<std::string, 3> helpOptions;
    };
    struct comboBoxEntries
    {
        std::array<std::string, 2> languages;
    };

    std::array<menuButtons, sizeof(languages)> menuBtns ;
    std::array<comboBoxEntries, sizeof(languages)> cbEntries;

    auto init() -> void;

};

extern guiStrings _UIStr;

#endif // GUISTRINGS_HPP
