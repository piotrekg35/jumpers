# CMakeList.txt: projekt CMake dla elementu proba, dołącz źródło i zdefiniuj
# tutaj logikę specyficzną dla projektu.
#
cmake_minimum_required (VERSION 3.8)

# Dodaj źródło do pliku wykonywalnego tego projektu.
add_executable (jumpers "main.cpp" "main.h" "Figure.h" "Point.h" "Point.cpp"  "Board.h" "Board.cpp" "Figure.cpp" "Game.h" "Game.cpp" )

# TODO: Dodaj testy i zainstaluj elementy docelowe w razie potrzeby.