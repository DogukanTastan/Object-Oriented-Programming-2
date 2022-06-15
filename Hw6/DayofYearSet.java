package Dogukan;
import java.util.ArrayList;

/**
* This class has an array. And it stores DayofYear objects, which is an inner class, in this array.
* @author Dogukan Tastan
* @version 1.0
* @since 6.01.2022
*/

public class DayofYearSet{  
    
    private static int num;
    private int size;

    public class DayofYear {
        private int day;
        private int month;
       
        /**
         * empty constructor
        */
        public DayofYear() {
            
        } 

        /**
        * Constructor running by taking day and month information
        */
        public DayofYear(int d, int m) {  // Definition of destructor setter getter functions
             setDate(d, m);
             num++;

        }

       public void setDate(int d, int m) {
             day = d;
             month = m;
        }

        public int getDay(){
            return day;
        }
        
        public int getMonth(){
            return month;
        }
    }
    /**
    * static function that counts how many times an object has been created
    */
    public static int counter(){
        return num;
    }
    /**
    * @param data This array holds dayofyear objects
     */
    public DayofYear[] data=new DayofYear[1];    


     /**
      * This constructor takes an arraylist object and adds the data in it
      */
 
   public DayofYearSet(ArrayList<DayofYear> obj) {
        size = obj.size();
        data = new DayofYear[size];
        for (int i = 0; i < size; i++)
            data[i] = obj.get(i);
    }

   /**
     *  empty constructor that doesn't take any objects
     */
  
   public DayofYearSet() {

    }


   /**
     * This constructor takes only one object
     */

    public DayofYearSet(DayofYear obj) {
        size += 1;
        data = new DayofYear[size];
        data[size-1] = obj;
    }

     /**
     * this function is used to access data
     */
    
    public DayofYear[] getData() {
        return data;
    }
    
    /**
     * function that prints details
     */
    
    public String toString(){ 

        return "DayofYearSet details: Size:" + size;
       
    }  
    /**
     * @return Returns the size of the data array in dayofyear
     */

     int size(DayofYearSet k) {

        return k.size;
    }

    /**
     * This function checks the size of the two objects first, and if they are equal, it decides by looking at the other cases.
     */

    public boolean equals(DayofYearSet obj,DayofYearSet obj2) {
        
        int counter = 0;

        if (obj.size != obj2.size)
            return false;
        else {
            for (int i = 0; i < obj.size; i++) {
                for (int j = 0; j < obj2.size; j++) {
                    if ((obj.data[i].getDay() == obj2.data[j].getDay()) && (obj.data[i].getMonth() == obj2.data[j].getMonth()))
                        counter++;
                }
            }
            if (counter == obj.size)
                return true;
            else
                return false;
        }
    }

    /**
     * does the opposite of equal
     */

    public boolean Notequals(DayofYearSet obj,DayofYearSet obj2) {
        
        int counter = 0;

        if (obj.size != obj2.size)
            return false;
        else {
            for (int i = 0; i < obj.size; i++) {
                for (int j = 0; j < obj2.size; j++) {
                    if ((obj.data[i].getDay() == obj2.data[j].getDay()) && (obj.data[i].getMonth() == obj2.data[j].getMonth()))
                        counter++;
                }
            }
            if (counter == obj.size)
                return false;
            else
                return true;
        }
    }

    /**
     * Merges two objects, exists from the same element, does not add it
     */

    public DayofYearSet union( DayofYearSet obj,DayofYearSet obj2) {

        int flag = 0,DinamicArray_size=obj.size;
       
        DayofYearSet k= new DayofYearSet();
        
        DayofYear[] DinamicArray=new DayofYear[DinamicArray_size];

        for (int i = 0; i < obj.size; i++)
            DinamicArray[i]=obj.data[i];

        for (int i = 0; i < obj2.size; i++) {
            flag = 0;
            for (int j = 0; j < obj.size; j++) {

                if ((obj2.data[i].getDay() == obj.data[j].getDay()) && (obj2.data[i].getMonth() == obj.data[j].getMonth())) {
                    flag++;
                }   
            }
            if(flag==0){
                DayofYear[] newDinamicArray=new DayofYear[DinamicArray_size+1];
                
                for(int p=0;p<DinamicArray_size;p++){
                    newDinamicArray[p]=DinamicArray[p];
                }
                newDinamicArray[DinamicArray_size]=obj2.data[i];
                DinamicArray_size+=1;
                DinamicArray=newDinamicArray;
                newDinamicArray=null;
            }
        }

        k.data = new DayofYear[DinamicArray_size];
        k.size = DinamicArray_size;
        for (int i = 0; i < k.size; i++)
            k.data[i] = DinamicArray[i];
        
        return k;
    }

    /**
     * Finds those in the first object but not in the second
     */

    DayofYearSet difference(DayofYearSet obj,DayofYearSet obj2) {

        int size,DinamicArray_size=0,t=1;
        DayofYearSet k= new DayofYearSet();

        if (obj.size < obj2.size)
            size = obj2.size;
        else
            size = obj.size;

        DayofYear[] DinamicArray=new DayofYear[t];

        for (int i = 0; i < size; i++) {

            if ((obj.data[i].getDay() != obj2.data[i].getDay()) || (obj.data[i].getMonth() != obj2.data[i].getMonth())) {

                DinamicArray[DinamicArray_size]=obj.data[i];
                DayofYear[] newDinamicArray=new DayofYear[t+1];
                for(int p=0;p<DinamicArray_size+1;p++)
                    newDinamicArray[p]=DinamicArray[p];
                DinamicArray=newDinamicArray;
                newDinamicArray=null;

                DinamicArray_size++;
                t++;
            }
        }
        
        k.data = new DayofYear[DinamicArray_size+1];

        for (int i = 0; i < DinamicArray_size; i++) {
            k.data[i] = DinamicArray[i];

        }
        k.size = DinamicArray_size;

        return k;
    }

     /**
     * takes the complement of the incoming object !
     */

    DayofYearSet complement(DayofYearSet obj) {

        int flag = 0,t=1;
        DayofYearSet k= new DayofYearSet();
        DayofYear[] DinamicArray=new DayofYear[t];

        for (int i = 1; i <= 12; i++) {
            for (int j = 1; j <= 30; j++) {
                flag = 0;
                for (int p = 0; p < obj.size; p++) {
                    if (obj.data[p].getMonth() == i && obj.data[p].getDay() == j) {
                        flag++;
                    }
                }
                if (flag == 0) {
                    DayofYear ob =new DayofYear(j, i);
                    
                    DinamicArray[t-1]=ob;
                    DayofYear[] newDinamicArray=new DayofYear[t+1];
                    for(int m=0;m<t;m++)
                        newDinamicArray[m]=DinamicArray[m];
                   
                    DinamicArray=newDinamicArray;
                    newDinamicArray=null;
                    t++;
                }
            }
        }

        k.data = new DayofYear[t];
        k.size = t-1;
        for (int i = 0; i < t-1; i++)
            k.data[i] = DinamicArray[i];
        return k;
    }

      /**
     * finds the intersection of two incoming objects
     */

    DayofYearSet intersection( DayofYearSet obj,DayofYearSet obj2) {

        DayofYearSet k = new DayofYearSet();
        int t=1;
        DayofYear[] DinamicArray=new DayofYear[t];

        for (int i = 0; i < obj.size; i++) {
            for (int j = 0; j < obj2.size; j++) {

                if (obj.data[i].getMonth() == obj2.data[j].getMonth() && obj.data[i].getDay() == obj2.data[j].getDay()) {

                    DinamicArray[t-1]=obj.data[i];
                    DayofYear[] newDinamicArray=new DayofYear[t+1];
                     for(int m=0;m<t;m++)
                        newDinamicArray[m]=DinamicArray[m];
                    DinamicArray=newDinamicArray;
                    newDinamicArray=null;
                    t++;
                }
            }
        }
        k.data = new DayofYear[t];
        k.size = t-1;

        for (int i = 0; i < t-1; i++)
            k.data[i] = DinamicArray[i];
        return k;
    }

    /**
     * Adds the incoming object
     */

    void add(DayofYearSet k, DayofYear obj) {

       int t=1;

        DayofYear[] DinamicArray=new DayofYear[k.size+1];

        for (int i = 0; i < k.size; i++)  // I add all the first object then add the object to be added
            DinamicArray[i]=k.data[i];

        DinamicArray[k.size]=obj;

        k.data = new DayofYear[k.size+1];  // I made an operation on the dynamic array using the information I got from the vector.
        k.size = k.size+1;
        
        for (int i = 0; i < k.size; i++)
            k.data[i] = DinamicArray[i];
    }

    /**
     * Finds and deletes the specified object from the specified set
     */

    void remove(DayofYearSet k,DayofYear obj) {

        DayofYear[] DinamicArray=new DayofYear[k.size-1];
        int num=0,t=0;

        for (int i = 0; i < k.size; i++) {

            if ((k.data[i].getDay() == obj.getDay()) && (k.data[i].getMonth() == obj.getMonth())) {
                num = i;
                break;
            }
            DinamicArray[t]=k.data[i];
            t++;
        }
        for (int i = num + 1; i < k.size; i++) {
            DinamicArray[t]=k.data[i];
            t++;
        }
        k.data = new DayofYear[t];
        k.size = t-1;
        for (int i = 0; i < t; i++)
            k.data[i] = DinamicArray[i];
    }
} 

