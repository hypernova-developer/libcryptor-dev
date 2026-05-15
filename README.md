# 🔐 libcryptor-dev

A modern, header-only, and independent security suite for **Pure C++**. 

## 🚀 The Philosophy: Lock & Key

Every lock needs a specific key. **libcryptor-dev** is designed with a clear separation between encryption (The Lock) and decryption (The Key). This project is a part of the **SyntaX Ecosystem**, built with a focus on architectural precision and zero external dependencies.



## 🏗️ Architectural Overview

Unlike traditional libraries, **libcryptor-dev** uses nested namespaces to prevent naming collisions and ensure a clean developer experience.

* **`cryptor::encryptor`**: Dedicated namespace for sealing data.
* **`cryptor::decryptor`**: Dedicated namespace for unlocking data.
* **Header-Only**: No `.dll` or `.lib` linking required. Just `#include "cryptor.hpp"`.

## 📦 Features

- **Namespace Isolation:** Strictly organized under `cryptor` namespace.
- **Modern C++:** Utilizes `inline` functions for high-performance header-only integration.
- **Zero Dependencies:** No external libraries required.
- **Allman Style:** Clean, readable, and structured code.

## 🛠️ Supported Methods

| Method | Description | Security Level |
| :--- | :--- | :--- |
| `ASCII_SHIFT` | Basic Caesar-style character shifting. | Basic |
| `XOR_LITE` | Bitwise XOR manipulation with a secret key. | Intermediate |
| `SHA_256` | Professional hashing (Roadmap). | High |

## 💻 Usage

```cpp
#include "include/cryptor.hpp"
#include <iostream>

int main()
{
    std::string secret = "Hypernovae";
    std::string key = "Libraries2026";

    // 1. Encryption (The Lock)
    std::string encrypted = cryptor::encryptor::process(cryptor::Method::XOR_LITE, secret, key);
    
    // 2. Decryption (The Key)
    std::string decrypted = cryptor::decryptor::process(cryptor::Method::XOR_LITE, encrypted, key);

    std::cout << "Original:  " << secret << std::endl;
    std::cout << "Encrypted: " << encrypted << std::endl;
    std::cout << "Decrypted: " << decrypted << std::endl;

    return 0;
}
```
## 📜 Development Status
This library is maintained by hypernova-developer. Current version reflects the progress of 762 total commits across the ecosystem.
_Next Goals: Implementation of SHA-256 and Base64 encoding support._

## Licensing
This project is protected under the GNU GPL v3.0 license and owned by **hypernova-developer*.
