# Copyright 2016-2021 L. Pickering, P Stowell, R. Terri, C. Wilkinson, C. Wret

################################################################################
#    This file is part of NUISANCE.
#
#    NUISANCE is free software: you can redistribute it and/or modify
#    it under the terms of the GNU General Public License as published by
#    the Free Software Foundation, either version 3 of the License, or
#    (at your option) any later version.
#
#    NUISANCE is distributed in the hope that it will be useful,
#    but WITHOUT ANY WARRANTY; without even the implied warranty of
#    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#    GNU General Public License for more details.
#
#    You should have received a copy of the GNU General Public License
#    along with NUISANCE.  If not, see <http://www.gnu.org/licenses/>.
################################################################################

set(LikelihoodFunction_Impl_Files
  JointFCN.cxx
  SampleList.cxx
)

add_library(FCN SHARED ${LikelihoodFunction_Impl_Files})
target_link_libraries(FCN Experiments CoreIncludes ROOT::ROOT)

install(TARGETS FCN DESTINATION lib)

install(FILES SampleList.cxx DESTINATION src/FCN)
