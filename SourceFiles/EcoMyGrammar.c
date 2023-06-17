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
 *   Данный файл является описание грамматики
 * </описание>
 *
 * <автор>
 *   Copyright (c) 2018 Vladimir Bashev. All rights reserved.
 * </автор>
 *
 */


/* Eco OS */
#include "EcoMyGrammar.h"

bool_t MakeTransitions(/* in */ IEcoFSM1State* pISourceState, /* in */ IEcoFSM1State* pITargetState, /* in */ IEcoList1* pIEvents);
bool_t MakeExceptEventTransitions(/* in */ IEcoFSM1State* pISourceState, /* in */ IEcoFSM1State* pITargetState, /* in */ IEcoList1* pIExceptEvents);

/*
 *
 * <сводка>
 *   Функция GetFAForLAOfMy
 * </сводка>
 *
 * <описание>
 *   Функция GetFAForLAOfMy - возвращает конечный автомат для лексического анализа
 * </описание>
 *
 */
IEcoFSM1StateMachine* GetFAForLAOfMy(IEcoFSM1* pIFSM) {
    IEcoFSM1StateMachine* pIFA = 0;
    IEcoFSM1Event* pIEvent[256] = {0};
    IEcoFSM1State* pIState[3] = {0};

    /* Создаем конечный автомат */
    pIFA = pIFSM->pVTbl->CreateStateMachine(pIFSM, "My");

    /* Добавляем состояния */
    pIState[0] = pIFA->pVTbl->AddState(pIFA, "q0");
    pIState[1] = pIFA->pVTbl->AddState(pIFA, "q1");
    pIState[2] = pIFA->pVTbl->AddState(pIFA, "q2");

    /* Создадим массив событий для алфавита по прядку кодов ASCII таблицы */
    /* Конец файла EOF */
    pIEvent[0] = pIFA->pVTbl->AddEvent(pIFA, "EOF", 0, 0);
    /* Конец строки \r\n */
    pIEvent[10] = pIFA->pVTbl->AddEvent(pIFA, "LF", 10, 0); /* \n */
    pIEvent[13] = pIFA->pVTbl->AddEvent(pIFA, "CR", 13, 0); /* \r */
    /* Пробел и табуляция */
    pIEvent[9] = pIFA->pVTbl->AddEvent(pIFA, "HT", 9, 0);
    pIEvent[32] = pIFA->pVTbl->AddEvent(pIFA, "SP", 32, 0);
    /* Пунктуация */
    pIEvent['*'] = pIFA->pVTbl->AddEvent(pIFA, "*", '*', 0);
    pIEvent['+'] = pIFA->pVTbl->AddEvent(pIFA, "+", '+', 0);
    /* Диапазон [0-9] */
    pIEvent['0'] = pIFA->pVTbl->AddEvent(pIFA, "0", '0', 0);
    pIEvent['1'] = pIFA->pVTbl->AddEvent(pIFA, "1", '1', 0);

    /* Устанавливаем начальное состояние автомата */
    pIState[0]->pVTbl->set_Initial(pIState[0], 1);

    /* Устанавливаем акцепторы - токены */
    pIState[2]->pVTbl->set_Final(pIState[2], 1);
    pIState[2]->pVTbl->set_Parameter(pIState[2], "final");
    /* ловушки - ошибки */
    pIState[1]->pVTbl->set_Trap(pIState[1], 1);
    pIState[1]->pVTbl->set_Parameter(pIState[1], "trap");

    /* Общая схема переходов нарисована в VISIO */

    /* Создаем переходы для новой строки */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[13],  pIState[0],  pIState[2]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[10],  pIState[0],  pIState[2]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[13],  pIState[1],  pIState[2]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[10],  pIState[1],  pIState[2]);

    /* Создаем переходы для пробелов и табуляции */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[32],  pIState[0],  pIState[1]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[9],  pIState[0],  pIState[1]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[32],  pIState[1],  pIState[1]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent[9],  pIState[1],  pIState[1]);

    /* Создаем переходы */
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['0'],  pIState[0],  pIState[1]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['1'],  pIState[0],  pIState[1]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['0'],  pIState[1],  pIState[1]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['1'],  pIState[1],  pIState[1]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['+'],  pIState[1],  pIState[1]);
    pIFA->pVTbl->AddTransition(pIFA, pIEvent['*'],  pIState[1],  pIState[1]);

    return pIFA;
}


/*
 *
 * <сводка>
 *   Функция GetRGForLAOfMy
 * </сводка>
 *
 * <описание>
 *   Функция GetRGForLAOfMy - возвращает регулярную грамматику для лексического анализа
 * </описание>
 *
 */
IEcoToolchainRL1Grammar* GetRGForLAOfMy (IEcoToolchainRL1* pIRL) {
    IEcoToolchainRL1Grammar* pIRG = 0;

    /* Создаем конечный автомат */
    pIRG = pIRL->pVTbl->CreateRegularGrammar(pIRL, "My", 0);


    return pIRG;
}


/*
 *
 * <сводка>
 *   Функция GetBNFForSAOfMy
 * </сводка>
 *
 * <описание>
 *   Функция GetBNFForSAOfMy - возвращает контекстно-свободную грамматику в BNF форме для синтаксического анализа
 * </описание>
 *
 */
IEcoToolchainBNF1* GetBNFForSAOfMy(IEcoToolchainBNF1* pIBNF) {
    /* Интерфейсы для работы с грамматикой */
    IEcoToolchainBNF1Rule* pIRule = 0;
    IEcoToolchainBNF1Element* pIElement = 0;
    uint32_t indexSet = 0;
    bool_t bOptFALSE = 0;
    bool_t bOptTRUE = 1;

    /* Beginning */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "c0-begin-state");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "translation-unit", bOptFALSE, &indexSet);

    /* A.2.1 Expressions */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "primary-expression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "constant", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "operator");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "*", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "+", bOptFALSE, &indexSet);


    return pIBNF;
}