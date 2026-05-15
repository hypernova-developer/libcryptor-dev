#ifndef CRYPTOR_HPP
#define CRYPTOR_HPP

#include <string>
#include <vector>

/**
 * @project libcryptor-dev
 * @brief Header-only encryption and decryption suite.
 * @author hypernova-developer (743 Commits)
 */

namespace cryptor
{
    /* Global Algorithms Menu */
    enum class Method
    {
        ASCII_SHIFT,   /* Basic Caesar-style */
        XOR_LITE       /* Bitwise XOR logic */
    };

    // --- ENCRYPTOR: The Lock ---
    namespace encryptor
    {
        static inline std::string process(Method method, const std::string& data, const std::string& key = "")
        {
            if (method == Method::ASCII_SHIFT)
            {
                std::string output = data;
                for (char &c : output) c += 1;
                return output;
            }
            else if (method == Method::XOR_LITE)
            {
                if (key.empty()) return data;
                std::string output = data;
                for (size_t i = 0; i < data.length(); i++)
                    output[i] ^= key[i % key.length()];
                return output;
            }
            return "[Error: Unknown Encryption Method]";
        }
    }

    // --- DECRYPTOR: The Key ---
    namespace decryptor
    {
        static inline std::string process(Method method, const std::string& data, const std::string& key = "")
        {
            if (method == Method::ASCII_SHIFT)
            {
                std::string output = data;
                for (char &c : output) c -= 1; // Reverse shift
                return output;
            }
            else if (method == Method::XOR_LITE)
            {
                // XOR is its own inverse, but logically separated for clarity
                if (key.empty()) return data;
                std::string output = data;
                for (size_t i = 0; i < data.length(); i++)
                    output[i] ^= key[i % key.length()];
                return output;
            }
            return "[Error: Unknown Decryption Method]";
        }
    }
}

#endif
