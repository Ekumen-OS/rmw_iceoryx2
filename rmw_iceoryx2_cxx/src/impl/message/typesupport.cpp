// Copyright (c) 2024 by Ekxide IO GmbH All rights reserved.
//
// This program and the accompanying materials are made available under the
// terms of the Apache Software License 2.0 which is available at
// https://www.apache.org/licenses/LICENSE-2.0, or the MIT license
// which is available at https://opensource.org/licenses/MIT.
//
// SPDX-License-Identifier: Apache-2.0 OR MIT

#include "rmw_iceoryx2_cxx/impl/message/typesupport.hpp"

#include "flatros2/typesupport.hpp"

namespace rmw::iox2
{

void *wrap_message(const rosidl_message_type_support_t* type_support, uint8_t *bytes, size_t number_of_bytes, void *type_erased_message, bool copy_on_wrap) {
    if (auto handle = get_message_typesupport_handle(type_support, flatros2::typesupport_identifier)) {
        auto ts = static_cast<const flatros2::flat_message_type_support_t *>(handle->data);
        if (ts->wrap_message) {
            return ts->wrap_message(bytes, number_of_bytes, type_erased_message, copy_on_wrap);
        }
    }
    if (type_erased_message) {
        memcpy(type_erased_message, bytes, number_of_bytes);
        return type_erased_message;
    }
    return bytes;
}

uint8_t *unwrap_message(const rosidl_message_type_support_t* type_support, void *message, size_t *number_of_bytes, bool keep_wrapper) {
    if (auto handle = get_message_typesupport_handle(type_support, flatros2::typesupport_identifier)) {
        auto ts = static_cast<const flatros2::flat_message_type_support_t *>(handle->data);
        if (ts->unwrap_message) {
            return ts->unwrap_message(message, number_of_bytes, keep_wrapper);
        }
        if (number_of_bytes) {
            *number_of_bytes = ts->message_size;
        }
    }
    return static_cast<uint8_t *>(message);
}

} // namespace rmw::iox2
