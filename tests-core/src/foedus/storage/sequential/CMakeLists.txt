add_foedus_test_individual(test_sequential_basic "Create;CreateAndDrop;CreateAndWrite")
add_foedus_test_individual(test_sequential_volatile_list "Empty;SingleThread;TwoThreads;FourThreads")

set(test_sequential_tpcb_individuals
  SingleThreadedNoContention
  TwoThreadedNoContention
  FourThreadedNoContention
  SingleThreadedContended
  TwoThreadedContended
  FourThreadedContended
  SingleThreadedNoContentionPrimitive
  TwoThreadedNoContentionPrimitive
  FourThreadedNoContentionPrimitive
  SingleThreadedContendedPrimitive
  TwoThreadedContendedPrimitive
  FourThreadedContendedPrimitive
  SingleThreadedNoContentionInc
  TwoThreadedNoContentionInc
  FourThreadedNoContentionInc
  SingleThreadedContendedInc
  TwoThreadedContendedInc
  FourThreadedContendedInc
  SingleThreadedNoContentionInc1S
  TwoThreadedNoContentionInc1S
  FourThreadedNoContentionInc1S
  SingleThreadedContendedInc1S
  TwoThreadedContendedInc1S
  FourThreadedContendedInc1S
  )
add_foedus_test_individual(test_sequential_tpcb "${test_sequential_tpcb_individuals}")
