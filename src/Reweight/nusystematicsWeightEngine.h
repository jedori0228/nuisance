#ifndef nusystWeightEngine_SEEN
#define nusystWeightEngine_SEEN
// Copyright 2016-2021 L. Pickering, P Stowell, R. Terri, C. Wilkinson, C. Wret

/*******************************************************************************
*    This file is part of NUISANCE.
*
*    NUISANCE is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    NUISANCE is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with NUISANCE.  If not, see <http://www.gnu.org/licenses/>.
*******************************************************************************/

#include "WeightEngineBase.h"

#include "systematicstools/interface/types.hh"

#include "nusystematics/utility/response_helper.hh"

#include <cmath>


class DUNErwtSingleton {
public:
    static nusyst::response_helper& getInstance(const std::string& fhicl_name) {
        static DUNErwtSingleton instance(fhicl_name);  // Pass parameter to constructor
        return instance.DUNErwt;
    }

private:
    DUNErwtSingleton(const std::string& fhicl_name) {
        // Private constructor to prevent instantiation
        DUNErwt.LoadConfiguration(fhicl_name);  // Configure DUNErwt once
    }

    ~DUNErwtSingleton() = default;

    DUNErwtSingleton(const DUNErwtSingleton&) = delete;
    DUNErwtSingleton& operator=(const DUNErwtSingleton&) = delete;

    nusyst::response_helper DUNErwt;
};

class nusystematicsWeightEngine : public WeightEngineBase {

 public:
  nusystematicsWeightEngine();

  nusyst::response_helper* DUNErwt;

  systtools::param_value_list_t EnabledParams;

  void Config();

  int ConvDial(std::string name);

  // Functions requiring Override
  void IncludeDial(std::string name, double startval);

  void SetDialValue(int nuisenum, double val);
  void SetDialValue(std::string name, double val);

  bool IsDialIncluded(std::string name);
  bool IsDialIncluded(int nuisenum);

  double GetDialValue(std::string name);
  double GetDialValue(int nuisenum);

  void Reconfigure(bool silent);

  bool NeedsEventReWeight();

  double CalcWeight(BaseFitEvt* evt);

  void Print();

  bool fUseCV;
};

#endif
