#include "stdafx.h"
template <class T, template <typename ty, typename Al = std::allocator<ty>> class Collection = std::vector> class Array2d
{
    Collection<T> ar_;
    const size_t rows_;
    const size_t cols_;

public:
    Array2d(size_t rows, size_t cols) : rows_(rows), cols_(cols)
    {
        ar_.resize(rows_ * cols_);
    }

    T& operator()(size_t row, size_t col)
    {
        auto element = row * cols_ + col;
        return ar_[element];
    }
};

int main()
{
    Array2d<int> b(2, 3);
    Array2d<int, std::deque> b2(4, 5);

    b(0, 1) = 2;
    b2(0, 1) = 2;
    std::cout << b(0, 1) << std::endl;
    std::cout << b2(0, 1) << std::endl;
}
