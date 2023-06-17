/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   EcoMyGrammar
 * </сводка>
 *
 * <описание>
 *   Данный файл описывает прототипы функций описания грамматики
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */

#include "IEcoFSM1.h"
#include "IEcoToolchainBNF1.h"
#include "IEcoToolchainRL1.h"

/* Прототипы функций */
IEcoFSM1StateMachine* GetFAForLAOfMy (IEcoFSM1* pIFSM);
IEcoToolchainRL1Grammar* GetRGForLAOfMy (IEcoToolchainRL1* pIRL);
IEcoToolchainBNF1* GetBNFForSAOfMy(IEcoToolchainBNF1* pIBNF);
