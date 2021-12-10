import java.util.*; 

class InterviewBit { 
   public static void main(String args[]) 
   { 

       // Defining HashTable to store  
       // String values mapped to integer keys 
       Hashtable<Integer, String> 
           hashTable = new Hashtable<Integer, String>(); 

       // Fill the values in HashTable
       hashTable.put(1, "InterviewBit"); 
       hashTable.put(2, "Example"); 
       hashTable.put(5, "for"); 
       hashTable.put(3, "HashTable"); 

       // Display the hashtable 
       System.out.println(hashTable); 
   } 
} 