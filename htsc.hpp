#ifndef HTSC_CPP_HTSC_HPP
#define HTSC_CPP_HTSC_HPP

#include <iostream>
#include <vector>

template <class T>
class HTSC
{
public:
    HTSC();
    HTSC(std::size_t size);
    HTSC(const HTSC<T>& other);

    friend std::ostream& operator<<(std::ostream& out_stream, const HTSC<T>& hash_table)
    {
        out_stream << "Size = " << hash_table.m_size
                   << "        "
                   << "Index = " << hash_table.i_index << std::endl;
        for (std::size_t i = 1; i <= hash_table.m_size; ++i)
            out_stream << i << ":        " << hash_table.m_table[i] << std::endl;
        return out_stream;
    }

private:
    const std::size_t c_default_size = 10;

    std::size_t m_size;
    std::vector<T> m_table;
    std::size_t i_index;
};

#endif /* HTSC_CPP_HTSC_HPP */
