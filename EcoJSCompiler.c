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

    /* Beginning */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "c0-begin-state");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "translation-unit", bOptFALSE, &indexSet);

    // Part from Anashkin Ilya

    /* A.2 Expressions */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "IdentifierReference");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "Identifier", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "yield", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "await", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "BindingReference");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "Identifier", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "yield", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "await", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "LabelReference");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "Identifier", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "yield", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "await", bOptFALSE, &indexSet);

    /* IdentifierName but not ReservedWord - кажется по интерфейсу не реализуемо but not ситуация*/
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "Identifier");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "IdentifierName", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "PrimaryExpression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "this", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "IdentifierReference", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "Literal", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ArrayLiteral", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ObjectLiteral", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "FunctionExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "GeneratorExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "AsyncFunctionExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "AsyncGeneratorExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "RegularExpressionLiteral", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "TemplateLiteral", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "CoverParenthesizedExpressionAndArrowParameterList", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "CoverParenthesizedExpressionAndArrowParameterList");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "(", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Expression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "(", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Expression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ",", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "(", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "(", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "...", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "BindingIdentifier", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "(", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Expression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ",", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "...", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "BindingIdentifier", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "(", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Expression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ",", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "...", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "BindingPattern", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ")", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ParenthesizedExpression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "(", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Expression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ")", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "Literal");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "NullLiteral", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "BooleanLiteral", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "NumericLiteral", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "StringLiteral", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ArrayLiteral");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "[", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Elision", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "]", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "[", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "ElementList", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "]", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "[", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "ElementList", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ",", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Elision", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "]", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ElementList");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "Elision", bOptTRUE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AssignmentExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "Elision", bOptTRUE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "SpreadElement", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ElementList", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ",", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Elision", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AssignmentExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ElementList", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ",", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Elision", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "SpreadElement", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "Elision");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, ",", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "Elision", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ",", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "SpreadElement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "...", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AssignmentExpression", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ObjectLiteral");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "{", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "}", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "{", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "PropertyDefinitionList", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "}", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "{", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "PropertyDefinitionList", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ",", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "}", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "PropertyDefinitionList");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "PropertyDefinition", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "PropertyDefinitionList", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ",", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "PropertyDefinition", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "PropertyDefinition");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "IdentifierReference", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "CoverInitializedname", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "PropertyName", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ":", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AssignmentExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "MethodDefinition", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "...", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AssignmentExpression", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "PropertyName");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "LiteralPropertyName", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ComputedPropertyName", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "LiteralPropertyName");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "IdentifierName", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "StringLiteral", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "NumericLiteral", bOptFALSE, &indexSet);
    
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ComputedPropertyName");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "[", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AssignmentExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "]", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "CoverInitializedName");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "IdentifierReference", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Initializer", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "Initializer");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "=", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AssignmentExpression", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "TemplateLiteral");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "NoSubstitutionTemplate", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "SubstitutionTemplate", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "SubstitutionTemplate");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "TemplateHead", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Expression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "TemplateSpans", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "TemplateSpans");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "TemplateTail", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "TemplateMiddleList", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "TemplateTail", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "TemplateMiddleList");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "TemplateMiddle", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Expression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "TemplateMiddleList", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "TemplateMiddle", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Expression", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "MemberExpression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "PrimaryExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "MemberExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "[", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Expression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "]", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "MemberExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ".", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "IdentifierName", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "MemberExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "TemplateLiteral", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "SuperProperty", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "MetaProperty", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "new", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "MemberExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Arguments", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "MemberExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ".", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "PrivateIdentifier", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "SuperProperty");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "super", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "[", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Expression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "]", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "super", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ".", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "IdentifierName", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "super", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "MetaProperty");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "NewTarget", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ImportMeta", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "NewTarget");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "new", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ".", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "target", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ImportMeta");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "import", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ".", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "meta", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "NewExpression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "MemberExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "new", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "NewExpression", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "CallExpression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "CoverCallExpressionAndAsyncArrowHead", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "SuperCall", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ImportCall", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "CallExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Arguments", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "CallExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "[", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Expression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "]", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "CallExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ".", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "IdentifierName", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "CallExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "TemplateLiteral", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "CallExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ".", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "PrivateIdentifier", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "CallMemberExpression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "MemberExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Arguments", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "SuperCall");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "super", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Arguments", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ImportCall");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "import", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AssignmentExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ")", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "Arguments");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "(", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "(", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "ArgumentList", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "(", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "ArgumentList", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ",", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ")", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ArgumentList");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "AssignmentExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "...", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AssignmentExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ArgumentList", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ",", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AssignmentExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ArgumentList", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ",", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "...", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AssignmentExpression", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "OptionalExpression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "MemberExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "OptionalChain", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "CallExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "OptionalChain", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "OptionalExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "OptionalChain", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "OptionalChain");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "?.", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Arguments", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "?.", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "[", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Expression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "]", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "?.", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "IdentifierName", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "?.", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "TemplateLiteral", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "?.", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "PrivateIdentifier", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "OptionalChain", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Arguments", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "OptionalChain", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "[", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "Expression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "]", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "OptionalChain", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ".", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "IdentifierName", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "OptionalChain", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "TemplateLiteral", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "OptionalChain", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ".", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "PrivateIdentifier", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "LeftHandSideExpression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "NewExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "CallExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "OptionalExpression", bOptFALSE, &indexSet);

    // no LineTerminator here - нет возможности добавить
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "UpdateExpression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "LeftHandSideExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "LeftHandSideExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "++", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "LeftHandSideExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "--", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "++", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "UnaryExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "--", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "UnaryExpression", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "UnaryExpression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "UpdateExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "delete", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "UnaryExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "void", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "UnaryExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "typeof", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "UnaryExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "+", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "UnaryExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "-", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "UnaryExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "~", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "UnaryExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "!", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "UnaryExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "AwaitExpression", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ExponentiationExpression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "UnaryExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "UpdateExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "**", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "ExponentiationExpression", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "MultiplicativeExpression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ExponentiationExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "MultiplicativeExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "MultiplicativeOperator", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "ExponentiationExpression", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "MultiplicativeOperator");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "*", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "/", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "%", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "AdditiveOperator");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "MultiplicativeExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "AdditiveExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "+", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "MultiplicativeExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "AdditiveExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "-", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "MultiplicativeExpression", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ShiftExpression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "AdditiveExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ShiftExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "<<", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AdditiveExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ShiftExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ">>", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AdditiveExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ShiftExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ">>>", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "AdditiveExpression", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "RelationalExpression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ShiftExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "RelationalExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "<", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "ShiftExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "RelationalExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ">", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "ShiftExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "RelationalExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "<=", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "ShiftExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "RelationalExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  ">=", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "ShiftExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "RelationalExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "instanceof", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "ShiftExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "RelationalExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "in", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "ShiftExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "PrivateIdentifier", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "in", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "ShiftExpression", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "EqualityExpression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "RelationalExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "EqualityExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "==", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "RelationalExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "EqualityExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "!=", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "RelationalExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "EqualityExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "===", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "RelationalExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "EqualityExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "!==", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "RelationalExpression", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "BitwiseANDExpression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "EqualityExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "BitwiseANDExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "&", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "EqualityExpression", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "BitwiseXORExpression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "BitwiseANDExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "BitwiseXORExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "^", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "BitwiseANDExpression", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "BitwiseORExpression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "BitwiseXORExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "BitwiseORExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "|", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "BitwiseXORExpression", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "LogicalANDExpression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "BitwiseORExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "LogicalANDExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "&&", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "BitwiseORExpression", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "LogicalORExpression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "LogicalANDExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "LogicalORExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "||", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet,  "LogicalANDExpression", bOptFALSE);

    // Part from Daniel Pustotin

    /* A.4 Functions and Classes */
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "UniqueFormalParameters");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "FormalParameters", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "FormalParameters");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "FunctionRestParameter", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "FormalParameterList", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "FormalParameterList", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ",", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "FormalParameterList", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ",", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "FunctionRestParameter", bOptFALSE);
    
    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "FormalParameterList");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "FormalParameter", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "FormalParameterList", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ",", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "FormalParameter", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "FunctionRestParameter");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "BindingRestElement", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "FormalParameter");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "BindingElement", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "FunctionDeclaration");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "function", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "BindingIdentifier", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "FormalParameters", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "{", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "FunctionBody", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "}", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "function", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "FormalParameters", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "{", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "FunctionBody", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "}", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "FunctionExpression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "function", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "BindingIdentifier", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "FormalParameters", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "{", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "FunctionBody", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "}", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "FunctionBody");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "FunctionStatementList", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "FunctionStatementList");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "StatementList", bOptTRUE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ArrowFunction");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ArrowParameters", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "=>", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ConciseBody", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ArrowParameters");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "BindingIdentifier", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "CoverParenthesizedExpressionAndArrowParameterList", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ConciseBody");
    // Lookahead - not "{"
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ExpressionBody", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "{", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "FunctionBody", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "}", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ExpressionBody");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "AssignmentExpression", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ArrowFormalParameters");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "(", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "UniqueFormalParameters", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "AsyncArrowFunction");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "async", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "AsyncArrowBindingIdentifier", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "=>", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "AsyncConciseBody", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "CoverCallExpressionAndAsyncArrowHead", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "=>", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "AsyncConciseBody", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "AsyncConciseBody");
    // Lookahead - not "{"
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ExpressionBody", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "{", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "AsyncFunctionBody", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "}", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "AsyncArrowBindingIdentifier");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "BindingIdentifier", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "CoverCallExpressionAndAsyncArrowHead");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "MemberExpression", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Arguments", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "AsyncArrowHead");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "async", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ArrowFormalParameters", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "MethodDefinition");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ClassElementName", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "UniqueFormalParameters", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "{", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "FunctionBody", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "}", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "GeneratorMethod", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "AsyncMethod", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "AsyncGeneratorMethod", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "get", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ClassElementName", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "{", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "FunctionBody", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "}", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "set", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ClassElementName", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "PropertySetParameterList", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "{", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "FunctionBody", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "}", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "PropertySetParameterList");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "FormalParameter", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "GeneratorDeclaration");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "function", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "*", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "BindingIdentifier", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "FormalParameters", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "{", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "GeneratorBody", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "}", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "function", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "*", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "FormalParameters", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "{", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "GeneratorBody", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "}", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "GeneratorExpression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "function", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "*", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "BindingIdentifier", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "FormalParameters", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "{", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "GeneratorBody", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "}", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "GeneratorMethod");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "*", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ClassElementName", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "UniqueFormalParameters", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "{", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "GeneratorBody", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "}", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "GeneratorBody");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "FunctionBody", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "YieldExpression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "yield", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "yield", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "AssignmentExpression", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "yield", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "*", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "AssignmentExpression", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "AsyncGeneratorDeclaration");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "async", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "function", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "*", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "BindingIdentifier", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "FormalParameters", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "{", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "AsyncGeneratorBody", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "}", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "async", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "function", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "*", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "FormalParameters", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "{", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "AsyncGeneratorBody", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "}", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "AsyncGeneratorExpression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "async", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "function", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "*", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "BindingIdentifier", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "FormalParameters", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "{", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "AsyncGeneratorBody", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "}", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "AsyncGeneratorMethod");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "async", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "*", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ClassElementName", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "UniqueFormalParameters", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "{", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "AsyncGeneratorBody", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "}", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "AsyncGeneratorBody");
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "FunctionBody", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "AsyncFunctionDeclaration");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "async", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "function", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "BindingIdentifier", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "FormalParameters", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "{", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "AsyncFunctionBody", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "}", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "async", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "function", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "FormalParameters", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "{", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "AsyncFunctionBody", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "}", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "AsyncFunctionExpression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "async", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "function", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "BindingIdentifier", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "FormalParameters", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "{", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "AsyncFunctionBody", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "}", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "AsyncMethod");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "async", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ClassElementName", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "(", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "UniqueFormalParameters", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ")", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "{", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "AsyncFunctionBody", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "}", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "AsyncFunctionBody");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "FunctionBody", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "AwaitExpression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "await", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "UnaryExpression", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ClassDeclaration");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "class", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "BindingIdentifier", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ClassTail", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "class", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ClassTail", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ClassExpression");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "class", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "BindingIdentifier", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ClassTail", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ClassTail");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ClassHeritage", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "{", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ClassBody", bOptTRUE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "}", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ClassHeritage");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "extends", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "LeftHandSideExpression", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ClassBody");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ClassElementList", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ClassElementList");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ClassElement", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ClassElementList", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ClassElement", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ClassElement");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "MethodDefinition", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "static", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "MethodDefinition", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "FieldDefinition", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "static", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "FieldDefinition", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ClassStaticBlock", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, ";", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "FieldDefinition");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ClassElementName", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Initializer", bOptTRUE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ClassElementName");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "PropertyName", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "PrivateIdentifier", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ClassStaticBlock");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "static", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "{", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ClassStaticBlockBody", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "}", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ClassStaticBlockBody");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ClassStaticBlockStatementList", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ClassStaticBlockStatementList");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "StatementList", bOptTRUE, &indexSet);

    /* A.5 Scripts and Modules */

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "Script");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ScriptBody", bOptTRUE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ScriptBody");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "StatementList", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "Module");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ModuleBody", bOptTRUE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ModuleBody");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ModuleItemList", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ModuleItemList");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ModuleItem", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ModuleItemList", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ModuleItem", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ModuleItem");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ImportDeclaration", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ExportDeclaration", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "StatementListItem", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ModuleExportName");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "IdentifierName", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "StringLiteral", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ImportDeclaration");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "import", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ImportClause", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "FromClause", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ";", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "import", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ModuleSpecifier", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ";", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ImportClause");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ImportedDefaultBinding", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "NameSpaceImport", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "NamedImports", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ImportedDefaultBinding", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ",", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "NameSpaceImport", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ImportedDefaultBinding", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ",", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "NamedImports", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ImportedDefaultBinding");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ImportedBinding", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "NameSpaceImport");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "*", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "as", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ImportedBinding", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "NamedImports");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "{", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "}", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "{", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ImportsList", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "}", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "{", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ImportsList", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ",", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "}", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "FromClause");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "from", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ModuleSpecifier", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ImportsList");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ImportSpecifier", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ImportsList", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ",", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ImportSpecifier", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ImportSpecifier");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ImportedBinding", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ModuleExportName", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "as", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ImportedBinding", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ModuleSpecifier");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "StringLiteral", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ImportedBinding");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "BindingIdentifier", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ExportDeclaration");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "export", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ExportFromClause", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "FromClause", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ";", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "export", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "NamedExports", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ";", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "export", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "VariableStatement", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "export", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "Declaration", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "export", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "default", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "HoistableDeclaration", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "export", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "default", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ClassDeclaration", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "export", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "default", bOptFALSE);
    // Lookahead - not "function", "async function", "class"
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "AssignmentExpression", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ExportFromClause");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "*", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "*", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "as", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ModuleExportName", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "NamedExports", bOptFALSE, &indexSet);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "NamedExports");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "{", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "}", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "{", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ExportsList", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "}", bOptFALSE);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "{", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ExportsList", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ",", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "}", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ExportsList");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ExportSpecifier", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ExportsList", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, ",", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "ExportSpecifier", bOptFALSE);

    pIRule = pIBNF->pVTbl->AddRule(pIBNF, "ExportSpecifier");
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ModuleExportName", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddAlternative(pIRule, "ModuleExportName", bOptFALSE, &indexSet);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "as", bOptFALSE);
    pIElement = pIRule->pVTbl->AddConcatenation(pIRule, indexSet, "IdentifierName", bOptFALSE);

    return pIBNF;
}