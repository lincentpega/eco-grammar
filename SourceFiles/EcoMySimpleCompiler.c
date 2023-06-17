/*
 * <кодировка символов>
 *   Cyrillic (UTF-8 with signature) - Codepage 65001
 * </кодировка символов>
 *
 * <сводка>
 *   EcoMySimpleCompiler
 * </сводка>
 *
 * <описание>
 *   Данный исходный файл является точкой входа
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */


/* Eco OS */
#include "IEcoSystem1.h"
#include "IdEcoMemoryManager1.h"
#include "IdEcoInterfaceBus1.h"
#include "IdEcoFileSystemManagement1.h"
#include "IdEcoToolchainRL1.h"
#include "IdEcoToolchainBNF1.h"
#include "IdEcoFSM1.h"
#include "IdEcoLog1.h"
#include "IdEcoString1.h"
#include "IdEcoList1.h"
#include "IEcoLog1FileAffiliate.h"
#include "EcoMyGrammar.h"
#include "EcoOutputDiagnostic.h"


/*
 *
 * <сводка>
 *   Функция EcoMain
 * </сводка>
 *
 * <описание>
 *   Функция EcoMain - точка входа
 * </описание>
 *
 */
int16_t EcoMain(IEcoUnknown* pIUnk) {
    int16_t result = -1;
    /* Указатель на системный интерфейс */
    IEcoSystem1* pISys = 0;
    /* Указатель на интерфейс работы с системной интерфейсной шиной */
    IEcoInterfaceBus1* pIBus = 0;
    /* Указатель на интерфейс работы с памятью */
    IEcoMemoryAllocator1* pIMem = 0;
    /* Указатель на интерфейс работы сo строкой */
    IEcoString1* pIStr = 0;
    /* Указатель на интерфейс работы с журналом */
    IEcoLog1* pILog = 0;
    IEcoLog1FileAffiliate* pIFileAffiliate = 0;
    /* Указатель на интерфейс работы с конечным автоматом */
    IEcoFSM1* pIFSM = 0;
    IEcoFSM1StateMachine* pIFA = 0;
    /* Интерфейсы для работы с регулярной грамматикой */
    IEcoToolchainRL1* pIRL = 0;
    IEcoToolchainRL1Grammar* pIRG = 0;
    IEcoToolchainRL1Expression* pIRE = 0;
    /* Интерфейсы для работы с грамматикой в БНФ */
    IEcoToolchainBNF1* pIMyGrLex = 0;
    IEcoToolchainBNF1* pIMyGrSyn = 0;

    /* Проверка и создание системного интрефейса */
    if (pISys == 0) {
        result = pIUnk->pVTbl->QueryInterface(pIUnk, &GID_IEcoSystem1, (void **)&pISys);
        if (result != 0 && pISys == 0) {
        /* Освобождение системного интерфейса в случае ошибки */
            goto Release;
        }
    }

    /* Получение интерфейса для работы с интерфейсной шиной */
    result = pISys->pVTbl->QueryInterface(pISys, &IID_IEcoInterfaceBus1, (void **)&pIBus);
    if (result != 0 || pIBus == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }
    /* Получение интерфейса для работы со строкой */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoString1, 0, &IID_IEcoString1, (void **)&pIStr);
    if (result != 0 || pIStr == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* Получение интерфейса распределителя памяти */
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoMemoryManager1, 0, &IID_IEcoMemoryAllocator1, (void**)&pIMem);
    if (result != 0 || pIMem == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    /* Получение интерфейса для работы с журналом */
    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLog1, 0, &IID_IEcoLog1, (void**) &pILog);
    if (result != 0|| pILog == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoLog1, 0, &IID_IEcoLog1FileAffiliate, (void**) &pIFileAffiliate);
    if (result != 0|| pIFileAffiliate == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }
    pILog->pVTbl->AddAffiliate(pILog, (IEcoLog1Affiliate*)pIFileAffiliate);
    pIFileAffiliate->pVTbl->Release(pIFileAffiliate);

    /* Получение интерфейса для работы с конечным автоматом */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoFSM1, 0, &IID_IEcoFSM1, (void **)&pIFSM);
    if (result != 0 || pIFSM == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    /* Получение интерфейса для работы с регулярной грамматикой  */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoToolchainRL1, 0, &IID_IEcoToolchainRL1, (void **)&pIRL);
    if (result != 0 || pIRL == 0) {
        /* Освобождение интерфейсов в случае ошибки */
        goto Release;
    }

    /* Получение интерфейса по работе с грамматикой синтаксического разбора My в БНФ */
    result = pIBus->pVTbl->QueryComponent(pIBus, &CID_EcoToolchainBNF1, 0, &IID_IEcoToolchainBNF1, (void**) &pIMyGrSyn);
    /* Проверка */
    if (result != 0 || pIMyGrSyn == 0) {
        /* Освобождение в случае ошибки */
        goto Release;
    }

    /* ВАРИАНТ 1: Формирование правил лексического анализа для My с помощью конечного автомата */
    pILog->pVTbl->InfoFormat(pILog, "****************************** MY OPTION 1 - FINITE AUTOMATA ******************************");
    pIFA = GetFAForLAOfMy(pIFSM);
    /* Вывод диагностической/отладочной информации */
    OutputDiagnosticInfoOfFA(ECO_LANG_MY, pILog, pIStr, pIFA);
    /* ИЛИ */
    /* ВАРИАНТ 2: Формирование правил лексического анализа для My с помощью регулярной грамматики */
    pILog->pVTbl->InfoFormat(pILog, "****************************** MY OPTION 2 - REGULAR GRAMMAR ******************************");
    pIRG = GetRGForLAOfMy(pIRL);
    /* Преобразование в конечный автомат */
    pIFA->pVTbl->Release(pIFA);
    pIRL->pVTbl->ConversionRGToFA(pIRL, pIRG, &pIFA);
    /* Вывод диагностической/отладочной информации */
    OutputDiagnosticInfoOfFA(ECO_LANG_MY, pILog, pIStr, pIFA);

    /* Формирование правил синтаксического анализа для My */
    pIMyGrSyn = GetBNFForSAOfMy(pIMyGrSyn);
    /* Вывод диагностической/отладочной информации */
    OutputDiagnosticInfoOfBNF(ECO_LANG_MY, pILog, pIStr, pIMyGrSyn);

Release:

    /* Освобождение интерфейса для работы с интерфейсной шиной */
    if (pIBus != 0) {
        pIBus->pVTbl->Release(pIBus);
    }

    /* Освобождение интерфейса работы с памятью */
    if (pIMem != 0) {
        pIMem->pVTbl->Release(pIMem);
    }

    /* Освобождение интерфейса для работы с грамматикой My */
    if (pIMyGrSyn != 0) {
        pIMyGrSyn->pVTbl->Release(pIMyGrSyn);
    }
    if (pIMyGrLex != 0) {
        pIMyGrLex->pVTbl->Release(pIMyGrLex);
    }

    /* Освобождение интерфейса для работы с регулярной грамматикой */
    if (pIRL != 0) {
        pIRL->pVTbl->Release(pIRL);
    }

    /* Освобождение интерфейса для работы с конечным автоматом */
    if (pIFSM != 0) {
        pIFSM->pVTbl->Release(pIFSM);
    }

    /* Освобождение интерфейса для работы с журналом*/
    if (pILog != 0) {
        pILog->pVTbl->Release(pILog);
    }

    /* Освобождение интерфейса для работы со строкой */
    if (pIStr != 0) {
        pIStr->pVTbl->Release(pIStr);
    }

    /* Освобождение системного интерфейса */
    if (pISys != 0) {
        pISys->pVTbl->Release(pISys);
    }

    return result;
}

