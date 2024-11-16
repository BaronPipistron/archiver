#include "../../include/Compressors/LZWCompressor.h"

namespace compressors {

void LZWCompressor::compress(
        const std::vector<std::byte>& data_to_compress,
        std::vector<std::byte>& container_to_compressed_data
        ) const 
{
    // TODO
}

void LZWCompressor::decompress(
        const std::vector<std::byte>& data_to_decompress,
        std::vector<std::byte>& container_to_decompressed_data
        ) const 
{
    // TODO
}

inline std::string_view LZWCompressor::getCompressionType() const noexcept {
    return compression_type_;
}

std::map<std::vector<std::byte>, uint32_t> LZWCompressor::create_compress_dictionary() const {
    std::map<std::vector<std::byte>, uint32_t> dictionary;

    for (uint32_t code = 0; code != 256; ++code) {
        std::vector<std::byte> word = {
            static_cast<std::byte>(code)
            };

        dictionary[word] = code;
    }

    return dictionary;
}

std::map<uint32_t, std::vector<std::byte>> LZWCompressor::create_decompress_dictionary() const {
    std::map<uint32_t, std::vector<std::byte>> dictionary;

    for (uint32_t code = 0; code != 256; ++code) {
        std::vector<std::byte> word = {
                static_cast<std::byte>(code)
            };

        dictionary[code] = word;
    }

    return dictionary;
}

} // namespaace compressors