#ifndef _ARCHIVER_LZWCOMPRESSOR_H_
#define _ARCHIVER_LZWCOMPRESSOR_H_

#include <cstdint>
#include <map>

#include "./ICompressor.h"

namespace compressors {

class LZWCompressor : public ICompressor {
  public:
    void compress(
        const std::vector<std::byte>& data_to_compress,
        std::vector<std::byte>& container_to_compressed_data
        ) const override;

    void decompress(
        const std::vector<std::byte>& data_to_decompress,
        std::vector<std::byte>& container_to_decompressed_data
        ) const override;

    std::string_view getCompressionType() const noexcept override;

  private:
    std::map<std::vector<std::byte>, uint32_t> create_compress_dictionary() const;
    std::map<uint32_t, std::vector<std::byte>> create_decompress_dictionary() const;

  private:
    static constexpr std::string_view compression_type_ = "LZW";
    // Maybe more fields or functions
};

} // namespace compressors

#include "../../src/Compressors/LZWCompressor.cpp"

#endif // _ARCHIVER_LZWCOMPRESSOR_H_