#ifndef HTSC_CPP_HTSC_HPP
#define HTSC_CPP_HTSC_HPP

#include <functional>
#include <iostream>
#include <vector>

template <class T>
class HTSC
{
public:
    enum ErrorCode
    {
        IS_FULL = 2,
        NOT_FOUND
    };

    HTSC();
    HTSC(std::size_t size);
    HTSC(const HTSC<T>& other);

    void insert(const T& data);
    void erase(const T& data);
    bool find(const T& data);

    HTSC& operator=(const HTSC& other);

    friend std::ostream& operator<<(std::ostream& out_stream, const HTSC<T>& hash_table)
    {
        out_stream << "Size = " << hash_table.m_size
                   << "\t\t"
                   << "Index = " << hash_table.i_index << std::endl;
        for (std::size_t i = 1; i <= hash_table.m_size; ++i)
            out_stream << i << ":\t\t" << hash_table.m_table[i] << std::endl;
        return out_stream;
    }

    friend std::ostream& operator<<(std::ostream& out_stream, const ErrorCode& error_code)
    {
        switch(error_code) {
            case(IS_FULL):
                out_stream << "Hash table is full";
                break;
            case(NOT_FOUND):
                out_stream << "Element is not found in hash table";
                break;
        }
        return out_stream;
    }

private:
    std::hash<T> hash_function;

    struct Element
    {
        bool f_is_busy;
        T m_data;
        std::size_t i_link;

        friend std::ostream& operator<<(std::ostream& out_stream, const Element& element)
        {
            out_stream << "Is busy = " << std::boolalpha << element.f_is_busy << std::noboolalpha
                       << "\t\t"
                       << "Link = " << element.i_link
                       << "\t\t"
                       << "Data = " << element.m_data;
            return out_stream;
        }
    };

    const std::size_t c_default_size = 10;

    std::size_t m_size;
    std::vector<Element> m_table;
    std::size_t i_index;
};

#endif /* HTSC_CPP_HTSC_HPP */
