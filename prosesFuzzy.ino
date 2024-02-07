//***********************************************************************
// Data for Fuzzy Inference System                                       
//***********************************************************************
// Pointers to the implementations of member functions
_FIS_MF fis_gMF[] =
{
    fis_trapmf, fis_trimf
};

// Count of member function for each Input
int fis_gIMFCount[] = { 3, 2, 4 };

// Count of member function for each Output 
int fis_gOMFCount[] = { 3, 4 };

// Coefficients for the Input Member Functions
FIS_TYPE fis_gMFI0Coeff1[] = { 0, 0, 25, 26.5 };
FIS_TYPE fis_gMFI0Coeff2[] = { 25, 26.5, 28 };
FIS_TYPE fis_gMFI0Coeff3[] = { 26.5, 28, 35, 35 };
FIS_TYPE* fis_gMFI0Coeff[] = { fis_gMFI0Coeff1, fis_gMFI0Coeff2, fis_gMFI0Coeff3 };
FIS_TYPE fis_gMFI1Coeff1[] = { 0, 0, 66.5, 76.5 };
FIS_TYPE fis_gMFI1Coeff2[] = { 66.5, 76.5, 100, 100 };
FIS_TYPE* fis_gMFI1Coeff[] = { fis_gMFI1Coeff1, fis_gMFI1Coeff2 };
FIS_TYPE fis_gMFI2Coeff1[] = { 650, 750, 850 };
FIS_TYPE fis_gMFI2Coeff2[] = { 750, 850, 1000, 1000 };
FIS_TYPE fis_gMFI2Coeff3[] = { 0, 0, 550, 650 };
FIS_TYPE fis_gMFI2Coeff4[] = { 550, 650, 750 };
FIS_TYPE* fis_gMFI2Coeff[] = { fis_gMFI2Coeff1, fis_gMFI2Coeff2, fis_gMFI2Coeff3, fis_gMFI2Coeff4 };
FIS_TYPE** fis_gMFICoeff[] = { fis_gMFI0Coeff, fis_gMFI1Coeff, fis_gMFI2Coeff };

// Coefficients for the Output Member Functions
FIS_TYPE fis_gMFO0Coeff1[] = { 100, 150, 200 };
FIS_TYPE fis_gMFO0Coeff2[] = { 0, 0, 125, 150 };
FIS_TYPE fis_gMFO0Coeff3[] = { 150, 255, 255 };
FIS_TYPE* fis_gMFO0Coeff[] = { fis_gMFO0Coeff1, fis_gMFO0Coeff2, fis_gMFO0Coeff3 };
FIS_TYPE fis_gMFO1Coeff1[] = { 0, 0, 1 };
FIS_TYPE fis_gMFO1Coeff2[] = { 1, 80, 160 };
FIS_TYPE fis_gMFO1Coeff3[] = { 80, 255, 255 };
FIS_TYPE fis_gMFO1Coeff4[] = { 0, 40, 80 };
FIS_TYPE* fis_gMFO1Coeff[] = { fis_gMFO1Coeff1, fis_gMFO1Coeff2, fis_gMFO1Coeff3, fis_gMFO1Coeff4 };
FIS_TYPE** fis_gMFOCoeff[] = { fis_gMFO0Coeff, fis_gMFO1Coeff };

// Input membership function set
int fis_gMFI0[] = { 0, 1, 0 };
int fis_gMFI1[] = { 0, 0 };
int fis_gMFI2[] = { 1, 0, 0, 1 };
int* fis_gMFI[] = { fis_gMFI0, fis_gMFI1, fis_gMFI2};

// Output membership function set
int fis_gMFO0[] = { 1, 0, 1 };
int fis_gMFO1[] = { 1, 1, 1, 1 };
int* fis_gMFO[] = { fis_gMFO0, fis_gMFO1};

// Rule Weights
FIS_TYPE fis_gRWeight[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

// Rule Type
int fis_gRType[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

// Rule Inputs
int fis_gRI0[] = { 1, 1, 1 };
int fis_gRI1[] = { 1, 2, 1 };
int fis_gRI2[] = { 1, 1, 2 };
int fis_gRI3[] = { 1, 2, 2 };
int fis_gRI4[] = { 1, 1, 3 };
int fis_gRI5[] = { 1, 1, 4 };
int fis_gRI6[] = { 1, 2, 3 };
int fis_gRI7[] = { 1, 2, 4 };
int fis_gRI8[] = { 2, 1, 1 };
int fis_gRI9[] = { 2, 2, 1 };
int fis_gRI10[] = { 2, 1, 2 };
int fis_gRI11[] = { 2, 2, 2 };
int fis_gRI12[] = { 2, 1, 3 };
int fis_gRI13[] = { 2, 2, 3 };
int fis_gRI14[] = { 2, 1, 4 };
int fis_gRI15[] = { 2, 2, 4 };
int fis_gRI16[] = { 3, 1, 1 };
int fis_gRI17[] = { 3, 2, 1 };
int fis_gRI18[] = { 3, 1, 2 };
int fis_gRI19[] = { 3, 2, 2 };
int fis_gRI20[] = { 3, 1, 3 };
int fis_gRI21[] = { 3, 2, 3 };
int fis_gRI22[] = { 3, 1, 4 };
int fis_gRI23[] = { 3, 2, 4 };
int* fis_gRI[] = { fis_gRI0, fis_gRI1, fis_gRI2, fis_gRI3, fis_gRI4, fis_gRI5, fis_gRI6, fis_gRI7, fis_gRI8, fis_gRI9, fis_gRI10, fis_gRI11, fis_gRI12, fis_gRI13, fis_gRI14, fis_gRI15, fis_gRI16, fis_gRI17, fis_gRI18, fis_gRI19, fis_gRI20, fis_gRI21, fis_gRI22, fis_gRI23 };

// Rule Outputs
int fis_gRO0[] = { 1, 4 };
int fis_gRO1[] = { 2, 4 };
int fis_gRO2[] = { 1, 1 };
int fis_gRO3[] = { 2, 1 };
int fis_gRO4[] = { 2, 3 };
int fis_gRO5[] = { 2, 2 };
int fis_gRO6[] = { 2, 3 };
int fis_gRO7[] = { 2, 2 };
int fis_gRO8[] = { 1, 4 };
int fis_gRO9[] = { 2, 4 };
int fis_gRO10[] = { 1, 1 };
int fis_gRO11[] = { 2, 1 };
int fis_gRO12[] = { 2, 3 };
int fis_gRO13[] = { 2, 3 };
int fis_gRO14[] = { 2, 2 };
int fis_gRO15[] = { 2, 2 };
int fis_gRO16[] = { 3, 4 };
int fis_gRO17[] = { 1, 4 };
int fis_gRO18[] = { 3, 1 };
int fis_gRO19[] = { 1, 1 };
int fis_gRO20[] = { 2, 3 };
int fis_gRO21[] = { 2, 3 };
int fis_gRO22[] = { 2, 2 };
int fis_gRO23[] = { 2, 2 };
int* fis_gRO[] = { fis_gRO0, fis_gRO1, fis_gRO2, fis_gRO3, fis_gRO4, fis_gRO5, fis_gRO6, fis_gRO7, fis_gRO8, fis_gRO9, fis_gRO10, fis_gRO11, fis_gRO12, fis_gRO13, fis_gRO14, fis_gRO15, fis_gRO16, fis_gRO17, fis_gRO18, fis_gRO19, fis_gRO20, fis_gRO21, fis_gRO22, fis_gRO23 };

// Input range Min
FIS_TYPE fis_gIMin[] = { 0, 0, 0 };

// Input range Max
FIS_TYPE fis_gIMax[] = { 35, 100, 1000 };

// Output range Min
FIS_TYPE fis_gOMin[] = { 0, 0 };

// Output range Max
FIS_TYPE fis_gOMax[] = { 255, 255 };

//***********************************************************************
// Data dependent support functions for Fuzzy Inference System           
//***********************************************************************
FIS_TYPE fis_MF_out(FIS_TYPE** fuzzyRuleSet, FIS_TYPE x, int o)
{
    FIS_TYPE mfOut;
    int r;

    for (r = 0; r < fis_gcR; ++r)
    {
        int index = fis_gRO[r][o];
        if (index > 0)
        {
            index = index - 1;
            mfOut = (fis_gMF[fis_gMFO[o][index]])(x, fis_gMFOCoeff[o][index]);
        }
        else if (index < 0)
        {
            index = -index - 1;
            mfOut = 1 - (fis_gMF[fis_gMFO[o][index]])(x, fis_gMFOCoeff[o][index]);
        }
        else
        {
            mfOut = 0;
        }

        fuzzyRuleSet[0][r] = fis_min(mfOut, fuzzyRuleSet[1][r]);
    }
    return fis_array_operation(fuzzyRuleSet[0], fis_gcR, fis_max);
}

FIS_TYPE fis_defuzz_mom(FIS_TYPE** fuzzyRuleSet, int o)
{
    FIS_TYPE step = (fis_gOMax[o] - fis_gOMin[o]) / (FIS_RESOLUSION - 1);
    FIS_TYPE max = 0, dist, value, sum;
    int count;
    int i;

    for (i = 0; i < FIS_RESOLUSION; ++i)
    {
        dist = fis_gOMin[o] + (step * i);
        value = fis_MF_out(fuzzyRuleSet, dist, o);
        max = max(max, value);
    }

    sum = 0;
    count = 0;
    for (i = 0; i < FIS_RESOLUSION; i++)
    {
        dist = fis_gOMin[o] + (step * i);
        value = fis_MF_out(fuzzyRuleSet, dist, o);
        if (max == value)
        {
            ++count;
            sum += i;
        }
    }

    return (fis_gOMin[o] + ((step * sum) / count));
}

//***********************************************************************
// Fuzzy Inference System                                                
//***********************************************************************
void fis_evaluate()
{
    FIS_TYPE fuzzyInput0[] = { 0, 0, 0 };
    FIS_TYPE fuzzyInput1[] = { 0, 0 };
    FIS_TYPE fuzzyInput2[] = { 0, 0, 0, 0 };
    FIS_TYPE* fuzzyInput[fis_gcI] = { fuzzyInput0, fuzzyInput1, fuzzyInput2, };
    FIS_TYPE fuzzyOutput0[] = { 0, 0, 0 };
    FIS_TYPE fuzzyOutput1[] = { 0, 0, 0, 0 };
    FIS_TYPE* fuzzyOutput[fis_gcO] = { fuzzyOutput0, fuzzyOutput1, };
    FIS_TYPE fuzzyRules[fis_gcR] = { 0 };
    FIS_TYPE fuzzyFires[fis_gcR] = { 0 };
    FIS_TYPE* fuzzyRuleSet[] = { fuzzyRules, fuzzyFires };
    FIS_TYPE sW = 0;

    // Transforming input to fuzzy Input
    int i, j, r, o;
    for (i = 0; i < fis_gcI; ++i)
    {
        for (j = 0; j < fis_gIMFCount[i]; ++j)
        {
            fuzzyInput[i][j] =
                (fis_gMF[fis_gMFI[i][j]])(g_fisInput[i], fis_gMFICoeff[i][j]);
        }
    }

    int index = 0;
    for (r = 0; r < fis_gcR; ++r)
    {
        if (fis_gRType[r] == 1)
        {
            fuzzyFires[r] = FIS_MAX;
            for (i = 0; i < fis_gcI; ++i)
            {
                index = fis_gRI[r][i];
                if (index > 0)
                    fuzzyFires[r] = fis_min(fuzzyFires[r], fuzzyInput[i][index - 1]);
                else if (index < 0)
                    fuzzyFires[r] = fis_min(fuzzyFires[r], 1 - fuzzyInput[i][-index - 1]);
                else
                    fuzzyFires[r] = fis_min(fuzzyFires[r], 1);
            }
        }
        else
        {
            fuzzyFires[r] = FIS_MIN;
            for (i = 0; i < fis_gcI; ++i)
            {
                index = fis_gRI[r][i];
                if (index > 0)
                    fuzzyFires[r] = fis_max(fuzzyFires[r], fuzzyInput[i][index - 1]);
                else if (index < 0)
                    fuzzyFires[r] = fis_max(fuzzyFires[r], 1 - fuzzyInput[i][-index - 1]);
                else
                    fuzzyFires[r] = fis_max(fuzzyFires[r], 0);
            }
        }

        fuzzyFires[r] = fis_gRWeight[r] * fuzzyFires[r];
        sW += fuzzyFires[r];
    }

    if (sW == 0)
    {
        for (o = 0; o < fis_gcO; ++o)
        {
            g_fisOutput[o] = ((fis_gOMax[o] + fis_gOMin[o]) / 2);
        }
    }
    else
    {
        for (o = 0; o < fis_gcO; ++o)
        {
            g_fisOutput[o] = fis_defuzz_mom(fuzzyRuleSet, o);
        }
    }
}
