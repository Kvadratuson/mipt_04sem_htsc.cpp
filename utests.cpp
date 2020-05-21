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
    HTSC<std::string> *hash_tables[4];

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
        for (std::size_t i = 0; i < TEST_DATA1_SIZE; ++i) {
            hash_tables[2]->insert(test_data1[i]);
        }
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
    }
    catch (const std::exception& exception) {
        std::cerr << "Construct(copy): FAILED (" << exception.what() << ")" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "Construct(copy): PASSED" << std::endl;

    /* Operator<< */
    try {
        std::cout << *hash_tables[0];
        std::cout << *hash_tables[3];
    }
    catch (const std::exception& exception) {
        std::cerr << "Operator<<: FAILED (" << exception.what() << ")" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << "Operator<<: PASSED" << std::endl;

    exit(EXIT_SUCCESS);
}
