/*******************************************************************************
* Copyright (C) 2017 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the 'License');
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
* 
* http://www.apache.org/licenses/LICENSE-2.0
* 
* Unless required by applicable law or agreed to in writing,
* software distributed under the License is distributed on an 'AS IS' BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions
* and limitations under the License.
* 
*******************************************************************************/

#include "gsmodmethodstuff.h"

/*
   methods
*/

static gsModMethod* gsModArith_C(void)
{
   static gsModMethod m = {
      gs_mont_encode,
      gs_mont_decode,
      gs_mont_mul,
      gs_mont_sqr,
      gs_mont_red,
      gs_mont_add,
      gs_mont_sub,
      gs_mont_neg,
      gs_mont_div2,
      gs_mont_mul2,
      gs_mont_mul3,
   };
   return &m;
}

#if (_IPP32E>=_IPP32E_L9)
static gsModMethod* gsModArith_X(void)
{
   static gsModMethod m = {
      gs_mont_encodeX,
      gs_mont_decodeX,
      gs_mont_mulX,
      gs_mont_sqrX,
      gs_mont_redX,
      gs_mont_add,
      gs_mont_sub,
      gs_mont_neg,
      gs_mont_div2,
      gs_mont_mul2,
      gs_mont_mul3,
   };
   return &m;
}
#endif

IPP_OWN_DEFN (gsModMethod*, gsModArith, (void))
{
   #if (_IPP32E>=_IPP32E_L9)
   if(IsFeatureEnabled(ippCPUID_ADCOX))
      return gsModArith_X();
   else
   #endif
      return gsModArith_C();
}
