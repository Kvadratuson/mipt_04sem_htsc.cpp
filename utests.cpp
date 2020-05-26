#include "htsc.hpp"

#include <string>

const std::size_t TEST_DATA1_SIZE = 10;
const std::size_t TEST_DATA2_SIZE = 26;
const std::size_t TEST_DATA3_SIZE = 8;
const std::string test_data1[] =
{
    "mifihoiwikioguhoponjoavakecewbijasuminehjaruwadorhiftigirhozavab",
    "boavalidigsetuwoimufoowjinurtarjuijdipfegpegijoiczuhasezfupterob",
    "woliokenirkumhusiakmuhbozaocebpuihipijpoljaturozujpuezuvupipajni",
    "bifriunamofecmihlodrucpannuzegejugilujlelfoagiveogerelibihugsamu",
    "namoijziuwloutisewikkamdafijzetivzavuzerihicvasecetgizgiekohobra",
    "rarasapezuwezuparepsarnonezsucjotolapelzokolzusmimalelpurpewukfo",
    "famkivelhoekvamopedejzuwzevgufdahkaucaigivesralicbendoupevoucipi",
    "fazazerovbimzoravkinogmegujegelobujsuzbuotugemuopfivervoivbazumi",
    "zopsilamtaizfusijeluzantabofdiformewkapzanoavalowuvsolejunomihip",
    "ribjigijwudbupapuhorahzomcacozsuipukokzaokuedmaocopeicdoihfuumiu"
};
const std::string test_data2[] =
{
    "a",
    "b",
    "c",
    "d",
    "e",
    "f",
    "g",
    "h",
    "i",
    "j",
    "k",
    "l",
    "m",
    "n",
    "o",
    "p",
    "q",
    "r",
    "s",
    "t",
    "u",
    "v",
    "w",
    "x",
    "y",
    "z"
};
const std::vector<bool> test_data3[] =
{
    {false, false, false},
    {false, false, true},
    {false, true, false},
    {false, true, true},
    {true, false, false},
    {true, false, true},
    {true, true, false},
    {true, true, true}
};

class Test
{
public:
    Test() = default;
    Test(const std::vector<bool>& bits): m_bits(bits) {};

    friend std::ostream& operator<<(std::ostream& out_stream, const Test& test)
    {
        for (std::size_t i = 0; i < test.m_bits.size(); ++i)
            out_stream << std::boolalpha << test.m_bits[i] << std::noboolalpha << " ";
        return out_stream;
    }

    bool operator==(const Test& rhs)
    {
        if (m_bits.size() != rhs.m_bits.size())
            return false;
        for (std::size_t i = 0; i < m_bits.size(); ++i)
            if (m_bits[i] != rhs.m_bits[i])
                return false;
        return true;
    }
    bool operator!=(const Test& rhs)
    {
        if (m_bits.size() != rhs.m_bits.size())
            return true;
        for (std::size_t i = 0; i < m_bits.size(); ++i)
            if (m_bits[i] != rhs.m_bits[i])
                return true;
        return false;
    }

    std::vector<bool> m_bits;
};

namespace std
{
    template <> struct hash<Test>
    {
        std::size_t operator()(Test const& test) const noexcept
        {
            return std::hash<std::vector<bool>>{}(test.m_bits);
        }
    };
}

int main()
{
    HTSC<std::string> *hash_tables[5];
    HTSC<Test> *hash_table;

    /* Construct() */
    try {
        hash_tables[0] = new HTSC<std::string>();
    }
    catch(const std::exception& exception) {
        std::cerr << "Construct(): FAILED (" << exception.what() << ")" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "Construct(): PASSED" << std::endl;

    /* Construct(size) */
    try {
        hash_tables[1] = new HTSC<std::string>(TEST_DATA1_SIZE);
    }
    catch(const std::exception& exception) {
        std::cerr << "Construct(size): FAILED (" << exception.what() << ")" << std::endl;
        exit(EXIT_FAILURE);
    }
    try {
        hash_tables[2] = new HTSC<std::string>(TEST_DATA2_SIZE);
    }
    catch(const std::exception& exception) {
        std::cerr << "Construct(size): FAILED (" << exception.what() << ")" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "Construct(size): PASSED" << std::endl;

    /* Insert("string") */
    try {
        hash_tables[0]->insert("0");
        hash_tables[0]->insert("1");
        hash_tables[0]->insert("2");
        hash_tables[0]->insert("3");
        hash_tables[0]->insert("4");
        hash_tables[0]->insert("5");
        hash_tables[0]->insert("6");
        hash_tables[0]->insert("7");
        hash_tables[0]->insert("8");
        hash_tables[0]->insert("9");
    }
    catch (const HTSC<std::string>::ErrorCode& exception) {
        std::cerr << "Insert(\"string\"): FAILED (" << exception << ")" << std::endl;
        exit(exception);
    }
    catch (const std::exception& exception) {
        std::cerr << "Insert(\"string\"): FAILED (" << exception.what() << ")" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "Insert(\"string\"): PASSED" << std::endl;

    /* Insert(std::string) */
    try {
        for (std::size_t i = 0; i < TEST_DATA2_SIZE; ++i) {
            hash_tables[2]->insert(test_data2[i]);
        }
        hash_tables[2]->insert(test_data2[22]);
    }
    catch (const HTSC<std::string>::ErrorCode& exception) {
        std::cerr << "Insert(std::string): FAILED (" << exception << ")" << std::endl;
        exit(exception);
    }
    catch (const std::exception& exception) {
        std::cerr << "Insert(std::string): FAILED (" << exception.what() << ")" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "Insert(std::string): PASSED" << std::endl;

    /* Insert(...)->IS_FULL */
    try {
        hash_tables[2]->insert(test_data1[0]);
    }
    catch (const HTSC<std::string>::ErrorCode& exception) {
        if (exception != HTSC<std::string>::IS_FULL) {
            std::cerr << "Insert(...)->IS_FULL: FAILED (" << exception << ")" << std::endl;
            exit(exception);
        }
    }
    catch (const std::exception& exception) {
        std::cerr << "Insert(...)->IS_FULL: FAILED (" << exception.what() << ")" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "Insert(...)->IS_FULL: PASSED" << std::endl;

    /* Construct(copy) */
    try {
        hash_tables[3] = new HTSC<std::string>(*hash_tables[2]);
        hash_tables[4] = new HTSC<std::string>(*hash_tables[0]);
    }
    catch (const std::exception& exception) {
        std::cerr << "Construct(copy): FAILED (" << exception.what() << ")" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "Construct(copy): PASSED" << std::endl;

    /* Erase("string") */
    try {
        hash_tables[4]->erase("0");
        hash_tables[4]->erase("2");
        hash_tables[4]->erase("4");
        hash_tables[4]->erase("6");
        hash_tables[4]->erase("8");
    }
    catch (const HTSC<std::string>::ErrorCode& exception) {
        std::cerr << "Erase(\"string\"): FAILED (" << exception << ")" << std::endl;
        exit(exception);
    }
    catch (const std::exception& exception) {
        std::cerr << "Erase(\"string\"): FAILED (" << exception.what() << ")" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "Erase(\"string\"): PASSED" << std::endl;

    /* Erase(std::string) */
    try {
        for (std::size_t i = 0; i < TEST_DATA2_SIZE; i += 2) {
            hash_tables[3]->erase(test_data2[i]);
        }
        hash_tables[3]->erase(test_data2[9]);
    }
    catch (const HTSC<std::string>::ErrorCode& exception) {
        std::cerr << "Erase(std::string): FAILED (" << exception << ")" << std::endl;
        exit(exception);
    }
    catch (const std::exception& exception) {
        std::cerr << "Erase(std::string): FAILED (" << exception.what() << ")" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "Erase(std::string): PASSED" << std::endl;

    /* Erase(...)->NOT_FOUND */
    try {
        hash_tables[3]->erase(test_data2[0]);
    }
    catch (const HTSC<std::string>::ErrorCode& exception) {
        if (exception != HTSC<std::string>::NOT_FOUND) {
            std::cerr << "Erase(...)->NOT_FOUND: FAILED (" << exception << ")" << std::endl;
            exit(exception);
        }
    }
    catch (const std::exception& exception) {
        std::cerr << "Erase(...)->NOT_FOUND: FAILED (" << exception.what() << ")" << std::endl;
        exit(EXIT_FAILURE);
    }
    try {
        hash_tables[3]->erase(test_data2[9]);
    }
    catch (const HTSC<std::string>::ErrorCode& exception) {
        if (exception != HTSC<std::string>::NOT_FOUND) {
            std::cerr << "Erase(...)->NOT_FOUND: FAILED (" << exception << ")" << std::endl;
            exit(exception);
        }
    }
    catch (const std::exception& exception) {
        std::cerr << "Erase(...)->NOT_FOUND: FAILED (" << exception.what() << ")" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "Erase(...)->NOT_FOUND: PASSED" << std::endl;

    /* Find("string") */
    try {
        if (hash_tables[4]->find("0")
            || (!hash_tables[4]->find("1"))
            || hash_tables[4]->find("2")
            || (!hash_tables[4]->find("3"))
            || hash_tables[4]->find("4")
            || (!hash_tables[4]->find("5"))
            || hash_tables[4]->find("6")
            || (!hash_tables[4]->find("7"))
            || hash_tables[4]->find("8")
            || (!hash_tables[4]->find("9")))
        {
            std::cerr << "Find(\"string\"): FAILED" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    catch (const std::exception& exception) {
        std::cerr << "Find(\"string\"): FAILED (" << exception.what() << ")" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "Find(\"string\"): PASSED" << std::endl;

    /* Find(std::string) */
    try {
        for (std::size_t i = 0; i < TEST_DATA2_SIZE; i += 2) {
            if (hash_tables[3]->find(test_data2[i])) {
                std::cerr << "Find(std::string): FAILED" << std::endl;
                exit(EXIT_FAILURE);
            }
        }
        for (std::size_t i = 1; i < TEST_DATA2_SIZE; i += 2) {
            if ((i != 9) && (!hash_tables[3]->find(test_data2[i]))) {
                std::cerr << "Find(std::string): FAILED" << std::endl;
                exit(EXIT_FAILURE);
            }
        }
    }
    catch (const std::exception& exception) {
        std::cerr << "Find(std::string): FAILED (" << exception.what() << ")" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "Find(std::string): PASSED" << std::endl;

    /* Operator= */
    try {
        *hash_tables[1] = *hash_tables[3];
        *hash_tables[1] = *hash_tables[4];
        *hash_tables[1] = *hash_tables[1];
    }
    catch (const std::exception& exception) {
        std::cerr << "Operator=: FAILED (" << exception.what() << ")" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "Operator=: PASSED" << std::endl;

    /* Operator<< */
    try {
        std::cout << *hash_tables[0];
        std::cout << *hash_tables[1];
        std::cout << *hash_tables[2];
        std::cout << *hash_tables[3];
    }
    catch (const std::exception& exception) {
        std::cerr << "Operator<<: FAILED (" << exception.what() << ")" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "Operator<<: PASSED" << std::endl;

    /* Operator<< for ErrorCode */
    try {
        hash_tables[2]->insert(test_data1[0]);
    }
    catch (const HTSC<std::string>::ErrorCode& exception) {
        if (exception != HTSC<std::string>::IS_FULL) {
            std::cerr << "Operator<< for ErrorCode: FAILED (" << exception << ")" << std::endl;
            exit(exception);
        }
        else {
            std::cerr << exception << std::endl;
        }
    }
    catch (const std::exception& exception) {
        std::cerr << "Operator<< for ErrorCode: FAILED (" << exception.what() << ")" << std::endl;
        exit(EXIT_FAILURE);
    }
    try {
        hash_tables[3]->erase(test_data2[0]);
    }
    catch (const HTSC<std::string>::ErrorCode& exception) {
        if (exception != HTSC<std::string>::NOT_FOUND) {
            std::cerr << "Operator<< for ErrorCode: FAILED (" << exception << ")" << std::endl;
            exit(exception);
        }
        else {
            std::cerr << exception << std::endl;
        }
    }
    catch (const std::exception& exception) {
        std::cerr << "Operator<< for ErrorCode: FAILED (" << exception.what() << ")" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "Operator<< for ErrorCode: PASSED" << std::endl;

    /* Additional test */
    try {
        hash_table = new HTSC<Test>();
        for (std::size_t i = 0; i < TEST_DATA3_SIZE; ++i)
            hash_table->insert(Test(test_data3[i]));
        std::cout << *hash_table;
    }
    catch (const std::exception& exception) {
        std::cerr << "Additional test: FAILED (" << exception.what() << ")" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "Additional test: PASSED" << std::endl;

    exit(EXIT_SUCCESS);
}
