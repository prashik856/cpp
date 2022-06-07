/*
Find longest Arithmetic Progression in an integer array A of size N, and return its length.

More formally, find longest sequence of indices, 0 < i1 < i2 < … < ik < ArraySize(0-indexed) such that sequence A[i1], A[i2], …, A[ik] is an Arithmetic Progression.

Arithmetic Progression is a sequence in which all the differences between consecutive pairs are the same, i.e sequence B[0], B[1], B[2], …, B[m - 1] of length m is an Arithmetic Progression if and only if B[1] - B[0] == B[2] - B[1] == B[3] - B[2] == … == B[m - 1] - B[m - 2]

Note: The common difference can be positive, negative or 0.



Input Format:

The first and the only argument of input contains an integer array, A.
Output Format:

Return an integer, representing the length of the longest possible arithmetic progression.
Constraints:

1 <= N <= 1000
1 <= A[i] <= 1e9
Examples:

Input 1:
    A = [3, 6, 9, 12]

Output 1:
    4

Explanation 1:
    [3, 6, 9, 12] form an arithmetic progression.

Input 2:
    A = [9, 4, 7, 2, 10]

Output 2:
    3

Explanation 2:
    [4, 7, 10] form an arithmetic progression.
*/
/*
Solution approach:
https://www.geeksforgeeks.org/longest-arithmetic-progression-dp-35/
Lenght of Longest Arithmatic Progression (LLAP)
-> A simple solution is to one by one consider every pair as first two elements of AP and check for the remaining elements 
in sorted set. 
-> To consider all pairs as first two elements, we need to run a O(n^2) nested loop. 
-> Inside the nested loops, we need a third loop which linearly looks for the more elements in Arithmetic Progression (AP). 
-> This process takes O(n3) time. 

We can solve this problem in O(n2) time using Dynamic Programming. 
To get idea of the DP solution, let us first discuss solution of following simpler problem.

Given a sorted set, find if there exist three elements in Arithmetic Progression or not 
- Please note that, the answer is true if there are 3 or more elements in AP, otherwise false.
- To find the three elements, we first fix an element as middle element and search for other two (one smaller and one greater).
- We start from the second element and fix every element as middle element. 
- For an element set[j] to be middle of AP, there must exist elements ‘set[i]’ and ‘set[k]’ such that 
    set[i] - d + set[k] + d= 2*set[j] where 0 <= i < j and j < k <=n-1. 
- How to efficiently find i and k for a given j? We can find i and k in linear time using following simple algorithm. 
-> Initialize i as j-1 and k as j+1
-> Do following while i >= 0 and k <= n-1
-> If set[i] + set[k] is equal to 2*set[j], then we are done.
        If set[i] + set[k] > 2*set[j], 
            then decrement i (do i–).
        Else if set[i] + set[k] < 2*set[j], 
            then increment k (do k++).
// The function returns true if there exist three
// elements in AP Assumption: set[0..n-1] is sorted.
// The code strictly implements the algorithm provided
// in the reference.
bool arithmeticThree(vector<int> set, int n)
{
     
    // One by fix every element as middle element
    for(int j = 1; j < n - 1; j++)
    {
         
        // Initialize i and k for the current j
        int i = j - 1, k = j + 1;
 
        // Find if there exist i and k that form AP
        // with j as middle element
        while (i >= 0 && k <= n-1)
        {
            if (set[i] + set[k] == 2 * set[j])
                return true;
                 
            (set[i] + set[k] < 2 * set[j]) ? k++ : i--;
        }
    }
    return false;
}

How to extend the above solution for the original problem? 
- The above function returns a boolean value. 
- The required output of original problem is Length of the Longest Arithmetic Progression (LLAP) which is an integer value. 
- If the given set has two or more elements, then the value of LLAP is at least 2 (Because two elements are always in AP)
- The idea is to create a 2D table L[n][n]. 
- An entry L[i][j] in this table stores LLAP with set[i] and set[j] as first two elements of AP and j > i. 
- The last column of the table is always 2 (Why – see the meaning of L[i][j]). 
- Rest of the table is filled from bottom right to top left. 
- To fill rest of the table, j (second element in AP) is first fixed. 
- i and k are searched for a fixed j. 
- If i and k are found such that i, j, k form an AP, then the value of L[i][j] is set as L[j][k] + 1. 
- Note that the value of L[j][k] must have been filled before as the loop traverses from right to left columns.


// Now, the above solution will work when we have a sorted array as input
What if the array is not sorted?
https://www.geeksforgeeks.org/longest-subsequence-forming-an-arithmetic-progression-ap/?ref=rp

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
    cout << endl;
}

void print2DVector(vector< vector<bool> > arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void print2DVector(vector< vector<char> > arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


void printStrings(vector<string> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << endl;
    }
    cout << endl;
}

void print2DStrings(vector< vector<string> > arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

class ListNode{
    public: 
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createLinkedList(vector<int> arr){
    ListNode *head = 0;
    int n = arr.size();
    for(int i=0; i<n; i++){
        int value = arr[i];
        ListNode *newNode = new ListNode(value);

        if(head == 0){
            head = newNode;
        } else {
            ListNode *temp = head;
            while(temp->next != 0){
                temp = temp -> next;
            }
            temp -> next = newNode;
        }
    }
    return head;
}

void printLinkedList(ListNode *head){
    ListNode *temp = head;
    while(temp != 0){
        cout << temp->val << " ";
        temp = temp -> next;
    }
    cout << endl;
}


int getLinkedListLength(ListNode *head){
    ListNode *temp = head;
    int count = 0;
    while(temp !=0){
        temp = temp -> next;
        count++;
    }
    return count;
}

class TreeNode{
    public:
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x): val(x), left(0), right(0){}
};

TreeNode *createTree(int rootValue, vector<int> a){
    TreeNode *root = new TreeNode(rootValue);

    // Create Tree
    for(int i=0; i<a.size(); i++){
        int val = a[i];
        TreeNode *node = new TreeNode(val);
        // We need to find the location for this val
        TreeNode *temp = root;
        while(true){
            // if value is less than current root
            if(val <= temp -> val){
                if(temp -> left == 0){
                    // found it
                    temp -> left = node;
                    break;
                } else {
                    temp = temp -> left;
                    continue;
                }
            } 
            // if value is greater than current root
            else {
                if(temp -> right == 0){
                    // found it
                    temp -> right = node;
                    break;
                } else {
                    temp = temp -> right;
                    continue;
                }
            }
        }
    }
    return root;
}

// Depth first search
void preOrder(TreeNode *root){
    if(root == 0){
        return;
    }
    cout << root -> val << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

// Sorted order
void inOrder(TreeNode *root){
    if(root == 0){
        return;
    }
    inOrder(root -> left);
    cout << root -> val << " ";
    inOrder(root -> right);
}

// Visited all children first
void postOrder(TreeNode *root){
    if(root == 0){
        return;
    }
    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> val << " ";
}

// Breadth first search
void bfs(TreeNode *root){
    if(root == 0){
        return;
    }
    queue<TreeNode *> q;
    q.push(root);

    while(!q.empty()){
        TreeNode *node = q.front();
        q.pop();
        cout << node->val << " ";
        if(node -> left != 0){
            q.push(node -> left);
        }
        if(node -> right != 0){
            q.push(node -> right);
        }
    }
}

class DisjointSet {
    private:
        vector<int> parent;
        vector<int> rank;
        int n;
    public:
        DisjointSet(int N){
            parent.clear();
            rank.clear();
            n = N;
            // parent of i is i
            for(int i=0; i<n; i++){
                parent.push_back(i);
            }
            // rank is 0?
            for(int i=0; i<n; i++){
                rank.push_back(0);
            }
        }

        int find(int i){
            if(parent[i] == i){
                return i;
            }

            else {
                // since parent[i] != i, we find representative of parent[i]
                int result = find(parent[i]);
                
                // Cache value
                parent[i] = result;
                
                return result;
            }
        }

        void getUnion(int i, int j) {
            /*
            1. If the rank of left is less than the rank of right, then it’s best to move left under right, 
            because that won’t change the rank of right (while moving right under left would increase the height). 
            2. In the same way, if the rank of right is less than the rank of left, then we should move right under left.
            3. If the ranks are equal, it doesn’t matter which tree goes under the other, but the rank of the result will 
            always be one greater than the rank of the trees.
            */
            // get root of i
            int irep = find(i);

            // get root of j
            int jrep = find(j);

            // if irep == jrep, we have same root
            if(irep == jrep){
                return;
            }

            // Else, let's get their ranks
            int rankirep = rank[irep];
            int rankjrep = rank[jrep];

            if(rankirep == rankjrep){
                // set anything
                parent[irep] = jrep;
                // put i under j
                // increase rank of j
                rank[jrep]++;
            } else if(rankirep > rankjrep) {
                // we move j under i, and we don't have to increase the rank of i
                parent[jrep] = irep;
            } else {
                // rankjrep > rankirep
                // we move i under j, and we don't have to increase the rank of j
                parent[irep] = jrep;
            }
        }
};

// Depth first search using Stack
void dfs(TreeNode *root){
    stack<TreeNode *> s;
    s.push(root);
    while(!s.empty()){
        TreeNode *node = s.top();
        s.pop();
        cout << node -> val << " ";
        if(node -> left != 0){
            s.push(node -> left);
        }
        if(node -> right != 0){
            s.push(node -> right);
        }
    }
}

int solve(vector<int> &a){
    int result = 0;
    int n = a.size();

    if(n <= 2){
        return n;
    }

    sort(a.begin(), a.end());

    // Create dict
    vector< vector<int> > dict(n, vector<int>(n, 0));
    
    // min result
    result = 2;
    for(int i=0; i<n; i++){
        dict[i][n-1] = 2;
    }

    // get our j
    for(int j=n-2; j >= 1; j--){
        // initialize i and k
        int i = j-1;
        int k = j+1;
        while(i >= 0 && k <n){
            // if we find our value
            if(a[i] + a[k] == 2 * a[j]){
                dict[i][j] = 1 + dict[j][k];
                result = max(dict[i][j], result);
                // increment k and decrement i
                i--;
                k++;
            } 
            // we need to set i before decrementing
            else if(a[i] + a[k] > 2 * a[j]){
                dict[i][j] = 2; // min value
                i--;
            } else if(a[i] + a[k] < 2 * a[j]){
                k++; // increment k as we already have calculated k
            }
        }
    }
    // My dictionary created is
    // cout << endl << "Dict created is: " << endl;
    // print2DVector(dict);

    return result;
}

int main(){
    vector<int> a = {95142543, 259145010, 353338551, 768734299, 855734538, 632387804, 645244422, 904316624, 33987926, 4413777, 94155814, 855059883, 30879454, 373674224, 26757117, 882774793, 905162248, 287746788, 27092872, 83366540, 982099936, 594313510, 680720373, 148179619, 447559433, 569916814, 814818875, 157606803, 423412573, 608041673, 555463862, 569706722, 505028101, 78178740, 763824636, 319328823, 397894308, 145557798, 406037053, 635461429, 764052269, 548009443, 911088342, 29610657, 523847919, 702755353, 49159371, 514086126, 918799398, 780310029, 602562236, 804363024, 519778100, 71916185, 735769858, 873155577, 296272461, 510416458, 445973261, 754669597, 693497597, 146618687, 478172256, 757299518, 871165081, 128002718, 636800552, 722122640, 211371056, 575386054, 394547137, 797971447, 470725811, 158941526, 934304034, 447472574, 183819424, 297832959, 967894176, 208790007, 145368451, 444907495, 22201208, 547281698, 491038185, 99119874, 534154070, 708027714, 614901171, 952671633, 987805623, 926764224, 427421077, 333241924, 159665292, 213745718, 757874415, 869782548, 514099107, 63237645, 904427670, 826596224, 531024325, 345138970, 397338243, 463449755, 276836213, 262902262, 150713732, 88723684, 825305970, 320561817, 719729820, 797434609, 38032536, 336447570, 349858036, 253777163, 330247196, 293129097, 293247061, 128384362, 608648723, 20726573, 459161597, 146475285, 793847130, 946548519, 82101857, 127667402, 369853658, 239005361, 94940614, 86541374, 654435396, 758194058, 873313332, 800177099, 483775153, 435900526, 39670338, 33096583, 55997505, 552220746, 823489108, 923075065, 700743124, 589356517, 46651028, 232296441, 81013641, 91632089, 314744924, 665715107, 284002479, 447259096, 890853569, 319938896, 987706404, 332940718, 466005168, 275989564, 501196756, 109272735, 448330557, 645287596, 556208622, 201994563, 824716258, 72940241, 767209874, 648085595, 337537581, 416070317, 687054784, 310176366, 117621866, 112004799, 195231794, 979490966, 768761080, 232109385, 158380516, 95351956, 557515427, 690621325, 123488837, 888162933, 195576231, 325984280, 587010463, 344977323, 901762585, 57918989, 634356032, 439264293, 739927485, 957182442, 565294614, 438914767, 234153121, 147713116, 123244680, 125359229, 231095693, 301128248, 517249981, 406619208, 756055699, 367385391, 630773009, 348930444, 769874175, 686277647, 133736689, 370887034, 427095021, 221919446, 694775907, 156329983, 395735667, 372500510, 701240565, 359921219, 808235958, 113928604, 316376128, 164064921, 70116096, 546436689, 247615628, 926285330, 968584207, 470691215, 651236781, 686162928, 353146506, 762267858, 622184824, 962459725, 140027048, 866252044, 232718672, 734990714, 662984251, 557395694, 825760844, 449436371, 977092495, 186106453, 81215312, 259891116, 8240211, 135300262, 880054681, 285404855, 394664007, 614721890, 86971110, 360815583, 807426177, 462583043, 742393158, 521809033, 794936703, 271530119, 203951755, 433237270, 375483333, 367681022, 230734108, 666428498, 462796554, 35913644, 157709901, 635485709, 98392809, 125524270, 857456133, 576205734, 212265192, 570735874, 622116589, 889375904, 180885181, 374134739, 250431554, 276267334, 365437724, 108596848, 899866210, 397799069, 692359572, 347185335, 430848043, 77873953, 67828025, 745533038, 680431245, 657506037, 826849817, 498194582, 117600021, 818597707, 317677044, 553723663, 313211363, 660959144, 881169101, 761842392, 987570527, 196731223, 410582001, 786732996, 564649193, 328750658, 910627099, 867434144, 772920549, 347077937, 773293504, 172881681, 77029773, 780489090, 850019754, 147043811, 685387200, 200387892, 664942348, 181143848, 426583714, 218317285, 282798096, 606280258, 142634310, 663089715, 182445495, 828528373, 792389460, 69808946, 752884160, 750428996, 288676941, 627788814, 659439187, 31313742, 156568279, 775597578, 242756156, 857526416, 683710292, 208128935, 845883002, 413871474, 238330885, 570182540, 985916866, 320946610, 744494830, 411130161, 335981705, 36257745, 572306291, 172569521, 199265770, 59048894, 297308141, 737212638, 425905500, 630734646, 777905327, 374379550, 70002737, 788695623, 264524654, 574702085, 710231809, 78162014, 482710754, 800165936, 846280435, 651068561, 6373035, 811158719, 918390674, 353336702, 737666559, 538762982, 124640899, 216609991, 579328669, 86075982, 348784816, 469788026, 503716383, 580712607, 797352058, 798073123, 32110696, 666063872, 776978313, 900191008, 487969938, 70691670, 556432496, 743411007, 448936403, 90331487, 931780874, 990395394, 429639061, 29935190, 609556529, 245836486, 15283374, 243371002, 453816499, 505726373, 2867782, 954163437, 290743283, 997060456, 780186451, 58533375, 222923299, 386664102, 378038089, 355783770, 350119260, 349210040, 100335029, 556169508, 618347389, 891190687, 617172004, 463856218, 665817316, 928087319, 116092045, 170107016, 687875352, 142819036, 546562530, 215133264, 456048324, 435036922, 557463439, 890609236, 508401459, 939623420, 729821726, 760890638, 23834981, 88825502, 389069046, 386639199, 98581296, 72208212, 275150126, 915867288, 892461140, 494847509, 771652352, 507335831, 209491204, 119217968, 94145525, 682132660, 262158707, 538686729, 990531971, 577605053, 108299508, 197431720, 372683425, 554267500, 863545234, 910261412, 90050256, 572423281, 426544421, 631661658, 252068658, 606441299, 501515228, 93114118, 527135983, 130680583, 546521020, 591224921, 310412578, 866419883, 906105098, 28090982, 752473958, 298606520, 10490198, 215090329, 808173199, 132879915, 90157901, 234120745, 677319911, 978673254, 984119202, 172370417, 74150313, 703786928, 206962817, 574290599, 236845952, 308967146, 195364376, 861162142, 586073234, 699096873, 838103371, 658107321, 195211770, 642947598, 956301302, 788368566, 136386772, 887425655, 689055170, 644675743, 511108396, 264215169, 741896807, 769580767, 49945088, 834729863, 867875010, 666362646, 429772217, 120404435, 707735168, 51718438, 574652255, 946480823, 18068605, 883850008, 722698157, 220417267, 143715394, 579265907, 104976871, 188454887, 896639904, 934115529, 500494510, 117775868, 552824362, 231053389, 663866744, 357070016, 132707371, 251008584, 954144482, 355447632, 782586894, 674323003, 1764379, 662880215, 956354693, 611960876, 927257449, 127119064, 817621707, 20163993, 667547545, 106731513, 687685343, 170563244, 839506583, 619579691, 127662334, 284684185, 93531779, 30580049, 710291910, 14537697, 595679545, 17342098, 484598514, 315493551, 362978811, 657568770, 807469928, 124172680, 689861296, 234591719, 3045341, 717180483, 900400590, 789197545, 110384716, 883792628, 832045917, 855959579, 119684597, 420577960, 211349620, 215102799, 726053865, 785218398, 878595968, 464869001, 507783618, 219246145, 861754183, 872838313, 332733934, 211811950, 469298748, 870355625, 482127835, 666714311, 971488351, 486547116, 853392660, 747848738, 945695499, 777771843, 278397609, 735481070, 314471358, 362858639, 785330017, 607092854, 714781878, 315493825, 367583929, 746375704, 884475001, 489537273, 643095654, 223461427, 841046810, 736362713, 99851327, 281258341, 497430140, 154525209, 797458440, 438560153, 716614967, 449829251, 64033890, 328282083, 551479838, 182216814, 206312276, 378074651, 970281304, 600802834, 225114441, 705957293, 177073776, 740360314, 715538277, 143389936, 477994015, 982820098, 886916186, 716335872, 663667219, 224878812, 998524097, 683530394, 131562332, 333690934, 189983598, 819881917, 426558044, 860623419, 121690361, 845465383, 911141706, 926499405, 271575438, 965636591, 920264558, 709200612, 756472252, 925940721, 545441458, 700637387, 959718405, 237551815, 361246529, 534134431, 715728954, 126872804, 973697181, 29380700, 953927914, 627275516, 622374289, 925572510, 799370122, 355944822, 548924636, 186601337, 882537936, 145532120, 220797725, 95613656, 660940033, 559962120, 448304891, 213919134, 451260060, 489329040, 364540690, 64531939, 109057038, 44344952, 128774352, 720751308, 785722653, 763675165, 652473456, 481825539, 954742960, 367109933, 296117697, 56773153, 703643203, 138712234, 243009616, 822461342, 829272675, 416979695, 938593704, 603254090, 621184740, 260166886, 348147710, 499365719, 473538354, 184711493, 258442709, 360934106, 651950187, 865225915, 166437745, 221721594, 590702813, 125278010, 726660066, 236228773, 673466332, 636072007, 288626883, 860205832, 619498417, 909165460, 997729412, 212161481, 975157147, 944717549, 447493545, 536279021, 252639488, 536704697, 964525079, 492693374, 585583, 178208666, 487103721, 544568080, 366794312, 360193071, 8535001, 640090878, 188056900, 650123336, 226112216, 295700946, 568631861, 693450274, 424994446, 351035597, 717692067, 908658290, 310422440, 175741129, 891132075, 705821944, 49738377, 581755153, 65803277, 1589931, 952158150, 947623026, 961471830, 716344959, 816392428, 834508310, 365459210, 469703647, 159300354, 522675289, 321724170, 928035464, 318315287, 543263932, 610179904, 807025690, 174057378, 509624832, 26025365, 395378987, 820230691, 919693544, 775844726, 101596895, 289506497, 611484397, 435267661, 140526518, 670918150, 758450073, 881190143, 41753462, 597025089, 83321812, 230356440, 761413363, 219331065, 141520976, 204904580, 341239692, 360424131, 670734950, 900641547, 543994550, 4766344, 651048669, 745798418, 845705611, 653678004, 913617000, 652834547, 696270503, 579943015, 747712792, 808334724, 700146943, 233018861, 411566523, 153716671, 93253753, 726497781, 729930249, 437353052, 829963107, 209901857, 578620402, 618090441, 867641348, 681772748, 655568664, 477684915, 82743692, 177570012, 490655774, 114389138, 540378301, 429761744, 503176133, 90665445, 174486569, 206836801, 603831738, 666038264, 346593061, 140175336, 137311393, 321403450, 906403542, 749071996, 30156235, 29692550, 826473343, 613238602, 927153458, 526817571, 147830813, 205422127, 449717533, 333881515, 171844591, 900269142, 727434656, 369852618, 221526081, 525941293, 452611996, 662730695, 590847296, 406120144, 958230042, 992447041, 551931838, 262788050, 378627891, 604917976, 668837734, 152645117, 337256674, 933040591, 687614140, 47596246, 12448015, 907865943, 631583663, 14948517, 636582067, 271270715, 139124424, 728244409, 20727583, 476136667, 904893547, 66656375, 380972715, 285919071, 447166135, 402199865, 568352123, 286861002, 172064696, 304606583, 995567857, 390128595, 623721874, 477752038, 137138130, 630589276, 482155384, 55988530, 401386324, 853812241, 536605233, 366575455, 976822362, 872443671, 142428378, 423216061, 526498363, 151619478, 279211177, 450483144, 316603710, 767810124, 355519245, 912444761, 278374900, 353819311, 258933031, 11832968, 234455829, 940359178, 210804550, 717787720, 368823018, 96908057, 941109573, 285142117, 273793735, 667590448, 664337381, 750881714, 381315603, 680128570, 939156429, 397296753, 839869148, 270758705, 123706942, 378403898, 61493096, 574821862, 575840201, 511203002, 780516387, 235058610, 333881210, 166726859, 785901702, 551726237, 28477513, 806449534, 154271494, 828237729, 202511449, 922084672, 161335325};
    cout << "Given input vector is: " << endl;
    printVector(a);

    int result = solve(a);
    cout << "Result: " << result << endl;
    return 0;
}

// g++ -std=c++11