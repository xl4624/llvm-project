//===-- Linux implementation of the pthread_setspecific function ----------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#include "pthread_setspecific.h"

#include "src/__support/common.h"
#include "src/__support/libc_errno.h"
#include "src/__support/macros/config.h"
#include "src/__support/threads/thread.h"

#include <pthread.h>

namespace LIBC_NAMESPACE_DECL {

LLVM_LIBC_FUNCTION(int, pthread_setspecific,
                   (pthread_key_t key, const void *data)) {
  if (set_tss_value(key, const_cast<void *>(data)))
    return 0;
  else
    return EINVAL;
}

} // namespace LIBC_NAMESPACE_DECL
