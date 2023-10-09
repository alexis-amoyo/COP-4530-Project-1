/* a Class template calculates the difference in the size of two inputs*/
template <typename Comparable>
int ComparatorWithRead<Comparable>::getDiff( const Comparable & lhs, const Comparable & rhs ) const{
    if(lhs < rhs){
        return rhs - lhs;
    }
    else
    {
        return lhs - rhs;
    }
}

/* a function template calculates the difference in the size of two inputs*/
template <typename Comparable>
int findDiff( const Comparable & a, const Comparable & b){
    if(b < a){
        return a - b;
    }
    else
    {
        return b - a;
    }
}

/**
 * a function template that takes a class template to calculate
 * the difference in the size of the first two inputs.
 */
template <typename Comparable, typename Comparator>
int findDiff (const Comparable & a, const Comparable & b, Comparator cmp){
    if(b < a){

        return cmp.getDiff(a,b);
    }
    else
    {
        return cmp.getDiff(b,a);
    }//is this how we use cmp?
}


/**
 * All functions below take four parameters (three inputs and one output).
 *
 * It searches from a NSequence <a> for the longest subsequence in which all items 
 * should fall within the range from the input <ref>, i.e., 
 * [<ref>.size - range, <ref>.size + range]
 * 
 * Output <start>: the starting position of the longest subsequence 
 * return value: the length of the longest subsequence as the return value.
 */
template <typename T>
int longestSubseq_Quad(const NSequence <T> & a, const T & ref, const int range, int * start){
    int maxSum = 0;
    int startRange = ref - range;
    int endRange = range + ref;
    int counterItems = 0;
    bool first = false;
    bool endSeq = false;


    for(int i = 0; i < a.getSize(); i++){
        int currentSum = 0;
        for(int j = i; j < a.getSize(); j++){
            if(a[j] > startRange && a[j] < endRange && !endSeq){
                currentSum += a[j];
                //cout << a[j] << endl;
                if(first == false){
                    first = true;
                    *start = j;
                }
                if(currentSum > maxSum){
                    maxSum = currentSum;
                    counterItems++;
                    //cout << "S" << &start << endl << "C" << counter << endl << "J" << j << endl << "I" << i << endl;
                }
            }
            else if((a[j-1] > startRange && a[j-1] < endRange)
                    && (a[j] <= startRange || a[j] >= endRange)
                    && (first == true)){
                //cout << "hi" << endl;
                endSeq == true;
                break;
            }
        }
    }
    //cout << endl << maxSum << endl;
    //cout << &start << endl << counter << endl;
    return counterItems;
}

template <typename T>
int longestSubseq_Cubic(const NSequence <T> & a, const T & ref, const int range, int * start){
    int maxSum = 0;
    int startRange = ref - range;
    int endRange = range + ref;
    int counterItems = 0;
    bool first = false;
    bool endSeq = false;


    for(int i = 0; i < a.getSize(); i++){
        for(int j = i; j < a.getSize(); j++){
            int currentSum = 0;
            for(int k = i; k <= j; k++){
                if(a[k] > startRange && a[k] < endRange && !endSeq){
                    currentSum += a[k];
                    //cout << a[k] << endl;
                    if(first == false){
                        first = true;
                        *start = k;
                    }
                    if(currentSum > maxSum){
                        maxSum = currentSum;
                        counterItems++;
                        //cout << "S" << &start << endl << "C" << counter << endl << "J" << j << endl << "I" << i << endl;
                    }
                }
                else if((a[k-1] > startRange && a[k-1] < endRange)
                        && (a[k] <= startRange || a[k] >= endRange)
                        && (first == true)){
                    //cout << "hi" << endl;
                    endSeq == true;
                    break;
                }
            }
        }
    }
    //cout << endl << maxSum << endl;
    //cout << &start << endl << counter << endl;
    return counterItems;
}


template <typename T>
int longestSubseq_Log(const NSequence <T> & a, const T & ref, const int range, int * start){
    
    int maxSum = 0, thisSum = 0;
    int startRange = ref - range;
    int endRange = range + ref;
    int counterItems = 0;
    bool first = false;
    bool endSeq = false;

    //cout << startRange << endl << endRange << endl;

    for(int i = 0; i < a.getSize(); i++){
        if(a[i] > startRange && a[i] < endRange && !endSeq){
                thisSum += a[i];
                //cout << a[i] << endl;
                if(first == false){
                    first = true;
                    *start = i;
                }
                if(thisSum > maxSum){
                    maxSum = thisSum;
                    counterItems++;
                }
                else if(thisSum < 0){
                    thisSum = 0;
                    counterItems++;
                }
            }
            else if((a[i-1] > startRange && a[i-1] < endRange)
                    && (a[i] <= startRange || a[i] >= endRange)
                    && (first == true)){
                //cout << "hi" << endl;
                endSeq == true;
                break;
            }
    }
    //return counterItems;


    int left = 0;
    int right = a.getSize() - 1;
    longestSubseq_LogMine(a, left, right, ref, range, start);
    /*
    if((ref-range) == (ref+range)){
        if(a[ref.getSize()-range] > 0){
            return a[ref.getSize()+range];
        }
        else
            return 0;
    } //base case

    int center = (ref-range) + (ref+range) / 2; //30
    int maxLeftSum = longestSubseq_Log( a, (ref-range), center, start); //10,30 
    int maxRightSum = longestSubseq_Log( a, center + 1, (ref+range), start); //31,50

    int maxLeftBorderSum = 0, leftBorderSum = 0, maxRightBorderSum = 0, rightBorderSum = 0;
    int counterItemsLeft = 0, counterItemsRight = 0; //unsure how to calculate tbh
    bool firstLeft = false, endSeqLeft = false, firstRight = false, endSeqRight = false;
    int startRange = ref - range;
    int endRange = ref + range;
    int maxSum = 0;
    int left = 0;
    int right = a.getSize()-1;

    for(int i = center; i >= ref-range; i--){
        if(a[i] > startRange && a[i] < endRange && !endSeqLeft){
            leftBorderSum += a[i];
            if(firstLeft == false){
                firstLeft = true;
                *start = i;
                //cout << "hoot" << endl;
            }
            if(leftBorderSum > maxLeftBorderSum){
                maxLeftBorderSum = leftBorderSum;
                counterItemsLeft++;
            }
        }
        else if((a[i-1] > startRange && a[i-1] < endRange)
            && (a[i] <= startRange || a[i] >= endRange)
            && (firstLeft == true)){
            //cout << "hi" << endl;
            endSeqLeft == true;
            break;
        }
    }

    for(int j = center + 1; j <= right; j++){
        if(a[j] > startRange && a[j] < endRange && !endSeqRight){
            rightBorderSum += a[j];
            if(firstRight == false){
                firstRight = true;
                *start = j;
            }
            if(rightBorderSum > maxRightBorderSum){
                maxRightBorderSum = rightBorderSum;
                counterItemsRight++;
            }
        }
        else if((a[j-1] > startRange && a[j-1] < endRange)
            && (a[j] <= startRange || a[j] >= endRange)
            && (firstRight == true)){
            //cout << "hi" << endl;
            endSeqRight == true;
            break;
        }
    }

    int totalBorderSum = maxLeftBorderSum + maxRightBorderSum;
    int tempMax = (totalBorderSum > maxLeftSum) ? totalBorderSum : maxLeftSum;
    maxSum = (tempMax > maxRightSum) ? tempMax : maxRightSum;
    return counterItemsLeft;*/
} //segFaults cuz you can't pass the parameters you want into ref and range
/*
int max3(int a, int b, int c){
    int max = a;
    if(b > max){
        max = b;
    }
    if(c > max){
        max = c;
    }
    return max;
}

template <typename T>
int longestSubseq_LogMine(const NSequence <T> & a, int left, int right, const T & ref, const int range, int * start){
    int maxSum = 0;

    if(left == right){
        if(a[left] > 0){
            return a[left];
        }
        else
            return 0;
    } //base case

    int center = (left + right) / 2;
    cout << "YOOOO" << endl;
    cout << left << endl << center << endl;
    int maxLeftSum = longestSubseq_LogMine( a, left, center, ref, range, start);
    cout << "NOOOO" << endl;
    cout << center+1 << endl << right << endl;
    int maxRightSum = longestSubseq_LogMine( a, center + 1, right, ref, range, start);
    cout << "MOOOO" << endl;

    int counterItemsLeft = 0, counterItemsRight = 0;
    bool firstLeft = false, endSeqLeft = false, firstRight = false, endSeqRight = false;
    int startRange = ref - range;
    int endRange = ref + range;

    int maxLeftBorderSum = 0, leftBorderSum = 0, maxRightBorderSum = 0, rightBorderSum = 0;

    for(int i = center; i >= left; i--){
        if(a[i] > startRange && a[i] < endRange && !endSeqLeft){
            leftBorderSum += a[i];
            if(firstLeft == false){
                firstLeft = true;
                *start = i;
                cout << "hoot" << endl;
            }
            if(leftBorderSum > maxLeftBorderSum){
                maxLeftBorderSum = leftBorderSum;
                counterItemsLeft++;
            }
        }
        else if((a[i-1] > startRange && a[i-1] < endRange)
            && (a[i] <= startRange || a[i] >= endRange)
            && (firstLeft == true)){
            //cout << "hi" << endl;
            endSeqLeft == true;
            break;
        }
    }

    for(int j = center + 1; j <= right; j++){
        if(a[j] > startRange && a[j] < endRange && !endSeqRight){
            rightBorderSum += a[j];
            if(firstRight == false){
                firstRight = true;
                *start = j;
            }
            if(rightBorderSum > maxRightBorderSum){
                maxRightBorderSum = rightBorderSum;
                counterItemsRight++;
            }
        }
        else if((a[j-1] > startRange && a[j-1] < endRange)
            && (a[j] <= startRange || a[j] >= endRange)
            && (firstRight == true)){
            //cout << "hi" << endl;
            endSeqRight == true;
            break;
        }
    }

    for(int i = center; i >= left; i--){
        leftBorderSum += a[i];
        if(leftBorderSum > maxLeftBorderSum){
            maxLeftBorderSum = leftBorderSum;
        }
    }

    for(int j = center + 1; j <= right; j++){
        rightBorderSum += a[j];
        if(rightBorderSum > maxRightBorderSum){
            maxRightBorderSum = rightBorderSum;
        }
    }

    return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
    
}*/