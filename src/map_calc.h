#include "smc_base.h"
#include "tree_op.h"

#ifndef MAP_CALC_H
#define MAP_CALC_H

/*
 * Compute the logarithm of the graph theoretic length of the boundary between
 * `distr_root` and `distr_other`, where the root of `ust` is in `distr_root`
 */
double log_boundary(const Graph &g, const subview_col<uword> &districts,
                    int distr_root, int distr_other);

/*
 * Compute the status quo penalty for district `distr`
 */
double sq_entropy(const subview_col<uword> &districts, const uvec &current,
                  int distr, const uvec &pop, int n_distr, int n_current, int V);

/*
 * Compute the VRA penalty for district `distr`
 */
double eval_vra(const subview_col<uword> &districts, int distr, double tgt_min,
                double tgt_other, double pow_vra, const uvec &pop, const uvec &min_pop);

/*
 * Compute the incumbent-preserving penalty for district `distr`
 */
double eval_inc(const subview_col<uword> &districts, int distr, const uvec &incumbents);

/*
 * Compute the deviation from the equal population constraint.
 */
NumericMatrix pop_dev(const umat &districts, const subview_col<uword> &pop, int n_distr);

/*
 * Compute the maximum deviation from the equal population constraint.
 */
// [[Rcpp::export]]
NumericVector max_dev(const arma::umat &districts, const arma::uvec &pop, int n_distr);

/*
 * Calculate the deviation for cutting at every edge in a spanning tree.
 */
std::vector<double> tree_dev(Tree &ust, int root, const uvec &pop,
                             double total_pop, double target);


#endif
