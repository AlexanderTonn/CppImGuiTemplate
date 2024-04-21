#include "guiStrings.hpp"

guiStrings _UIStr;

/**
 * @brief init the arrays
 * @note if the arrays are empty it's possible the some imGui Functions will causing a exception
 */
auto guiStrings::init() -> void
{
    menuBtns[ENG].menuBar = {"File", "Edit", "Help"};
    menuBtns[GER].menuBar = {"Datei", "Bearbeiten", "Hilfe"};

    menuBtns[ENG].fileOptions = {"New", "Open", "Save", "Save As"};
    menuBtns[GER].fileOptions = {"Neu", "Öffnen", "Speichern", "Speichern unter"};

    menuBtns[ENG].helpOptions = {"About", "Language"};
    menuBtns[GER].helpOptions = {"Über", "Sprache"};

    cbEntries[ENG].languages = {"English", "German"};
    cbEntries[GER].languages = {"Englisch", "Deutsch"};
}
