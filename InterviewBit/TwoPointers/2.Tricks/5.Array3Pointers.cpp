/*
https://www.interviewbit.com/problems/array-3-pointers/#:~:text=You%20are%20given,10%20from%20C.
You are given 3 arrays A, B and C. All 3 of the arrays are sorted.

Find i, j, k such that :

max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])) is minimized.

Return the minimum max(abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i]))

**abs(x) is absolute value of x and is implemented in the following manner : **

      if (x < 0) return -x;
      else return x;
Example :

Input : 
        A : [1, 4, 10]
        B : [2, 15, 20]
        C : [10, 12]

Output : 5 
         With 10 from A, 15 from B and 10 from C. 
*/
/*
https://www.geeksforgeeks.org/find-three-closest-elements-from-given-three-sorted-arrays/
Method 1: 
A Simple Solution is to run three nested loops to consider all triplets from A, B and C. 
Compute the value of max(abs(A[i] – B[j]), abs(B[j] – C[k]), abs(C[k] – A[i])) for every triplet and return minimum of all values. 
Time complexity of this solution is O(n3)

Method 2:
A Better Solution is to use Binary Search. 
1) Iterate over all elements of A[], 
      a) Binary search for element just smaller than or equal to in B[] and C[], and note the difference. 
2) Repeat step 1 for B[] and C[]. 
3) Return overall minimum.
Time complexity of this solution is O(nLogn)

Method 3:
Efficient Solution
Let ‘p’ be size of A[], ‘q’ be size of B[] and ‘r’ be size of C[]  

1)   Start with i=0, j=0 and k=0 (Three index variables for A,
                                  B and C respectively)

//  p, q and r are sizes of A[], B[] and C[] respectively.
2) Do following while i < p and j < q and k < r
    a) Find min and maximum between A[i], B[j] and C[k]
    b) Compute diff = maximumValue - MinimumValue
    c) if diff == 0 -> This is the result
    d) else, result = min(result, diff)
        Increment the pointer of the array where minimum is present.
        Why increment? Because we want to decrease this difference value.
        Why take max and min of a, b, and c. since we need max of a-b, b-c and c-a first, which is basically
        difference between max and min if we keep incrementing i,j,k.
We can store the value of indices as well if required.

Note that we increment the pointer of the array which has the minimum because our goal is to decrease the difference. 
Increasing the maximum pointer increases the difference. 
Increase the second maximum pointer can potentially increase the difference. 
*/

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print2DVector(vector< vector<int> > arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void printStrings(vector<string> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << endl;
    }
}

int binarySearch(vector<int> arr, int value){
    int low = 0;
    int high = arr.size() - 1;
    int mid = 0;
    while(low < high){
        mid = (low + high)/2;

        if(arr[mid] == value){
            return mid;
        }

        if(value > arr[mid]){
            // increase value
            low = mid + 1;
        } else {
            // decrease value
            high = mid - 1;
        }
    }

    int i = high;
    while(i >= 1 && arr[i] > value){
        i--;
    }

    return i;
}

int solve(vector<int> a,vector<int> b, vector<int> c ){
    int result = INT_MAX;

    int maxValue = INT_MIN;
    for(int i=0; i<a.size(); i++){
        int aValue = a[i];
        // cout << "A value is: " << aValue << endl;

        int bIndex = binarySearch(b, aValue);
        // cout << "B index is: " << bIndex << endl;

        int cIndex = binarySearch(c, aValue);
        // cout << "C index is: " << cIndex << endl;

        int bValue = *lower_bound(b.begin(), b.end(), aValue);
        int cValue = *lower_bound(c.begin(), c.end(), aValue);
        // cout << "B value is: " << bValue << endl;
        // cout << "C value is: " << cValue << endl;
        // cout << endl;

        int diffAB = abs(aValue - bValue);
        int diffBC = abs(bValue - cValue);
        int diffCA = abs(cValue - aValue);
        // cout << "Diff values is: " << diffAB << " " << diffBC << " " << diffCA << endl;

        maxValue = max(max(diffAB, diffBC), max(diffBC, diffCA));
        // cout << "Max Value is: " << maxValue << endl;

        result = min(result, maxValue);
        // cout << "Result is: " << result << endl;
        // cout << endl;
    }

    // Repeat for b
    for(int i=0; i<b.size(); i++){
        int bValue = b[i];

        int aValue = *lower_bound(a.begin(), a.end(), bValue);
        int cValue = *lower_bound(c.begin(), c.end(), bValue);

        int diffAB = abs(aValue - bValue);
        int diffBC = abs(bValue - cValue);
        int diffCA = abs(cValue - aValue);
        // cout << "Diff values is: " << diffAB << " " << diffBC << " " << diffCA << endl;

        maxValue = max(max(diffAB, diffBC), max(diffBC, diffCA));
        // cout << "Max Value is: " << maxValue << endl;

        result = min(result, maxValue);
    }

    // Repeat for c
    for(int i=0; i<c.size(); i++){
        int cValue = c[i];
        
        int aValue = *lower_bound(a.begin(), a.end(), cValue);
        int bValue = *lower_bound(b.begin(), b.end(), cValue);

        int diffAB = abs(aValue - bValue);
        int diffBC = abs(bValue - cValue);
        int diffCA = abs(cValue - aValue);
        // cout << "Diff values is: " << diffAB << " " << diffBC << " " << diffCA << endl;

        maxValue = max(max(diffAB, diffBC), max(diffBC, diffCA));
        // cout << "Max Value is: " << maxValue << endl;

        result = min(result, maxValue);
    }
    return result;
}

// This is a very efficient solution!
int solve(vector<int> a, vector<int> b, vector<int> c, bool efficient){
    int result = INT_MAX;
    int p = a.size();
    int q = b.size();
    int r = c.size();

    int i=0,j=0,k=0;
    while(i<p && j<q && k < r){
        int minimum = min(a[i], min(b[j], c[k]));
        int maximum = max(a[i], max(b[j], c[k]));

        int difference = maximum - minimum;

        if(difference == 0){
            return difference;
        }

        result = min(result, difference);
        if(a[i] == minimum){
            i++;
        } else if(b[j] == minimum){
            j++;
        } else {
            k++;
        }
    }

    return result;
}

int main(){
    vector<int> a = { 1, 12, 32, 36, 40, 49, 54, 63, 71, 71, 75, 79, 126, 141, 165, 167, 175, 187, 195, 197, 199, 215, 232, 242, 277, 281, 303, 321, 322, 324, 335, 345, 348, 354, 356, 374, 381, 391, 410, 420, 425, 429, 431, 440, 452, 459, 465, 478, 480, 497, 522, 545, 566, 595, 610, 610, 615, 633, 637, 643, 644, 648, 649, 662, 703, 708, 726, 733, 736, 744, 759, 766, 773, 795, 811, 815, 816, 834, 842, 853, 856, 864, 872, 876, 889, 898, 903, 927, 938, 949, 966, 985, 995, 1009, 1020, 1025, 1032, 1033, 1036, 1036, 1037, 1044, 1049, 1061, 1075, 1089, 1092, 1108, 1116, 1121, 1137, 1137, 1154, 1165, 1183, 1247, 1265, 1269, 1273, 1291, 1293, 1320, 1324, 1327, 1332, 1343, 1346, 1366, 1376, 1393, 1411, 1414, 1436, 1438, 1468, 1510, 1516, 1530, 1531, 1531, 1553, 1577, 1582, 1582, 1628, 1643, 1654, 1657, 1664, 1671, 1688, 1689, 1698, 1703, 1721, 1728, 1737, 1740, 1762, 1771, 1773, 1778, 1804, 1827, 1833, 1861, 1866, 1868, 1873, 1881, 1902, 1918, 1920, 1931, 1957, 1985, 1990, 2003, 2028, 2033, 2035, 2069, 2071, 2078, 2093, 2094, 2129, 2131, 2134, 2151, 2171, 2179, 2184, 2201, 2202, 2204, 2227, 2228, 2238, 2287, 2294, 2300, 2307, 2322, 2341, 2341, 2346, 2392, 2393, 2396, 2401, 2418, 2424, 2431, 2452, 2459, 2466, 2472, 2489, 2492, 2504, 2509, 2512, 2517, 2526, 2529, 2561, 2579, 2581, 2592, 2608, 2617, 2625, 2625, 2635, 2640, 2651, 2653, 2687, 2711, 2714, 2740, 2746, 2775, 2793, 2797, 2800, 2803, 2805, 2821, 2822, 2826, 2840, 2849, 2849, 2860, 2862, 2881, 2882, 2887, 2907, 2916, 2917, 2928, 2943, 2948, 2957, 2964, 2989, 2997, 3007, 3009, 3024, 3031, 3045, 3051, 3052, 3067, 3068, 3072, 3087, 3094, 3094, 3094, 3109, 3127, 3129, 3161, 3185, 3196, 3203, 3205, 3211, 3236, 3255, 3268, 3285, 3307, 3312, 3320, 3338, 3348, 3391, 3395, 3413, 3422, 3436, 3442, 3459, 3466, 3494, 3515, 3526, 3527, 3532, 3538, 3540, 3549, 3554, 3561, 3586, 3590, 3592, 3597, 3606, 3609, 3623, 3626, 3636, 3641, 3657, 3676, 3692, 3719, 3721, 3761, 3762, 3770, 3791, 3808, 3818, 3835, 3836, 3850, 3850, 3865, 3881, 3886, 3890, 3910, 3911, 3914, 3916, 3953, 3954, 3985, 3991, 4004, 4007, 4021, 4025, 4032, 4038, 4038, 4041, 4044, 4047, 4053, 4056, 4083, 4102, 4103, 4110, 4114, 4130, 4138, 4145, 4168, 4203, 4236, 4240, 4249, 4259, 4282, 4303, 4307, 4311, 4345, 4362, 4364, 4384, 4387, 4400, 4410, 4418, 4437, 4441, 4442, 4444, 4466, 4471, 4482, 4483, 4494, 4497, 4510, 4529, 4530, 4537, 4538, 4543, 4563, 4569, 4577, 4585, 4590, 4593, 4600, 4605, 4605, 4610, 4663, 4669, 4672, 4688, 4690, 4698, 4702, 4704, 4713, 4718, 4725, 4755, 4763, 4764, 4770, 4776, 4780, 4780, 4813, 4831, 4851, 4860, 4885, 4887, 4898, 4920, 4925, 4936, 4951, 4952, 4969, 4974, 4989, 4998, 5005, 5033, 5040, 5042, 5054, 5081, 5119, 5139, 5139, 5142, 5147, 5150, 5155, 5160, 5178, 5183, 5184, 5185, 5195, 5220, 5253, 5254, 5286, 5289, 5291, 5293, 5304, 5306, 5330, 5331, 5347, 5375, 5386, 5404, 5418, 5425, 5430, 5443, 5443, 5446, 5447, 5455, 5480, 5497, 5502, 5525, 5530, 5532, 5547, 5575, 5592, 5603, 5606, 5612, 5643, 5646, 5659, 5668, 5675, 5693, 5694, 5698, 5702, 5717, 5721, 5724, 5732, 5733, 5741, 5751, 5768, 5781, 5785, 5787, 5800, 5810, 5811, 5817, 5817, 5824, 5840, 5858, 5900, 5904, 5917, 5917, 5925, 5941, 5947, 5947, 5949, 5981, 5986, 5994, 6006, 6024, 6036, 6046, 6098, 6104, 6108, 6111, 6133, 6153, 6157, 6171, 6203, 6212, 6214, 6222, 6230, 6253, 6257, 6279, 6287, 6292, 6293, 6306, 6312, 6323, 6343, 6360, 6372, 6381, 6382, 6393, 6396, 6401, 6413, 6413, 6430, 6445, 6466, 6473, 6474, 6489, 6504, 6528, 6564, 6579, 6585, 6625, 6633, 6634, 6638, 6645, 6647, 6650, 6668, 6672, 6685, 6689, 6706, 6709, 6758, 6781, 6793, 6812, 6826, 6833, 6855, 6859, 6860, 6866, 6881, 6888, 6902, 6906, 6912, 6912, 6945, 6966, 7010, 7023, 7026, 7046, 7058, 7063, 7073, 7080, 7084, 7087, 7110, 7112, 7113, 7123, 7126, 7143, 7150, 7161, 7187, 7195, 7240, 7268, 7271, 7274, 7277, 7307, 7309, 7317, 7332, 7335, 7339, 7344, 7348, 7348, 7357, 7383, 7386, 7394, 7402, 7410, 7416, 7420, 7428, 7445, 7458, 7468, 7510, 7526, 7539, 7540, 7549, 7550, 7554, 7557, 7563, 7567, 7627, 7640, 7643, 7650, 7676, 7677, 7686, 7699, 7725, 7725, 7728, 7740, 7751, 7763, 7769, 7770, 7775, 7782, 7798, 7819, 7873, 7891, 7918, 7927, 7929, 7930, 7940, 7942, 7970, 7975, 7985, 8000, 8005, 8009, 8018, 8022, 8033, 8038, 8047, 8057, 8075, 8082, 8092, 8098, 8106, 8111, 8133, 8150, 8162, 8165, 8172, 8179, 8182, 8192, 8193, 8194, 8194, 8200, 8201, 8209, 8222, 8230, 8235, 8263, 8284, 8295, 8336, 8355, 8421, 8430, 8437, 8439, 8447, 8452, 8453, 8455, 8457, 8465, 8477, 8486, 8526, 8551, 8555, 8558, 8570, 8587, 8607, 8645, 8649, 8653, 8672, 8678, 8683, 8708, 8715, 8717, 8719, 8728, 8728, 8739, 8739, 8750, 8784, 8804, 8809, 8814, 8844, 8846, 8899, 8909, 8934, 8937, 8937, 8971, 8971, 8988, 9002, 9036, 9047, 9050, 9051, 9052, 9052, 9058, 9064, 9069, 9071, 9077, 9084, 9085, 9126, 9166, 9180, 9189, 9192, 9206, 9213, 9216, 9218, 9256, 9258, 9258, 9258, 9271, 9277, 9297, 9302, 9308, 9308, 9309, 9315, 9355, 9378, 9379, 9404, 9406, 9409, 9412, 9429, 9454, 9456, 9465, 9483, 9485, 9504, 9509, 9511, 9514, 9515, 9517, 9521, 9547, 9574, 9582, 9585, 9596, 9610, 9616, 9627, 9628, 9631, 9633, 9636, 9667, 9679, 9691, 9695, 9712, 9723, 9725, 9731, 9747, 9748, 9750, 9754, 9758, 9763, 9779, 9802, 9807, 9809, 9814, 9816, 9824, 9839, 9853, 9868, 9884, 9885, 9897, 9911, 9917, 9921, 9924, 9934, 9937, 9972, 9989, 9991 };
    vector<int> b = { 2565, 2863, 6652 };
    vector<int> c = { 15, 52, 99, 145, 166, 205, 271, 306, 336, 349, 350, 360, 387, 397, 426, 458, 460, 503, 665, 709, 755, 836, 844, 860, 944, 968, 992, 1036, 1066, 1115, 1143, 1148, 1160, 1172, 1232, 1254, 1270, 1314, 1326, 1346, 1484, 1529, 1545, 1618, 1652, 1740, 1791, 1808, 1819, 1854, 1859, 1987, 1990, 1991, 2039, 2101, 2129, 2148, 2167, 2201, 2218, 2270, 2309, 2362, 2382, 2384, 2417, 2489, 2515, 2642, 2711, 2761, 2795, 2825, 2835, 2912, 3036, 3065, 3122, 3135, 3204, 3226, 3351, 3384, 3410, 3418, 3493, 3554, 3560, 3575, 3599, 3679, 3680, 3712, 3719, 3724, 3749, 3752, 3976, 3997, 4025, 4062, 4116, 4161, 4172, 4318, 4376, 4393, 4415, 4480, 4488, 4512, 4539, 4645, 4740, 4842, 4857, 4866, 4996, 4997, 5040, 5056, 5102, 5160, 5176, 5208, 5208, 5324, 5359, 5383, 5396, 5436, 5437, 5486, 5505, 5621, 5657, 5763, 5778, 5860, 5898, 5923, 5941, 6005, 6046, 6049, 6113, 6134, 6154, 6193, 6199, 6202, 6203, 6253, 6370, 6554, 6565, 6574, 6593, 6643, 6650, 6699, 6856, 6857, 6873, 6907, 6913, 6935, 7009, 7045, 7051, 7068, 7084, 7087, 7098, 7104, 7112, 7132, 7181, 7191, 7244, 7302, 7350, 7417, 7513, 7580, 7613, 7702, 7721, 7761, 7828, 7843, 7870, 7909, 7910, 8090, 8180, 8270, 8281, 8310, 8370, 8399, 8404, 8510, 8532, 8557, 8619, 8650, 8677, 8708, 8725, 8739, 8779, 8782, 8816, 8878, 8931, 8953, 8954, 9011, 9094, 9137, 9160, 9183, 9183, 9204, 9318, 9333, 9391, 9395, 9401, 9424, 9438, 9484, 9520, 9596, 9703, 9733, 9820, 9826, 9848, 9863, 9967, 9989 };
    int result = solve(a, b, c);
    cout << "Result is: " << result << endl;
    return 0;
}

// g++ -std=c++11