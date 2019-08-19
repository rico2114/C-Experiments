//
// Created by Juan Sebastian Quiceno Rico on 2019-08-18.
//

#ifndef EXPERIMENTS_MACROS_H
#define EXPERIMENTS_MACROS_H

namespace Macros {

#define MEASURE_SET_UP(__class__, __value__) template<> bool COUNT_SET_UP<__class__>::value = __value__;

}

#endif //EXPERIMENTS_MACROS_H
