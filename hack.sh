#!/bin/sh
sed -i -e "s/int \*m_function/void \*m_function/g" yellowcolIndividual.hpp
sed -i -e "s/if (m_function) delete m_function/Function\* me = (Function\*)m_function; if (me) delete me/g" yellowcolIndividual.cpp
sed -i -e "s/m_function=(genome.m_function ? new int(\*(genome.m_function)) : NULL)/m_function=(void\*)(genome.m_function ? new Function(\*((Function\*)genome.m_function)) : NULL)/g" yellowcolIndividual.cpp