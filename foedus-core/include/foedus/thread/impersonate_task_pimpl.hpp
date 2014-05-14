/*
 * Copyright (c) 2014, Hewlett-Packard Development Company, LP.
 * The license and distribution terms for this file are placed in LICENSE.txt.
 */
#ifndef FOEDUS_THREAD_IMPERSONATE_TASK_PIMPL_HPP_
#define FOEDUS_THREAD_IMPERSONATE_TASK_PIMPL_HPP_
#include <foedus/assert_nd.hpp>
#include <foedus/error_stack.hpp>
#include <foedus/thread/fwd.hpp>
#include <future>
namespace foedus {
namespace thread {
/**
 * @brief Pimpl object of ImpersonateTask.
 * @ingroup THREADPOOL
 * @details
 * A private pimpl object for ImpersonateTask.
 * Do not include this header from a client program unless you know what you are doing.
 */
class ImpersonateTaskPimpl final {
 public:
    ImpersonateTaskPimpl() {}
    ~ImpersonateTaskPimpl() {}

    void set_result(const ErrorStack& result) {
        ASSERT_ND(!result_.is_error());
        if (result.is_error()) {  // otherwise no need to copy
            result_ = result;
        }
        done_future_.set_value();  // signal
    }

    /**
     * Result of this task. It's RET_OK until the task completes.
     */
    ErrorStack                  result_;

    /**
     * Signals when this task is done.
     * ImpersonateSession retrieves a future from this and waits on it.
     * The impersonated thread calls set_value when it finishes the task.
     */
    std::promise<void>          done_future_;
};
}  // namespace thread
}  // namespace foedus
#endif  // FOEDUS_THREAD_IMPERSONATE_TASK_PIMPL_HPP_