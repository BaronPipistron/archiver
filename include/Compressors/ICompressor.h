#ifndef _ARCHIVER_ICOMPRESSOR_H_
#define _ARCHIVER_ICOMPRESSOR_H_

#include <cstddef>
#include <string>
#include <string_view>
#include <vector>

namespace compressors {

class ICompressor {
  public:
    virtual void compress(
        const std::vector<std::byte>& data_to_compress,
        std::vector<std::byte>& container_to_compressed_data
        ) const = 0;
        
    virtual void decompress(
        const std::vector<std::byte>& data_to_decompress,
        std::vector<std::byte>& container_to_decompressed_data
        ) const = 0;

    virtual std::string_view getCompressionType() const noexcept = 0;

  protected:
    virtual ~ICompressor() noexcept = default;
};

} // namespace compressors

#endif // _ARCHIVER_ICOMPRESSOR_H_