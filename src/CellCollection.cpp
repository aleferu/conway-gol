#include "CellCollection.hpp"
#include <algorithm>
#include "raylib.h"
#include <iostream>


CellCollection::CellCollection()  {
    std::fill(m_cells, m_cells + CELLCOUNT, false);
}


void CellCollection::setCellAlive(const int mouseX, const int mouseY) {
    const int row = mouseX / CELLSIZE;
    const int col = mouseY / CELLSIZE;
    m_cells[row * CELLINROW + col] = true;
}


void CellCollection::drawCells() const {
    for (int i = 0; i < CELLCOUNT; ++i) {
        if (m_cells[i]) DrawRectangle(i / CELLINROW * CELLSIZE, i % CELLINROW * CELLSIZE, CELLSIZE, CELLSIZE, WHITE);
    }
}
