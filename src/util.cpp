#include <gsl/gsl_errno.h>
#include "util.h"

namespace util {

// See Rcpp-exports for alternative to Rf_error
void handler_pass_to_R(const char *reason,
                       const char *file,
                       int line,
                       int gsl_errno) {
  ::Rf_error("GSLERROR: %s: %s:%d [%d]", reason, file, line, gsl_errno);
}

void set_sane_gsl_error_handling() {
  gsl_set_error_handler(&handler_pass_to_R);
}

// TODO: add r_check_bounds with signature (int, size_t) that does
// conversion and checks positivity of idx?
void check_bounds(size_t idx, size_t size) {
  // We don't check size < 0 or idx < 0, as not possible with size_t
  if ( size == 0 )
    ::Rf_error("Index %d impossible from empty range", idx);
  else if ( idx >= size )
    ::Rf_error("Index %d out of bounds: must be in [0,%d]", idx, size-1);
}

size_t check_bounds_r(size_t idx, size_t size) {
  // We don't check size < 0 or idx < 0, as not possible with size_t
  if ( size == 0 )
    ::Rf_error("Index %d out of bounds: container is empty", idx);
  else if ( idx < 1 || idx > size )
    ::Rf_error("Index %d out of bounds: must be in [1,%d]", idx, size);
  return idx - 1;
}

void check_length(size_t received, size_t expected) {
  if ( expected != received )
    ::Rf_error("Incorrect length input; expected %d, received %d\n",
	       expected, received);
}

std::vector<double> seq_len(double from, double to, int len) {
  std::vector<double> ret;
  ret.reserve(len);
  const double dx = (to - from) / (len - 1);
  double x = from;
  for ( int i = 0; i < len; i++, x += dx )
    ret.push_back(x);
  ret.back() = to; // Protect against rounding errors.
  return ret;
}

std::vector<int> rbinom_multiple(std::vector<int>::iterator it,
				 std::vector<int>::iterator end,
				 double p) {
  std::vector<int> ret;
  while ( it != end ) {
    const int k = (int)R::rbinom(*it, p);
    *it -= k;
    ret.push_back(k);
    it++;
  }
  return ret;
}

namespace test {
std::vector<double> test_sum_double(std::vector<double> a,
				    std::vector<double> b) {
  check_length(a.size(), b.size());
  return sum(a, b);
}

std::vector<int> test_sum_int(std::vector<int> a,
			      std::vector<int> b) {
  check_length(a.size(), b.size());
  return sum(a, b);
}


}

}
