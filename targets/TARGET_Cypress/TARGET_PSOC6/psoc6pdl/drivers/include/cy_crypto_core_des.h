/***************************************************************************//**
* \file cy_crypto_core_des.h
* \version 2.20
*
* \brief
*  This file provides constant and parameters for the API for the DES method
*  in the Crypto driver.
*
********************************************************************************
* Copyright 2016-2019 Cypress Semiconductor Corporation
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*    http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/


#if !defined(CY_CRYPTO_CORE_DES_H)
#define CY_CRYPTO_CORE_DES_H

#include "cy_crypto_common.h"

#if defined(CY_IP_MXCRYPTO)

#if (CPUSS_CRYPTO_DES == 1)

#include "cy_crypto_core_des_v1.h"
#include "cy_crypto_core_des_v2.h"

typedef cy_en_crypto_status_t (*cy_crypto_des_func_t)(CRYPTO_Type *base,
                                        cy_en_crypto_dir_mode_t dirMode,
                                        uint8_t const *key,
                                        uint8_t *dst,
                                        uint8_t const *src);

/*******************************************************************************
* Function Name: Cy_Crypto_Core_Des
****************************************************************************//**
*
* Performs DES operation on a Single Block. All addresses must be 4-Byte aligned.
* Ciphertext (dstBlock) may overlap with plaintext (srcBlock)
* This function is independent from the previous Crypto state.
*
* \param base
* The pointer to the CRYPTO instance address.
*
* \param dirMode
* Can be \ref CY_CRYPTO_ENCRYPT or \ref CY_CRYPTO_DECRYPT
* (\ref cy_en_crypto_dir_mode_t)
*
* \param key
* The pointer to the encryption/decryption key.
*
* \param dst
* The pointer to a destination cipher block.
*
* \param src
* The pointer to a source block.
*
* \return
* A Crypto status \ref cy_en_crypto_status_t.
*
*******************************************************************************/
__STATIC_INLINE cy_en_crypto_status_t Cy_Crypto_Core_Des(CRYPTO_Type *base,
                                        cy_en_crypto_dir_mode_t dirMode,
                                        uint8_t const *key,
                                        uint8_t *dst,
                                        uint8_t const *src)
{
    cy_en_crypto_status_t myResult;

    if (cy_device->cryptoVersion == 1u)
    {
        myResult = Cy_Crypto_Core_V1_Des(base, dirMode, key, dst, src);
    }
    else
    {
        myResult = Cy_Crypto_Core_V2_Des(base, dirMode, key, dst, src);
    }

    return myResult;
}

/*******************************************************************************
* Function Name: Cy_Crypto_Core_Tdes
****************************************************************************//**
*
* Performs TDES operation on a Single Block. All addresses must be 4-Byte aligned.
* Ciphertext (dstBlock) may overlap with plaintext (srcBlock)
* This function is independent from the previous Crypto state.
*
* \param base
* The pointer to the CRYPTO instance address.
*
* \param dirMode
* Can be \ref CY_CRYPTO_ENCRYPT or \ref CY_CRYPTO_DECRYPT
* (\ref cy_en_crypto_dir_mode_t)
*
* \param key
* The pointer to the encryption/decryption keys.
*
* \param dst
* The pointer to a destination cipher block.
*
* \param src
* The pointer to a source data block.
*
* \return
* A Crypto status \ref cy_en_crypto_status_t.
*
*******************************************************************************/
__STATIC_INLINE cy_en_crypto_status_t Cy_Crypto_Core_Tdes(CRYPTO_Type *base,
                                        cy_en_crypto_dir_mode_t dirMode,
                                        uint8_t const *key,
                                        uint8_t *dst,
                                        uint8_t const *src)
{
    cy_en_crypto_status_t myResult;

    if (cy_device->cryptoVersion == 1u)
    {
        myResult = Cy_Crypto_Core_V1_Tdes(base, dirMode, key, dst, src);
    }
    else
    {
        myResult = Cy_Crypto_Core_V2_Tdes(base, dirMode, key, dst, src);
    }

    return myResult;
}

#endif /* #if (CPUSS_CRYPTO_DES == 1) */

#endif /* CY_IP_MXCRYPTO */

#endif /* #if !defined(CY_CRYPTO_CORE_DES_H) */


/* [] END OF FILE */

