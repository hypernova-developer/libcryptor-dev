#pragma once

#ifndef CRYPTOR_HPP
#define CRYPTOR_HPP

#include <string>
#include <vector>
#include <numeric>

namespace cryptor
{
    enum class Method
    {
        ASCII_SHIFT,
        XOR_LITE,
        VIGENERE,
        MINI_RC4
    };

    namespace encryptor
    {
        static inline std::string process(Method method, const std::string& data, const std::string& key = "")
        {
            if (method == Method::ASCII_SHIFT)
            {
                std::string output = data;
                for (char &c : output) 
                {
                    c += 1;
                }
                return output;
            }
            else if (method == Method::XOR_LITE)
            {
                if (key.empty()) 
                {
                    return data;
                }
                std::string output = data;
                for (size_t i = 0; i < data.length(); i++)
                {
                    output[i] ^= key[i % key.length()];
                }
                return output;
            }
            else if (method == Method::VIGENERE)
            {
                if (key.empty())
                {
                    return data;
                }
                std::string output = data;
                for (size_t i = 0; i < data.length(); i++)
                {
                    output[i] = static_cast<char>(static_cast<unsigned char>(data[i]) + static_cast<unsigned char>(key[i % key.length()]));
                }
                return output;
            }
            else if (method == Method::MINI_RC4)
            {
                if (key.empty())
                {
                    return data;
                }
                std::vector<unsigned char> s(256);
                std::iota(s.begin(), s.end(), 0);
                int j = 0;
                for (int i = 0; i < 256; i++)
                {
                    j = (j + s[i] + static_cast<unsigned char>(key[i % key.length()])) % 256;
                    std::swap(s[i], s[j]);
                }
                std::string output = data;
                int i = 0;
                j = 0;
                for (size_t k = 0; k < data.length(); k++)
                {
                    i = (i + 1) % 256;
                    j = (j + s[i]) % 256;
                    std::swap(s[i], s[j]);
                    unsigned char t = (s[i] + s[j]) % 256;
                    output[k] ^= s[t];
                }
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
                for (char &c : output) 
                {
                    c -= 1;
                }
                return output;
            }
            else if (method == Method::XOR_LITE)
            {
                if (key.empty()) 
                {
                    return data;
                }
                std::string output = data;
                for (size_t i = 0; i < data.length(); i++)
                {
                    output[i] ^= key[i % key.length()];
                }
                return output;
            }
            else if (method == Method::VIGENERE)
            {
                if (key.empty())
                {
                    return data;
                }
                std::string output = data;
                for (size_t i = 0; i < data.length(); i++)
                {
                    output[i] = static_cast<char>(static_cast<unsigned char>(data[i]) - static_cast<unsigned char>(key[i % key.length()]));
                }
                return output;
            }
            else if (method == Method::MINI_RC4)
            {
                if (key.empty())
                {
                    return data;
                }
                std::vector<unsigned char> s(256);
                std::iota(s.begin(), s.end(), 0);
                int j = 0;
                for (int i = 0; i < 256; i++)
                {
                    j = (j + s[i] + static_cast<unsigned char>(key[i % key.length()])) % 256;
                    std::swap(s[i], s[j]);
                }
                std::string output = data;
                int i = 0;
                j = 0;
                for (size_t k = 0; k < data.length(); k++)
                {
                    i = (i + 1) % 256;
                    j = (j + s[i]) % 256;
                    std::swap(s[i], s[j]);
                    unsigned char t = (s[i] + s[j]) % 256;
                    output[k] ^= s[t];
                }
                return output;
            }
            return "[Error: Unknown Decryption Method]";
        }
    }
}

#endif
