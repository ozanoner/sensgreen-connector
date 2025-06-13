
idf_component_register(SRCS "multisensor_ex.cpp"
                    INCLUDE_DIRS "." "../../../include") 

target_compile_features(${COMPONENT_LIB} PRIVATE cxx_std_17)
target_compile_options(${COMPONENT_LIB} PRIVATE -Wno-missing-field-initializers)
