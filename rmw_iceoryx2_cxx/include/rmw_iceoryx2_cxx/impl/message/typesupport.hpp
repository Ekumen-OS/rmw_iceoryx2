// Copyright (c) 2024 by Ekxide IO GmbH All rights reserved.
//
// This program and the accompanying materials are made available under the
// terms of the Apache Software License 2.0 which is available at
// https://www.apache.org/licenses/LICENSE-2.0, or the MIT license
// which is available at https://opensource.org/licenses/MIT.
//
// SPDX-License-Identifier: Apache-2.0 OR MIT

#ifndef RMW_IOX2_MESSAGE_TYPESUPPORT_HPP_
#define RMW_IOX2_MESSAGE_TYPESUPPORT_HPP_

#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"

#define RMW_ICEORYX2_CXX_TYPESUPPORT_C rosidl_typesupport_fastrtps_c__identifier
#define RMW_ICEORYX2_CXX_TYPESUPPORT_CPP rosidl_typesupport_fastrtps_cpp::typesupport_identifier

namespace rmw::iox2
{

void *wrap_message(const rosidl_message_type_support_t* type_support, uint8_t *bytes, size_t number_of_bytes, void *type_erased_message = nullptr, bool copy_on_wrap = false);
uint8_t *unwrap_message(const rosidl_message_type_support_t* type_support, void *message, size_t *number_of_bytes = nullptr, bool keep_wrapper = true);

} // namespace rmw::iox2

#endif  // RMW_IOX2_MESSAGE_TYPESUPPORT_HPP_
