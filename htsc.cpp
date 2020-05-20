#include "htsc.hpp"

#include <string>

template class HTSC<std::string>;

template <class T>
HTSC<T>::HTSC()
{
    m_size = c_default_size;
    m_table.resize(m_size + 1);
    i_index = m_size;
}

template <class T>
HTSC<T>::HTSC(std::size_t size)
{
    m_size = size;
    m_table.resize(m_size + 1);
    i_index = m_size;
}

template <class T>
HTSC<T>::HTSC(const HTSC<T>& other)
{
    m_size = other.m_size;
    m_table = other.m_table;
    i_index = other.i_index;
}
