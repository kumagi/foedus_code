add_foedus_test_individual(test_assorted "Align32;Align64")
set(test_endianness_individual
  RoundtripU8
  RoundtripU16
  RoundtripU32
  RoundtripU64
  RoundtripI8
  RoundtripI16
  RoundtripI32
  RoundtripI64
  ComparisonU8
  ComparisonU16
  ComparisonU32
  ComparisonU64
  ComparisonI8
  ComparisonI16
  ComparisonI32
  ComparisonI64
)
add_foedus_test_individual(test_endianness "${test_endianness_individual}")
add_foedus_test_individual(test_dumb_spinlock "OneThread;TwoThreads;FourThreads;SixThreads;OneThreadLazy;TwoThreadsLazy;FourThreadsLazy;SixThreadsLazy")
set(test_raw_atomics_individual
  Uint8
  Uint16
  Uint32
  Uint64
  Int8
  Int16
  Int32
  Int64
  Uint8Weak
  Uint16Weak
  Uint32Weak
  Uint64Weak
  Int8Weak
  Int16Weak
  Int32Weak
  Int64Weak
)
add_foedus_test_individual(test_raw_atomics "${test_raw_atomics_individual}")
set(test_const_div_individual
  Test3
  Test4
  Test5
  Test6
  Test7
  Test8
  Test9
  Test10
  Test11
  Test12
  Test60
  Test125
  Test254
  Test256
  Test625
  TestRandom
)
add_foedus_test_individual(test_const_div "${test_const_div_individual}")

add_foedus_test_individual(test_fixed_string "Construct;Assign;AssignTruncate;Copy;Compare")

add_foedus_test_individual(test_mprotect "SmallPage;HugePage")
