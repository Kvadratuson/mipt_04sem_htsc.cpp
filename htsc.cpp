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
void HTSC<T>::insert(const T& key)
{
    size_t i;
    i = hash_function(key) % m_size + 1;
    if (!m_table[i].f_is_busy) {
        m_table[i].f_is_busy = true;
        m_table[i].m_key = key;
    }
    else if (m_table[i].m_key != key) {
        while (m_table[i].i_link != 0) {
            i = m_table[i].i_link;
            if (m_table[i].m_key == key)
                return;
        }
        while (m_table[i_index].f_is_busy != false)
            --i_index;
        if (i_index == 0) {
            throw IS_FULL;
        } else {
            m_table[i_index].f_is_busy = true;
            m_table[i_index].m_key = key;
            m_table[i].i_link = i_index;
        }
    }
}

template <class T>
void HTSC<T>::erase(const T& key)
{
    size_t i;
    i = hash_function(key) % m_size + 1;
    if ((!m_table[i].f_is_busy) && (m_table[i].i_link == 0)) {
        throw NOT_FOUND;
    }
    else {
        while (i != 0) {
            if (m_table[i].m_key == key) {
                m_table[i].f_is_busy = false;
                m_table[i].m_key = T();
                if (i > i_index)
                    i_index = i;
                return;
            }
            i = m_table[i].i_link;
        }
        throw NOT_FOUND;
    }
}

template <class T>
bool HTSC<T>::find(const T& key)
{
    size_t i;
    i = hash_function(key) % m_size + 1;
    if ((!m_table[i].f_is_busy) && (m_table[i].i_link == 0)) {
        return false;
    }
    else {
        while (i != 0) {
            if (m_table[i].m_key == key)
                return true;
            i = m_table[i].i_link;
        }
        return false;
    }
}

template <class T>
HTSC<T>& HTSC<T>::operator=(const HTSC<T>& other)
{
    if (this != &other) {
        m_size = other.m_size;
        m_table = other.m_table;
        i_index = other.i_index;
    }
    return *this;
}
