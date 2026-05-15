#pragma once

#ifndef CRYPTOR_HPP
#define CRYPTOR_HPP

#include <string>
#include <vector>

namespace cryptor
{
    enum class Method
    {
        ASCII_SHIFT,
        XOR_LITE
    };

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

    namespace decryptor
    {
        static inline std::string process(Method method, const std::string& data, const std::string& key = "")
        {
            if (method == Method::ASCII_SHIFT)
            {
                std::string output = data;
                for (char &c : output) c -= 1;
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
            return "[Error: Unknown Decryption Method]";
        }
    }
}

#endif
