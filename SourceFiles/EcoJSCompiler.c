/*
 *
 * <сводка>
 *   Функция GetBNFForSAOfJS
 * </сводка>
 *
 * <описание>
 *   Функция GetBNFForSAOfJS - возвращает контекстно-свободную грамматику в BNF форме для синтаксического анализа
 * </описание>
 *
 */

IEcoToolchainBNF1* GetBNFForSAOfJS(IEcoToolchainBNF1* pIBNF) {
    /* Интерфейсы для работы с грамматикой */
    IEcoToolchainBNF1Rule* pIRule = 0;
    IEcoToolchainBNF1Element* pIElement = 0;
    uint32_t indexSet = 0;
    bool_t bOptFALSE = 0;
    bool_t bOptTRUE = 1;

    /* Все что ниже написал Игорь Краснюков */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "CoalesceExpression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "CoalesceExpressionHead", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "??", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "BitwiseORExpression", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "CoalesceExpressionHead");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "CoalesceExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "BitwiseORExpression", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ShortCircuitExpression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "LogicalORExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "CoalesceExpression", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ConditionalExpression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ShortCircuitExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ShortCircuitExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "?", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AssignmentExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ":", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AssignmentExpression", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "AssignmentExpression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ConditionalExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "YieldExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ArrowFunction", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "AsyncArrowFunction", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "LeftHandSideExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "=", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AssignmentExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "LeftHandSideExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AssignmentOperator", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AssignmentExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "LeftHandSideExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "&&=", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AssignmentExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "LeftHandSideExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "||=", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AssignmentExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "LeftHandSideExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "??=", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AssignmentExpression", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "AssignmentOperator");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "*=", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "/=", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "%=", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "+=", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "-=", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "<<=", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, ">>=", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, ">>>=", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "&=", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "^=", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "|=", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "**=", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "AssignmentExpression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "LeftHandSideExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "=", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AssignmentExpression", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "AssignmentPattern");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ObjectAssignmentPattern", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ArrayAssignmentPattern", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ObjectAssignmentPattern");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "{", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "}", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "{", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AssignmentRestProperty", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "}", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "{", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AssignmentPropertyList", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "}", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "{", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AssignmentPropertyList", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ",", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AssignmentRestProperty", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "}", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ArrayAssignmentPattern");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "[", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Elision", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AssignmentRestElement", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "]", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "[", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AssignmentElementList", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "]", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "[", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AssignmentElementList", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ",", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Elision", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AssignmentRestElement", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "]", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "AssignmentRestProperty");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "...", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "DestructuringAssignmentTarget", bOptFALSE);

    // rule for AssignmentPropertyList
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "AssignmentPropertyList");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "AssignmentProperty", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "AssignmentPropertyList", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ",", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AssignmentProperty", bOptFALSE);

    // rule for AssignmentElementList
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "AssignmentElementList");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "AssignmentElisionElement", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "AssignmentElementList", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ",", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AssignmentElisionElement", bOptFALSE);

    // rule for AssignmentElisionElement
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "AssignmentElisionElement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "Elision", bOptTRUE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AssignmentElement", bOptFALSE);

    // rule for AssignmentProperty
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "AssignmentProperty");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "IdentifierReference", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Initializer", bOptTRUE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "PropertyName", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ":", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AssignmentElement", bOptFALSE);

    // rule for AssignmentElement
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "AssignmentElement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "DestructuringAssignmentTarget", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Initializer", bOptTRUE);

    // rule for AssignmentRestElement
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "AssignmentRestElement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "...", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "DestructuringAssignmentTarget", bOptFALSE);

    // rule for DestructuringAssignmentTarget
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "DestructuringAssignmentTarget");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "LeftHandSideExpression", bOptFALSE, &indexSet);

    // rule for Expression
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "Expression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "AssignmentExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "Expression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ",", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AssignmentExpression", bOptFALSE);

    // A3 Statements
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "Statement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "BlockStatement", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "VariableStatement", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "EmptyStatement", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "IfStatement", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "BreakableStatement", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ContinueStatement", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "BreakStatement", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ReturnStatement", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "WithStatement", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "LabelledStatement", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ThrowStatement", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "TryStatement", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "DebuggerStatement", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "Declaration");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "HoistableDeclaration", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ClassDeclaration", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "LexicalDeclaration", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "HoistableDeclaration");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "FunctionDeclaration", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "GeneratorDeclaration", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "AsyncFunctionDeclaration", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "AsyncGeneratorDeclaration", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "BreakableStatement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "IterationStatement", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "SwitchStatement", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "BlockStatement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "Block", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "Block");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "{", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "StatementList", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "}", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "StatementList");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "StatementListItem", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "StatementList", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "StatementListItem", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "StatementListItem");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "Statement", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "Declaration", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "LexicalDeclaration");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "LetOrConst", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "BindingList", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ";", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "LetOrConst");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "let", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "const", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "BindingList");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "LexicalBinding", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "BindingList", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ",", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "LexicalBinding", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "LexicalBinding");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "BindingIdentifier", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Initializer", bOptTRUE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "BindingPattern", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Initializer", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "VariableStatement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "var", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "VariableDeclarationList", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "VariableDeclarationList");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "VariableDeclaration", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "VariableDeclarationList", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ",", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "VariableDeclaration", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "VariableDeclaration");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "BindingIdentifier", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Initializer", bOptTRUE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "BindingPattern", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Initializer", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "BindingPattern");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ObjectBindingPattern", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ArrayBindingPattern", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ObjectBindingPattern");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "{", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "}", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "{", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "BindingRestProperty", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "}", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "{", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "BindingPropertyList", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "}", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "{", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "BindingPropertyList", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ",", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "BindingRestProperty", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "}", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ArrayBindingPattern");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "[", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Elision", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "BindingRestElement", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "]", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "[", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "BindingElementList", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "]", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "[", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "BindingElementList", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ",", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Elision", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "BindingRestElement", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "]", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "BindingRestProperty");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "...", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "BindingIdentifier", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "BindingPropertyList");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "BindingProperty", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "BindingPropertyList", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ",", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "BindingProperty", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "BindingElementList");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "BindingElisionElement", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "BindingElementList", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ",", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "BindingElisionElement", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "BindingElisionElement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "Elision", bOptTRUE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "BindingElement", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "BindingProperty");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "SingleNameBinding", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "PropertyName", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ":", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "BindingElement", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "BindingElement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "SingleNameBinding", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "BindingPattern", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Initializer", bOptTRUE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "SingleNameBinding");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "BindingIdentifier", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Initializer", bOptTRUE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "BindingRestElement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "...", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "BindingIdentifier", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "...", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "BindingPattern", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "EmptyStatement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, ";", bOptFALSE, &indexSet);

    // lookahead and LineTerminatorHere are not supported
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ExpressionStatement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "Expression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ";", bOptFALSE);

    // lookagead is not supported
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "IfStatement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "if", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Expression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Statement", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "else", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Statement", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "if", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Expression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Statement", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "IterationStatement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "DoWhileStatement", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "WhileStatement", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ForStatement", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ForInOfStatement", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "DoWhileStatement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "do", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Statement", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "while", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Expression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ";", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "WhileStatement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "while", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Expression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Statement", bOptFALSE);

    // lookagead is not supported
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ForStatement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "for", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Expression", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ";", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Expression", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ";", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Expression", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Statement", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "for", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "var", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "VariableDeclarationList", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ";", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Expression", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ";", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Expression", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Statement", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "for", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "LexicalDeclaration", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Expression", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ";", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Expression", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Statement", bOptFALSE);

    // lookagead is not supported
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ForInOfStatement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "for", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "LeftHandSideExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "in", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Expression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Statement", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "for", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "var", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ForBinding", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "in", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Expression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Statement", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "for", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ForDeclaration", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "in", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Expression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Statement", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "for", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "LeftHandSideExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "of", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "AssignmentExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Statement", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "for", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "var", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ForBinding", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "of", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "AssignmentExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Statement", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "for", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ForDeclaration", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "of", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "AssignmentExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Statement", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "for", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "await", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "LeftHandSideExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "of", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "AssignmentExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Statement", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "for", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "await", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "var", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ForBinding", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "of", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "AssignmentExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Statement", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "for", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "await", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ForDeclaration", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "of", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "AssignmentExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Statement", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ForDeclaration");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "LetOrConst", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ForBinding", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ForBinding");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "BindingIdentifier", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "BindingPattern", bOptFALSE, &indexSet);

    // NoLineTerminator not implemented
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ContinueStatement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "continue", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ";", bOptTRUE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "continue", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "LabelIdentifier", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ";", bOptTRUE);

    // NoLineTerminator not implemented
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "BreakStatement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "break", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ";", bOptTRUE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "break", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "LabelIdentifier", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ";", bOptTRUE);

    // NoLineTerminator not implemented
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ReturnStatement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "return", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ";", bOptTRUE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "return", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Expression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ";", bOptTRUE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "WithStatement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "with", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Expression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Statement", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "SwitchStatement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "switch", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Expression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "CaseBlock", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "CaseBlock");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "{", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "CaseClauses", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "}", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "{", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "CaseClauses", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "DefaultClause", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "CaseClauses", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "}", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "CaseClauses");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "CaseClause", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "CaseClauses", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "CaseClause", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "CaseClause");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "case", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Expression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ":", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "StatementList", bOptTRUE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "DefaultClause");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "default", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ":", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "StatementList", bOptTRUE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "LabelledStatement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "LabelIdentifier", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ":", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "LabelledItem", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "LabelledItem");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "Statement", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "FunctionDeclaration", bOptFALSE, &indexSet);

    // NoLineTerminator not implemented
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ThrowStatement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "throw", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Expression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ";", bOptTRUE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "TryStatement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "try", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Block", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Catch", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "try", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Block", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Finally", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "try", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Block", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Catch", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Finally", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "Catch");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "catch", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "CatchParameter", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Block", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "catch", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Block", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "Finally");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "finally", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Block", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "CatchParameter");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "BindingIdentifier", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "BindingPattern", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "DebuggerStatement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "debugger", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ";", bOptTRUE);
    
    return pIBNF;
}