/*******************************************************************************
* Copyright (C) 2002 Intel Corporation
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

/* 
// 
//  Purpose:
//     Cryptography Primitive.
//     Encrypt byte data stream according to TDES (CBC mode)
// 
//  Contents:
//     EncyptCBC_TDES()
// 
// 
*/

#include "owndefs.h"
#include "owncp.h"
#include "pcpdes.h"

IPP_OWN_DEFN (void, EncryptCBC_TDES, (const Ipp64u* pSrc, Ipp64u* pDst, int nBlocks, const RoundKeyDES* pRKey[3], Ipp64u iv, const Ipp32u spbox[]))
{
   while(nBlocks) {
      Ipp64u tmp = *pSrc ^ iv;
      tmp = Cipher_DES(tmp, pRKey[0], spbox);
      tmp = Cipher_DES(tmp, pRKey[1], spbox);
      tmp = Cipher_DES(tmp, pRKey[2], spbox);
      *pDst = tmp;
      iv = tmp;
      pSrc++;
      pDst++;
      nBlocks--;
   }
}
