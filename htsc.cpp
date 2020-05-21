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

template <class T>
void HTSC<T>::insert(const T& data)
{
    size_t i;
    i = hash_function(data) % m_size + 1;
    if (!m_table[i].f_is_busy) {
        m_table[i].f_is_busy = true;
        m_table[i].m_data = data;
    }
    else if (m_table[i].m_data != data) {
        while (m_table[i].i_link != 0) {
            i = m_table[i].i_link;
            if (m_table[i].m_data == data)
                return;
        }
        while (m_table[i_index].f_is_busy != false)
            --i_index;
        if (i_index == 0) {
            throw IS_FULL;
        } else {
            m_table[i_index].f_is_busy = true;
            m_table[i_index].m_data = data;
            m_table[i].i_link = i_index;
        }
    }
}