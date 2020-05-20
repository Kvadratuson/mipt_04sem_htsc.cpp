#include "htsc.hpp"

#include <string>

#define TEST_DATA1_SIZE 10
#define TEST_DATA2_SIZE 26
std::string test_data1[] =
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
std::string test_data2[] =
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

int main()
{
    { /* Construct */
        try {
            HTSC<std::string> hash_table1;
        }
        catch(const std::exception& exception) {
            std::cerr << "Construct.1: FAILED (" << exception.what() << ")" << std::endl;
            exit(EXIT_FAILURE);
        }
        try {
            HTSC<std::string> hash_table(5);
        }
        catch(const std::exception& exception) {
            std::cerr << "Construct.2: FAILED (" << exception.what() << ")" << std::endl;
            exit(EXIT_FAILURE);
        }
        try {
            HTSC<std::string> hash_table1(5);
            HTSC<std::string> hash_table2(hash_table1);
        }
        catch(const std::exception& exception) {
            std::cerr << "Construct.3: FAILED (" << exception.what() << ")" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    std::cout << "Construct: PASSED" << std::endl;

    try { /* Operator<< */
        HTSC<std::string> hash_table;
        std::cout << hash_table;
    }
    catch (const std::exception& exception) {
        std::cerr << "Operator<<: FAILED (" << exception.what() << ")" << std::endl;
        exit(EXIT_FAILURE);
    }

    std::cout << "Operator<<: PASSED" << std::endl;

    { /* Emplace */
        HTSC<std::string> hash_table(10);
        try {
            hash_table.emplace("0");
            hash_table.emplace("1");
            hash_table.emplace("2");
            hash_table.emplace("3");
            hash_table.emplace("4");
            hash_table.emplace("5");
            hash_table.emplace("6");
            hash_table.emplace("7");
            hash_table.emplace("8");
            hash_table.emplace("9");
        }
        catch (const HTSC<std::string>::ErrorCode& exception) {
            std::cerr << "Emplace: FAILED (" << exception << ")" << std::endl;
            exit(exception);
        }
        catch (const std::exception& exception) {
            std::cerr << "Emplace: FAILED (" << exception.what() << ")" << std::endl;
            exit(EXIT_FAILURE);
        }
        try {
            hash_table.emplace("10");
        }
        catch (const HTSC<std::string>::ErrorCode& exception) {
            if (exception != HTSC<std::string>::IS_FULL) {
                std::cerr << "Emplace.Full: FAILED (" << exception << ")" << std::endl;
                exit(exception);
            }
        }
        catch (const std::exception& exception) {
            std::cerr << "Emplace.Full: FAILED (" << exception.what() << ")" << std::endl;
            exit(EXIT_FAILURE);
        }
        try {
            hash_table.emplace("0");
            hash_table.emplace("1");
            hash_table.emplace("2");
            hash_table.emplace("3");
            hash_table.emplace("4");
            hash_table.emplace("5");
            hash_table.emplace("6");
            hash_table.emplace("7");
            hash_table.emplace("8");
            hash_table.emplace("9");
        }
        catch (const HTSC<std::string>::ErrorCode& exception) {
            std::cerr << "Emplace.Repeat: FAILED (" << exception << ")" << std::endl;
            exit(exception);
        }
        catch (const std::exception& exception) {
            std::cerr << "Emplace.Repeat: FAILED (" << exception.what() << ")" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    std::cout << "Emplace: PASSED" << std::endl;

    { /* Insert */
        HTSC<std::string> hash_table(TEST_DATA2_SIZE);
        try {
            for (std::size_t i = 0; i < TEST_DATA2_SIZE; ++i) {
                hash_table.insert(test_data2[i]);
            }
        }
        catch (const HTSC<std::string>::ErrorCode& exception) {
            std::cerr << "Insert: FAILED (" << exception << ")" << std::endl;
            exit(exception);
        }
        catch (const std::exception& exception) {
            std::cerr << "Insert: FAILED (" << exception.what() << ")" << std::endl;
            exit(EXIT_FAILURE);
        }
        try {
            for (std::size_t i = 0; i < TEST_DATA1_SIZE; ++i) {
                hash_table.insert(test_data1[i]);
            }
        }
        catch (const HTSC<std::string>::ErrorCode& exception) {
            if (exception != HTSC<std::string>::IS_FULL) {
                std::cerr << "Insert.Full: FAILED (" << exception << ")" << std::endl;
                exit(exception);
            }
        }
        catch (const std::exception& exception) {
            std::cerr << "Insert.Full: FAILED (" << exception.what() << ")" << std::endl;
            exit(EXIT_FAILURE);
        }
        try {
            for (std::size_t i = 0; i < TEST_DATA2_SIZE; ++i) {
                hash_table.insert(test_data2[i]);
            }
        }
        catch (const HTSC<std::string>::ErrorCode& exception) {
            std::cerr << "Insert.Repeat: FAILED (" << exception << ")" << std::endl;
            exit(exception);
        }
        catch (const std::exception& exception) {
            std::cerr << "Insert.Repeat: FAILED (" << exception.what() << ")" << std::endl;
            exit(EXIT_FAILURE);
        }
        std::cout << hash_table;
    }

    std::cout << "Insert: PASSED" << std::endl;

    exit(EXIT_SUCCESS);
}
