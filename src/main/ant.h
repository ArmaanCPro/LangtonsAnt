#include "board.h"

#include <iostream>

class Ant
{
private:
    struct DirectionalMovement
    {
        enum class Direction
        {
            North, South, East, West
        };

        DirectionalMovement() = default;
        DirectionalMovement(Direction dir)
            :
            dir(dir)
        {}

        Direction GetCurrentDirection()
        {
            return dir;
        }

        void TurnClockwise()
        {
            switch (dir)
            {
            case Direction::North:
                dir = Direction::East;
                break;
            case Direction::South:
                dir = Direction::West;
                break;
            case Direction::East:
                dir = Direction::South;
                break;
            case Direction::West:
                dir = Direction::North;
                break;
            }
        }
        void TurnCounterclockwise()
        {
            switch (dir)
            {
            case Direction::North:
                dir = Direction::West;
                break;
            case Direction::South:
                dir = Direction::East;
                break;
            case Direction::East:
                dir = Direction::North;
                break;
            case Direction::West:
                dir = Direction::South;
                break;
            }
        }

    private:
        Direction dir = Direction::North;
    };
public:
    Ant(uint32_t xLoc, uint32_t yLoc)
        :
        m_XLoc(xLoc), m_YLoc(yLoc)
    {}
    Ant(uint32_t xLoc, uint32_t yLoc, DirectionalMovement::Direction dir)
        :
        m_XLoc(xLoc), m_YLoc(yLoc),
        m_Direction(dir)
    {}

    void Update(Board& brd)
    {
        auto currentCell = brd.GetCell(m_XLoc, m_YLoc);
        switch (currentCell)
        {
        case CellValue::White:
            brd.SetCell(CellValue::Black, m_XLoc, m_YLoc);
            //m_Direction -= 90;
            m_Direction.TurnClockwise();
            break;

        case CellValue::Black:
            brd.SetCell(CellValue::White, m_XLoc, m_YLoc);
            //m_Direction += 90;
            m_Direction.TurnCounterclockwise();
            break;

        default:
            std::cerr << "Ant movement does not support this cell type" << std::endl;
        }

        // movement for next frame

        auto currentDir = m_Direction.GetCurrentDirection();
        switch (currentDir)
        {
        case DirectionalMovement::Direction::North:
            m_YLoc++;
            break;
        case DirectionalMovement::Direction::South:
            m_YLoc--;
            break;
        case DirectionalMovement::Direction::East:
            m_XLoc++;
            break;
        case DirectionalMovement::Direction::West:
            m_XLoc--;
            break;
        }

        /*
        if (m_Direction % 180 == 0) // horizontal movement
        {
            if (m_Direction % 360 == 0) // move right
            {
                m_Direction = 0;
                m_XLoc++;
            }
            else // move left
            {
                m_Direction = 180;
                m_XLoc--;
            }
        }
        else // vertical movement
        {
            if (m_Direction < 0) // move down
            {
                m_Direction = -90;
                m_YLoc--;
            }
            else // move up
            {
                m_Direction = 90;
                m_YLoc++;
            }
        }
        */
    }

private:
    //uint8_t m_Direction = 0; // consider making this a different data type
    DirectionalMovement m_Direction;
    uint32_t m_XLoc;
    uint32_t m_YLoc;
};
