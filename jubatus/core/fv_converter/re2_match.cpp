// Jubatus: Online machine learning framework for distributed environment
// Copyright (C) 2011 Preferred Infrastructure and Nippon Telegraph and Telephone Corporation.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License version 2.1 as published by the Free Software Foundation.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

#include "re2_match.hpp"

#include <string>
#include "exception.hpp"

namespace jubatus {
namespace core {
namespace fv_converter {

regexp_match::regexp_match(const std::string& regexp)
    : re_(regexp) {
  if (!re_.ok()) {
    throw JUBATUS_EXCEPTION(converter_exception("invalid regular expression"));
  }
}

bool regexp_match::match(const std::string& key) {
  return re2::RE2::FullMatch(key, re_);
}

}  // namespace fv_converter
}  // namespace core
}  // namespace jubatus
