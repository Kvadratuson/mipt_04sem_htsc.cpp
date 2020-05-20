#include "htsc.hpp"

#include <string>

int main()
{
    try { /* Construct.1 */
        HTSC<std::string> hash_table1;
    }
    catch(const std::exception& exception) {
        std::cerr << "Construct.1: FAILED (" << exception.what() << ")" << std::endl;
        exit(EXIT_FAILURE);
    }
    try { /* Construct.2 */
        HTSC<std::string> hash_table2(5);
    }
    catch(const std::exception& exception) {
        std::cerr << "Construct.2: FAILED (" << exception.what() << ")" << std::endl;
        exit(EXIT_FAILURE);
    }
    try { /* Construct.3 */
        HTSC<std::string> hash_table2(5);
        HTSC<std::string> hash_table3(hash_table2);
    }
    catch(const std::exception& exception) {
        std::cerr << "Construct.3: FAILED (" << exception.what() << ")" << std::endl;
        exit(EXIT_FAILURE);
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

    exit(EXIT_SUCCESS);
}
