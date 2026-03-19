#ifndef globals_h
#define globals_h

const int monthsInYear = 12;
const double percentDenominator = 100;

struct gAmortizeMonth
{
  int Month;
  int yearMonth;
  long loanMonth;
  double payments;
  double pureInterests;
  double paidDownPrincipal;
  double principalBalance;

};
#endif
