/*
 * Copyright (c) 2014, Hewlett-Packard Development Company, LP.
 * The license and distribution terms for this file are placed in LICENSE.txt.
 */
#ifndef FOEDUS_MEMORY_MEMORY_ID_HPP_
#define FOEDUS_MEMORY_MEMORY_ID_HPP_
#include <stdint.h>
/**
 * @file foedus/memory/memory_id.hpp
 * @brief Definitions of IDs in this package and a few related constant values.
 * @ingroup MEMORY
 */
namespace foedus {
namespace memory {

/**
 * @brief Offset in PagePool that compactly represents the page address (unlike 8 bytes pointer).
 * @ingroup MEMORY
 * @details
 * Offset 0 means nullptr. Page-0 never appears as a valid page.
 */
typedef uint32_t PagePoolOffset;

/**
 * So far 2MB is the only page size available via Transparent Huge Page (THP).
 * @ingroup MEMORY
 */
const uint64_t HUGEPAGE_SIZE = 1 << 21;

}  // namespace memory
}  // namespace foedus
#endif  // FOEDUS_MEMORY_MEMORY_ID_HPP_
