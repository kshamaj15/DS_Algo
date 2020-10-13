// Note: numbers A[i]<=0 and A[i]>N ( N being the size of the array ) is not important to us since the missing positive integer will be in the range [1, N+1].
// The answer will be N+1 only if all of the elements of the array are exact one occurrence of [1, N].
// Creating buckets would have been an easy solution if using extra space was allowed.
// An array of size N initialized to 0 would have been created.
// For every value A[i] which lies in the range [1, N], its count in the array would have been incremented.

// Finally, traversing the array would help to find the first array position with value 0 and that will be our answer.
// However, usage of buckets is not allowed, can we use the existing array as bucket somehow?
// Now, since additional space is not allowed either, the given array itself needs to be used to track it.
// It may be helpful to use the fact that the size of the set we are looking to track is [1, N]
// which happens to be the same size as the size of the array.
// This means we can use the array to track these elements.
// We traverse the array and if A[i] is in [1,N] range, we try to put in the index of same value in the array.


// https://www.interviewbit.com/problems/first-missing-integer/
// very interesting question

#include<iostream>
#include<vector>
using namespace std;

int firstMissingPositive(vector<int> &A) {
    int ans = A.size()+1;
    for(int i=0; i<A.size(); i++) {
        if(A[i]>0 && A[i] <= A.size()) {
            if(A[A[i]-1] != A[i]) {
                int temp = A[A[i]-1];
                A[A[i]-1] = A[i];
                A[i] = temp;
                i--;
            }
        }
    }
    for(int i=0; i<A.size(); i++) {
        if(A[i] != i+1) {
            ans = i+1;
            break;
        }
    }
    return ans;
}



int main() {
    vector<int> a({699, 2, 690, 936, 319, 784, 562, 35, 151, 698, 126, 730, 587, 157, 201, 761, 956, 359, 198, 986, 915, 7, 703, 324, 814, 382, 294, 204, 120, 731, 615, 330, 486, 52, 223, 376, 649, 458, 564, 971, 72, 605, 177, 20, 461, 790, 872, 363, 916, 435, 991, 184, 410, 320, 16, 480, 768, 801, 117, 338, 650, 786, 17, 369, 979, 304, 445, 688, 862, 229, 311, 351, 985, 697, 135, 299, 310, 3, 643, 221, 831, 196, 887, 679, 484, 209, 824, 292, 588, 721, 140, 675, 827, 913, 271, 170, 812, 552, 334, 860, 981, 550, 308, 584, 442, 328, 251, 456, 976, 31, 507, 954, 982, 742, 45, 727, 794, 309, 527, 623, 56, 843, 436, 681, 143, 130, 689, 870, 362, 580, 560, 474, 385, 525, 881, 51, 890, 917, 820, 826, 139, 443, 978, 144, 512, 205, 682, 188, 344, 429, 497, 181, 749, 864, 664, 145, 621, 629, 886, 572, 89, 725, 945, 29, 553, 977, 783, 590, 236, 728, 125, 90, 492, 261, 543, 259, 662, 622, 285, 392, 561, 670, 200, 504, 246, 513, 910, 583, 460, 179, 207, 709, 127, 926, 816, 426, 520, 174, 464, 883, 780, 5, 268, 606, 1, 109, 704, 391, 661, 924, 516, 241, 477, 952, 405, 522, 247, 335, 356, 839, 423, 779, 4, 43, 720, 238, 965, 951, 914, 10, 496, 775, 651, 788, 373, 491, 746, 799, 518, 93, 86, 774, 652, 955, 494, 252, 781, 946, 412, 202, 741, 719, 612, 673, 896, 1000, 289, 554, 69, 424, 980, 506, 593, 889, 25, 959, 28, 736, 8, 969, 865, 657, 567, 434, 9, 167, 357, 929, 645, 250, 565, 94, 928, 473, 509, 823, 313, 762, -1, 208, 903, 922, 655, 948, 326, 485, 150, 73, 505, 225, 122, 129, 648, 838, 811, 972, 735, 78, 428, 740, 782, 632, 316, 440, 737, 297, 873, 281, 479, 654, 0, 633, 212, 152, 154, 470, 866, 79, 722, 958, 732, 900, 832, 278, 58, 842, 745, 540, 169, 347, 592, 438, 882, 462, 53, 34, 519, 489, 85, 757, 919, 701, 15, 211, 667, 637, 74, 573, 240, 559, -2, 472, 203, 112, 162, 776, -4, 155, 837, 99, 98, 64, 101, 983, 366, 853, 970, 482, 40, 921, 374, 758, 413, 339, 705, 771, 360, 734, 282, 219, 766, 535, 133, 532, 254});
    int b;
    b = firstMissingPositive(a);
    cout<<b;
    return 0;
}