#include "CellCollection.hpp"
#include <algorithm>
#include "raylib.h"
#include <iostream>


CellCollection::CellCollection()  {
    m_cells = new bool[CELLCOUNT];
    m_aux = new bool[CELLCOUNT];
    std::fill(m_cells, m_cells + CELLCOUNT, false);
}


CellCollection::~CellCollection() {
    delete[] m_cells;
    delete[] m_aux;
}


void CellCollection::setCellAlive(const int mouseX, const int mouseY) {
    const int row = mouseX / CELLSIZE;
    const int col = mouseY / CELLSIZE;
    m_cells[row * CELLSINROW + col] = true;
}


void CellCollection::setCellDead(const int mouseX, const int mouseY) {
    const int row = mouseX / CELLSIZE;
    const int col = mouseY / CELLSIZE;
    m_cells[row * CELLSINROW + col] = false;
}


void CellCollection::drawCells() const {
    for (int i = 0; i < CELLCOUNT; ++i) {
        if (m_cells[i]) DrawRectangle(i / CELLSINROW * CELLSIZE, i % CELLSINROW * CELLSIZE, CELLSIZE, CELLSIZE, WHITE);
    }
}


/**
 * Any live cell with two or three live neighbours survives.
 * Any dead cell with three live neighbours becomes a live cell.
 * All other live cells die in the next generation. Similarly, all other dead cells stay dead.
 */
void CellCollection::computeNextCycle() {
    static int neighbours[8][2] = {{-1, -1},   { 0, -1},   {+1, -1},
                                   {-1,  0}, /*{ 0,  0},*/ {+1,  0},
                                   {-1, +1},   { 0, +1},   {+1, +1}};
    for (int i = 0; i < CELLCOUNT; ++i) {
        int aliveCounter = 0;
        int row = i / CELLSINROW;
        int col = i % CELLSINROW;
        for (int* offset: neighbours)
            if (shouldCellCount(row + offset[0], col + offset[1]))
                ++aliveCounter;
        if ((m_cells[i] && (aliveCounter == 2 || aliveCounter == 3)) || (!m_cells[i] && aliveCounter == 3)) {
            m_aux[i] = true;
        }
        else {
            m_aux[i] = false;
        }
    }
    bool* temp = m_aux;
    m_aux = m_cells;
    m_cells = temp;
}


void CellCollection::clearCells() {
    std::fill(m_cells, m_cells + CELLCOUNT, false);
}


inline bool CellCollection::shouldCellCount(const int row, const int col) const {
    return row >= 0 && col >= 0 && row < CELLSINROW && col < CELLSINROW && m_cells[row * CELLSINROW + col];
}
