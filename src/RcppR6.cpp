// Generated by RcppR6 (0.1): do not edit by hand
#include <tree2.h>

// [[Rcpp::export]]
ode::test::Lorenz Lorenz__ctor(double sigma, double R, double b) {
  return ode::test::Lorenz(sigma, R, b);
}
// [[Rcpp::export]]
size_t Lorenz__size__get(tree2::RcppR6::RcppR6<ode::test::Lorenz> obj_) {
  return obj_->size();
}

// [[Rcpp::export]]
std::vector<double> Lorenz__ode_values__get(tree2::RcppR6::RcppR6<ode::test::Lorenz> obj_) {
  return obj_->ode_values();
}
// [[Rcpp::export]]
void Lorenz__ode_values__set(tree2::RcppR6::RcppR6<ode::test::Lorenz> obj_, std::vector<double> value) {
  obj_->set_ode_values(value);
}

// [[Rcpp::export]]
std::vector<double> Lorenz__ode_rates__get(tree2::RcppR6::RcppR6<ode::test::Lorenz> obj_) {
  return obj_->r_ode_rates();
}

// [[Rcpp::export]]
Rcpp::NumericVector Lorenz__pars__get(tree2::RcppR6::RcppR6<ode::test::Lorenz> obj_) {
  return obj_->r_get_pars();
}


// [[Rcpp::export]]
ode::OdeSystem<ode::test::Lorenz> OdeSystem___Lorenz__ctor(ode::test::Lorenz obj, double abs_tol, double rel_tol) {
  return ode::OdeSystem<ode::test::Lorenz>(obj, abs_tol, rel_tol);
}
// [[Rcpp::export]]
void OdeSystem___Lorenz__do_step(tree2::RcppR6::RcppR6<ode::OdeSystem<ode::test::Lorenz> > obj_, double dt) {
  obj_->do_step(dt);
}
// [[Rcpp::export]]
bool OdeSystem___Lorenz__try_step(tree2::RcppR6::RcppR6<ode::OdeSystem<ode::test::Lorenz> > obj_, double dt) {
  return obj_->try_step(dt);
}
// [[Rcpp::export]]
void OdeSystem___Lorenz__advance(tree2::RcppR6::RcppR6<ode::OdeSystem<ode::test::Lorenz> > obj_, double t, double dt) {
  obj_->advance(t, dt);
}
// [[Rcpp::export]]
ode::state_saver<std::vector<double> > OdeSystem___Lorenz__advance_save(tree2::RcppR6::RcppR6<ode::OdeSystem<ode::test::Lorenz> > obj_, double t, double dt) {
  return obj_->advance_save(t, dt);
}
// [[Rcpp::export]]
ode::test::Lorenz OdeSystem___Lorenz__obj__get(tree2::RcppR6::RcppR6<ode::OdeSystem<ode::test::Lorenz> > obj_) {
  return obj_->get_obj();
}

// [[Rcpp::export]]
double OdeSystem___Lorenz__t__get(tree2::RcppR6::RcppR6<ode::OdeSystem<ode::test::Lorenz> > obj_) {
  return obj_->t;
}
// [[Rcpp::export]]
void OdeSystem___Lorenz__t__set(tree2::RcppR6::RcppR6<ode::OdeSystem<ode::test::Lorenz> > obj_, double value) {
  obj_->t = value;
}

// [[Rcpp::export]]
std::vector<double> OdeSystem___Lorenz__y__get(tree2::RcppR6::RcppR6<ode::OdeSystem<ode::test::Lorenz> > obj_) {
  return obj_->y;
}
// [[Rcpp::export]]
void OdeSystem___Lorenz__y__set(tree2::RcppR6::RcppR6<ode::OdeSystem<ode::test::Lorenz> > obj_, std::vector<double> value) {
  obj_->y = value;
}


// [[Rcpp::export]]
tree2::CohortSchedule::Event CohortScheduleEvent__ctor(double introduction, size_t species_index) {
  return tree2::CohortSchedule::Event(introduction, species_index);
}
// [[Rcpp::export]]
size_t CohortScheduleEvent__species_index__get(tree2::RcppR6::RcppR6<tree2::CohortSchedule::Event> obj_) {
  return obj_->r_species_index();
}

// [[Rcpp::export]]
std::vector<double> CohortScheduleEvent__times__get(tree2::RcppR6::RcppR6<tree2::CohortSchedule::Event> obj_) {
  return obj_->times;
}

// [[Rcpp::export]]
double CohortScheduleEvent__time_introduction__get(tree2::RcppR6::RcppR6<tree2::CohortSchedule::Event> obj_) {
  return obj_->time_introduction();
}

// [[Rcpp::export]]
double CohortScheduleEvent__time_end__get(tree2::RcppR6::RcppR6<tree2::CohortSchedule::Event> obj_) {
  return obj_->time_end();
}

