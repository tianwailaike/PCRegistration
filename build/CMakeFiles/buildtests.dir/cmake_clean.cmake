file(REMOVE_RECURSE
  "pctest_automoc.cpp"
  "super4pcs_algo_automoc.cpp"
  "icp_algo_automoc.cpp"
  "super4pcs_automoc.cpp"
  "icprefine_automoc.cpp"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/buildtests.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()