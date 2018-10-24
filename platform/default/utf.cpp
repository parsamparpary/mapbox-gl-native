#include <mbgl/util/utf.hpp>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wimplicit-fallthrough"
#include <boost/locale/encoding_utf.hpp>
#pragma GCC diagnostic pop

namespace mbgl {
namespace util {

std::u16string convertUTF8ToUTF16(const std::string& str) {
    return boost::locale::conv::utf_to_utf<char16_t>(str);
}

std::string convertUTF16ToUTF8(const std::u16string& str) {
    return boost::locale::conv::utf_to_utf<char>(str);
}

} // namespace util
} // namespace mbgl
