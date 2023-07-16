#ifndef CELLCOLLECTION_HPP
#define CELLCOLLECTION_HPP


class CellCollection
{
public:
    CellCollection();
    void setCellAlive(const int row, const int col);
    void drawCells() const;
    
private:
    static inline const int CELLINROW = 100;
    static inline const int CELLCOUNT = CELLINROW * CELLINROW;
    static inline const int CELLSIZE = 8;
    bool m_cells[CELLCOUNT];
};


#endif // CELLCOLLECTION_HPP
