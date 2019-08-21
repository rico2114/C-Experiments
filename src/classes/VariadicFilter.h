//
// Created by Juan Sebastian Quiceno Rico on 2019-08-20.
//

#ifndef EXPERIMENTS_VARIADICFILTER_H
#define EXPERIMENTS_VARIADICFILTER_H

#include "VariadicClass.h"

template <typename ... As1, typename ... As2>
static VariadicClass<As1...> * Filter(VariadicClass<As2...> in)
{
    using unused = int[];
    auto ret = new VariadicClass<As1...>();
    (void)unused { 0, (ret->template Set<As1>(in.template Get<As1>()), 0)... };
    return ret;
}

#endif //EXPERIMENTS_VARIADICFILTER_H
