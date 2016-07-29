#ifndef MINERVA_CC1PI0_XSEC_1DTH_ANTINU_H_SEEN
#define MINERVA_CC1PI0_XSEC_1DTH_ANTINU_H_SEEN

#include "Measurement1D.h"

class MINERvA_CC1pi0_XSec_1Dth_antinu : public Measurement1D {
public:
  MINERvA_CC1pi0_XSec_1Dth_antinu(std::string inputfile, FitWeight *rw, std::string  type, std::string fakeDataFile);
  virtual ~MINERvA_CC1pi0_XSec_1Dth_antinu() {};

  void FillEventVariables(FitEvent *event);
  bool isSignal(FitEvent *event);

private:
  bool isNew;
  double hadMassCut;

};

#endif
