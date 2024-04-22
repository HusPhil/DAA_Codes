double ks_methodOne(int p[], int w[], int maxW, int numberOfItems) {
    double result = 0;
    double neededW = maxW;
    double pwr[numberOfItems];

    for(int i = 0; i < numberOfItems; i++) {
        for(int j = 0; j < numberOfItems - i - 1; j++) {
            if(p[j+1] > p[j]) {
                swap(&p[j], &p[j+1]);
                swap(&w[j], &w[j+1]);
            }
        }
    }

    for(int i = 0; i < numberOfItems; i++) {
        double ratio = (double)p[i]/w[i];
        double weightToAdd;

        if(neededW > w[i]) {
            weightToAdd = w[i];
        }
        else {
            weightToAdd = neededW;
        }
        
        result += weightToAdd*ratio;        


        neededW -= weightToAdd;
        printf("Needed Weight:%f, Current Value: %f\n", neededW, result); 
        if(neededW <= 0) break;


    }

    return result;
}

double ks_methodTwo(int p[], int w[], int maxW, int numberOfItems) {
    double result = 0;
    double neededW = maxW;
    double pwr[numberOfItems];

    for(int i = 0; i < numberOfItems; i++) {
        for(int j = 0; j < numberOfItems - i - 1; j++) {
            if(w[j+1] < w[j]) {
                swap(&w[j], &w[j+1]);
                swap(&p[j], &p[j+1]);
            }
        }
    }

    for(int i = 0; i < numberOfItems; i++) {
        double ratio = (double)p[i]/w[i];
        double weightToAdd;

        if(neededW > w[i]) {
            weightToAdd = w[i];
        }
        else {
            weightToAdd = neededW;
        }
        
        result += weightToAdd*ratio;        


        neededW -= weightToAdd;
        printf("Needed Weight:%f, Current Value: %f\n", neededW, result); 
        if(neededW <= 0) break;


    }

    return result;
}

double ks_methodThree(int p[], int w[], int maxW, int numberOfItems) {
    double result = 0;
    double neededW = maxW;
    double pwr[numberOfItems];

    for(int i = 0; i < numberOfItems; i++) {
        pwr[i] = (double)p[i]/w[i];
    }

    for(int i = 0; i < numberOfItems; i++) {
        for(int j = 0; j < numberOfItems - i - 1; j++) {
            if(pwr[j+1] > pwr[j]) {
                double temp = pwr[j];
                pwr[j] = pwr[j+1];
                pwr[j+1] = temp;

                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;

                temp = w[j];
                w[j] = w[j+1];
                w[j+1] = temp;
            }
        }
    }
    

    for(int i = 0; i < numberOfItems; i++) {
        double ratio = (double)p[i]/w[i];
        double weightToAdd;

        if(neededW > w[i]) {
            weightToAdd = w[i];
        }
        else {
            weightToAdd = neededW;
        }
        
        result += weightToAdd*ratio;        


        neededW -= weightToAdd;
        printf("Needed Weight:%f, Current Value: %f\n", neededW, result); 
        if(neededW <= 0) break;


    }

    return result;
}