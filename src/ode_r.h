// -*-c++-*-
#ifndef TREE_ODE_R_H_
#define TREE_ODE_R_H_

#include <Rcpp.h>
#include <vector>

#include "ode_solver.h"

namespace ode {

class OdeR {
public:
  OdeR(SEXP fun, SEXP env, SEXP pars);
  unsigned int size() const { return size_; }
  void derivs(double time, iter_const y, iter dydt);
  std::vector<double> r_derivs(double time, std::vector<double> y);

  // These are going to be tedious to expose, but in this case we're
  // really not trying to do any abstraction at all.
  void ode_set_state(std::vector<double> y, double t) {
    size_ = y.size();
    solver.set_state(y, t);
    solver.reset(); // reset step sizes, etc.
  }
  std::vector<double> ode_get_state() const {
    return solver.get_state();
  }
  double ode_get_time() const {
    return solver.get_time();
  }
  void ode_step() {
    solver.step();
  }
  void ode_step_fixed(double step_size) { 
    solver.step_fixed(step_size); 
  }
  void ode_advance(double time_max) {
    solver.advance(time_max);
  }
  Rcpp::NumericMatrix ode_r_run(std::vector<double> times, 
				std::vector<double> y) {
    size_ = y.size();
    return solver.r_run(times, y);
  }

private:
  SEXP target(double time, SEXP y);

  SEXP fun, env, pars;
  unsigned int size_;

  Solver<OdeR> solver;
};

}

#endif
