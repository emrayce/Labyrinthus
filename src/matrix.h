#ifndef MATRIX_H
#define MATRIX_H

template<class T, size_t rows, size_t cols>
class Matrix
{
    std::array<T, rows * cols> m_Data;
public:
    T& operator()(size_t y, size_t x)
    {
        return m_Data[y * cols + x];
    }

    // more methods go here
}

#endif
