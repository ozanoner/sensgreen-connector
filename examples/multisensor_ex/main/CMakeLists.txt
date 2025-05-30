
idf_component_register(SRCS "multisensor_ex.cpp"
                    INCLUDE_DIRS "." "../../../include") 

target_compile_features(${COMPONENT_LIB} PRIVATE cxx_std_17)