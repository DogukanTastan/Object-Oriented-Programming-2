package Dogukan;
import java.util.ArrayList;
import java.io.*;

public class Main{  
	
	public static void main(String[] args) {
		
		File file = new File("text.txt");  
		
		ArrayList<DayofYearSet.DayofYear> set1=new ArrayList<DayofYearSet.DayofYear>();
		ArrayList<DayofYearSet.DayofYear> set2=new ArrayList<DayofYearSet.DayofYear>(); //set3, set4, set5;
		ArrayList<DayofYearSet.DayofYear> set3=new ArrayList<DayofYearSet.DayofYear>();
		ArrayList<DayofYearSet.DayofYear> set4=new ArrayList<DayofYearSet.DayofYear>();
		ArrayList<DayofYearSet.DayofYear> set5=new ArrayList<DayofYearSet.DayofYear>();

		DayofYearSet x1=new DayofYearSet();
		DayofYearSet x2=new DayofYearSet();
		DayofYearSet x3=new DayofYearSet();
		DayofYearSet x4=new DayofYearSet();
		DayofYearSet x5=new DayofYearSet();
		DayofYearSet x6=new DayofYearSet();
		
		DayofYearSet call=new DayofYearSet();

		DayofYearSet.DayofYear obj=x1.new DayofYear(1, 1);		
		set1.add(obj);
		DayofYearSet.DayofYear obj2=x2.new DayofYear(1, 2);
		set1.add(obj2);

		DayofYearSet.DayofYear obj3=x3.new DayofYear(2, 1);
		set2.add(obj3);
		DayofYearSet.DayofYear obj4=x4.new DayofYear(2, 1);
		set2.add(obj4);

		DayofYearSet.DayofYear obj5=x5.new DayofYear(1, 1);
		set3.add(obj5);
		DayofYearSet.DayofYear obj6=x6.new DayofYear(1, 5);
		set3.add(obj6);

		DayofYearSet Set_obj=new DayofYearSet(set1);
		DayofYearSet Set_obj1=new DayofYearSet(set2);
		DayofYearSet Set_obj2=new DayofYearSet(set3);

		try(BufferedWriter br = new BufferedWriter(new FileWriter(file))){   // Writes some sets to text files.
			 br.write("This is set_obj\n");
			 br.write(Set_obj.data[0].getDay()+" ");
			 br.write(Set_obj.data[0].getMonth()+"\n");		
			 br.write(Set_obj.data[1].getDay()+" ");
			 br.write(Set_obj.data[1].getMonth()+"\n");	
			 br.write("This is set_obj2\n");
			 br.write(Set_obj1.data[0].getDay()+" ");
			 br.write(Set_obj1.data[0].getMonth()+"\n");		
			 br.write(Set_obj1.data[1].getDay()+" ");
			 br.write(Set_obj1.data[1].getMonth()+"\n");	
		} 
		catch (IOException e) {
			    System.out.println("Unable to read file " +file.toString());
		}


		System.out.println( "\nTEST SECTION\n***********************************************************\n\n");
		
		System.out.println("Tested toString (info) function\n\n");
		System.out.println("Set_obj Info:\n" + Set_obj + "\nSet_obj2 Info:\n" + Set_obj2 + "\n\n");

		System.out.println("Tested ==,!= function\n");
		
		boolean answer = call.equals(Set_obj ,Set_obj2);
		
		System.out.println(Set_obj.data[0].getDay() + " " + Set_obj.data[0].getMonth() + "\n" + Set_obj.data[1].getDay() + " " + Set_obj.data[1].getMonth() + "\n"); // 
		System.out.println(Set_obj2.data[0].getDay() + " " + Set_obj2.data[0].getMonth() + "\n" +Set_obj2.data[1].getDay() + " " +Set_obj2.data[1].getMonth() + "\n == Answer: ");
		System.out.println(answer + "\n");
		boolean answer2 = call.Notequals(Set_obj , Set_obj2);
		System.out.println(Set_obj.data[0].getDay() + " " + Set_obj.data[0].getMonth() + "\n" + Set_obj.data[1].getDay() + " " + Set_obj.data[1].getMonth() + "\n");
		System.out.println(Set_obj2.data[0].getDay() + " " + Set_obj2.data[0].getMonth() + "\n" + Set_obj2.data[1].getDay() + " " + Set_obj2.data[1].getMonth() + "\n != Answer:");
		System.out.println(answer2 + "\n\n");

		System.out.println("Tested Add function\n");
		System.out.println(Set_obj.data[0].getDay() +" " + Set_obj.data[0].getMonth() + "\n" +Set_obj.data[1].getDay() + " " + Set_obj.data[1].getMonth() + "\nAdded state (object(2,1)):\n");
		call.add(Set_obj, obj3);  
		System.out.println( Set_obj.data[0].getDay() + " " + Set_obj.data[0].getMonth() + "\n" + Set_obj.data[1].getDay() + " " + Set_obj.data[1].getMonth() + "\n" + Set_obj.data[2].getDay() + " " + Set_obj.data[2].getMonth());

		System.out.println( "\n\nTested Remove function\n");
		System.out.println(Set_obj.data[0].getDay() +" " + Set_obj.data[0].getMonth() + "\n" + Set_obj.data[1].getDay() + " " + Set_obj.data[1].getMonth() + "\nRemoved state (object(1,2))\n");
		call.remove(Set_obj, obj2);  // (Set_obj=1,1 1,2   obj2=1,2
		System.out.println( Set_obj.data[0].getDay() + " " + Set_obj.data[0].getMonth() + "\n");
		
		System.out.println("Tested Size Function\n");
		int size_test = call.size(Set_obj);
		System.out.println( size_test + "\n\n");

		System.out.println( "Static Function Test:\n");
		DayofYearSet test_static=new DayofYearSet();
		System.out.println("Objects created " + test_static.counter()+" times\n\n");

		System.out.println( "Tested Union Function\n");
		System.out.println("Object 1:\n" + Set_obj1.data[0].getDay() + " " + Set_obj1.data[0].getMonth() + "\n" + Set_obj1.data[1].getDay() + " " + Set_obj1.data[1].getMonth() + "\n");
		System.out.println("Object 2:\n" + Set_obj2.data[0].getDay() + " " + Set_obj2.data[0].getMonth() + "\n" + Set_obj2.data[1].getDay() + " " + Set_obj2.data[1].getMonth() + "\n");
		DayofYearSet Set_objTest = call.union(Set_obj1 , Set_obj2);
		System.out.println( "Mergeted:\n" + Set_objTest.data[0].getDay() + " " + Set_objTest.data[0].getMonth() + "\n" + Set_objTest.data[1].getDay() +" " + Set_objTest.data[1].getMonth() + "\n"
			+ Set_objTest.data[2].getDay() + " " + Set_objTest.data[2].getMonth() + "\n" + Set_objTest.data[3].getDay() + " " + Set_objTest.data[3].getMonth() + "\n\n");

		System.out.println( "Tested Difference Function-\n");
		System.out.println( "Object 1:\n" + Set_obj1.data[0].getDay() + " " + Set_obj1.data[0].getMonth() + "\n" + Set_obj1.data[1].getDay() + " " + Set_obj1.data[1].getMonth() + "\n");
		System.out.println( "Object 2:\n" + Set_obj2.data[0].getDay() + " " + Set_obj2.data[0].getMonth() + "\n" + Set_obj2.data[1].getDay() + " " +Set_obj2.data[1].getMonth() + "\n");
		DayofYearSet Set_objTest2 = call.difference(Set_obj1 , Set_obj2);
		System.out.println("Difference Set (Object1/Object2):\n" + Set_objTest2.data[0].getDay() + " " + Set_objTest2.data[0].getMonth() + "\n\n");


		System.out.println( "De Morgan Test With ! and ^ Operators:\n");
		
		DayofYearSet Xor=new DayofYearSet();	
		Xor = call.complement(Set_obj1);
		DayofYearSet Xor2=new DayofYearSet();
		Xor2 = call.complement(Set_obj2);
		DayofYearSet test3=new DayofYearSet();
		test3 = call.intersection(Xor , Xor2);
		DayofYearSet sum=new DayofYearSet();
		sum = call.union(Set_obj1 ,Set_obj2);
		DayofYearSet Xor3=new DayofYearSet();
		Xor3 = call.complement(sum);
		if (call.equals(test3 , Xor3))
			System.out.println("De Morgan says !(Set_obj+Set_obj2) = !Set_obj ^ !Set_obj2 \n\n  (Equality successfully achieved)");
		else
			System.out.println( "This statement is also not in accordance with Morgan's rule.\n\n");


		System.out.println( "***********************************************************\nTest Ended...\n");
	}
}


// Dogukan TASTAN 1901042627