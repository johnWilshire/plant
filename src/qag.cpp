#include <plant/qag.h>
#include <plant/util.h>
#include <plant/util_post_rcpp.h>
#include <Rcpp.h>

namespace plant {
namespace quadrature {

// Default construction using delegating constructors:
QAG::QAG() : QAG(15, 1, NA_REAL, NA_REAL) {}

QAG::QAG(size_t rule, size_t max_iterations, double atol, double rtol)
  : adaptive(max_iterations > 1),
    q(rule),
    limit(max_iterations),
    epsabs(atol),
    epsrel(rtol),
    area(NA_REAL),
    error(NA_REAL),
    iteration(0),
    roundoff_type1(0),
    roundoff_type2(0) {
}

intervals_type QAG::get_last_intervals() const {
  return w.get_intervals();
}

// * R interface
double QAG::r_integrate(SEXP f, double a, double b) {
  util::RFunctionWrapper fw(Rcpp::as<Rcpp::Function>(f));
  return integrate(fw, a, b);
}

double QAG::r_integrate_with_intervals(SEXP f, SEXP intervals) {
  util::RFunctionWrapper fw(Rcpp::as<Rcpp::Function>(f));

  Rcpp::List intervals_list(Rcpp::as<Rcpp::List>(intervals));
  util::check_length(static_cast<size_t>(intervals_list.size()), 2);
  intervals_type tmp;
  tmp.push_back(Rcpp::as< std::vector<double> >(intervals_list[0]));
  tmp.push_back(Rcpp::as< std::vector<double> >(intervals_list[1]));
  if (tmp[0].size() != tmp[1].size()) {
    Rcpp::stop("Intervals must have the same length");
  }

  return integrate_with_intervals(fw, tmp);
}

double QAG::r_integrate_with_last_intervals(SEXP f, double a, double b) {
  util::RFunctionWrapper fw(Rcpp::as<Rcpp::Function>(f));
  return integrate_with_last_intervals(fw, a, b);
}

bool QAG::subinterval_too_small(double a1, double mid,
                                double b2) {
  const double e = std::numeric_limits<double>::epsilon();
  const double u = std::numeric_limits<double>::min();
  const double tmp = (1 + 100 * e) * (std::abs(mid) + 1000 * u);
  return std::abs(a1) <= tmp && std::abs(b2) <= tmp;
}

}
}
