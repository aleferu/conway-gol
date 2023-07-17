#ifndef CELLCOLLECTION_HPP
#define CELLCOLLECTION_HPP


class CellCollection
{
public:
    CellCollection();
    ~CellCollection();
    void setCellAlive(const int row, const int col);
    void setCellDead(const int row, const int col);
    void drawCells() const;
    void computeNextCycle();
    void clearCells();
    
private:
    static inline const int CELLSINROW = 100;
    static inline const int CELLCOUNT = CELLINROW * CELLSINROW;
    static inline const int CELLSIZE = 8;
    bool* m_cells;
    bool* m_aux;
    inline bool shouldCellCount(const int row, const int col) const;
};


#endif // CELLCOLLECTION_HPP
