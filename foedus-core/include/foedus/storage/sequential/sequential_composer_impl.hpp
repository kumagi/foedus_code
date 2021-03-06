/*
 * Copyright (c) 2014-2015, Hewlett-Packard Development Company, LP.
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details. You should have received a copy of the GNU General Public
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 *
 * HP designates this particular file as subject to the "Classpath" exception
 * as provided by HP in the LICENSE.txt file that accompanied this code.
 */
#ifndef FOEDUS_STORAGE_SEQUENTIAL_SEQUENTIAL_COMPOSER_IMPL_HPP_
#define FOEDUS_STORAGE_SEQUENTIAL_SEQUENTIAL_COMPOSER_IMPL_HPP_

#include <stdint.h>

#include <iosfwd>
#include <string>

#include "foedus/fwd.hpp"
#include "foedus/memory/fwd.hpp"
#include "foedus/snapshot/fwd.hpp"
#include "foedus/storage/composer.hpp"
#include "foedus/storage/page.hpp"
#include "foedus/storage/storage_id.hpp"
#include "foedus/storage/sequential/fwd.hpp"

namespace foedus {
namespace storage {
namespace sequential {
/**
 * @brief Composer for an sequential storage.
 * @ingroup SEQUENTIAL
 * @details
 * Like partitioner, this does a quite simple stuff.
 * We don't need to do any merge-sort as there is no order.
 * We just sequentially add them all.
 *
 * @par Page allcation in compose()
 * This composer sequentially writes out data pages until the main buffer in snapshot_writer_
 * becomes full. Whenever it does, it writes out all the pages and treat the first page
 * as one head page. So, this compose() can output more than one head pages.
 * By doing this, we don't have to worry about any of the intermediate pages and pointer
 * installations. Sooooo simple.
 * The limit is of course 500 pointers (4kb), but surely it will fit.
 * If it doesn't, we must consider allowing variable-sized root info page.
 *
 * @note
 * This is a private implementation-details of \ref SEQUENTIAL, thus file name ends with _impl.
 * Do not include this header from a client program. There is no case client program needs to
 * access this internal class.
 */
class SequentialComposer final {
 public:
  /** Output of one compose() call, which are then combined in construct_root(). */
  struct RootInfoPage final {
    PageHeader          header_;          // +16 -> 16
    /** Number of pointers stored in this page. */
    uint32_t            pointer_count_;   // +4 -> 20
    uint32_t            dummy_;           // +4 -> 24
    /** Pointers to head pages. */
    SnapshotPagePointer pointers_[(kPageSize - 24) / 8];  // -> 4096
  };

  explicit SequentialComposer(Composer *parent);

  std::string to_string() const;

  ErrorStack compose(const Composer::ComposeArguments& args);
  ErrorStack construct_root(const Composer::ConstructRootArguments& args);
  Composer::DropResult drop_volatiles(const Composer::DropVolatilesArguments& args);

 private:
  SequentialPage*     compose_new_head(
    snapshot::SnapshotWriter* snapshot_writer,
    RootInfoPage* root_info_page);

  Engine* const   engine_;
  const StorageId storage_id_;
};

}  // namespace sequential
}  // namespace storage
}  // namespace foedus
#endif  // FOEDUS_STORAGE_SEQUENTIAL_SEQUENTIAL_COMPOSER_IMPL_HPP_
