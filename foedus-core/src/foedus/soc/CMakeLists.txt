set_property(GLOBAL APPEND PROPERTY ALL_FOEDUS_CORE_SRC
  ${CMAKE_CURRENT_SOURCE_DIR}/shared_cond.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/shared_memory_repo.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/shared_mutex.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/shared_polling.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/shared_rendezvous.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/soc_manager.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/soc_manager_pimpl.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/soc_options.cpp
)
