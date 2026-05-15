#include "cryptor.hpp"
#include <iostream>

int main()
{
    std::string raw = "hypernova-developer";
    
    std::string locked = cryptor::encryptor::process(cryptor::Method::ASCII_SHIFT, raw);
    
    std::string unlocked = cryptor::decryptor::process(cryptor::Method::ASCII_SHIFT, locked);

    std::cout << "Locked: " << locked << "\nUnlocked: " << unlocked << std::endl;
    return 0;
}
