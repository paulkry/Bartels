#ifndef SIM_linear_tri3dmesh_stvk_dq2_H
#define SIM_linear_tri3dmesh_stvk_dq2_H

#include <Eigen/Dense>
#include <EigenTypes.h>

#include <assemble.h>
#include <linear_tri3d_stvk_dq2.h>


namespace sim {

//some c++ trickery to allow for default call backs 
auto default_callback = [](auto &element_matrix){};

template<typename DerivedRet, int Options, typename StorageIndex,
        typename DerivedV, typename DerivedQ, typename DefoType, 
         typename NormalType,
         typename DNormalType,
         typename DerivedVol, 
         typename DerivedParam, class ElementMatrixCallback = decltype(default_callback)>
void linear_tri3dmesh_stvk_dq2(Eigen::SparseMatrix<DerivedRet, Options, StorageIndex> &H, Eigen::DenseBase<DerivedV> &V,  Eigen::Ref<const Eigen::MatrixXi> E,
                                        const Eigen::MatrixBase<DerivedQ> &q, 
                                        const Eigen::MatrixBase<DefoType> &dXinv, 
                                        const Eigen::MatrixBase<NormalType> &N,
                                        const Eigen::MatrixBase<NormalType> &n, 
                                        const Eigen::MatrixBase<DNormalType> &dndq,
                                        const Eigen::MatrixBase<DerivedVol>  &volume, 
                                        const Eigen::MatrixBase<DerivedParam> &params,
                                        const ElementMatrixCallback func = default_callback);



}

#ifndef SIM_STATIC_LIBRARY
#   include <../src/linear_tri3dmesh_stvk_dq2.cpp>
#endif

#endif