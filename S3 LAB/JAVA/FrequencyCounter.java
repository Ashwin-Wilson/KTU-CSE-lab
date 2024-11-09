import java.util.*;
class FrequencyCounter{
	public static void main(String arr[]){
	
	int count = 0;
	Scanner sc = new Scanner(System.in);
	System.out.println("Enter a string");
	String str = sc.nextLine();
	
	System.out.println("Enter a character: ");
	char a = sc.nextLine().charAt(0);
	for(int i=0;i<str.length();i++){
		if(str.charAt(i)==a){
			count++;
		}
	}
	System.out.println(""+a+" repeated "+count+" times");
	
	
	
	}
}
