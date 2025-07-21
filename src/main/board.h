#include <raylib.h>

#include <vector>
#include <cstdint>

enum CellValue
{
    White,
    Black,
    Ant
};

class Board
{
private:
    struct BoardSettings
    {
        uint32_t CellSize = 5;
        uint32_t Rows = 50;
        uint32_t Columns = 50;
    };

public:
    Board()
    {
        m_Cells.resize(m_Settings.Rows * m_Settings.Columns);
    }

    BoardSettings GetBoardSettings() const
    {
        return m_Settings;
    }
    void SetCell(CellValue new_value, uint32_t x, uint32_t y)
    {
        m_Cells[y * m_Settings.Rows + x] = new_value;
    }
    CellValue GetCell(uint32_t x, uint32_t y)
    {
        return m_Cells[y * m_Settings.Rows + x];
    }
private:
    BoardSettings m_Settings;
    std::vector<CellValue> m_Cells;
};
